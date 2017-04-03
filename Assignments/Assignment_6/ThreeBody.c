﻿#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <math.h>
#include <stdlib.h>
#include "exits.h"
#include "iterHeader.h"


double main(int argc, const char *argv[] ){


//Manage the input values from *argv[]


int problemDesired;
int clearance;
int tolerance;


// For some strange reason, this piece is necessary to avoid seg faulting
if (argv[1] && argv[2] && argv[3]){

	problemDesired = atoi(argv[1]);
	clearance = atoi(argv[2]);
	tolerance = atoi(argv[3]);
}




struct initial *satIn;
satIn = malloc(sizeof(struct initial));
struct initial *moonIn;
moonIn = malloc(sizeof(struct initial));


struct output *satOut;
satOut = malloc(sizeof(struct output));
struct output *moonOut;
moonOut = malloc(sizeof(struct output));



struct inEuler *in;
in = malloc(sizeof(struct inEuler));
struct outEuler *out;
out = malloc(sizeof(struct outEuler));
// Now define all initial conditions. This might be cleaner in a separate file.


double deltaVx = 0;
double deltaVy = 0;

sat->x = 340000000*cos(50*3.14159265/180);
sat->y = 340000000*sin(50*3.14159265/180);
sat->vx = 1000*cos(50*3.14159265/180) + deltaVx;
sat->vy = 1000*sin(50*3.14159265/180) + deltaVy;
sat->ax = 0;
sat->ay = 0;

moon->x = 384403000*cos(42.5*3.14159265/180);
moon->y = 384403000*sin(42.5*3.14159265/180);
moon->vx = -1012.0715844*sin(42.5*3.14159265/180); // this value is pulled from matlab code instead of dynamically calculating it
moon->vy = 1012.0715844*cos(42.5*3.14159265/180);


double runIterate = 0;






return 0;

}
