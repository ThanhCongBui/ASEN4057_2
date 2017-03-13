#ifndef _euler_c
#define _euler_c

struct input {

	double x;
	double y;
	double dx;
	double dy;
	double time;
};


struct output {

	double x;
	double y;
	double time;
};

void euler(double timestep, struct input *objIn, struct output *objOut);

#endif
