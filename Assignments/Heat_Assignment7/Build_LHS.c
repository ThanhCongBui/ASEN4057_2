
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>


int Build_LHS(double cells_per_side){

// Build K matrix here. Need to know resolution of overall grid as well as x and y dimensions
// Need to know Conductivity at each point, source (?) at each point, and BC at each point

double h_MeshSize  = 1/cells_per_side;
double* x_array;
double* y_array;
double nodes_per_side = cells_per_side + 1;
 int nodes = cells_per_side+1;
//make sure that x and y arrays have the correct dimensions
 x_array=malloc(nodes_per_side*sizeof(double));
 y_array = malloc(nodes_per_side*sizeof(double));
 
 //populate the x_array and y_array with proper "mesh" sizing. 
for (int ii = 0; ii < nodes_per_side; ii++){

  x_array[ii] = ii*h_MeshSize;
  y_array[ii] = ii*h_MeshSize;
  
 }
// Hope that the arrays are correctly sized and populated.

// Create indexing scheme that makes it possible to run through the
// five point scheme in the overall K matrix calculation
 
 double *index[nodes][nodes];
 for (int ii = 0; ii < nodes_per_side; ii++){

   for (int jj = 0; jj < nodes_per_side; jj++){

     *index[ii][jj] = (ii-1)*nodes_per_side + jj;
     
   }
 }


 // Now the overall initialization can occur. I'll get to the K matrix
 // later after putting in some work on building the 'f' heating vector RHS

return 0;



}
