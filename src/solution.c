#include <math.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "helper.h"

#define dT 10 //time difference
#define eps 0.000001 //in case of dividing by 0
double grav_forces[XYZ];
double M[NUMBER_OF_BODIES];
double a[XYZ];


double G = 0.000667;


void compute_coordinates()
{
        double dx = coordinates[0] -coordinates[3];
        double dy = coordinates[1] - coordinates[4];
        double D = sqrt(dx*dx + dy*dy);
        // if(D == 0){
        //     printf("COLLISION!!\n");
        //     break;
        // }
        double angle_radians = atan2(dy,dx);

        double F = (G*M[0])/ (D*D);
        a[3] = F*cos(angle_radians);
        a[4] = F*sin(angle_radians);
        velocities[3]+=(a[3] *dT);
        velocities[3]+=(a[4]*dT);
        coordinates[3]+=(velocities[3]*dT);
        coordinates[4]+=(velocities[4]*dT);

    }

    //printf("coordinates[1]: %f coordinates[2]: %f coordinates[3]: %f\n", coordinates[0], coordinates[1], coordinates[2]);
    //printf("coordinates[4]: %f coordinates[5]: %f coordinates[6]: %f\n", coordinates[3], coordinates[4], coordinates[5]);
}

int main(int argc, char *argv[])
{
    for(int i = 0; i < XYZ;i++)
    {
        velocities[i] = 0;
        grav_forces[i] = 0;
        coordinates[i] = 0;
        a[i] = 0;
    }

    coordinates[0] = 320;
    coordinates[1] = 240;
    coordinates[2] = 0;

    coordinates[3] = 170;
    coordinates[4] = 240;
    coordinates[5] = 0;

    M[0] = 1098900;
    M[1] = 0.5974;


    velocities[0] = 0;
    velocities[1] = 0;
    velocities[2] = 0;
    velocities[3] = 0;
    velocities[4] = 2;
    velocities[5] = 0;

    visualize(argc, argv);

    return 0;
}