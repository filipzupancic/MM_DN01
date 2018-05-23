#ifndef helper
#define helper

//defining a structure that represents vector
//that holds the coordinates x, y, z
typedef struct vector {
  double x;
  double y;
  double z;
} vector;

//defining a structure that represents particle 
//and its properties
typedef struct particle {
  vector position[2];
  vector velocity;
  vector force;
  double mass;
} particle;

//defining basic vector operations
#define vector_add(a,b)              ((vector){a.x+b.x, a.y+b.y, a.z+b.z})
#define vector_substract(a,b)        ((vector){a.x-b.x, a.y-b.y, a.z-b.z})
#define vector_scalar_product(a, b)  ((vektor){a.x * b, a.y * b, a.z * b})

//functions that are implemented in file visualize.c
//and can be called from other c files if we include helper.c
void visualize(int argc, char *argv[]);

//functions that are implemented in file solution.c
//and can be called from other c files if we include helper.c

#endif