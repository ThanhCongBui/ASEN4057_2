#ifndef _DELVTIME_OPT_H
#define _DELVTIME_OPT_H
#include <stdio.h>

struct y_type y;

double * delVtime_opt(double *y0, struct y_type y, double clearance, double accuracy, FILE *outfile2, double rE);

#endif
