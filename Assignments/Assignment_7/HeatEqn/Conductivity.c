#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include <cblas.h>


int Conductivity(int problemNumber, int x, int y){



int kappa;

if (problemNumber == 1){

	kappa = 1;
}

if (problemNumber == 2){

	kappa = 1;

	}

if (problemNumber == 3){
	
	kappa == 1; // All of these units are Watts per Meter Kelvin

	}


if (problemNumber == 4){

	if (x>0.5){

		kappa = 20;

		}

	else{
		kappa = 1;
		}
	}

if (problemNumber == 5){


	if ((x>0.01) && (x<0.015) && (y>0.01) && (y<0.015)){

	kappa = 167;
	}
	else{

	kappa = 157;

		}

	}




return kappa;


}
