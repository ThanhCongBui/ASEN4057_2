#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include <cblas.h>
#include "Conductivity.h"
int Conductivity(int problem_index, double x, double  y){



int kappa;

if (problem_index == 1){

	kappa = 1;
}

if (problem_index == 2){

	kappa = 1;

	}

if (problem_index == 3){
	
	kappa == 1; // All of these units are Watts per Meter Kelvin

	}


if (problem_index == 4){

	if (x>0.5){

		kappa = 20;

		}

	else{
		kappa = 1;
		}
	}

if (problem_index == 5){


	if ((x>0.01) && (x<0.015) && (y>0.01) && (y<0.015)){

	kappa = 167;
	}
	else{

	kappa = 157;

		}

	}


return kappa;


}
