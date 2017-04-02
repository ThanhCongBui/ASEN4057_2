#ifndef _iterateSolution_h
#define _iterateSolution_h


struct input{

	double x;
	double y;
	double vx;
	double vy;
	double ax;
	double ay;

};



double iterateSolution(struct input *sat, struct input *moon, double clearance);

#endif
