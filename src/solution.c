#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define NUMBER_OF_BODIES 2    
#define XYZ 3*NUMBER_OF_BODIES

#define dT 0.01 //time difference
#define eps 0.000001 //in case of dividing by 0

/* Array  of particles coordinates: 
*   Ex: coordinates[0] = x0
        coordinates[1] = y0
        coordinates[2] = z0
*/
double coordinates[XYZ];

/* Array  of particles velocities: 
*   Ex: velocities[0] = v(x0)
        velocities[1] = v(y0)
        velocities[2] = v(z0)
*/
double velocities[XYZ];
/* Array  of particles velocities: 
*   Ex: velocities[0] = v(x0)
        velocities[1] = v(y0)
        velocities[2] = v(z0)
*/
double grav_forces[XYZ];
/* Array  of particles gravitational forces: 
*   Ex: grav_forces[0] = F((x0))
        grav_forces[1] = F((y0))
        grav_forces[2] = F((z0))
*/

double force_down;
double force_up;
int main(){
    for(int i = 0; i < XYZ;i++){
        velocities[i] = 0;
        grav_forces[i] = 0;
        coordinates[i] = 0;
    }

    coordinates[0] = 0;
    coordinates[1] = 0;
    coordinates[2] = 0;

    coordinates[3] = 100;
    coordinates[4] = 10;
    coordinates[5] = 0;

    velocities[0] = 1;
    velocities[1] = 0;
    velocities[2] = 0;

    velocities[3] = 0;
    velocities[4] = 0;
    velocities[5] = 0;

   clock_t start_t, end_t, total_t;
   start_t = clock();


    double t = 0;
    while(t  < 150){
     for(int i = 0; i <XYZ; i+=3){
        printf("%d. particle | coordinate X:%10f | velocity_X: %10f | force_X:%10f\n",i/3,coordinates[i], velocities[i], grav_forces[i]);
        for(int j = 0; j < XYZ; j+=3){
            if(i != j){
                //we calculate the sum of all particles on a singular particle in its own direction
                if(coordinates[i] < coordinates[j]){
                             //current force on particle i in direction x
                        force_down = (abs(coordinates[i] - coordinates[j]));
                        force_down = force_down*force_down*force_down;
                        force_up = coordinates[i] - coordinates[j];
                        grav_forces[i]+= force_up/(force_down+eps);
                        //current force on particle i in direction y

                        force_down = (abs(coordinates[i+1] - coordinates[j+1]));
                        force_down = force_down*force_down*force_down;
                        force_up = coordinates[i+1] - coordinates[j+1];
                        grav_forces[i+1]+= force_up/(force_down+eps); 

                        //current force on particle i in direction z
                        force_down = (abs(coordinates[i+2] - coordinates[j+2]));
                        force_down = force_down*force_down*force_down;
                        force_down+=eps;
                        force_up = coordinates[i+2] - coordinates[j+2];
                        grav_forces[i+2]+= force_up/(force_down +eps); 
                }else{
                             //current force on particle i in direction x
                        force_down = (abs(coordinates[i] - coordinates[j]));
                        force_down = force_down*force_down*force_down;
                        force_up = coordinates[i] - coordinates[j];
                        grav_forces[i]-= force_up/(force_down+eps);
                        //current force on particle i in direction y

                        force_down = (abs(coordinates[i+1] - coordinates[j+1]));
                        force_down = force_down*force_down*force_down;
                        force_up = coordinates[i+1] - coordinates[j+1];
                        grav_forces[i+1] -= force_up/(force_down+eps); 

                        //current force on particle i in direction z
                        force_down = (abs(coordinates[i+2] - coordinates[j+2]));
                        force_down = force_down*force_down*force_down;
                        force_down+=eps;
                        force_up = coordinates[i+2] - coordinates[j+2];
                        grav_forces[i+2]-= force_up/(force_down +eps); 
                    
                }
                    
            }
        }
        // we upgrade our current velocity and coordinate x of particle i
        //    grav_forces[i]*=(-1);
        velocities[i]+=(dT*grav_forces[i]);
        coordinates[i]+=(dT*velocities[i]);

        //changing velocity and coordinate y of particle i
          //  grav_forces[i+1]*=(-1);
        velocities[i+1]+=(dT*grav_forces[i+1]);
        coordinates[i+1]+=(dT*velocities[i+1]);

        //upgrading coordinate z
         //grav_forces[i+2]*=(-1);
        velocities[i+2]+=(dT*grav_forces[i+2]);
        coordinates[i+2]+=(dT*velocities[i+2]);
        
    }
        t+=dT;
    }


       end_t = clock();
          total_t = (double)(end_t - start_t);
                printf("Total time taken: %ld miliseconds\n", total_t);
             
    return 0;
}