#ifndef helper
#define helper

#define NUMBER_OF_BODIES 2    
#define XYZ 3*NUMBER_OF_BODIES

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

//functions that are implemented in file visualize.c
//and can be called from other c files if we include helper.c
void visualize(int argc, char *argv[]);

//functions that are implemented in file solution.c
//and can be called from other c files if we include helper.c
void compute_coordinates();

#endif