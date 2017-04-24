#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>
#include "BC.h"

double BC( double xVal, int problem_index){

  double temp;

	if(problem_index == 1){


	  temp = xVal;

	}
	// Note that this folowing section is completely unrealistic. These lines of code
	// Basically suggest that there are conditions in which the boundary temperature
	// values can be zero Kelvin.

	// This is physically incorrect, but for the purposes of this homework exercise,
	// the problem will use what was given.
	
	if((problem_index == 2) || (problem_index == 3) || (problem_index == 4)){

	  temp = 0;

	}
	
	if (problem_index == 5){


	  temp = 343.15; // Kelvin. Note that the Celsius value in the document is 70 C. 

	}

return temp;

}
