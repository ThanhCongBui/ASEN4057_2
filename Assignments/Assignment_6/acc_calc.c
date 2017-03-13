#include <stdio.h>
#include "accHeader.h"
void accCalc(struct initSat, struct initMoon, struct outSat, struct outMoon) {

printf("Unpacking structures");
//Define initial values

double mMoon=7.34767309E22;
double mEarth=5.97219E24;
double mSat=28833;
double rMoon=1737100;
double rEarth=6371000;


// output is going to be x y vx vy 
// unpack variables

double satX = initSat->x;
double satY = initSat->y;
double satVx = initSat->vx;
double satVy = initSat->vy;


double moonX = initMoon->x;
double moonY = initMoon->y;
double moonVx = initMoon->vx;
double moonVy = initMoon->vy;

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
double satAx = outSat->x;
double satAy = outSat->y;

double moonAx = outMoon->x;
double moonAy = outMoon->y;

satAx=(earthonsatX+moononsatX)/mSat;

satAy=(earthonsatY+moononsatY)/mSat;

moonAx=(earthonmoonX-moononsatX)/mMoon;

moonAy=(earthonmoonY-moononsatY)/mMoon;

return;

}

