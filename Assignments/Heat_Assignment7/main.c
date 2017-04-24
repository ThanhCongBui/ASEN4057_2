#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>
#include <math.h>
#include <string.h>
#include "BC.h"
#include "Build_LHS.h"
#include "Build_RHS.h"
#include "Conductivity.h"
#include "Output.h"
#include "Source.h"

void main(int argc, const char * argv[]){


int cells_per_side = atoi(argv[1]);

int problem_index = atoi(argv[2]);

 double h = 1/cells_per_side;
// Tackle case in which the length changes for some silly reason.
 if (problem_index == 5){
   double h = 0.025/cells_per_side;
   printf("Problem Five was selected. Changing length to 2.5 cm");
 }

 

int nodes_per_side = cells_per_side+1;

double *x_array;
double *y_array;
// Give enough memory to x_array and y_array to span the whole size of the problem
 printf("testing early stuff \n");
x_array = malloc(nodes_per_side*sizeof(double));
y_array = malloc(nodes_per_side*sizeof(double));
x_array[0] = 0;
y_array[0] = 0;

 printf("Testing Populate Posn vectors \n");
 for (int ii = 0; ii < nodes_per_side; ii++){

   //Populate the position vectors x_array and y_array
   x_array[ii+1] = x_array[ii] + h;
   y_array[ii+1] = x_array[ii] + h;

 }


 // Create the index matrix
 printf("Testing Index Matrix\n");
 int **index = (int**) calloc(nodes_per_side, sizeof(int*));
 index[0] = (int*) calloc(nodes_per_side, sizeof(int));
 
 printf("testing prelim index filling \n");
 for (int ii = 1; ii < nodes_per_side; ii++){

   index[ii] = index[ii - 1] + nodes_per_side;
 }
 printf("testing filling index\n");
 // Iterate like in the matlab code to populate the index matrix
 for (int ii = 0; ii < nodes_per_side; ii++){

   for (int jj = 0; jj < nodes_per_side; jj++){

     *(index[ii] + jj) = ii*nodes_per_side + jj;
   }
 }

 // Create the right hand side 
 double *RHS_F = Build_RHS(nodes_per_side, x_array, y_array, index, problem_index);


 // Create the left hand side 
 
 double **LHS_K = Build_LHS(nodes_per_side, x_array, y_array, index, problem_index);
 // Create the answer vector
int n = nodes_per_side;
 double *TEMP_ANSWER = malloc(n*n*sizeof(double));
 // Perform the matrix multiplication
 
 cblas_dgemm(CblasRowMajor,CblasTrans, CblasNoTrans, n*n, 1, n*n, 1.0, *LHS_K, n*n, RHS_F, n*n, 0.0, TEMP_ANSWER, n*n);


 // Write everything to a file
 char name[30];
   FILE *writeme; 
   snprintf(name, sizeof(name),"heat_solution_%d_cells_problem_%d.txt",cells_per_side, problem_index);
 writeme = fopen(name,"wb");




 Output(writeme, nodes_per_side, x_array, y_array, TEMP_ANSWER, index);

   



 
return;

}
