#include <stdio.h>
#include "accHeader.h"


void acc_calc(struct initial *sat, struct initial *moon, struct output *satOut, struct output *moonOut ) {

printf("Unpacking structures");
//Define initial values

double mMoon=7.34767309E22;
double mEarth=5.97219E24;
double mSat=28833;
double rMoon=1737100;
double rEarth=6371000;


// output is going to be x y vx vy 
// unpack variables

double satX = sat->x;
double satY = sat->y;
double satVx = sat->vx;
double satVy = sat->vy;


double moonX = moon->x;
double moonY = moon->y;
double moonVx = moon->vx;
double moonVy = moon->vy;

double G=6.67259E-11;

//Compute the force on the satellite from the moon

double moononsatX=G*mSat*mMoon*(moonX-satX)/((moonX-satX)*(moonX-satX)*(moonX-satX));
double moononsatY=G*mSat*mMoon*(moonY-satY)/((moonY-satY)*(moonY-satY)*(moonY-satY));

//Compute the force on the satellite from the Earth

double earthonsatX=G*mSat*mEarth*(satX)/(satX*satX*satX);
double earthonsatY=G*mSat*mEarth*(satY)/(satY*satY*satY);

// Compute the force on the Moon from the Earth

double earthonmoonX=G*mMoon*mEarth*(moonX)/(moonX*moonX*moonX);
double earthonmoonY=G*mMoon*mEarth*(moonY)/(moonY*moonY*moonY);
// Initialize acceleration doubles
double satAx;
double satAy;

double moonAx;
double moonAy;

satAx=(earthonsatX+moononsatX)/mSat;

satAy=(earthonsatY+moononsatY)/mSat;

moonAx=(earthonmoonX-moononsatX)/mMoon;

moonAy=(earthonmoonY-moononsatY)/mMoon;

// Set acceleration values equal to correct component in struct
moonOut->ax=moonAx;
moonOut->ay=moonAy;

satOut->ax=satAx;
satOut->ay=satAy;

printf("Exited file \n");

return;

}



/*void main (){

return;
}*/
