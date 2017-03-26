#include <stdio.h>
#include <stdlib.h>
#include "readHead.h"

void main(int argc, const char*argv[]){


printf("First file is %s\n",argv[1]);
printf("Second file is %s\n",argv[2]);

int *mat1;
int *mat2;

mat1 = readfile(&argv[1],1,mat1);

mat2 = readfile(&argv[2],2,mat2);

printf("Vector is of size %lu", sizeof(mat1)/sizeof(int));

for (int ii = 0; ii < 10;ii++){
printf("Vector values are %d\n",mat1[ii]);

}
return;

}

