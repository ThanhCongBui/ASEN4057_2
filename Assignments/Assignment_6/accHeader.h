//header file for acc_calc which is to be compiled into tuckAcc

#ifndef _acc_calc_h
#define _acc_calc_h

struct initial{
	double x;
	double y;
	double vx;
	double vy;

};

struct output{
	//acceleration in x and y
	double x;
	double y;
	double vx;
	double vy;
	double ax;
	double ay;

};

void acc_calc(struct initial *sat, struct initial *moon, struct output *satOut, struct output *moonOut );

#endif
