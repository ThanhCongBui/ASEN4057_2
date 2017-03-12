#include <stdio.h>

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

double fSatMoon=G*mSat*mMoon*(satX-moonX)/((satX-moonX)*(satX-moonX)*(satX-moonX));



return;

}
