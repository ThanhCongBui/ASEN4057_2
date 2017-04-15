#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
int main( int argc, char * argv[]){

	//Declare files
	FILE *AFile;
	FILE *BFile;
	FILE *CFile;
	
	//Open each file from the command line inputs
	AFile = fopen(argv[1],"r");
	BFile = fopen(argv[2],"r");
	CFile = fopen(argv[3],"r");

	// Initialize matrix size ints
	int a_m, a_n, b_m, b_n, c_m, c_n;

	//Scan first two values to check matrix sizes
	fscanf(AFile,"%d %d",&a_m, &a_n);
 	fscanf(BFile,"%d %d", &b_m, &b_n);
	fscanf(CFile,"%d %d",&c_m, &c_n);
	
	//Now make the matrices as doubles
	double * A;
	double * B;
	double * C;

	//Create memory for matrices
	A = malloc(a_m*a_n*sizeof(double));
	B = malloc(b_m*b_n*sizeof(double));
	C = malloc(c_m*c_n*sizeof(double));

	//Create ints for following iteration
	int ii, jj;

	//Iterate to fill the matrices A, B, and C with proper values
	for (ii = 0; ii < a_m; ii++)
		for (jj = 0; jj < a_n; jj++)
			fscanf(AFile,"%lf",&A[ii*a_n+jj]);

	for (ii = 0; ii < b_m; ii++)
		for (jj = 0; jj < b_n; jj++)
			fscanf(BFile,"%lf",&B[ii*b_n+jj]);

	for (ii = 0; ii < c_m; ii++)
		for (jj = 0; jj < c_n; jj++)
			fscanf(CFile,"%lf",&C[ii*c_n*jj]);
//Close all the files
fclose(AFile);
fclose(BFile);
fclose(CFile);

//Create char* with the contents of the output name (i.e. A_mult_B)

char * full_nameXX;
char * full_nameXP;
char * full_namePM;
char * full_nameXM;
char * full_nameMX;
char * fillerP = "_plus_";
char * fillerM = "_minus_";
char * fillerX = "_mult_";

// Allocate memory for each string that is going to hold a filename
full_nameXX = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerX) + strlen(argv[3]));

full_nameXP = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerP) + strlen(argv[3]));

full_namePM = malloc(strlen(argv[1]) + strlen(fillerP) + strlen(argv[2]) + strlen(fillerM) + strlen(argv[3]));

full_nameXM = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerM) + strlen(argv[3]));

full_nameMX = malloc(strlen(argv[1]) + strlen(fillerM) + strlen(argv[2]) + strlen(fillerX) + strlen(argv[3]));
//Do matrix multiplication here

printf("Values are: %d",a_m);

//cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,a_m,1.0,);

//I need to do A*B*C, A*B + C, A + B*C, A*B - C, A - B*C and save each in a separate text file

//For multiplication, A_n = B_m. For add/subt, A and B must be same size


return 0;
}

