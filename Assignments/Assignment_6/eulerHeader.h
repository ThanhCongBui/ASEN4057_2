#ifndef _euler_h
#define _euler_h

struct inEuler {

	double x;
	double dx; 
	double time;
};


struct outEuler {

	double x;
	double time;
};

void euler(double timestep, struct inEuler *objIn, struct outEuler *objOut);

#endif
