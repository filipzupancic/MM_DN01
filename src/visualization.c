#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h> 
#include <stdlib.h>
#include <stdio.h>
#include "helper.h"

/* Global variables */
char title[] = "million_body_problem";

int refresh_interval = 1000;        

float red=1.0f, blue=1.0f, green=1.0f;

//angle of rotation for the camera direction
float angle=0.0;
//actual vector representing the camera's direction
float lx=0.0f, ly=0.0f, lz=-1.0f;
//XZ position of the camera
float x=0.0f, y=1.0f,z=5.0f;

//GLfloat eye[] = {0., 0., 20.};

//initialize graphics
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int generate_rand(int min, int max)
{
  return min + (int) (rand() / (double) (RAND_MAX) * (max - min + 1));
}

//function displays objects in space
void display() 
{
  // Clear Color and Depth Buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();
  // Set the camera
  gluLookAt(  x, y, z,
      x+lx, y+ly,  z+lz,
      0.0f, 1.0f,  0.0f);

  //printf("x1: %f z1: %f x2: %f z2: %f\n", x, z, x+lx, z+lz);

  //compute_coordinates();
  //coordinates = cv.coordinates;
  //int len_coordinates = sizeof(coordinates)/sizeof(double);
  
  //printf("len_coordinates: %d\n", len_coordinates);

  glColor3f(0.0f, 1.0f, 0.0f);
  glPointSize(3.);
  glBegin(GL_POINTS);
  for (int i = 0; i < 1000; i++)
  {
    //glTranslatef(generate_rand(1,100), generate_rand(1,100), generate_rand(1,100));
    //glutSolidSphere(1,20,20);
    glVertex3d(generate_rand(1,100), generate_rand(1,100), generate_rand(1,100));
  }
  /*
  for (int i = 0; i < len_coordinates; i+=3)
  {
    glVertex3d(coordinates[i], coordinates[i+1], coordinates[i+2]);
  } 
  */
  glEnd();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w': ly+=0.1; break;
        case 's': ly-=0.1; break;
        case 'q': exit(0); break;
    }
}

//reads user input from keyboard
void user_input(int key, int x, int y) {

  float fraction = 0.1f;

  switch (key) {
    case GLUT_KEY_LEFT :
      angle -= 0.01f;
      lx = sin(angle);
      lz = -cos(angle);
      break;
    case GLUT_KEY_RIGHT :
      angle += 0.01f;
      lx = sin(angle);
      lz = -cos(angle);
      break;
    case GLUT_KEY_UP :
      x += lx * fraction;
      z += lz * fraction;
      break;
    case GLUT_KEY_DOWN :
      x -= lx * fraction;
      z -= lz * fraction;
      break;
  }

}
 
//called when timer expires
void timer(int value) 
{
   glutPostRedisplay();      
   glutTimerFunc(refresh_interval, timer, 0); 
}
 
//window resize event
void resize(int width, int height) 
{  
  //prevent divide by zero 
  if (height == 0) height = 1; 
  float aspect = 1.0 * width / height; 
 
  //projection matrix
  glMatrixMode(GL_PROJECTION);

  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);
 
  //reset matrix
  glLoadIdentity(); 
  
  //set perspective   
  gluPerspective(45, aspect, 1, 100);

  //model view 
  glMatrixMode(GL_MODELVIEW);
}
 
//initializes glut, creates window and connects element in file 
void visualize (int argc, char* argv[]) { 
  //create window and initialize glut 
  glutInit(&argc, argv);            
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
  glutInitWindowSize(500, 500);   
  glutInitWindowPosition(50, 50); 
  glutCreateWindow(title);         

  initGL();

  //cllbacks
  glutDisplayFunc(display);
  glutReshapeFunc(resize); 
   
  // here are the new entries
  //glutKeyboardFunc(processNormalKeys);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(user_input);

  //timer                
  glutTimerFunc(0, timer, 0);

  //loop
  glutMainLoop();            
}


//main - only for testing purposes
//code will be executed from solution.c
int main(int argc, char *argv[])
{
  visualize(argc, argv);

  return 0;
}