/* basic structure of optimizer:

check desired objective as input by user

if 1:
run broad sweep of successful cases and find minimum delta v successful 
using a sweep of angles as well

once minimum successful case is found and corresponding angles are found, run 
finer sweep around the found delta v to find minimum case given absolute
accuracy

if 2: 
similar to 1, to minimize time do same process but find minimum time achieved
in broad sweep.  Take corresponding velocities and check for minimum time 
in smaller sweep.

*/

