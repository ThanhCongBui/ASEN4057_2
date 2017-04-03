// Function for optimization of objective 1
// Find minimum delta V required to return to Earth
// similar to objective 2, however simply need to check that iterate terminated
// due to successful landing on earth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include "exits.h"
#include "iterHeader.h"

// will need to figure out input call
double optimizer1( ) {

// Declaring arrays for initial sweep to find broad minimum
double vMag = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
double angle = { 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330};

// Declaring variables to store minimum values and corresponding velocity
// and angle
double vMagMin, angleMin;

// Declaring looping counters
int i, j;

// Declaring delta Vx and Vy for later calculation
double vX, vY;
//Initial arbitrarily large delta V 
double vMagMin = 110;
// delaring radian converter
double radConv = PI / 180;

// Looping through magnitudes and angles of each magnitude
for (i=0; i<9; i++){
	for (j=0; j<10; j++){
		// Calculate delta Vx & Vy using current vMag and angle value
		vX = vMag[i]*cos(radConv*angle[j]);
		vY = vMag[i]*sin(radConv*angle[j]);
		// Part that I'm unsure about, need to run iterateSolution with
		// vX and vY

		// If input is successful and craft returns to earth:
		// Store vMag and angle values
		// if (iterate solution returned 0 && vMag[i]<vMagMin){
			// vMagMin = vMag[i];
			// angleMin = angle[j];
		//}
		
	}
}

// Now that broad approximation of min velocity is found, similar process done 
// to find more accurate minimum values of deltaV that still return to Earth

// create new array of values around found delta V
// need to figure out how to pull in provided absolute accuracy
// create array of V values to test in steps of absolute accuracy +- 5 m/s
// need to grab absolute accuracy 
double absAcc;
double steps = 10/absAcc;
double vMagFine = {};
int k;
for ( k = 0; k<steps; k++){
	vMagFine[k]=((vMagMin-5)+(k*absAcc));
}

// now that the vMagFine array has been created, same process as above to find
// minimum valid value for delta V

double vXFine, vYFine;
double vMinFine = 110;
int l;
for ( l=0; l<steps; l++ ){

	vXFine = vMagFine[l]*cos(radConv*angleMin);
	vYFine = vMagFine[l]*sin(radConv*angleMin);
	// run iterate solution using each value of vMagFine and find 
        // minimum vMagFine that returns to Earth
	// if (iterateSolution return 0 && vMagFine[l]<vMinFine){
		// vMinFine = vMagfine[l];
	//} 
}
// Once minimum delta V magnitude is found, return vMinFine
}
