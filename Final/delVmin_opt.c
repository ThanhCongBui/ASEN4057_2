#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "delVmin_opt.h"

double * delVmin_opt( double *y0, struct y_type y, double clearance, double accuracy, FILE * outfile1, double rE){

  int cond=0; //We dont want integrator to put anything in text file
    int er;
    double delVx,delVy,delV_mag,delVx_temp,delVy_temp;
    double delV_temp=100;
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
            er = integrator(yte, outfile1, clearance, cond);// calculate trajectpory
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
    fprintf(outfile1,"Minimum change in velocity to get to Earth is %.4f [m/s]\n", delV_temp);
    double *delV = malloc(sizeof(double)*2);
    delV[0] = delVx_temp;
    delV[1] = delVy_temp;
    return delV;

}
