#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>

int Build_RHS(double * F, int * index, int problem_index, int cells_per_side, double * x_array, double * y_array){

  double h_MeshSize =/cells_per_side;
  int nodes_per_side = cells_per_side+1;

  
    for (int ii = 0; ii < nodes_per_side * nodes_per_side; ii++){

		// F[ii] = BC call 

		}


  return 0;

}
