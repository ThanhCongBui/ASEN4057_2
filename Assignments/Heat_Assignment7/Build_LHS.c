
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>
#include <buildLHS.h>

void Build_LHS(double * K, int * index, int problem_index, int cells_per_side, double * x_array, double * y_array){

// Build K matrix here. Need to know resolution of overall grid as well as x and y dimensions
// Need to know Conductivity at each point, source (?) at each point, and BC at each point

printf("K value is %lf \n",*K[1]);


 // Now the overall initialization can occur. I'll get to the K matrix
 // later after putting in some work on building the 'f' heating vector RHS

return;



}
