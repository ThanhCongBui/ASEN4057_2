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
printf("nodes value is %d \n",nodes_per_side);
double * x_array;
double * y_array;
x_array = malloc(nodes_per_side*sizeof(double));
y_array = malloc(nodes_per_side*sizeof(double));
int *index;
index = malloc(nodes_per_side*nodes_per_side*sizeof(int));

for (int ii = 0; ii < nodes_per_side; ii++){

	for (int jj = 0; jj < nodes_per_side; jj++){

		index[ii+jj] =(ii)*nodes_per_side + jj;
		
		}
	}

printf("Value is %d\n", index[2]);







double *K[nodes_per_side*nodes_per_side][nodes_per_side*nodes_per_side];

 Build_LHS(K, index, problem_index, cells_per_side, x_array, y_array);



return ;

}
