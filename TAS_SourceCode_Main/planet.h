






void readcolors(char* colorsname);
void makeoutline(int do_bw);
void smoothshades();
void mercator();  //use this to make map to strech on 3d globe
void icosahedral();
int planet0(double x, double y, double z, int i, int j);
double planet(double a, double b, double c, double d, double as, double bs, double cs, double ds,
	double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz, double dx, double dy, double dz,
	double x, double y, double z, int level);
double planet1(double x, double y, double z);
double rand2(double p, double q);
void printbmp(FILE *outfile);
void printbmpBW(FILE *outfile);
double log_2(double x);
void planet_surface(int hexnum);

