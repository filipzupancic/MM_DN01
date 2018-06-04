#include <math.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "helper.h"

#define dT 1e-5 //time difference

double F[XYZ];

double generate_rand(int min, int max)
{
  return min + (double)rand() / (double) (RAND_MAX) * (max - min + 1);
}

void generate_parameters()
{
    masses[0] = 1000000;
    for (int i = 1; i < NUMBER_OF_BODIES; i++)
    {
        masses[i] = 1;
    }

    //first we position black hole in the middle
    coordinates[0] = 0;
    coordinates[1] = 0;
    coordinates[2] = 0;

    velocities[0] = 0;
    velocities[1] = 0;
    velocities[2] = 0;

    int i = 3; 
    while (i < XYZ)
    {
        double x = generate_rand(-R, R);
        double y = generate_rand(-R, R);
        double z = generate_rand(-H, H);

        if (pow(x, 2) + pow(y, 2) < pow(R, 2))
        {
            coordinates[i] = x;
            coordinates[i+1] = y;
            coordinates[i+2] = z;
            
            double r = sqrt(x*x + y*y + z*z);
            double v = sqrt(masses[0]/r);
            velocities[i] = -v * coordinates[i+1]/r;
            velocities[i+1] = v * coordinates[i]/r;
            velocities[i+2] = 0;

            i+=3;
        }  
    }
}

void compute_coordinates()
{
        for(int i = 0; i <  XYZ; i+=3){F[i] = 0;}
        
        for(int i = 0; i < XYZ; i+=3){
        double dx,dy,dz,D,F1,F2,F3;
            for(int j = 0; j < XYZ; j+=3){
                if(i != j){
                dx = coordinates[i] - coordinates[j];
                dy = coordinates[i+1] - coordinates[j+1];
                dz = coordinates[i+2] - coordinates[j+2];
                D = sqrt(dx*dx + dy*dy + dz*dz);
                D = pow(D,3);
                F1 = (dx/(D+eps))*masses[i/3]*masses[j/3];
                F2 = (dy/(D+eps))*masses[i/3]*masses[j/3];
                F3 =  (dz/(D+eps))*masses[i/3]*masses[j/3];

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
            
            //velocities[i] = 2;
            velocities[i]+=((F[i]/masses[i/3])*dT); 
            velocities[i+1]+=((F[i+1]/masses[i/3])*dT);
            velocities[i+2]+=((F[i+2]/masses[i/3])*dT);
        }
}

int main(int argc, char *argv[])
{
    generate_parameters();

    visualize(argc, argv);

    return 0;
}