/* planet.c */
/* planet generating program */
/* Copyright 1988--2009 Torben AE. Mogensen */
// Adapted for the Traveller's Aid Society Access Terminal
// by Perry Horner 2014



/* The program generates planet maps based on recursive spatial subdivision */
/* of a tetrahedron containing the globe. The output is a colour PPM bitmap. */

/* The colours may optionally be modified according to latitude to move the */
/* icecaps lower closer to the poles, with a corresponding change in land colours. */

/* The Mercator map at magnification 1 is scaled to fit the Width */
/* it uses the full height (it could extend infinitely) */
/* The orthographic projections are scaled so the full view would use the */
/* full Height. Areas outside the globe are coloured black. */
/* Stereographic and gnomonic projections use the same scale as orthographic */
/* in the center of the picture, but distorts scale away from the center. */

/* It is assumed that pixels are square */
/* I have included procedures to print the maps as bmp (Windows) or */
/* ppm(portable pixel map) bitmaps  on standard output or specified files. */

/* I have tried to avoid using machine specific features, so it should */
/* be easy to port the program to any machine. Beware, though that due */
/* to different precision on different machines, the same seed numbers */
/* can yield very different planets. */





void readcolors( char* colorsname)
{
	int crow=0, cNum = 0, oldcNum=0, i=0;
	int	rValue=0,gValue=0,bValue=0,result = 0;

	if (NULL == (colfile = fopen(colorsname, "r")))
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR,
			"planet.c readcolors:Cannot open %s\n",colorsname);
		fclose(ERR);
		#if defined(_WIN32)
			Beep(750, 300);
		#endif
			CleanUp();
			device->drop();
		exit(1);
	}


	// Format of colour file is a sequence of lines       
	// each consisting of four integers:                  
	//   colour_number red green blue                     
	// where 0 <= colour_number <= 65535                  
	// and 0<= red, green, blue <= 255                    
	// The colour numbers must be increasing              
	// The first colours have special uses:               
	// 0 is usually black (0,0,0)                         
	// 1 is usually white (255,255,255)                   
	// 2 is the background colour                         
	// 3 is used for latitude/longitude grid lines        
	// 4 and 5 are used for outlines and contour lines    
	// 6 upwards are used for altitudes                   
	// Halfway between 6 and the max colour is sea level  
	// Shallowest sea is (max+6)/2 and land is above this 
	// With 65536 colours, (max+6)/2 = 32770              
	// Colours between specified are interpolated         

	for (crow = 0; !feof(colfile); crow++)
	{
		rValue = 0;
		gValue = 0;
		bValue = 0;
		result = 0;

		oldcNum = cNum;  // remember last colour number 
		result = fscanf(colfile, " %d %d %d %d",
			&cNum, &rValue, &gValue, &bValue);

		if (result > 0)
		{
			if (cNum < oldcNum) cNum = oldcNum;
			if (cNum > 65535) cNum = 65535;
			rtable[cNum] = rValue;
			gtable[cNum] = gValue;
			btable[cNum] = bValue;
			// interpolate colours between oldcNum and cNum 
			for (i = oldcNum + 1; i<cNum; i++) {
				rtable[i] = (rtable[oldcNum] * (cNum - i) + rtable[cNum] * (i - oldcNum))
					/ (cNum - oldcNum + 1);
				gtable[i] = (gtable[oldcNum] * (cNum - i) + gtable[cNum] * (i - oldcNum))
					/ (cNum - oldcNum + 1);
				btable[i] = (btable[oldcNum] * (cNum - i) + btable[cNum] * (i - oldcNum))
					/ (cNum - oldcNum + 1);
			}
		}
	}

	nocols = cNum + 1;
	if (nocols < 10) nocols = 10;

	HIGHEST = nocols - 1;
	SEA = (HIGHEST + LOWEST) / 2;
	LAND = SEA + 1;

	for (i = cNum + 1; i<nocols; i++) {
		// fill up rest of colour table with last read colour 
		rtable[i] = rtable[cNum];
		gtable[i] = gtable[cNum];
		btable[i] = btable[cNum];
	}
	fclose(colfile);

}

void makeoutline(int do_bw)
{
	int i=0, j=0, k=0, t=0;


	outx = (int*)calloc(Width*Height, sizeof(int));
	outy = (int*)calloc(Width*Height, sizeof(int));
	k = 0;
	for (i = 1; i<Width - 1; i++)
	for (j = 1; j<Height - 1; j++)
	if ((col[i][j] >= LOWEST && col[i][j] <= SEA) &&
		(col[i - 1][j] >= LAND || col[i + 1][j] >= LAND ||
		col[i][j - 1] >= LAND || col[i][j + 1] >= LAND ||
		col[i - 1][j - 1] >= LAND || col[i - 1][j + 1] >= LAND ||
		col[i + 1][j - 1] >= LAND || col[i + 1][j + 1] >= LAND)) {
		/* if point is sea and any neighbour is not, add to outline */
		outx[k] = i; outy[k++] = j;
	}

	if (contourstep>0) {

		for (i = 1; i<Width - 1; i++)
		for (j = 1; j<Height - 1; j++) {
			t = (col[i][j] - LAND) / contourstep;
			if (t >= 0 &&
				((col[i - 1][j] - LAND) / contourstep > t ||
				(col[i + 1][j] - LAND) / contourstep > t ||
				(col[i][j - 1] - LAND) / contourstep > t ||
				(col[i][j + 1] - LAND) / contourstep > t)) {
				/* if point is at countour line and any neighbour is higher */
				outx[k] = i; outy[k++] = j;
			}
		}
	}
	if (do_bw) /* if outline only, clear colours */
	for (i = 0; i<Width; i++)
	for (j = 0; j<Height; j++) {
		if (col[i][j] >= LOWEST)
			col[i][j] = WHITE;
		else col[i][j] = BLACK;
	}
	/* draw outline (in black if outline only) */
	while (k-->0) {
		if (do_bw) t = BLACK;
		else if (contourstep == 0 || col[outx[k]][outy[k]]<LAND ||
			((col[outx[k]][outy[k]] - LAND) / contourstep) % 2 == 1)
			t = OUTLINE1;
		else t = OUTLINE2;
		col[outx[k]][outy[k]] = t;
	}


}


void smoothshades()
{
	int i=0, j=0;

	for (i = 0; i<Width - 2; i++)
	for (j = 0; j<Height - 2; j++)
		shades[i][j] = (4 * shades[i][j] + 2 * shades[i][j + 1]
		+ 2 * shades[i + 1][j] + shades[i + 1][j + 1] + 4) / 9;
}


void mercator()  //use this to make map to strech on 3d globe
{
	double y, scale1, cos2, theta1;
	double plcos;
	int i, j, k;

	y = sin(lat);
	y = (1.0 + y) / (1.0 - y);
	y = 0.5*log(y);
	k = (int)(0.5*y*Width*scale / PI);
	for (j = 0; j < Height; j++) {
		if (((j % (Height / 25)) == 0))
		{
			/*ERR = fopen("error.txt", "a");
			fprintf(ERR, "3. j=%d Height=%d\n", j,Height);
			fclose(ERR); */
			fflush(stderr);
		}
		y = PI*(2.0*(j - k) - Height) / Width / scale;
		y = exp(2.*y);
		y = (y - 1.) / (y + 1.);
		scale1 = scale*Width / Height / sqrt(1.0 - y*y) / PI;
		cos2 = sqrt(1.0 - y*y);
		Depth = 3 * ((int)(log_2(scale1*Height))) + 3;
		for (i = 0; i < Width; i++) {
			theta1 = longi - 0.5*PI + PI*(2.0*i - Width) / Width / scale;
			plcos = cos(theta1)*cos2;
			planet0(plcos, y, -sin(theta1)*cos2, i, j);
		}
	}
}



void icosahedral() // modified version of gnomonic
{
	double x=0, y=0, z=0, x1=0, y1=0, z1=0, zz=0, ymin=0, ymax=0;
	int i=0, j=0;
	double lat1=0, longi1=0, sla=0, cla=0, slo=0, clo=0, x0=0, y0=0, sq3=0;
	double L1=0, L2=0, S=0;

	ymin = 2.0;
	ymax = -2.0;
	sq3 = sqrt(3.0);
	L1 = 10.812317;
	L2 = -52.622632;
	S = 55.6;



	for (j = 0; j < Height; j++) {

		
		if (((j % (Height / 25)) == 0)) { 
			/*ERR = fopen("error.txt", "a"); 
			fprintf(ERR, "3. j=%d Height=%d\n", j,Height); 
			fclose(ERR); */
			fflush(stderr); 
		}

		for (i = 0; i < Width; i++) {


			x0 = 198.0*(2.0*i - Width) / Width / scale - 36;
			y0 = 198.0*(2.0*j - Height) / Width / scale - lat / DEG2RAD;

			longi1 = 0.0;

			lat1 = 500.0;

			if (y0 / sq3 <= 18.0 && y0 / sq3 >= -18.0) { /* middle row of triangles */
				/* upward triangles */
				if (x0 - y0 / sq3 < 144.0 && x0 + y0 / sq3 >= 108.0) {
					lat1 = -L1;
					longi1 = 126.0;
				}
				else if (x0 - y0 / sq3 < 72.0 && x0 + y0 / sq3 >= 36.0) {
					lat1 = -L1;
					longi1 = 54.0;
				}
				else if (x0 - y0 / sq3 < 0.0 && x0 + y0 / sq3 >= -36.0) {
					lat1 = -L1;
					longi1 = -18.0;
				}
				else if (x0 - y0 / sq3 < -72.0 && x0 + y0 / sq3 >= -108.0) {
					lat1 = -L1;
					longi1 = -90.0;
				}
				else if (x0 - y0 / sq3 < -144.0 && x0 + y0 / sq3 >= -180.0) {
					lat1 = -L1;
					longi1 = -162.0;
				}

				/* downward triangles */
				else if (x0 + y0 / sq3 < 108.0 && x0 - y0 / sq3 >= 72.0) {
					lat1 = L1;
					longi1 = 90.0;
				}
				else if (x0 + y0 / sq3 < 36.0 && x0 - y0 / sq3 >= 0.0) {
					lat1 = L1;
					longi1 = 18.0;
				}
				else if (x0 + y0 / sq3 < -36.0 && x0 - y0 / sq3 >= -72.0) {
					lat1 = L1;
					longi1 = -54.0;
				}
				else if (x0 + y0 / sq3 < -108.0 && x0 - y0 / sq3 >= -144.0) {
					lat1 = L1;
					longi1 = -126.0;
				}
				else if (x0 + y0 / sq3 < -180.0 && x0 - y0 / sq3 >= -216.0) {
					lat1 = L1;
					longi1 = -198.0;
				}
			}

			if (y0 / sq3 > 18.0) { /* bottom row of triangles */
				if (x0 + y0 / sq3 < 180.0 && x0 - y0 / sq3 >= 72.0) {
					lat1 = L2;
					longi1 = 126.0;
				}
				else if (x0 + y0 / sq3 < 108.0 && x0 - y0 / sq3 >= 0.0) {
					lat1 = L2;
					longi1 = 54.0;
				}
				else if (x0 + y0 / sq3 < 36.0 && x0 - y0 / sq3 >= -72.0) {
					lat1 = L2;
					longi1 = -18.0;
				}
				else if (x0 + y0 / sq3 < -36.0 && x0 - y0 / sq3 >= -144.0) {
					lat1 = L2;
					longi1 = -90.0;
				}
				else if (x0 + y0 / sq3 < -108.0 && x0 - y0 / sq3 >= -216.0) {
					lat1 = L2;
					longi1 = -162.0;
				}
			}
			if (y0 / sq3 < -18.0) { /* top row of triangles */
				if (x0 - y0 / sq3 < 144.0 && x0 + y0 / sq3 >= 36.0) {
					lat1 = -L2;
					longi1 = 90.0;
				}
				else if (x0 - y0 / sq3 < 72.0 && x0 + y0 / sq3 >= -36.0) {
					lat1 = -L2;
					longi1 = 18.0;
				}
				else if (x0 - y0 / sq3 < 0.0 && x0 + y0 / sq3 >= -108.0) {
					lat1 = -L2;
					longi1 = -54.0;
				}
				else if (x0 - y0 / sq3 < -72.0 && x0 + y0 / sq3 >= -180.0) {
					lat1 = -L2;
					longi1 = -126.0;
				}
				else if (x0 - y0 / sq3 < -144.0 && x0 + y0 / sq3 >= -252.0) {
					lat1 = -L2;
					longi1 = -198.0;
				}
			}

			if (lat1 > 400.0) {
				col[i][j] = BACK;
				if (doshade>0) shades[i][j] = 255;
			}
			else {
				x = (x0 - longi1) / S;
				y = (y0 + lat1) / S;

				longi1 = longi1*DEG2RAD - longi;
				lat1 = lat1*DEG2RAD;

				sla = sin(lat1); cla = cos(lat1);
				slo = sin(longi1); clo = cos(longi1);


				zz = sqrt(1.0 / (1.0 + x*x + y*y));
				x = x*zz;
				y = y*zz;
				z = sqrt(1.0 - x*x - y*y);
				x1 = clo*x + slo*sla*y + slo*cla*z;
				y1 = cla*y - sla*z;
				z1 = -slo*x + clo*sla*y + clo*cla*z;

				if (y1 < ymin) ymin = y1;
				if (y1 > ymax) ymax = y1;
				planet0(x1, y1, z1, i, j);
			}
		} //end for i

	} //end for j loop

}





int planet0(double x, double y, double z, int i, int j)
{
	double alt=0, y2=0;
	int colour=0;

	alt = planet1(x, y, z);
	y2 = y*y; y2 = y2*y2; y2 = y2*y2;

	
	
	/* calculate colour */
	if (alt <= 0.) { /* if below sea level then */
		if (icecap && y2 + alt >= 0.98)
			colour = HIGHEST;	 /* icecap if close to poles */
		else {
			colour = SEA + (int)((SEA - LOWEST + 1)*(10 * (alt)));
			if (colour<LOWEST) colour = LOWEST;
		}
	}
	else {
		if (icecap) alt += 0.1*y2;  /* altitude adjusted with latitude */
		if (alt >= 0.1) /* if high then */
			colour = HIGHEST;
		else {
			colour = LAND + (int)((HIGHEST - LAND + 1)*(10 * alt));
			if (colour>HIGHEST) colour = HIGHEST;
		}
	}

	col[i][j] = colour;
	if (vgrid != 0.0) {
		xxx[i][j] = x;
		yyy[i][j] = y;
	}
	if (hgrid != 0.0) zzz[i][j] = z;
	if (doshade>0) shades[i][j] = shade;
	return(colour);
}



double planet(double a, double b, double c, double d, double as,double bs, double cs, double ds,
	double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz, double dx, double dy, double dz,
	double x, double y, double z, int level)
{

	double abx=0, aby=0, abz=0, acx=0, acy=0, acz=0, adx=0, ady=0, adz=0;
	double bcx=0, bcy=0, bcz=0, bdx=0, bdy=0, bdz=0, cdx=0, cdy=0, cdz=0;
	double lab=0, lac=0, lad=0, lbc=0, lbd=0, lcd=0;
	double ex=0, ey=0, ez=0, e=0, es=0, es1=0, es2=0, es3=0;
	double eax=0, eay=0, eaz=0, epx=0, epy=0, epz=0;
	double ecx=0, ecy=0, ecz=0, edx=0, edy=0, edz=0;
	double x1=0, y1=0, z1=0, x2=0, y2=0, z2=0, l1=0, tmp=0;

	if (level>0) {
		if (level == 11) {
			ssa = a; ssb = b; ssc = c; ssd = d; ssas = as; ssbs = bs; sscs = cs; ssds = ds;
			ssax = ax; ssay = ay; ssaz = az; ssbx = bx; ssby = by; ssbz = bz;
			sscx = cx; sscy = cy; sscz = cz; ssdx = dx; ssdy = dy; ssdz = dz;
		}
		abx = ax - bx; aby = ay - by; abz = az - bz;
		acx = ax - cx; acy = ay - cy; acz = az - cz;
		lab = abx*abx + aby*aby + abz*abz;
		lac = acx*acx + acy*acy + acz*acz;

		/* reorder vertices so ab is longest edge */
		if (lab<lac)
			return(planet(a, c, b, d, as, cs, bs, ds,
			ax, ay, az, cx, cy, cz, bx, by, bz, dx, dy, dz,
			x, y, z, level));
		else {
			adx = ax - dx; ady = ay - dy; adz = az - dz;
			lad = adx*adx + ady*ady + adz*adz;
			if (lab<lad)
				return(planet(a, d, b, c, as, ds, bs, cs,
				ax, ay, az, dx, dy, dz, bx, by, bz, cx, cy, cz,
				x, y, z, level));
			else {
				bcx = bx - cx; bcy = by - cy; bcz = bz - cz;
				lbc = bcx*bcx + bcy*bcy + bcz*bcz;
				if (lab<lbc)
					return(planet(b, c, a, d, bs, cs, as, ds,
					bx, by, bz, cx, cy, cz, ax, ay, az, dx, dy, dz,
					x, y, z, level));
				else {
					bdx = bx - dx; bdy = by - dy; bdz = bz - dz;
					lbd = bdx*bdx + bdy*bdy + bdz*bdz;
					if (lab<lbd)
						return(planet(b, d, a, c, bs, ds, as, cs,
						bx, by, bz, dx, dy, dz, ax, ay, az, cx, cy, cz,
						x, y, z, level));
					else {
						cdx = cx - dx; cdy = cy - dy; cdz = cz - dz;
						lcd = cdx*cdx + cdy*cdy + cdz*cdz;
						if (lab<lcd)
							return(planet(c, d, a, b, cs, ds, as, bs,
							cx, cy, cz, dx, dy, dz, ax, ay, az, bx, by, bz,
							x, y, z, level));
						else { /* ab is longest, so cut ab */
							es = rand2(as, bs);
							es1 = rand2(es, es);
							es2 = 0.5 + 0.1*rand2(es1, es1);
							es3 = 1.0 - es2;
							if (ax<bx) {
								ex = es2*ax + es3*bx; ey = es2*ay + es3*by; ez = es2*az + es3*bz;
							}
							else if (ax>bx) {
								ex = es3*ax + es2*bx; ey = es3*ay + es2*by; ez = es3*az + es2*bz;
							}
							else { /* ax==bx, very unlikely to ever happen */
								ex = 0.5*ax + 0.5*bx; ey = 0.5*ay + 0.5*by; ez = 0.5*az + 0.5*bz;
							}
							if (lab>1.0) lab = pow(lab, 0.5);
							/* decrease contribution for very long distances */

							/* new altitude is: */
							e = 0.5*(a + b) /* average of end points */
								+ es*dd1*fabs(a - b) /* plus contribution for altitude diff */
								+ es1*dd2*pow(lab, POW); /* plus contribution for distance */
							eax = ax - ex; eay = ay - ey; eaz = az - ez;
							epx = x - ex; epy = y - ey; epz = z - ez;
							ecx = cx - ex; ecy = cy - ey; ecz = cz - ez;
							edx = dx - ex; edy = dy - ey; edz = dz - ez;
							if ((eax*ecy*edz + eay*ecz*edx + eaz*ecx*edy
								- eaz*ecy*edx - eay*ecx*edz - eax*ecz*edy)*
								(epx*ecy*edz + epy*ecz*edx + epz*ecx*edy
								- epz*ecy*edx - epy*ecx*edz - epx*ecz*edy)>0.0)
								return(planet(c, d, a, e, cs, ds, as, es,
								cx, cy, cz, dx, dy, dz, ax, ay, az, ex, ey, ez,
								x, y, z, level - 1));
							else
								return(planet(c, d, b, e, cs, ds, bs, es,
								cx, cy, cz, dx, dy, dz, bx, by, bz, ex, ey, ez,
								x, y, z, level - 1));
						}
					}
				}
			}
		}
	}
	else { /* level == 0 */
		if (doshade == 1 || doshade == 2) {
			x1 = 0.25*(ax + bx + cx + dx);
			x1 = a*(x1 - ax) + b*(x1 - bx) + c*(x1 - cx) + d*(x1 - dx);
			y1 = 0.25*(ay + by + cy + dy);
			y1 = a*(y1 - ay) + b*(y1 - by) + c*(y1 - cy) + d*(y1 - dy);
			z1 = 0.25*(az + bz + cz + dz);
			z1 = a*(z1 - az) + b*(z1 - bz) + c*(z1 - cz) + d*(z1 - dz);
			l1 = sqrt(x1*x1 + y1*y1 + z1*z1);
			if (l1 == 0.0) l1 = 1.0;
			tmp = sqrt(1.0 - y*y);
			if (tmp<0.0001) tmp = 0.0001;
			x2 = x*x1 + y*y1 + z*z1;
			y2 = -x*y / tmp*x1 + tmp*y1 - z*y / tmp*z1;
			z2 = -z / tmp*x1 + x / tmp*z1;
			shade =
				(int)((-sin(PI*shade_angle / 180.0)*y2 - cos(PI*shade_angle / 180.0)*z2)
				/ l1*48.0 + 128.0);
			if (shade<10) shade = 10;
			if (shade>255) shade = 255;
			if (doshade == 2 && (a + b + c + d)<0.0) shade = 150;
		}
		else if (doshade == 3) {
			if ((a + b + c + d)<0.0) {
				x1 = x; y1 = y; z1 = z;
			}
			else {
				l1 = 50.0 /
					sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by) + (az - bz)*(az - bz) +
					(ax - cx)*(ax - cx) + (ay - cy)*(ay - cy) + (az - cz)*(az - cz) +
					(ax - dx)*(ax - dx) + (ay - dy)*(ay - dy) + (az - dz)*(az - dz) +
					(bx - cx)*(bx - cx) + (by - cy)*(by - cy) + (bz - cz)*(bz - cz) +
					(bx - dx)*(bx - dx) + (by - dy)*(by - dy) + (bz - dz)*(bz - dz) +
					(cx - dx)*(cx - dx) + (cy - dy)*(cy - dy) + (cz - dz)*(cz - dz));
				x1 = 0.25*(ax + bx + cx + dx);
				x1 = l1*(a*(x1 - ax) + b*(x1 - bx) + c*(x1 - cx) + d*(x1 - dx)) + x;
				y1 = 0.25*(ay + by + cy + dy);
				y1 = l1*(a*(y1 - ay) + b*(y1 - by) + c*(y1 - cy) + d*(y1 - dy)) + y;
				z1 = 0.25*(az + bz + cz + dz);
				z1 = l1*(a*(z1 - az) + b*(z1 - bz) + c*(z1 - cz) + d*(z1 - dz)) + z;
			}
			l1 = sqrt(x1*x1 + y1*y1 + z1*z1);
			if (l1 == 0.0) l1 = 1.0;
			x2 = cos(PI*shade_angle / 180.0 - 0.5*PI)*cos(PI*shade_angle2 / 180.0);
			y2 = -sin(PI*shade_angle2 / 180.0);
			z2 = -sin(PI*shade_angle / 180.0 - 0.5*PI)*cos(PI*shade_angle2 / 180.0);
			shade = (int)((x1*x2 + y1*y2 + z1*z2) / l1*170.0 + 10);
			if (shade<10) shade = 10;
			if (shade>255) shade = 255;
		}
		return((a + b + c + d) / 4);
	}
}

double planet1(double x, double y, double z)
{
	double abx=0, aby=0, abz=0, acx=0, acy=0, acz=0, adx=0, ady=0, adz=0, apx=0, apy=0, apz=0;
	double bax=0, bay=0, baz=0, bcx=0, bcy=0, bcz=0, bdx=0, bdy=0, bdz=0, bpx=0, bpy=0, bpz=0;

	abx = ssbx - ssax; aby = ssby - ssay; abz = ssbz - ssaz;
	acx = sscx - ssax; acy = sscy - ssay; acz = sscz - ssaz;
	adx = ssdx - ssax; ady = ssdy - ssay; adz = ssdz - ssaz;
	apx = x - ssax; apy = y - ssay; apz = z - ssaz;
	if ((adx*aby*acz + ady*abz*acx + adz*abx*acy
		- adz*aby*acx - ady*abx*acz - adx*abz*acy)*
		(apx*aby*acz + apy*abz*acx + apz*abx*acy
		- apz*aby*acx - apy*abx*acz - apx*abz*acy)>0.0){
		/* p is on same side of abc as d */
		if ((acx*aby*adz + acy*abz*adx + acz*abx*ady
			- acz*aby*adx - acy*abx*adz - acx*abz*ady)*
			(apx*aby*adz + apy*abz*adx + apz*abx*ady
			- apz*aby*adx - apy*abx*adz - apx*abz*ady)>0.0){
			/* p is on same side of abd as c */
			if ((abx*ady*acz + aby*adz*acx + abz*adx*acy
				- abz*ady*acx - aby*adx*acz - abx*adz*acy)*
				(apx*ady*acz + apy*adz*acx + apz*adx*acy
				- apz*ady*acx - apy*adx*acz - apx*adz*acy)>0.0){
				/* p is on same side of acd as b */
				bax = -abx; bay = -aby; baz = -abz;
				bcx = sscx - ssbx; bcy = sscy - ssby; bcz = sscz - ssbz;
				bdx = ssdx - ssbx; bdy = ssdy - ssby; bdz = ssdz - ssbz;
				bpx = x - ssbx; bpy = y - ssby; bpz = z - ssbz;
				if ((bax*bcy*bdz + bay*bcz*bdx + baz*bcx*bdy
					- baz*bcy*bdx - bay*bcx*bdz - bax*bcz*bdy)*
					(bpx*bcy*bdz + bpy*bcz*bdx + bpz*bcx*bdy
					- bpz*bcy*bdx - bpy*bcx*bdz - bpx*bcz*bdy)>0.0){
					/* p is on same side of bcd as a */
					/* Hence, p is inside tetrahedron */
					return(planet(ssa, ssb, ssc, ssd, ssas, ssbs, sscs, ssds,
						ssax, ssay, ssaz, ssbx, ssby, ssbz,
						sscx, sscy, sscz, ssdx, ssdy, ssdz,
						x, y, z, 11));
				}
			}
		}
	} /* otherwise */
	return(planet(M, M, M, M,
		/* initial altitude is M on all corners of tetrahedron */
		r1, r2, r3, r4,
		/* same seed set is used in every call */
		-sqrt(3.0) - 0.20, -sqrt(3.0) - 0.22, -sqrt(3.0) - 0.23,
		-sqrt(3.0) - 0.19, sqrt(3.0) + 0.18, sqrt(3.0) + 0.17,
		sqrt(3.0) + 0.21, -sqrt(3.0) - 0.24, sqrt(3.0) + 0.15,
		sqrt(3.0) + 0.24, sqrt(3.0) + 0.22, -sqrt(3.0) - 0.25,
		/* coordinates of vertices of tetrahedron*/
		x, y, z,
		/* coordinates of point we want colour of */
		Depth));
	/* subdivision depth */

}


double rand2(double p, double q) /* random number generator taking two seeds */
  /* rand2(p,q) = rand2(q,p) is important     */
{
	double r=0;
	r = (p + 3.14159265)*(q + 3.14159265);
	return(2.*(r - (int)r) - 1.);
}



void printbmp(FILE *outfile) // prints picture in BMP format 
{
	int i=0, j=0, c=0, s=0, W1=0;


	fprintf(outfile, "BM");

	W1 = (3 * Width + 3);
	W1 -= W1 % 4;
	s = 54 + W1*Height; /* file size */
	putc(s & 255, outfile);
	putc((s >> 8) & 255, outfile);
	putc((s >> 16) & 255, outfile);
	putc(s >> 24, outfile);

	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(54, outfile); /* offset to data */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(40, outfile); /* size of infoheader */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(Width & 255, outfile);
	putc((Width >> 8) & 255, outfile);
	putc((Width >> 16) & 255, outfile);
	putc(Width >> 24, outfile);

	putc(Height & 255, outfile);
	putc((Height >> 8) & 255, outfile);
	putc((Height >> 16) & 255, outfile);
	putc(Height >> 24, outfile);

	putc(1, outfile);  /* no. of planes = 1 */
	putc(0, outfile);

	putc(24, outfile);  /* bpp */
	putc(0, outfile);

	putc(0, outfile); /* no compression */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* image size (unspecified) */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* h. pixels/m */
	putc(32, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* v. pixels/m */
	putc(32, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* colours used (unspecified) */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);


	putc(0, outfile); /* important colours (all) */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	if (doshade) {
		for (j = Height - 1; j >= 0; j--) {
			for (i = 0; i<Width; i++) {
				s = shades[i][j];
				c = s*btable[col[i][j]] / 150;
				if (c>255) c = 255;
				putc(c, outfile);
				c = s*gtable[col[i][j]] / 150;
				if (c>255) c = 255;
				putc(c, outfile);
				c = s*rtable[col[i][j]] / 150;
				if (c>255) c = 255;
				putc(c, outfile);
			}
			for (i = 3 * Width; i<W1; i++) putc(0, outfile);

		}
	}
	else {
		for (j = Height - 1; j >= 0; j--) {
			for (i = 0; i<Width; i++) {
				putc(btable[col[i][j]], outfile);
				putc(gtable[col[i][j]], outfile);
				putc(rtable[col[i][j]], outfile);
			}
			for (i = 3 * Width; i<W1; i++) putc(0, outfile);
		}
	}
	fclose(outfile);
	
}

void printbmpBW(FILE *outfile) /* prints picture in b/w BMP format */
{
	int i, j, c, s, W1;

	fprintf(outfile, "BM");

	W1 = (Width + 31);
	W1 -= W1 % 32;
	s = 62 + (W1*Height) / 8; /* file size */
	putc(s & 255, outfile);
	putc((s >> 8) & 255, outfile);
	putc((s >> 16) & 255, outfile);
	putc(s >> 24, outfile);

	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(62, outfile); /* offset to data */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(40, outfile); /* size of infoheader */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(Width & 255, outfile);
	putc((Width >> 8) & 255, outfile);
	putc((Width >> 16) & 255, outfile);
	putc(Width >> 24, outfile);

	putc(Height & 255, outfile);
	putc((Height >> 8) & 255, outfile);
	putc((Height >> 16) & 255, outfile);
	putc(Height >> 24, outfile);

	putc(1, outfile);  /* no. of planes = 1 */
	putc(0, outfile);

	putc(1, outfile);  /* bpp 1*/
	putc(0, outfile);

	putc(0, outfile); /* no compression */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* image size (unspecified) */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* h. pixels/m */
	putc(32, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* v. pixels/m */
	putc(32, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(2, outfile); /* colours used  2*/
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);


	putc(2, outfile); /* important colours (2) */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(0, outfile); /* colour 0 = black */
	putc(0, outfile);
	putc(0, outfile);
	putc(0, outfile);

	putc(255, outfile); /* colour 1 = white */
	putc(255, outfile);
	putc(255, outfile);
	putc(255, outfile);

	for (j = Height - 1; j >= 0; j--)
	for (i = 0; i<W1; i += 8) {
		if (i<Width && col[i][j] >= WHITE)
			c = 128;
		//else c = 0;
		else c = 255; //background color

		if (i + 1<Width && col[i + 1][j] >= WHITE)
			c += 64;
		if (i + 2<Width && col[i + 2][j] >= WHITE)
			c += 32;
		if (i + 3<Width && col[i + 3][j] >= WHITE)
			c += 16;
		if (i + 4<Width && col[i + 4][j] >= WHITE)
			c += 8;
		if (i + 5<Width && col[i + 5][j] >= WHITE)
			c += 4;
		if (i + 6<Width && col[i + 6][j] >= WHITE)
			c += 2;
		if (i + 7<Width && col[i + 7][j] >= WHITE)
			c += 1;
		putc(c, outfile);
	}
	fclose(outfile);
}



double log_2(double x)
{ 
	return(log(x) / log(2.0)); 
}


void planet_surface(int hexnum)

{

	int i=0;
	char filename2[256] = "./temp/tempplanet.bmp\0"; //grid planet
	char filename3[256] = "./temp/tempplanet2.bmp\0"; //globe planet
	char colorsname[255] = "                                                        ";
	// char colorsname[256] //normal.col, water.col, desert.col, garden.col, barren.col, hell.col
	int do_file = 0;
	int inc=0;
	char uwpchar[255];
	char *tmpuwp;
	char charuwp[10] = "         ";
	double seeduwp; //seed good to 8 decimal places and UWP position 5 plus hex number

	FILE *outfile2; //grid planet map
	FILE *outfile3; //globe planet map

	longi = 0.0;
	lat = 0.0;
	scale = 1.0;
	M = 0;  //water percentile
	do_bw = 0; //1=black and white output, 0 = color
	do_outline = 0; //1=outline land with black
	doshade = 0;  //shading set to 1 will create textured land and ocean
	
	
	if (((sec_world[hexnum].uwp[2]) == 'a') || ((sec_world[hexnum].uwp[2]) == 'A'))
	{
		hydro = 10; //waterworld
	}
	else
		hydro = ((int)(sec_world[hexnum].uwp[2]) - 48);

	//M thresholds should range between .03 and -.03 to be semi-close to the system hydro percentage
	//M = -.02;  initial altitude (slightly below sea level)
	/*The initial altitude (-i) option specifies the initial altitude of the
	corners of the box, before subdivison. Increasing this will increase
	the amount of land on the planet and vice-versa. The default value is
	-0.015, which gives a slight preference for water. Changing this value
	by +/- 0.01 will change the water percentage by 5-15% (depending on
	the planet in question). If you, for example, want a planet with 70%
	water, adjust the initial altitude until the indicated water percentage is 70.*/

	if (hydro == 0) M = 0;  // desert world
	if (hydro == 1) M = 0.046; // 10%
	if (hydro == 2) M = 0.04;  //20%
	if (hydro == 3) M = 0.038;  //30%
	if (hydro == 4) M = 0.005;  //40%
	if (hydro == 5) M = 0.01;  //50%
	if (hydro == 6) M = -0.012;  //60%
	if (hydro == 7) M = -0.02; //70%
	if (hydro == 8) M = -0.03;  //80%
	if (hydro == 9) M = -0.04; //90%
	if (hydro > 9) M = -0.99; //waterworld

	if(water==1) M = -0.99; //waterworld
	if (asteroid == 1)
	{
		//do_bw = 1; //1=black and white output, 0 = color
		do_outline = 0; //1=outline land with black
		doshade = 1; //texture surface
		M = .05; //asteroid
	}



	
	dd2 = .035; // Distance contribution to variation(default = 0.03)
	dd1 = 0.5; //Altitude contribution to variation (default = 0.4)
	vgrid = hgrid = 0.0; //no map grid
	do_file = 1; //output a bitmap file

	 //icecap = 0 color depends on latitude (1=icecap 0=latitude only (this is set in navlib.c)


	//Width = 800, Height = 600; /* default map size DO NOT CHANGE Icosahedral maps are 2.117 times as wide as high. (377.8932451582428)*/
	Width = 800;
	Height = 375;
	

	sprintf(charuwp, sec_world[hexnum].uwp);
	charuwp[7] = '\0';


	sprintf(uwpchar, ".%d%d%d%d%d%d%d", charuwp[0], charuwp[1], charuwp[2], charuwp[3], charuwp[4], charuwp[5], charuwp[6]);
	uwpchar[strlen(uwpchar)] = '\0';

		seeduwp = strtod(uwpchar, &tmpuwp)+(hexnum*.000001);
		
	rseed = seeduwp; //random seed is based on the unique UWP positions 0 through 4 (5 places) + .000001 X hexnumber

	
	sprintf(colorsname, "./bmaps/planet/colors/normal.col");

	if (normal == 1) sprintf(colorsname, "bmaps/planet/colors/normal.col");
	if (water  == 1) sprintf(colorsname, "bmaps/planet/colors/water.col");
	if (desert == 1) sprintf(colorsname, "bmaps/planet/colors/desert.col");
	if (garden == 1) sprintf(colorsname, "bmaps/planet/colors/garden.col");
	if (barren == 1) sprintf(colorsname, "bmaps/planet/colors/barren.col");
	if (hell == 1) sprintf(colorsname, "bmaps/planet/colors/hell.col");
	if (iceworld == 1) sprintf(colorsname, "bmaps/planet/colors/iceworld.col");
	if (asteroid == 1) sprintf(colorsname, "bmaps/planet/colors/asteroid.col");

	if ((normal == 1)&&(hydro<2)) sprintf(colorsname, "bmaps/planet/colors/normalnowater.col");
	
	if ((desert == 1) || (hell == 1))
	{
		do_outline = 1;
	}

	readcolors(colorsname);



		outfile2 = fopen(filename2, "wb");
		if (!outfile2){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Can't open to write output grid planet file: %s\n",filename2);
			fclose(ERR);
		}

		outfile3 = fopen(filename3, "wb");
		if (!outfile3){
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Can't open to write output globe planet file: %s\n", filename3);
			fclose(ERR);
		}

	if (longi>180) longi -= 360;
	longi = longi*DEG2RAD;
	lat = lat*DEG2RAD;

	sla = sin(lat); cla = cos(lat);
	slo = sin(longi); clo = cos(longi);

	

	col = (unsigned short**)calloc(Width, sizeof(unsigned short*));
	if (col == 0) {
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "planet.c col == 0 Memory allocation failed.");
		fclose(ERR);
#if defined(_WIN32)
		Beep(750, 300);
#endif
		device->drop();
		exit(1);
	}
	for (i = 0; i<Width; i++) {
		col[i] = (unsigned short*)calloc(Height, sizeof(unsigned short));
		if (col[i] == 0) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR,
				"planet.c col[i] Memory allocation failed at %d out of %d cols\n",
				i + 1, Width);
			fclose(ERR);
#if defined(_WIN32)
			Beep(750, 300);
#endif
			device->drop();
			exit(1);
		}
	}

	if (doshade>0) {
		shades = (unsigned short**)calloc(Width, sizeof(unsigned short*));
		if (shades == 0) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planet.c shades == 0 Memory allocation failed.");
			fclose(ERR);
#if defined(_WIN32)
			Beep(750, 300);
#endif
			device->drop();
			exit(1);
		}
		for (i = 0; i<Width; i++) {
			shades[i] = (unsigned short*)calloc(Height, sizeof(unsigned short));
			if (shades[i] == 0) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR,
					"planet.c shades[i] Memory allocation failed at %d out of %d shades\n",
					i, Width);
				fclose(ERR);
#if defined(_WIN32)
				Beep(750, 300);
#endif
				device->drop();
				exit(1);
			}
		}
	}

	if (vgrid != 0.0) {
		xxx = (double**)calloc(Width, sizeof(double*));
		if (xxx == 0) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planet.c xxx Memory allocation failed.");
			fclose(ERR);
#if defined(_WIN32)
			Beep(750, 300);
#endif
			device->drop();
			exit(1);
		}
		for (i = 0; i<Width; i++) {
			xxx[i] = (double*)calloc(Height, sizeof(double));
			if (xxx[i] == 0) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR,
					"planet.c xxx[i] Memory allocation failed at %d out of %d xs\n",
					i + 1, Width);
				fclose(ERR);
#if defined(_WIN32)
				Beep(750, 300);
#endif
				device->drop();
				exit(1);
			}
		}

		yyy = (double**)calloc(Width, sizeof(double*));
		if (yyy == 0) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planet.c yyy Memory allocation failed.");
			fclose(ERR);
#if defined(_WIN32)
			Beep(750, 300);
#endif
			device->drop();
			exit(1);
		}
		for (i = 0; i<Width; i++) {
			yyy[i] = (double*)calloc(Height, sizeof(double));
			if (yyy[i] == 0) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR,
					"planet.c yyy[i] Memory allocation failed at %d out of %d ys\n",
					i + 1, Width);
				fclose(ERR);
#if defined(_WIN32)
				Beep(750, 300);
#endif
				device->drop();
				exit(1);
			}
		}
	}

	if (hgrid != 0.0) {
		zzz = (double**)calloc(Width, sizeof(double*));
		if (zzz == 0) {
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "planet.c zzz Memory allocation failed.");
			fclose(ERR);
#if defined(_WIN32)
			Beep(750, 300);
#endif
			device->drop();
			exit(1);
		}
		for (i = 0; i<Width; i++) {
			zzz[i] = (double*)calloc(Height, sizeof(double));
			if (zzz[i] == 0) {
				ERR = fopen("error.txt", "a");
				fprintf(ERR,
					"planet.c zzz[i] Memory allocation failed at %d out of %d zs\n",
					i + 1, Width);
				fclose(ERR);
#if defined(_WIN32)
				Beep(750, 300);
#endif
				device->drop();
				exit(1);
			}
		}
	}


	Depth = 3 * ((int)(log_2(scale*Height))) + 6;

	r1 = rseed;

	r1 = rand2(r1, r1);
	r2 = rand2(r1, r1);
	r3 = rand2(r1, r2);
	r4 = rand2(r2, r3);


	


	mercator();//*********************create globe map*****************
	if (do_outline) makeoutline(do_bw);
	if (doshade>0) smoothshades();
	/* plot picture */
		if (do_bw) printbmpBW(outfile3);
		else  printbmp(outfile3);

		icosahedral(); //*********************create grid map*****************

		if (do_outline) makeoutline(do_bw);
		if (doshade>0) smoothshades();
		/* plot picture */
		if (do_bw) printbmpBW(outfile2);
		else  printbmp(outfile2);

		//free(col);
		//free(xxx);
		//free(yyy);
		//free(zzz);


		tmpuwp='\0';

		colfile = NULL;
		outfile = NULL;
		outfile2 = NULL;
		outfile3 = NULL;

		return;
}