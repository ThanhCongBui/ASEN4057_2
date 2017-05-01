#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]){

  int cond = 1;
  int objetive = atoi(argv[1]);
  double clearance = atof(argv[2]);
  double accuracy = atof(argv[3]);
  double rE = 6371000;
  //Rename if theres a "." in argument
  char * name = malloc(sizeof(char)*strlen(argv[3]));
  sprintf(name, "%s", argv[3]);
  char * new = myrename(name);
  //Create output files
  FILE *outfile, *outfile1, *outfile2;
  char *file, *outfile_delvmin;
  file = malloc( ( 10 + strlen(argv[1]) + strlen(argv[2]) + strlen(argv[3]) ) * sizeof(char) );
  sprintf(file, "Optimum_%s_%s_%s", argv[1], argv[2],argv[3] );
  outfile = fopen(file, "w");
  //Create initial conditions
  double *y0 = malloc(sizeof(double)*8);
  y0[0] = 2.1855*pow(10,8);
  y0[1] = 2.6046*pow(10,8);
  y0[2] = 2.8341*pow(10,8);
  y0[3] = 2.597*pow(10,8);
  y0[4] = 642.7876;
  y0[5] = 766.0444;
  y0[6] = -683.7457;
  y0[7] = 746.1774;
  //Create struct vector, assign initial conditions
  y.xs = y0[0];
  y.ys = y0[1];
  y.xm = y0[2];
  y.ym = y0[3];
  y.vxs = y0[4];
  y.vys = y0[5];
  y.vxm = y0[6];
  y.vym = y0[7];
  double * delV_min;
  int er;
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

  
