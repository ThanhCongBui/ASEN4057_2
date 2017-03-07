#!/bin/bash

# Tucker Emmett, Problem 1 for Homework 5. 
# Goal is to take in two integer arguments and then count out 
# the numbers starting at the first and ending at the second.
# For example, p1(3,15) should spit out 3 4 5 6 ... 15.

for (( ii=$1; ii<$2+1; ii=ii+1 ));

do 
	echo $ii
done


