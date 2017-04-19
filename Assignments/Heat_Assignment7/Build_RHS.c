#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>

int Build_RHS(double cells_per_side){

  double h_MeshSize = 1/cells_per_side;
  int nodes_per_side = cells_per_side+1;

  // Populate x and y arrays

  

  double *f_RHS;
  f_RHS = malloc(nodes_per_side*sizeof(double));
  


  return 0;

}
