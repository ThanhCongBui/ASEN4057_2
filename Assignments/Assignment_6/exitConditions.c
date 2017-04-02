#include <stdio.h>
#include <stdlib.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include "exits.h"
#include <math.h>


int exitConditions(struct position *sat, struct position *moon, double clearance){

double satX = sat->x;
double satY = sat->y;

double moonX = moon->x;
double moonY = moon->y;


double rMoon = 1737100;
double rEarth = 6371000;


double distSM = sqrt( (satX-moonX)^2 + (satY-moonY)^2 );
double distEM = sqrt( moonX^2 + moonY^2);

double distSE = sqrt( satX^2 + satY^2 );
double lostSpace = 2*distEM;

printf("For debugging purposes: \n");
printf("1 is moon crash \n");
printf("2 is success \n");
printf("3 is lost to space \n");
printf("0 is nothing happened \n");
//Crash into moon condition

if (distSM <= rMoon + clearance){

printf("The satellite has crashed into the Moon. Please select another initial condition. \n");

return 1; //Termination condition 1 as outlined in the PDF is true
}




//Successful return to Earth condition

if (distSE <= rEarth){
printf("The satellite has successfully returned to Earth \n");

return 2; // This is the condition in which the trip is a success. Look for this output!


}

//Satellite lost to space condition.
if (distSE >= lostSpace){


printf("The satellite has been lost to space. Please select another initial condition. \n");
return 3;


}

return 0; // set the default condition to 0, or 'no crash detected'

}
