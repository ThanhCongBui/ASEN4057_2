#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>
#include "Build_LHS.h"
#include "Conductivity.h"

double **Build_LHS( int nodes_per_side, double *x, double *y, int **index, int problem_index){

  // Create values to index each finite difference step
  int top, right, bottom, left, center;

  // Create values for 
  int kT, kR, kB, kL;


  // Create K matrix that will be later multiplied by d temperature values or something like that

  int n = nodes_per_side; // nodes_per_side was too many letters to type
  int c = nodes_per_side - 1; //cells_per_side also too long, just make a variable c
  double **K = (double**) calloc(n*n, sizeof(double));

  K[0] = (double*) calloc(n*n*n*n, sizeof(double));

  for (int ii = 1; ii < (n*n); ii++){

    K[ii] = K[ii-1] + n*n;

  }

  double h = 1/c; // Create the spacing value = 1/cells per side, where cells_per = nodes-1
  int pi = problem_index;

  // Start iterating to populate the K matrix


  for (int ii = 1; ii < c; ii++){
    for (int jj = 1; jj < c; jj++){

      //First, properly populate the center/left/etc positions

      center = index[ii][jj];
      
      top = index[ii][jj + 1];

      right = index[ii + 1][jj];

      bottom = index[ii][jj - 1];

      left = index[ii - 1][jj];


      // Calulate conductivity at each stage before populating the K matrix

      kT = Conductivity(pi, x[ii], y[jj] + 0.5*h);
      kR = Conductivity(pi, x[ii] + 0.5*h, y[jj]);
      kB = Conductivity(pi, x[ii], y[jj] - 0.5*h);
      kL = Conductivity(pi, x[ii] - 0.5*h, y[jj]);

      // And now calculate and populate the K matrix.

      *(K[center] + center) = (kT + kR + kB + kL)/(h*h);
      *(K[center] + top) = (-kT)/(h*h);
      *(K[center] + right) = (-kR)/(h*h);
      *(K[center] + bottom) = (-kB)/(h*h);
      *(K[center] + left) = (-kL)/(h*h);

    }
  }

  // Iterate to populate the extreme sides of the matrix


  
  for (int ii = 0; ii < n; ii++){
    bottom = index[ii][0];
    top = index[ii][c];
    right = index[c][ii];
    left = index[0][ii];

    *(K[bottom] + bottom) = 1;
    *(K[top] + top) = 1;
    *(K[right] + right) = 1;
    *(K[left] + left) = 1;
  }

  // Iterate to populate the left and right sides
    
      
  return K;

}
