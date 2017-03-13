#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <math.h>
double ThreeBody(double argc, char *argv[] ){

struct initial *sat;
struct initial *moon;
struct output *satOut;
struct output *moonOut;

double distEarthSat = 340000000; //meters
double v0Sat = 1000; // meters/second
double theta0Sat = 50; // degrees
double distEarthMoon = 384403000; // meters
double mMoon = 7.34767309E22; // kg
double mEarth = 5.97219E24; // kg



/*

Recall initial is of format:

	double x;
	double y;
	double vx;
	double vy;

and output is of format:

	double ax;
	double ay;

*/


double timestep = 0.01;






return 0;

}
