#ifndef _INTEGRATOR_H
#define _INTEGRATOR_H
#include <stdio.h>
//If this doesn't compile well, add <stdlib.h> or <stdio.h> to this file. Something 
// with FILE type might be conflicting

struct dydt_type{
    double xs_dot;
    double ys_dot;
    double xm_dot;
    double ym_dot;
    double vxs_dot;
    double vys_dot;
    double vxm_dot;
    double vym_dot;
  };

struct y_type{
  double xs; //= y0[0];
  double ys; //= y0[1];
  double xm; //= y0[2];
  double ym; //= y0[3];
  double vxs; //= y0[4];
  double vys; //= y0[5];
  double vxm; //= y0[6];
  double vym; //= y0[7];
};


int integrator(double *y0, FILE * outfile, double clearance, int cond);


#endif
