#include <stdio.h>
#include <stdlib.h>
#include "Output.h"

void Output(FILE *fid, int nodes_per_side, double *x, double *y, double *temp, int **index){



for (int ii = 0; ii < nodes_per_side; ii++){
  for (int jj = 0; jj < nodes_per_side; jj++){

    fprintf(fid, "%lf  %lf  %lf\n", x[ii], y[jj], temp[index[ii][jj]]);
  }
 }
 


 fclose(fid);



return;
}
