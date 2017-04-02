#ifndef _exitConditions_h
#define _exitConditions_h

struct position{

	double x;
	double y;
};



int exitConditions(struct position *sat, struct position *moon, int clearance);


#endif
