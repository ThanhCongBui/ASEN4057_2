#include <stdio.h>
#include "eulerHeader.h"


void euler( double timestep, struct input *objIn, struct output *objOut){

objOut->time = objIn->time + timestep;

objOut->x = objIn->x + timestep*(objIn->dx);

objOut->y = objIn->y + timestep*(objIn->dy);


return;

}

