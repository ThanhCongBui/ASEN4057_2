#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>
#include <math.h>
#include <string.h>


void main(int argc, const char * argv[]){

int cells_per_side;
int problem_index;

cells_per_side = atoi(argv[1]);

problem_index = atoi(argv[2]);


double h = 1/cells_per_side;
int nodes_per_side = cells_per_side+1;

double *x_array;
double *y_array;
x_array = malloc(nodes_per_side*sizeof(double));
y_array = malloc(nodes_per_side*sizeof(double));




 int index[nodes_per_side][nodes_per_side] = 0;
 // Set initial index matrix to all zeroes
 for (int ii = 0; ii < nodes_per_side; ii++){

   index[ii][ii] = 0;

 }
// index = malloc(nodes_per_side*nodes_per_side*sizeof(int));
 printf("Nodes is %d",nodes_per_side);
 for (int ii = 1; ii < nodes_per_side+1; ii++){
	for (int jj = 1; jj < nodes_per_side +1; jj++){
    index[ii][jj] = (ii-1)*nodes_per_side + jj; 
   }
 }


 for (int ii = 0; ii < nodes_per_side; ii++){
   for (int jj = 0; jj < nodes_per_side; jj++){


	printf("Current index value is %d \n",index[ii][jj]);
}	
 }

return ;

}
