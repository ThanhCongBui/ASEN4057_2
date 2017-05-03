#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ADDED PART TO CODE FOR PARALLEL //
#include <mpi.h>
//STRUCTS
struct dydt_type{
    double xs_dot;
    double ys_dot;
    double xm_dot;
    double ym_dot;
    double vxs_dot;
    double vys_dot;
    double vxm_dot;
    double vym_dot;
  };
struct dydt_type dydt;
struct y_type{
  double xs; //= y0[0];
  double ys; //= y0[1];
  double xm; //= y0[2];
  double ym; //= y0[3];
  double vxs; //= y0[4];
  double vys; //= y0[5];
  double vxm; //= y0[6];
  double vym; //= y0[7];
};
struct y_type y;
struct y_type ytemp;

//FUNCTION PROTOTYPES
double *forces(double RAx, double RAy, double RBx, double RBy, double mA, double mB);
struct dydt_type dydtfun(struct dydt_type dydt, struct y_type y, double * masses);
int integrator(double *y0, FILE * outfile, double clearance, int cond);
double *delVmin_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile1, double rE);
double *delVtime_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile2, double rE);
char * myrename(char *name);

//---------------------------------MAIN--------------------------------------------
int main(int argc, char *argv[]){
  //Take out arguments
  int cond = 1; //We want integrator to write data to a file

  
  // ADDED PART TO CODE FOR PARALLEL//
  int run, processID, numProcess;
  // initialize the MPI stuff
  run = MPI_Init(&argc, &argv);

    // We'll need to add command line arguments that take care of the number of processes
  //Choose objective 
    if(objective == 1){
	    outfile1 = fopen("outfile1","w");
	    delV_min = delVmin_opt(y0, y,clearance,accuracy, outfile1, rE);
	    fclose(outfile1);
	    y0[4] += delV_min[0];
  	    y0[5] += delV_min[1];
            er = integrator(y0, outfile, clearance, 1);
	    free(delV_min);
    }
    else if(objective == 2){
	    outfile2 = fopen("outfile2","w");
	    delV_min = delVtime_opt(y0, y,clearance,accuracy, outfile2, rE);
	    fclose(outfile2);
	    y0[4] += delV_min[0];
  	    y0[5] += delV_min[1];
	    er = integrator(y0, outfile, clearance, 1);
	    free(delV_min);
    }
free(name);
free(file);
fclose(outfile);
free(y0);
return 0;
}
//---------------------------------END OF MAIN--------------------------------------------



//---------------------------------OPTIMIZATION(objective 1)---------------------------------------
double * delVmin_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile1, double rE){
    int cond=0; //We dont want integrator to put anything in text file
    int er;
    double delVx,delVy,a_delV_mag, b_delV_mag,a_delVx_temp, b_delVx_temp,a_delVy_temp,b_delVy_temp, a_delV_temp, b_delV_temp;
    double soln_delVx, soln_delVy, soln_delV_mag;
    double a_delV_temp = 100;
    double b_delV_temp = 100;
    double * a_yte = malloc(sizeof(double)*8);
    double * b_yte = malloc(sizeof(double)*8);
    
   a_yte[0] = y0[0];
   a_yte[1] = y0[1];
   a_yte[2] = y0[2];
   a_yte[3] = y0[3];
   a_yte[6] = y0[6];
   a_yte[7] = y0[7];

   b_yte[0] = y0[0];
   b_yte[1] = y0[1];
   b_yte[2] = y0[2];
   b_yte[3] = y0[3];
   b_yte[4] = y0[4];
   b_yte[5] = y0[5];
   b_yte[6] = y0[6];
   b_yte[7] = y0[7];

    /*This is the section that I'm going to parallelize.
    Goal is to make one process do -100/sqrt(2) to 0, and the other do 0 to 100/sqrt(2)
    According to Google, this can be done by saying:

    If process = 1
    do some loop
    else (i.e. process = 2)
    do the other loop

    Of course, the issues are going to be with syntax and data types
    */
    // This loop will be the A loop, ranging from negative 100 / sqrt(2) to zero.

   //Logic follows:
   // IF PROCESSOR_RANK == 0
   // DO 
    for (delVx = -100/sqrt(2); delVx <= 0; delVx+=accuracy){
        a_yte[4] = y0[4] + delVx;
        for (delVy = -100/sqrt(2); delVy <= 0; delVy+=accuracy){
            //alter initial conditions
            a_yte[5] = y0[5] + delVy;
            er = integrator(a_yte, outfile1, clearance, cond);// calculate trajectpory
            if(er == 2){ //discard if not returned to earth
               a_delV_mag = sqrt(pow(delVx,2) + pow(delVy,2)); //calculate magnitude of delta v
                if (a_delV_mag <= a_delV_temp){//if delta V is smaller than guess, set guess to the delta V
                    a_delV_temp = a_delV_mag;
                    a_delVx_temp = delVx;
		    a_delVy_temp = delVy;
                }
            }
        }
    }
    // DONE


    

    // IF PROCESSOR_RANK ~= 0
    // DO
    for (delVx = 0; delVx <= 100/sqrt(2); delVx+=accuracy){
      b_yte[4] = y0[4] + delVx;
      for (delVy = 0; delVy <= 100/sqrt(2); delVy+=accuracy){
	b_yte[5] = y0[5] + delVy;
	er = integrator(b_yte, outfile1, clearance, cond);

	if (er == 2){
	  b_delV_mag = sqrt(pow(delVx,2) + pow(delVy,2));
	  if (b_delV_mag <= b_delV_temp){

	    b_delV_temp = b_delV_mag;
	    b_delVx_temp = delVx;
	    b_delVy_temp = delVy;
	  }
	}
      }
    }

    // Pick the smallest delta-V as the correct solution, and assign that value
    // to soln_ variables. 

    if (a_delV_temp < b_delV_temp){
      soln_delVx = a_delVx;
      soln_delVy = a_delVy;
      soln_delV_mag = a_delV_temp;
    }
    else{
      soln_delVx = b_delVx;
      soln_delVy = b_delVy;
      soln_delV_mag = b_delV_temp;
    }
    
    
   
    free(a_yte);
    free(b_yte);
    
    fprintf(outfile1,"Minimum change in velocity to get to Earth is %.4f [m/s]\n", soln_delV_mag);
    double *delV = malloc(sizeof(double)*2);
    delV[0] = soln_delVx;
    delV[1] = soln_delVy;
    return delV;
}
//---------------------------------OPTIMIZATION(objective 2)---------------------------------------
double * delVtime_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile2, double rE){
    int cond=0; //We dont want integrator to put anything in text file
    int er;
    double delVx,delVy,delV_mag,delVx_temp,delVy_temp;
    double delV_temp=3000;
    double * yte = malloc(sizeof(double)*8);
    yte[0] = y0[0];
    yte[1] = y0[1];
    yte[2] = y0[2];
    yte[3] = y0[3];
    yte[6] = y0[6];
    yte[7] = y0[7];
    for (delVx=-100/sqrt(2);delVx<=100/sqrt(2);delVx+=accuracy){
        yte[4] = y0[4] + delVx;
        for (delVy=-100/sqrt(2);delVy<=100/sqrt(2);delVy+=accuracy){
            //alter initial conditions
            yte[5] = y0[5] + delVy;
            er = integrator(yte, outfile2, clearance, cond);// calculate trajectpory
            if(er == 2){ //discard if not returned to earth
                delV_mag = sqrt(pow(delVx,2) + pow(delVy,2)); //calculate magnitude of delta v
                if (delV_mag <= delV_temp){//if delta V is smaller than guess, set guess to the delta V
                    delV_temp = delV_mag;
                    delVx_temp = delVx;
		    delVy_temp = delVy;
                }
            }
        }
    }
    free(yte);
    fprintf(outfile2,"Change in velocity to get to Earth in fastest time is %.4f [m/s]\n", delV_temp);
    double *delV = malloc(sizeof(double)*2);
    delV[0] = delVx_temp;
    delV[1] = delVy_temp;    
    return delV;
}
