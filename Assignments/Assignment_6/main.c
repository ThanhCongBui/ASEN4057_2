#include <stdio.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include <stdlib.h>

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

double timestep=10;


euler(timestep, myIn, myOut);



printf("MyIn consists of values %f %f %f \n",myIn->x, myIn->dx,myIn->time);

printf("MyOut consists of values %f %f \n", myOut->x, myOut->time);





return 0;

}
