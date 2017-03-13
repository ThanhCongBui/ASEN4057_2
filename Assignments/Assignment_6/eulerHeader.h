#ifndef _euler_c
#define _euler_c

struct input {

	double x;
	double y;
	double dx;
	double dy;
};

void euler(int timestep, struct input *body);

#endif
