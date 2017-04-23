#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Source.h"

double Source( int nodes_per_side, double x, double y, int problem_index){
  //Important to note that all of these calculations are for the interior of the problem
  //The boundary condition calculations are contained in the file BC.c

  //Create the variable heat
	double heat;

	if (problem_index == 1){

		heat = 0;

		}

	if (problem_index == 2){

	  heat = 2*(y*(1-y) + x*(1-x));

	}

	if (problem_index == 3){

	  heat = exp(-50*sqrt(pow((x-0.5),2) + pow((y-0.5),2)));
	}

	if (problem_index == 4){

	  if (x < 0.1) {
	    heat = 1;
	  }
	  else{

	    heat = 0;
	  }

	}
	  
	if(problem_index == 5){

	  if( x < 0.015 && x > 0.01 && y < 0.015 && y > 0.01){

	    heat = 1600000;
	  }
	  else{

	    heat = 0;
	  }

	}
return heat;


}

