#! /bin/bash

asnm_7_Dir=$(pwd)
cd $1
matrices=$(ls)

for fileA in $matrices
do
	for fileB in $matrices
	do
		for fileC in $matrices
		do
			${asnm_7_Dir =}/a.out $fileA $fileB $fileC
		done
	done
done


