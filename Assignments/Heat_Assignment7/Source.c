#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cblas.h>
#include <lapacke.h>
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

	  f = 2*(y








return f;


}
