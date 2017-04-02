#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <stdlib.h>
#include <math.h>
#include "exits.h"
#include "iterHeader.h"



int main(){

struct input *sat;
sat = malloc(sizeof(struct input));
struct input *moon;
moon = malloc(sizeof(struct input));

printf("everything seems to be working \n");
struct initial *satAcc;
satAcc = malloc(sizeof(struct initial));
struct initial *moonAcc;
moonAcc = malloc(sizeof(struct initial));


struct inEuler *in;
in = malloc(sizeof(struct inEuler));
struct outEuler *out;
out = malloc(sizeof(struct outEuler));

// Now define all initial conditions. This might be cleaner in a separate file.


sat->x = 0;
sat->y = 0;
sat->vx = 0;
sat->vy = 0;
sat->ax = 0;
sat->ay = 0;

moon = sat;



return 0;

}
