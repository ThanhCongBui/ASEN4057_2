#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <cblas.h>
#include <math.h>
#include <string.h>


void main(int argc, char * argv[]){

int cells_per_side;
int problem_index;
cells_per_side = atoi(argv[1]);
problem_index = atoi(argv[2]);


double h = 1/cells_per_side;
int nodes_per_side = cells_per_side+1;

double * x_array;
double * y_array;
x_array = malloc(nodes_per_side*sizeof(double));



return;

}
