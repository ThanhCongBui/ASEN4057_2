#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "accHeader.h"
#include "eulerHeader.h"
#include "exits.h"
#include "iterHeader.h"

double iterateSolution(struct initial *sat, struct initial *moon, struct output *satOut, struct output *moonOut,  int clearance){



/* So this is going to look something like this :


take in the acc_calc struct

call euler like so:

velocity_update = euler(acceration);

position_update = euler(velocity_update);

*/
acc_calc(satIn, moonIn, satOut, moonOut, clearance);


/*
check exitConditions()

if == 0, continue. Otherwise update all structs and return out of this function. 



initial_velocity = velocity_update;
initial_position = position_update;

and run again.


We might have to do this recursively instead of iterating for some set amount of iterates.
I'm not too good with recursive programming but I think it'll be our best oppportunity here.



myIn->x = sat->x;
int conditionCheck = 0;
while (conditionCheck == 0){

euler(timestep, myIn,myOut)


}
*/


void acc_calc(sat

return 0;

}
