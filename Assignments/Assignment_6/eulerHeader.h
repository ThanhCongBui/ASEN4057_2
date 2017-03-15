#ifndef _euler_c
#define _euler_c

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
