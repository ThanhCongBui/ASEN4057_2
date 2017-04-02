#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <math.h>
#include <stdlib.h>
#include "exits.h"
#include "iterHeader.h"


double main(double argc, char *argv[] ){



struct input *sat;
sat = malloc(sizeof(struct input));
struct input *moon;
moon = malloc(sizeof(struct input));


struct initial *satAcc;
satAcc = malloc(sizeof(struct initial));
struct initial *moonAcc;
moonAcc = malloc(sizeof(struct initial));


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
double clearance = 10000;
//runIterate = iterateSolution(sat,moon,clearance);





return 0;

}
