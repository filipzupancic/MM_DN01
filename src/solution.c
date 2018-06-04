#include <math.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "helper.h"

#define dT 10 //time difference
double F[XYZ];


void compute_coordinates()
{
        for(int i = 0; i <  XYZ; i+=3){F[i] = 0;}
        double dx,dy,dz,D,F1,F2,F3;

        for(int i = 0; i < XYZ; i+=3){
            for(int j = 0; j < XYZ; j+=3){
                if(i != j){
                 dx = coordinates[i] -coordinates[j];
                 dy = coordinates[i+1]- coordinates[j+1];
                 dz = coordinates[i+2] - coordinates[j+2];
                 D = sqrt(dx*dx + dy*dy + dz*dz);
                D = pow(D,3);
                 F1 = (dx/D)*masses[i]*masses[j];
                 F2 = (dy/D)*masses[i]*masses[j];
                 F3 =  (dz/D)*masses[i]*masses[j];

                F[i]-=F1;
                F[i+1]-=F2;
                F[i+2]-=F3;
                }
            }
        }
        for(int i = 0; i < XYZ; i+=3){
            coordinates[i]+=(velocities[i]*dT);
            coordinates[i+1]+=(velocities[i+1]*dT);
            coordinates[i+2]+=(velocities[i+2]*dT);
            
            velocities[i]+=((F[i]/masses[i])*dT); 
            velocities[i+1]+=((F[i+1]/masses[i])*dT);
            velocities[i+2]+=((F[i+2]/masses[i])*dT);
        }

       
       

     
}

int main(int argc, char *argv[])
{
    // for(int i = 0; i < XYZ;i++)
    // {
    //     velocities[i] = 0;
    //     coordinates[i] = 0;
    // }
    // coordinates[0] = 320;
    // coordinates[1] = 240;
    // coordinates[2] = 0;

    // coordinates[3] = 170;
    // coordinates[4] = 240;
    // coordinates[5] = 0;

    // M[0] = 1098900;
    // M[1] = 0.5974;


    // velocities[0] = 0;
    // velocities[1] = 0;
    // velocities[2] = 0;
    // velocities[3] = 0;
    // velocities[4] = 2;
    // velocities[5] = 0;

    visualize(argc, argv);

    return 0;
}