/* 
	Traveller's Aid Society Access Terminal

	     by Perry Horner 2001
	  

  The Traveller game in all forms is owned by Far Future Enterprises. 
  Copyright 1977 - 2015 Far Future Enterprises. Traveller is a registered 
  trademark of Far Future Enterprises. Far Future permits web sites and 
  fanzines for this game, provided it contains this notice, that Far Future 
  is notified, and subject to a withdrawal of permission on 90 days notice. 
  The use of this program is for personal, non-commercial use only. 
  Any use of Far Future Enterprises's copyrighted material or trademarks 
  anywhere in this program and its files should not be viewed as a challenge 
  to those copyrights or trademarks. In addition, any program/ article/ file 
  cannot be republished or distributed without the consent of the author who 
  contributed it. 
  

   The bulk of the code is by Perry Horner (perry1@liberated-technologies.com)

 
*/



int InitTAS()
{
    //load background screens
	int x = 0;

	LoginBackground = driver->getTexture("bmaps/menu/taslogin.jpg");
	if (LoginBackground == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/taslogin.jpg\n");
		fclose(ERR);
		//CleanUp();
		device->drop();
		return 1;
	}

	LoginUnameFLAG = 0; //is the username set 0=no 1=yes
	LoginPassFLAG = 0;

	PrinterOnButton = NULL;
	PrinterOnButton = driver->getTexture("bmaps/menu/printeron.bmp");

	if (PrinterOnButton == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/printeron.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	PrinterOffButton = NULL;
	PrinterOffButton = driver->getTexture("bmaps/menu/printeroff.bmp");

	if (PrinterOffButton == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/printeroff.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	bluestar = NULL;
	bluestar = driver->getTexture("bmaps/menu/bluestar.jpg");

	if (bluestar == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/menu/bluestar.jpg\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	yellowstar = NULL;
	yellowstar = driver->getTexture("bmaps/menu/yellowstar.jpg");

	if (yellowstar == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/menu/yellowstar.jpg\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	
	orangestar = NULL;
	orangestar = driver->getTexture("bmaps/menu/orangestar.jpg");

	if (orangestar == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/orangestar.jpg\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	MainMenuBackground = driver->getTexture("bmaps/menu/tasbackground.bmp");

	if (MainMenuBackground == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/tasbackground.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	
	BreakingNews = NULL;
	BreakingNews = driver->getTexture("bmaps/menu/newsbreak.jpg");

	if (BreakingNews == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/menu/newsbreak.jpg\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(BreakingNews, SColor(0, 0, 0, 0));
	

	SubmitHover = NULL;
	SubmitHover = driver->getTexture("bmaps/menu/submithover.bmp");

	if (SubmitHover == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/submithover.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(SubmitHover, SColor(0, 0, 0, 0));


	//Navigation Library stuff needed static

	Galaxy = NULL;
	Galaxy = driver->getTexture("bmaps/navlib/galaxy1.bmp");

	if (Galaxy == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/galaxy1.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	libdatablank = NULL;
	libdatablank = driver->getTexture("bmaps/menu/libdatablank.bmp");
	
	if (libdatablank == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/libdatablank.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	xboatblank = NULL;
	xboatblank = driver->getTexture("bmaps/menu/xboatblank.bmp");

	if (xboatblank == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/menu/xboatblank.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	
	SecLibDataMenu = NULL;
	SecLibDataMenu = driver->getTexture("bmaps/navlib/seclibdatamenu.bmp");

	if (SecLibDataMenu == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/seclibdatamenu.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	planetskin = NULL;
	planetskin = driver->getTexture("bmaps/navlib/tempplanet2.bmp");

	if (planetskin == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/tempplanet2.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	tempplanet = NULL;
	tempplanet = driver->getTexture("bmaps/navlib/tempplanet.bmp");

	if (tempplanet == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/tempplanet.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	// Load fonts

	
	Courier10White = guienv->getFont("fonts/courier10w.xml");
	if (Courier10White == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/courier10w.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	Courier10Black = guienv->getFont("fonts/courier10b.xml");
	if (Courier10Black == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/courier10b.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier10Yellow = NULL;
	Courier10Yellow = guienv->getFont("fonts/courier10y.xml");
	if (Courier10Yellow == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/courier10y.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier10Red = NULL;
	Courier10Red = guienv->getFont("fonts/courier10r.xml");
	if (Courier10Red == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/courier10r.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	arial_24_yellow_blackout_bevel = NULL;
	arial_24_yellow_blackout_bevel = guienv->getFont("fonts/Arial_24_yellow.xml");
	if (arial_24_yellow_blackout_bevel == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/Arial_24_yellow.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}


	//the following font is loaded in the main.c module for the login screen so it is commented out here
	//Courier10Green=guienv->getFont("fonts/courier10g.png");



	Courier8White = NULL;
	Courier8White = guienv->getFont("fonts/Courier8w.xml");
	if (Courier8White == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Courier8w.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier8Black = NULL;
	Courier8Black = guienv->getFont("fonts/Courier8b.xml");
	if (Courier8Black == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Courier8b.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier8Yellow = NULL;
	Courier8Yellow = guienv->getFont("fonts/Courier8y.xml");
	if (Courier8Yellow == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Courier8y.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier8Red = NULL;
	Courier8Red = guienv->getFont("fonts/Courier8r.xml");
	if (Courier8Red == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Courier8r.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Optima18White = NULL;
	Optima18White = guienv->getFont("fonts/Optima18w.xml");
	if (Optima18White == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Optima18w.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Optima18Black = NULL;
	Optima18Black = guienv->getFont("fonts/Optima18Black.xml");
	if (Optima18Black == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/Optima18Black.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	Optima18Green = NULL;
	Optima18Green = guienv->getFont("fonts/optima18Green.xml");
	if (Optima18Green == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/optima18Green.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	Optima18Yellow = NULL;
	Optima18Yellow = guienv->getFont("fonts/optima18y.xml");
	if (Optima18Yellow == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/optima18y.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	Arial24NeonYellowShadow = NULL;
	Arial24NeonYellowShadow = guienv->getFont("fonts/Arial_24_yellow.xml");
	if (Arial24NeonYellowShadow == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Arial_24_yellow.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	arial_36_mac_green = NULL;
	arial_36_mac_green = guienv->getFont("fonts/Arial_36_green.xml");
	if (arial_36_mac_green == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/Arial_36_green.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	arial_24_red_blackout_bevel = NULL;
	arial_24_red_blackout_bevel = guienv->getFont("fonts/arial_24_red_blackout_bevel.xml");
	if (arial_24_red_blackout_bevel == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/arial_24_red_blackout_bevel.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	arial_24_yellow_blackout_bevel = guienv->getFont("fonts/arial_24_yellow_blackout_bevel.xml");
	if (arial_24_yellow_blackout_bevel == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load fonts/arial_24_yellow_blackout_bevel.xml\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	Courier10LtBlue = NULL;
	Courier10LtBlue = guienv->getFont("fonts/courier10ltb.xml");
	if (Courier10LtBlue == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/courier10ltb.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	Optima18Red = NULL;
	Optima18Red = guienv->getFont("fonts/Optima18Red.xml");
	if (Optima18Red == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load fonts/Optima18Red.xml\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	sectorfile = -2; //initalize the 198 possible sector numbers to -2

	for (x = 0; x <= 197; x++)
	{
		sectorlocationname[x].sectornumber = -2;
	}

	return TRUE;


}

//initialize navigation library bitmaps
int InitNAV()
{
	int x = 0;

	libdataimagebutton = NULL;
	libdataimagebutton = driver->getTexture("bmaps/libdata/imageavailable.bmp");
	if (libdataimagebutton == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/libdata/imageavailable.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	seclibdatablank = NULL;
	seclibdatablank = driver->getTexture("bmaps/navlib/seclib.bmp");
	if (seclibdatablank == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/seclib.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
	}

	sublibdatablank = NULL;
	sublibdatablank = driver->getTexture("bmaps/navlib/sublib.bmp");
	if (sublibdatablank == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/sublib.bmp");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	SubsecBackground = NULL;
	SubsecBackground = driver->getTexture("bmaps/navlib/subsecbg.bmp");
	if (SubsecBackground == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/subsecbg.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	fleetback = NULL;
	fleetback = driver->getTexture("bmaps/navlib/fleetbg.bmp");
	if (fleetback == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/fleetbg.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	secback = NULL;
	secback = driver->getTexture("bmaps/navlib/secback.bmp");
	if (secback == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/secback.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	seclibbmp = NULL;
	seclibbmp = driver->getTexture("bmaps/navlib/seclib.bmp");
	if (seclibbmp == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/seclib.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	subseclibbmp = NULL;
	subseclibbmp = driver->getTexture("bmaps/navlib/sublib.bmp");
	if (subseclibbmp == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/sublib.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	idbsystemgrid = NULL;
	idbsystemgrid = driver->getTexture("bmaps/navlib/sysgrid.bmp");
	if (idbsystemgrid == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/sysgrid.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbsystemgrid, SColor(0, 0, 0, 0));

	planetmap = NULL;
	planetmap = driver->getTexture("bmaps/navlib/planetmap.bmp");
	if (planetmap == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/planetmap.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(planetmap, SColor(255, 255, 255, 255));
 
	//load planet images

	planetpicwater = NULL;
	planetpicwater = driver->getTexture("bmaps/navlib/waterplanet.bmp");
	if (planetpicwater == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/waterplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpichell = NULL;
	planetpichell = driver->getTexture("bmaps/navlib/hellplanet.bmp");
	if (planetpichell == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/hellplanet.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	planetpicring = NULL;
	planetpicring = driver->getTexture("bmaps/navlib/ringworld.bmp");
	if (planetpicring == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/ringworld.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	planetpicdesert = NULL;
	planetpicdesert = driver->getTexture("bmaps/navlib/desertplanet.bmp");
	if (planetpicdesert == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/desertplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicgarden = NULL;
	planetpicgarden = driver->getTexture("bmaps/navlib/gardenplanet.bmp");
	planetpicgarden->regenerateMipMapLevels(0);
	if (planetpicgarden == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/gardenplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicfrozen = NULL;
	planetpicfrozen = driver->getTexture("bmaps/navlib/frozenplanet.bmp");
	planetpicfrozen->regenerateMipMapLevels(0);
	if (planetpicfrozen == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/frozenplanet.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	
	planetpicbarren = NULL;
	planetpicbarren = driver->getTexture("bmaps/navlib/barrenplanet.bmp");
	if (planetpicbarren == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/barrenplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicasteroid = NULL;
	planetpicasteroid = driver->getTexture("bmaps/navlib/asteroidplanet.bmp");
	if (planetpicasteroid == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/asteroidplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicgas = NULL;
	planetpicgas = driver->getTexture("bmaps/navlib/gasplanet.bmp");
	if (planetpicgas == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/gasplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicnormal = NULL;
	planetpicnormal = driver->getTexture("bmaps/navlib/normalplanet.bmp");
	if (planetpicnormal == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/normalplanet.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	planetpicblackhole = NULL;
	planetpicblackhole = driver->getTexture("bmaps/navlib/blackhole.bmp");
	if (planetpicblackhole == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/blackhole.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

    //load buttons and static images

	fltsectorinfo = NULL;
	fltsectorinfo = driver->getTexture("bmaps/navlib/fltsectorinfo.bmp");
	if (fltsectorinfo == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/fltsectorinfo.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	idblibdataavailable = NULL;
	idblibdataavailable = driver->getTexture("bmaps/navlib/libdataa.bmp");
	if (idblibdataavailable == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/libdataa.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	idbsunlogo = NULL;
	idbsunlogo = driver->getTexture("bmaps/navlib/sunlogo.bmp");
	if (idbsunlogo == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/sunlogo.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

    //load planet bitmap images for map items
	plnormal = NULL;
	plnormal = driver->getTexture("bmaps/navlib/mapnormal.bmp");
	if (plnormal == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapnormal.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plnormal, SColor(255, 255, 255, 255));

	plhellworld = NULL;
	plhellworld = driver->getTexture("bmaps/navlib/maphell.bmp");
	if (plhellworld == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/maphell.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(plhellworld, SColor(255, 255, 255, 255));

	pldesert = NULL;
	pldesert = driver->getTexture("bmaps/navlib/mapdesert.bmp");
	if (pldesert == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapdesert.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(pldesert, SColor(255, 255, 255, 255));

	plgarden = NULL;
	plgarden = driver->getTexture("bmaps/navlib/mapgarden.bmp");
	if (plgarden == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapgarden.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plgarden, SColor(255, 255, 255, 255));

	plfrozen = NULL;
	plfrozen = driver->getTexture("bmaps/navlib/mapfrozen.bmp");
	if (plfrozen == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/mapfrozen.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(plfrozen, SColor(255, 255, 255, 255));

	plbarren = NULL;
	plbarren = driver->getTexture("bmaps/navlib/mapbarren.bmp");
	if (plbarren == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapbarren.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plbarren, SColor(255, 255, 255, 255));

	plwater = NULL;
	plwater = driver->getTexture("bmaps/navlib/mapwater.bmp");
	if (plwater == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapwater.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plwater, SColor(255, 255, 255, 255));
 
	plasteroid = NULL;
	plasteroid = driver->getTexture("bmaps/navlib/mapasteroids.bmp");
	if (plasteroid == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/mapasteroids.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plasteroid, SColor(255, 255, 255, 255));

	plring = NULL;
	plring = driver->getTexture("bmaps/navlib/mapring.bmp");
	if (plring == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/mapring.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(plring, SColor(255, 255, 255, 255));
   
	plblackhole = NULL;
	plblackhole = driver->getTexture("bmaps/navlib/mapblackhole.bmp");
	if (plblackhole == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/mapblackhole.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(plblackhole, SColor(255, 255, 255, 255));

	//load symbol bitmap images for map items
	plamber = NULL;
	plamber = driver->getTexture("bmaps/navlib/amberzone.bmp");
	if (plamber == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/amberzone.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plamber, SColor(255, 255, 255, 255));

	plred = NULL;
	plred = driver->getTexture("bmaps/navlib/redzone.bmp");
	if (plred == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/redzone.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(plred, SColor(255, 255, 255, 255));

	idbgas = NULL;
	idbgas = driver->getTexture("bmaps/navlib/symbolgas.bmp");
	if (idbgas == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolgas.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbgas, SColor(255, 255, 255, 255));

	idbnavalbase = NULL;
	idbnavalbase = driver->getTexture("bmaps/navlib/symbolnaval.bmp");
	if (idbnavalbase == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolgas.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbnavalbase, SColor(255, 255, 255, 255));

	idbimpscouta = NULL;
	idbimpscouta = driver->getTexture("bmaps/navlib/symbolscouta.bmp");
	if (idbimpscouta == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolscouta.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbimpscouta, SColor(255, 255, 255, 255));

	idbimpnavy = NULL;
	idbimpnavy = driver->getTexture("bmaps/navlib/symbolimpnavy.bmp");
	if (idbimpnavy == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolimpnavy.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbimpnavy, SColor(255, 255, 255, 255));

	idbimpscoutb = NULL;
	idbimpscoutb = driver->getTexture("bmaps/navlib/symbolscoutb.bmp");
	if (idbimpscoutb == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolscoutb.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbimpscoutb, SColor(255, 255, 255, 255));

	idbcorsair = NULL;
	idbcorsair = driver->getTexture("bmaps/navlib/symbolcorsair.bmp");
	if (idbcorsair == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolcorsair.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbcorsair, SColor(255, 255, 255, 255));

	idbdepot = NULL;
	idbdepot = driver->getTexture("bmaps/navlib/symboldepot.bmp");
	if (idbdepot == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symboldepot.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbdepot, SColor(255, 255, 255, 255));

	idbmilbase = NULL;
	idbmilbase = driver->getTexture("bmaps/navlib/symbolmilbase.bmp");
	if (idbmilbase == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolmilbase.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbmilbase, SColor(255, 255, 255, 255));

	idbaslan = NULL;
	idbaslan = driver->getTexture("bmaps/navlib/symbolaslan.bmp");
	if (idbaslan == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolaslan.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbaslan, SColor(255, 255, 255, 255));

	idbtlaukhu = NULL;
	idbtlaukhu = driver->getTexture("bmaps/navlib/symboltlaukhu.bmp");
	if (idbtlaukhu == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symboltlaukhu.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbtlaukhu, SColor(255, 255, 255, 255));
 
	idbzhodani = NULL;
	idbzhodani = driver->getTexture("bmaps/navlib/symbolzhodani.bmp");
	if (idbzhodani == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolzhodani.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbzhodani, SColor(255, 255, 255, 255));
 
	idbembassy = NULL;
	idbembassy = driver->getTexture("bmaps/navlib/symbolembessy.bmp");
	if (idbembassy == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolembessy.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbembassy, SColor(255, 255, 255, 255));

	idboutpost = NULL;
	idboutpost = driver->getTexture("bmaps/navlib/symboloutpost.bmp");
	if (idboutpost == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symboloutpost.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idboutpost, SColor(255, 255, 255, 255));

	idbplanetary = NULL;
	idbplanetary = driver->getTexture("bmaps/navlib/symbolplanetary.bmp");
	if (idbplanetary == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/symbolplanetary.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbplanetary, SColor(255, 255, 255, 255));

	idbsystem1 = NULL;
	idbsystem1 = driver->getTexture("bmaps/navlib/smallsystem.bmp");
	if (idbsystem1 == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/navlib/smallsystem.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	driver->makeColorKeyTexture(idbsystem1, SColor(255, 255, 255, 255));

	idbsystem2 = NULL;
	idbsystem2 = driver->getTexture("bmaps/navlib/smallsystem2.bmp");
	if (idbsystem2 == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/smallsystem2.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(idbsystem2, SColor(255, 255, 255, 255));

	//maerker hex for current location
	hexmarker = NULL;
	hexmarker = driver->getTexture("bmaps/navlib/hexmarker.bmp");
	if (hexmarker == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/hexmarker.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(hexmarker, SColor(255, 255, 255, 255));

	//fleet icons

	//imperial
	icloseescort = NULL;
	icloseescort = driver->getTexture("bmaps/navlib/silhouette/icloseescort.bmp");
	if (icloseescort == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/icloseescort.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(icloseescort, SColor(255, 255, 255, 255));

	isystemdefenceboat = NULL;
	isystemdefenceboat = driver->getTexture("bmaps/navlib/silhouette/isystemdefenceboat.bmp");
	if (isystemdefenceboat == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/isystemdefenceboat.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(isystemdefenceboat, SColor(255, 255, 255, 255));


	ipatrolcruiser = NULL;
	ipatrolcruiser = driver->getTexture("bmaps/navlib/silhouette/ipatrolcruiser.bmp");
	if (ipatrolcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/ipatrolcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(ipatrolcruiser, SColor(255, 255, 255, 255));


	imerccruiser = NULL;
	imerccruiser = driver->getTexture("bmaps/navlib/silhouette/imerccruiser.bmp");
	if (imerccruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/imerccruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(imerccruiser, SColor(255, 255, 255, 255));

	
	icorvette = NULL;
	icorvette = driver->getTexture("bmaps/navlib/silhouette/icorvette.bmp");
	if (icorvette == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/icorvette.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(icorvette, SColor(255, 255, 255, 255));

	idestroyer = NULL;
	idestroyer = driver->getTexture("bmaps/navlib/silhouette/idestroyer.bmp");
	if (idestroyer == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/idestroyer.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(idestroyer, SColor(255, 255, 255, 255));

	idreadnought = NULL;
	idreadnought = driver->getTexture("bmaps/navlib/silhouette/idreadnought.bmp");
	if (idreadnought == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/idreadnought.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(idreadnought, SColor(255, 255, 255, 255));

	itender = NULL;
	itender = driver->getTexture("bmaps/navlib/silhouette/itender.bmp");
	if (itender == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/itender.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(itender, SColor(255, 255, 255, 255));

	icruiser = NULL;
	icruiser = driver->getTexture("bmaps/navlib/silhouette/icruiser.bmp");
	if (icruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/icruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(icruiser, SColor(255, 255, 255, 255));

	icarrier = NULL;
	icarrier = driver->getTexture("bmaps/navlib/silhouette/icarrier.bmp");
	if (icarrier == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/icarrier.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(icarrier, SColor(255, 255, 255, 255));

	ifrigate = NULL;
	ifrigate = driver->getTexture("bmaps/navlib/silhouette/ifrigate.bmp");
	if (ifrigate == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/ifrigate.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(ifrigate, SColor(255, 255, 255, 255));

	//vargr
	vargrcorsair = NULL;
	vargrcorsair = driver->getTexture("bmaps/navlib/silhouette/vargrcorsair.bmp");
	if (vargrcorsair == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vargrcorsair.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vargrcorsair, SColor(255, 255, 255, 255));

	vcloseescort = NULL;
	vcloseescort = driver->getTexture("bmaps/navlib/silhouette/vcloseescort.bmp");
	if (vcloseescort == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vcloseescort.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vcloseescort, SColor(255, 255, 255, 255));

	vsystemdefenceboat = NULL;
	vsystemdefenceboat = driver->getTexture("bmaps/navlib/silhouette/vsystemdefenceboat.bmp");
	if (vsystemdefenceboat == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vsystemdefenceboat.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vsystemdefenceboat, SColor(255, 255, 255, 255));

	vpatrolcruiser = NULL;
	vpatrolcruiser = driver->getTexture("bmaps/navlib/silhouette/vpatrolcruiser.bmp");
	if (vpatrolcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vpatrolcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vpatrolcruiser, SColor(255, 255, 255, 255));

	vmerccruiser = NULL;
	vmerccruiser = driver->getTexture("bmaps/navlib/silhouette/vmerccruiser.bmp");
	if (vmerccruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vmerccruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vmerccruiser, SColor(255, 255, 255, 255));

	vdreadnought = NULL;
	vdreadnought = driver->getTexture("bmaps/navlib/silhouette/vdreadnought.bmp");
	if (vmerccruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vdreadnought.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vdreadnought, SColor(255, 255, 255, 255));

	vdestroyer = NULL;
	vdestroyer = driver->getTexture("bmaps/navlib/silhouette/vdestroyer.bmp");
	if (vdestroyer == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vdestroyer.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vdestroyer, SColor(255, 255, 255, 255));

	vcorvette = NULL;
	vcorvette = driver->getTexture("bmaps/navlib/silhouette/vcorvette.bmp");
	if (vcorvette == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vcorvette.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vcorvette, SColor(255, 255, 255, 255));

	vtender = NULL;
	vtender = driver->getTexture("bmaps/navlib/silhouette/vtender.bmp");
	if (vtender == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vtender.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vtender, SColor(255, 255, 255, 255));

	vcruiser = NULL;
	vcruiser = driver->getTexture("bmaps/navlib/silhouette/vcruiser.bmp");
	if (vcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vcruiser, SColor(255, 255, 255, 255));

	vcarrier = NULL;
	vcarrier = driver->getTexture("bmaps/navlib/silhouette/vcarrier.bmp");
	if (vcarrier == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vcarrier.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vcarrier, SColor(255, 255, 255, 255));

	vfrigate = NULL;
	vfrigate = driver->getTexture("bmaps/navlib/silhouette/vfrigate.bmp");
	if (vfrigate == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/vfrigate.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(vfrigate, SColor(255, 255, 255, 255));

	//zhodani
	zcloseescort = NULL;
	zcloseescort = driver->getTexture("bmaps/navlib/silhouette/zcloseescort.bmp");
	if (zcloseescort == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zcloseescort.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zcloseescort, SColor(255, 255, 255, 255));

	zsystemdefenceboat = NULL;
	zsystemdefenceboat = driver->getTexture("bmaps/navlib/silhouette/zsystemdefenceboat.bmp");
	if (zsystemdefenceboat == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zsystemdefenceboat.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zsystemdefenceboat, SColor(255, 255, 255, 255));

	zpatrolcruiser = NULL;
	zpatrolcruiser = driver->getTexture("bmaps/navlib/silhouette/zpatrolcruiser.bmp");
	if (zpatrolcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zpatrolcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zpatrolcruiser, SColor(255, 255, 255, 255));

	zmerccruiser = NULL;
	zmerccruiser = driver->getTexture("bmaps/navlib/silhouette/zmerccruiser.bmp");
	if (zmerccruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zmerccruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zmerccruiser, SColor(255, 255, 255, 255));

	zdreadnought = NULL;
	zdreadnought = driver->getTexture("bmaps/navlib/silhouette/zdreadnought.bmp");
	if (zdreadnought == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zdreadnought.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zdreadnought, SColor(255, 255, 255, 255));

	zdestroyer = NULL;
	zdestroyer = driver->getTexture("bmaps/navlib/silhouette/zdestroyer.bmp");
	if (zdestroyer == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zdestroyer.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zdestroyer, SColor(255, 255, 255, 255));

	zcorvette = NULL;
	zcorvette = driver->getTexture("bmaps/navlib/silhouette/zcorvette.bmp");
	if (zcorvette == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zcorvette.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zcorvette, SColor(255, 255, 255, 255));

	ztender = NULL;
	ztender = driver->getTexture("bmaps/navlib/silhouette/ztender.bmp");
	if (ztender == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/ztender.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(ztender, SColor(255, 255, 255, 255));

	zcruiser = NULL;
	zcruiser = driver->getTexture("bmaps/navlib/silhouette/zcruiser.bmp");
	if (zcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zcruiser, SColor(255, 255, 255, 255));

	zcarrier = NULL;
	zcarrier = driver->getTexture("bmaps/navlib/silhouette/zcarrier.bmp");
	if (zcarrier == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zcarrier.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zcarrier, SColor(255, 255, 255, 255));

	zfrigate = NULL;
	zfrigate = driver->getTexture("bmaps/navlib/silhouette/zfrigate.bmp");
	if (zfrigate == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/zfrigate.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(zfrigate, SColor(255, 255, 255, 255));

	//solomani
	scloseescort = NULL;
	scloseescort = driver->getTexture("bmaps/navlib/silhouette/scloseescort.bmp");
	if (scloseescort == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/scloseescort.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(scloseescort, SColor(255, 255, 255, 255));

	ssystemdefenceboat = NULL;
	ssystemdefenceboat = driver->getTexture("bmaps/navlib/silhouette/ssystemdefenceboat.bmp");
	if (ssystemdefenceboat == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/ssystemdefenceboat.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(ssystemdefenceboat, SColor(255, 255, 255, 255));

	spatrolcruiser = NULL;
	spatrolcruiser = driver->getTexture("bmaps/navlib/silhouette/spatrolcruiser.bmp");
	if (spatrolcruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/spatrolcruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(spatrolcruiser, SColor(255, 255, 255, 255));

	smerccruiser = NULL;
	smerccruiser = driver->getTexture("bmaps/navlib/silhouette/smerccruiser.bmp");
	if (smerccruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/smerccruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(smerccruiser, SColor(255, 255, 255, 255));

	sdreadnought = NULL;
	sdreadnought = driver->getTexture("bmaps/navlib/silhouette/sdreadnought.bmp");
	if (sdreadnought == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/sdreadnought.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(sdreadnought, SColor(255, 255, 255, 255));

	sdestroyer = NULL;
	sdestroyer = driver->getTexture("bmaps/navlib/silhouette/sdestroyer.bmp");
	if (sdestroyer == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/sdestroyer.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(sdestroyer, SColor(255, 255, 255, 255));

	scorvette = NULL;
	scorvette = driver->getTexture("bmaps/navlib/silhouette/scorvette.bmp");
	if (scorvette == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/scorvette.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(scorvette, SColor(255, 255, 255, 255));

	stender = NULL;
	stender = driver->getTexture("bmaps/navlib/silhouette/stender.bmp");
	if (stender == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/stender.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(stender, SColor(255, 255, 255, 255));

	scruiser = NULL;
	scruiser = driver->getTexture("bmaps/navlib/silhouette/scruiser.bmp");
	if (scruiser == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/scruiser.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(scruiser, SColor(255, 255, 255, 255));

	scarrier = NULL;
	scarrier = driver->getTexture("bmaps/navlib/silhouette/scarrier.bmp");
	if (scarrier == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/scarrier.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(scarrier, SColor(255, 255, 255, 255));

	sfrigate = NULL;
	sfrigate = driver->getTexture("bmaps/navlib/silhouette/sfrigate.bmp");
	if (sfrigate == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/navlib/silhouette/sfrigate.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}
	driver->makeColorKeyTexture(sfrigate, SColor(255, 255, 255, 255));




	//reset the sector location numbers for the galaxy map
	for (x = 0; x <= 197; x++){
		sectorlocationname[x].sectornumber = -1;
	}

	return TRUE;
}

int InitNEWS()
{

	if (Era == 2) 
	{
		NewsMenuBackground = driver->getTexture("bmaps/news/newsmenu2.bmp"); //TNE Era
		if (NewsMenuBackground == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/newsmenu2.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	} //end if Era is TNE
	else
	{
		NewsMenuBackground = driver->getTexture("bmaps/news/newsmenu.bmp");
		if (NewsMenuBackground == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/newsmenu.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	} //end else regular tns


	if (Era == 2)
	{
		archivemenubmp = driver->getTexture("bmaps/news/archivemenu2.bmp"); //TNE Era
		if (archivemenubmp == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/archivemenu2.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	}
	else
	{
		archivemenubmp = driver->getTexture("bmaps/news/archivemenu.bmp");
		if (archivemenubmp == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/archivemenu.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	}


	if (Era == 2)
	{
		rumormenubmp = driver->getTexture("bmaps/news/rumorsmenu2.bmp"); //TNE Era
		if (rumormenubmp == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/rumorsmenu2.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	}
	else
	{
		rumormenubmp = driver->getTexture("bmaps/news/rumorsmenu.bmp");
		if (rumormenubmp == NULL)
		{
			ERR = fopen("error.txt", "a");
			fprintf(ERR, "Could not load bmaps/news/rumorsmenu.bmp\n");
			fclose(ERR);
			CleanUp();
			device->drop();
			return 1;
		}
	}


	return TRUE;
}

int InitLIBDATA()
{

	libdatabmp = driver->getTexture("bmaps/libdata/libdatamenu.bmp");
	if (libdatabmp == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/libdata/libdatamenu.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	return TRUE;
}

int InitACCOUNTS()
{

	accountsvcs = driver->getTexture("bmaps/accounts/accountsvcs.bmp");

	if (accountsvcs == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/accounts/accountsvcs.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	acctinfo = driver->getTexture("bmaps/accounts/acctinfo.bmp");

	if (acctinfo == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/accounts/acctinfo.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}
	
	banking = driver->getTexture("bmaps/accounts/banking.bmp");

	if (banking == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/accounts/banking.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	loancredit = driver->getTexture("bmaps/accounts/loancredit.bmp");

	if (loancredit == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/accounts/loancredit.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	return TRUE;
}

int InitCLASSIFIEDS()
{

	classifiedmenu = driver->getTexture("bmaps/classifieds/classifiedmenu.bmp");
	if (classifiedmenu == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/classifiedmenu.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}


	foresalemenu = driver->getTexture("bmaps/classifieds/foresalemenu.bmp");
	if (foresalemenu == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/foresalemenu.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	missionsmenu = driver->getTexture("bmaps/classifieds/missionsmenu.bmp");
	if (missionsmenu == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/missionsmenu.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	FSitems = driver->getTexture("bmaps/classifieds/FSitems.bmp");
	if (FSitems == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/FSitems.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	FSspacecraft = driver->getTexture("bmaps/classifieds/FSspacecraft.bmp");
	if (FSspacecraft == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/FSspacecraft.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	FSvehicles = driver->getTexture("bmaps/classifieds/FSvehicles.bmp");
	if (FSvehicles == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/FSvehicles.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	helpwantedmenu = driver->getTexture("bmaps/classifieds/helpwantedmenu.bmp");
	if (helpwantedmenu == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/classifieds/helpwantedmenu.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}



	return TRUE;
}

int InitXBOAT()
{

	//communications main menu
	xboatmainmenu = driver->getTexture("bmaps/communications/communicationsmenu.bmp");
	if (xboatmainmenu == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/communications/communicationsmenu.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	//communications menu to create/send message
	xboatsendmessagemenu = driver->getTexture("bmaps/communications/xboatsendmessage.bmp");
	if (xboatsendmessagemenu == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/communications/xboatsendmessage.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	//communications menu to read message
	xboatreadmessagemenu = driver->getTexture("bmaps/communications/xboatreadmessage.bmp");
	if (xboatreadmessagemenu == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/communications/xboatreadmessage.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	//communications menu NEXT button
	xboatnextbutton = driver->getTexture("bmaps/communications/nextbutton.bmp");
	if (xboatnextbutton == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/communications/nextbutton.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	//communications menu NEXT button hoverover
	xboatnextbuttonover = driver->getTexture("bmaps/communications/nextbuttonover.bmp");
	if (xboatnextbuttonover == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/communications/nextbuttonover.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}

	//communications menu BACK button
	xboatbackbutton = driver->getTexture("bmaps/communications/backbutton.bmp");
	if (xboatbackbutton == NULL)
	{
	ERR = fopen("error.txt", "a");
	fprintf(ERR, "Could not load bmaps/communications/backbutton.bmp\n");
	fclose(ERR);
	CleanUp();
	device->drop();
	return 1;
	}

	//communications menu BACK button hoverover
	xboatbackbuttonover = driver->getTexture("bmaps/communications/backbuttonover.bmp");
	if (xboatbackbuttonover == NULL)
	{
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Could not load bmaps/communications/backbuttonover.bmp\n");
		fclose(ERR);
		CleanUp();
		device->drop();
		return 1;
	}


	return TRUE;
}

void InitAllianceCodes(void)
{
	char erafilename2[120];
	char line[128];
	FILE *FDR;

	sprintf(erafilename2, "%s/allegiance_codes.txt", SectorDirectory);

	FDR = NULL;
	TotalAllegianceCount = 0;  //set initial allegience file count
	if (!(FDR = fopen(erafilename2, "r")))
	{
		fprintf(stderr, "Unable to read %s\n",&erafilename2);
		ERR = fopen("error.txt", "a");
		fprintf(ERR, "Unable to read %s\n",&erafilename2);
		fclose(ERR);
	}
	else //we have a file to read
	{
		while (!feof(FDR))
		{
			fgets(line, 128, FDR);
			if (strlen(line) > 1)
			{
				//--- get allegiance two character code
				strncpy(allegiance[TotalAllegianceCount].allegianceshort, "  ", 2);
				strncpy(allegiance[TotalAllegianceCount].allegianceshort, &line[0], 2); //set short code
				allegiance[TotalAllegianceCount].allegianceshort[2] = '\0';
				strncpy(allegiance[TotalAllegianceCount].allegiancefull, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 30); //set long name
				strncpy(allegiance[TotalAllegianceCount].allegiancefull, &line[3], (strlen(&line[3]))); //set long name			
				allegiance[TotalAllegianceCount].count = 0;  //initialize count to zero
				//increment to next code
				TotalAllegianceCount++;
			}//end if the line has data
		}//end while not end of file
	}//end else read allegiance file
	fclose(FDR);
}

void InitAllianceCounts(void)
{
	int tempcount = 0;


	for (tempcount = 0; tempcount <= 499; tempcount++)
	{
		//--- set allegiance two character code
		allegiance[tempcount].allegianceshort[0] = '\0'; //set short code
		allegiance[tempcount].allegiancefull[0] = '\0'; //set long name
		allegiance[tempcount].count = 0;  //initialize count to zero
	}


}
