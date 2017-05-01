#ifndef _DELVMIN_OPT_H
#define _DELVMIN_OPT_H
#include <stdio.h>
struct y_type{

	double xs; 
	double yx; 
	double xm; 
	double ym;
	double vxs;
	double vys;
	double vxm;
	double vym;
};


double * delVmin_opt( double *y0, struct y_type y, double clearance, double accuracy, FILE * outfile1, double rE);

#endif
