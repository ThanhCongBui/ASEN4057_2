#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>
#include "Build_RHS.h"
#include "BC.h"

double *Build_RHS(int nodes_per_side, double *x, double *y, int *index, int problem_index){

  int center;
  double *f = malloc(nodes_per_side*sizeof(double*));
		
 for (int ii = 0; ii < nodes_per_side, ii++;){
   for (int jj = 0; jj < nodes_per_side, jj++;){

     f[center] = Source(nodes_per_side, x[ii], y[jj], problem_index);


 }

  return f;

}
