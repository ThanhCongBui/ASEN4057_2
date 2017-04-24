#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include "Build_RHS.h"
#include "BC.h"
#include "Source.h"

double *Build_RHS(int nodes_per_side, double *x, double *y, int **index, int problem_index){

  int center;
  double *f = malloc(nodes_per_side*sizeof(double*));
		
 for (int ii = 0; ii < nodes_per_side, ii++;){
   for (int jj = 0; jj < nodes_per_side, jj++;){

     if ( ii == 0 || jj == 0){
     f[center] = BC (x[ii], problem_index);
     }

     if (ii == (nodes_per_side - 1) || jj == (nodes_per_side -1) ){
       f[center] = BC(x[ii], problem_index);
     }

     else{

       f[center] = Source(nodes_per_side, x[ii], y[jj], problem_index);
        }
 }
 }


  return f;

}
