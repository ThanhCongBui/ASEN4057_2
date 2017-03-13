//header file for acc_calc which is to be compiled into tuckAcc

#ifndef _acc_calc_h
#define _acc_calc_h

struct initSat{
double x;
double y;
double vx;
double vy;

};

struct initMoon{

double x;
double y; 
double vx;
double vy;

};

struct outSat{

double x;
double y;

};


struct outMoon{

double x;
double y;

};

extern void
acc_calc(struct *initSat, struct *initMoon, struct *outSat, struct *outMoon);


#endif
