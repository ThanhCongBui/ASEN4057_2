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
  int rank, size;
  // initialize the MPI stuff
  MPI_Init(&argc, &argv); // Initialize MPI with the input number of processes
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

  printf("Using %d processes\n",size);
  
  // Need to update delVmin and time_opt header files to reflect them taking in
  // 'int rank' as a variable to use in the parallel processes.
  // Need to manage command line inputs such that argv and argc correctly reflect
  // input values for number of processes
  //
  //Choose objective 
    if(objective == 1){
	    outfile1 = fopen("outfile1","w");
	    delV_min = delVmin_opt(y0, y,clearance,accuracy, outfile1, rE, rank, size);
	    fclose(outfile1);
	    y0[4] += delV_min[0];
  	    y0[5] += delV_min[1];
            er = integrator(y0, outfile, clearance, 1);
	    free(delV_min);
    }
    else if(objective == 2){
	    outfile2 = fopen("outfile2","w");
	    delV_min = delVtime_opt(y0, y,clearance,accuracy, outfile2, rE, rank, size);
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
 MPI_Finalize();
return 0;
}
//---------------------------------END OF MAIN--------------------------------------------



//---------------------------------OPTIMIZATION(objective 1)---------------------------------------
double * delVmin_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile1, double rE, int rank, int size){

  // Note the inclusion of MPI_Comm comm in the input. This is necessary to keep track
  // of the process rank during parallel operations
    int cond=0; //We dont want integrator to put anything in text file
    int er;
    double delVx,delVy,delV_mag,delVx_temp,delVy_temp, delV_temp;
    double delV_temp = 100;
    double * yte = malloc(sizeof(double)*8);
    
    
   yte[0] = y0[0];
   yte[1] = y0[1];
   yte[2] = y0[2];
   yte[3] = y0[3];
   yte[6] = y0[6];
   yte[7] = y0[7];

    /*This is the section that I'm going to parallelize.
    Goal is to make one process do -100/sqrt(2) to 0, and the other do 0 to 100/sqrt(2)
After talking to Evans, this will be accomplished by iterating over the whole range and letting the for loop
automatically assign things to processes
    */

   // Note that the iteration range is -100/sqrt(2) to +100/sqrt(2) in searching for deltaV

   int increment = 200/(size*sqrt(2)); // This is necessary to properly step between processes. For 2 processes, increment = 100/sqrt(2). For 4, = 50/sqrt(2)
   
   int startValx = -100/sqrt(2) + rank*increment; // This covers the -100 to 0 case, assigning those values to process 0
   int startValy = startValx;
   int endValx, endValy;

   if (rank != (size-1)){
     endValx = -100/sqrt(2) + (rank + 1)*increment; // Creates a mesh of 'increment' size throughout the processes. This is valid for processes not equal to the final process. 
   }
   else{
     endValx = 100/sqrt(2); // For the singular case in which rank == size-1 (we're at the last process), endVal is equal to the maximum range value.
   }

   endValy = endValx;


   // I think I want to write a for loop over startVal to endVal which will properly take care of parallelizing the code


   for (startValx; startValx < endValx; startValx += accuracy){

     yte[4] = y0[4] + delVx;

     for (startValy; startValy < endValy; startValy += accuracy){

       yte[5] = y0[5] + delVy;

       er = integrator(yte,outfile1, clearance, cond);

       if (er == 2){
	 delV_mag = sqrt(pow(delVx,2) + pow(delVy,2));

	 if (delV_mag <= delV_temp){

	   delV_temp = delV_mag;
	   delVx_temp = delVx;
	   delVy_temp = delVy;
	 }
       }
     }
   }

   int *nullVal = NULL;
   //Need to do two gathers to get x and y values
   MPI_Gather(&delVx_temp, 1, MPI_DOUBLE, nullVal, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	 
   
   /*  
    for (delVx = -100/sqrt(2); delVx <= 0; delVx+=accuracy){
        yte[4] = y0[4] + delVx;
	
        for (delVy = -100/sqrt(2); delVy <= 0; delVy+=accuracy){
            //alter initial conditions
            yte[5] = y0[5] + delVy;
            er = integrator(yte, outfile1, clearance, cond);// calculate trajectory
	    
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
   */ 


    

    // 
   
   free(yte);
    
    fprintf(outfile1,"Minimum change in velocity to get to Earth is %.4f [m/s]\n", delV_mag);
    double *delV = malloc(sizeof(double)*2);
    delV[0] = delVx_temp;
    delV[1] = delVy_temp;
    return delV;
}
//---------------------------------OPTIMIZATION(objective 2)---------------------------------------
double * delVtime_opt(double *y0, struct y_type y,double clearance,double accuracy, FILE * outfile2, double rE, int rank, int size){
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
