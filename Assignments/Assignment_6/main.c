#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <stdlib.h>
#include <math.h>
#include "exits.h"
int main(){



struct inEuler *myIn;

myIn = malloc(sizeof(struct inEuler));

myIn->x = 1;
myIn->dx = 3;
myIn->time = 1;


struct outEuler *myOut;
myOut = malloc(sizeof(struct outEuler));

myOut->x = 0;
myOut->time=0;

double timestep=0.5;



for (int i = 1; i<100000; i++){
euler(timestep, myIn, myOut);

myIn->x = myOut->x;
myIn->dx = myOut->dx;
myIn->time = myOut->time;

i++;
}

printf("MyIn consists of values %f %f %f \n",myIn->x, myIn->dx,myIn->time);

printf("MyOut consists of values %f %f \n", myOut->x, myOut->time);





return 0;

}
