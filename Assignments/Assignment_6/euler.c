#include <stdio.h>
#include "eulerHeader.h"


void euler( double timestep, struct inEuler *objIn, struct outEuler *objOut){

objOut->time = objIn->time + timestep;

objOut->x = objIn->x + timestep*(objIn->dx);

objOut->dx = objIn->dx;
return;

}

