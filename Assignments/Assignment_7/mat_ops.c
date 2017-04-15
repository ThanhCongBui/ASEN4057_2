#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <stdlib.h>
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
			fscanf(CFile,"%lf",&C[ii*c_n+jj]);
//Close all the files
fclose(AFile);
fclose(BFile);
fclose(CFile);

//Create char* with the contents of the output name (i.e. A_mult_B)

char * full_nameXX;
char * full_nameXP;
char * full_namePX;
char * full_nameXM;
char * full_nameMX;
char * fillerP = "_plus_";
char * fillerM = "_minus_";
char * fillerX = "_mult_";

// Allocate memory for each string that is going to hold a filename
full_nameXX = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerX) + strlen(argv[3]));

full_nameXP = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerP) + strlen(argv[3]));

full_namePX = malloc(strlen(argv[1]) + strlen(fillerP) + strlen(argv[2]) + strlen(fillerM) + strlen(argv[3]));

full_nameXM = malloc(strlen(argv[1]) + strlen(fillerX) + strlen(argv[2]) + strlen(fillerM) + strlen(argv[3]));

full_nameMX = malloc(strlen(argv[1]) + strlen(fillerM) + strlen(argv[2]) + strlen(fillerX) + strlen(argv[3]));


// First case. A*B*C

if ((a_n == b_m) && (b_n == c_m))
{
	//Create intermediate matrices to avoid overwriting the necessary matrices
	double * Mid;
 	double * Final;
	Final = malloc(a_m*c_n*sizeof(double));
	Mid=malloc(a_n*b_m*sizeof(double));

	//First iteration to populate A*B
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,a_m,b_m,c_m,1.0,A,a_m,B,b_m,0,Mid,c_m);

	//Second iteration to populate Mid*C

	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,a_m,b_m,c_m,1.0,Mid,a_n,C,c_m,0.0,Final,c_n);


FILE *XXFile; 
	strcpy(full_nameXX,argv[1]);
	strcat(full_nameXX,fillerX);
	strcat(full_nameXX,argv[2]);
	strcat(full_nameXX,fillerX);
	strcat(full_nameXX,argv[3]);
	XXFile = fopen(full_nameXX,"w");
	fprintf(XXFile,"%d %d\n",a_m,c_n);
	
		for (int ii = 0; ii < a_m; ii++){

			for (int jj = 0; jj < c_n; jj++)

				fprintf(XXFile,"%lf ",Final[ii*c_n+jj]);
				fprintf(XXFile,"\n");

		

			}
		fclose(XXFile);
		free(Final);
		free(Mid);
		free(full_nameXX);

}

else { printf("Dimension mismatch, cannot compute A*B*C matrix operation. \n");}


// Second Case. A*B + C 
if ((a_n == b_m) && (b_m == c_m) && (b_n == c_n))
{
	

	//Create intermediate matrices to avoid overwriting the necessary matrices
	double * Mid;
 	double * Final;
	Final = malloc(c_m*c_n*sizeof(double));
	Mid=malloc(a_n*b_m*sizeof(double));
	

	//First iteration to populate A*B
	
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,a_m,b_m,c_m,1.0,A,a_m,B,b_m,0,Mid,c_m);

	//Second iteration to populate Mid+C. Simple matrix addition iteration
	
	for (int ii = 0; ii<c_m; ii++){
		for (int jj = 0; jj<c_n; jj++){

			Final[ii*c_n+jj] = Mid[ii*c_n+jj] + C[ii*c_n+jj];
				
			}
		}


FILE *XPFile; 
	strcpy(full_nameXP,argv[1]);
	strcat(full_nameXP,fillerX);
	strcat(full_nameXP,argv[2]);
	strcat(full_nameXP,fillerP);
	strcat(full_nameXP,argv[3]);
	XPFile = fopen(full_nameXP,"w");
	fprintf(XPFile,"%d %d\n",a_m,c_n);
	
		for (int ii = 0; ii < a_m; ii++){

			for (int jj = 0; jj < c_n; jj++)

				fprintf(XPFile,"%lf ",Final[ii*c_n+jj]);
				fprintf(XPFile,"\n");
			}
		fclose(XPFile);
		free(Final);
		free(Mid);
		free(full_nameXP);

}

else { printf("Dimension mismatch, cannot compute A*B + Cmatrix operation. \n");}



// Third Case. A + B*C 

if ((b_n == c_m) && (a_m == b_m) && (c_n == a_n))
{
	

	//Create intermediate matrices to avoid overwriting the necessary matrices
	double * Mid;
 	double * Final;
	Final = malloc(a_m*a_n*sizeof(double));
	Mid=malloc(b_n*a_m*sizeof(double));
	

	//First iteration to populate B*C
	
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,b_m,c_m,a_m,1.0,B,b_m,C,c_m,0,Mid,a_m);

	//Second iteration to populate A+Mid. Simple matrix addition iteration
	
	for (int ii = 0; ii<c_m; ii++){
		for (int jj = 0; jj<c_n; jj++){

			Final[ii*c_n+jj] = Mid[ii*c_n+jj] + A[ii*c_n+jj];
				
			}
		}


FILE *PXFile; 
	strcpy(full_namePX,argv[1]);
	strcat(full_namePX,fillerP);
	strcat(full_namePX,argv[2]);
	strcat(full_namePX,fillerX);
	strcat(full_namePX,argv[3]);
	PXFile = fopen(full_namePX,"w");
	fprintf(PXFile,"%d %d\n",a_m,c_n);
	
		for (int ii = 0; ii < a_m; ii++){

			for (int jj = 0; jj < c_n; jj++)

				fprintf(PXFile,"%lf ",Final[ii*c_n+jj]);
				fprintf(PXFile,"\n");

			}
		fclose(PXFile);
		free(Final);
		free(Mid);
		free(full_namePX);

}

else { printf("Dimension mismatch, cannot compute A + B*C matrix operation. \n");}


// Fourth Case. A*B - C

if ((a_n == b_m) && (a_m == c_m) && (c_n == a_n))
{
	

	//Create intermediate matrices to avoid overwriting the necessary matrices
	double * Mid;
 	double * Final;
	Final = malloc(a_m*a_n*sizeof(double));
	Mid=malloc(b_n*a_m*sizeof(double));
	

	//First iteration to populate A*B
	
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,a_m,b_m,c_m,1.0,A,a_m,B,b_m,0,Mid,c_m);

	//Second iteration to populate Mid-C. Simple matrix addition iteration
	
	for (int ii = 0; ii<c_m; ii++){
		for (int jj = 0; jj<c_n; jj++){

			Final[ii*c_n+jj] = Mid[ii*c_n+jj] - C[ii*c_n+jj];
				
			}
		}


FILE *XMFile; 
	strcpy(full_nameXM,argv[1]);
	strcat(full_nameXM,fillerX);
	strcat(full_nameXM,argv[2]);
	strcat(full_nameXM,fillerM);
	strcat(full_nameXM,argv[3]);
	XMFile = fopen(full_nameXM,"w");
	fprintf(XMFile,"%d %d\n",a_m,c_n);
	
		for (int ii = 0; ii < a_m; ii++){

			for (int jj = 0; jj < c_n; jj++)

				fprintf(XMFile,"%lf ",Final[ii*c_n+jj]);
				fprintf(XMFile,"\n");

			}
		fclose(XMFile);
		free(Final);
		free(Mid);
		free(full_nameXM);

}

else { printf("Dimension mismatch, cannot compute A*B - Cmatrix operation. \n");}



// Fifth Case. A-B*C

if ((b_n == c_m) && (a_m == b_m) && (c_n == a_n))
{
	

	//Create intermediate matrices to avoid overwriting the necessary matrices
	double * Mid;
 	double * Final;
	Final = malloc(a_m*a_n*sizeof(double));
	Mid=malloc(b_m*c_n*sizeof(double));
	

	//First iteration to populate B*C
	
	cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,b_m,c_m,a_m,1.0,B,b_m,C,c_m,0,Mid,a_m);

	//Second iteration to populate A-Mid. Simple matrix addition iteration
	
	for (int ii = 0; ii<c_m; ii++){
		for (int jj = 0; jj<c_n; jj++){

			Final[ii*c_n+jj] = A[ii*c_n+jj] - Mid[ii*c_n+jj];
				
			}
		}


FILE *MXFile; 
	strcpy(full_nameMX,argv[1]);
	strcat(full_nameMX,fillerM);
	strcat(full_nameMX,argv[2]);
	strcat(full_nameMX,fillerX);
	strcat(full_nameMX,argv[3]);
	MXFile = fopen(full_nameMX,"w");
	fprintf(MXFile,"%d %d\n",a_m,c_n);
	
		for (int ii = 0; ii < a_m; ii++){

			for (int jj = 0; jj < c_n; jj++)

				fprintf(MXFile,"%lf ",Final[ii*c_n+jj]);
				fprintf(MXFile,"\n");

			}
		fclose(MXFile);
		free(Final);
		free(Mid);
		free(full_nameMX);

}

else { printf("Dimension mismatch, cannot compute A - B*C matrix operation. \n");}
//I need to do A*B*C(DONE), A*B + C (DONE), A + B*C, A*B - C, A - B*C and save each in a separate text file

//For multiplication, A_n = B_m. For add/subt, A and B must be same size

// Compile with gcc 'filename.c' -llapacke -llapack -lblas -lgfortran
return 0;
}


