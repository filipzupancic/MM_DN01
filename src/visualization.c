#include <GL/glut.h>

//initializes openGL graphics
void initGL() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 		//set background color to black
   glClearDepth(1.0f);                   		//set background depth to farthest
   glEnable(GL_DEPTH_TEST);   				//enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    				//set the type of depth-test
   glShadeModel(GL_SMOOTH);   				//enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  	//perspective corrections
}

//displays particles in space
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	//clears color and depth buffers
  glMatrixMode(GL_MODELVIEW);     			//operate on model-view matrix     			

  glLoadIdentity();                 			//reset the model-view matrix
  glTranslatef(0.0f, 0.0f, -6.0f);  			//move right and into the screen
  

  glPointSize(3.);  					//defining particle size
  glBegin(GL_POINTS);           			//begin drawing points
    glColor3f(1.0f, 0.0f, 0.0f);      			//red
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);      			//green
    glVertex3f(0.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);      			//blue
    glVertex3f(1.0f, -1.0f, 1.0f);
  glEnd();                             			//done drawing points

  glutSwapBuffers();  					// Swap the front and back frame buffers (double buffering)
  
}

void reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
  {
    height = 1;
  }
   
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0f, aspect, 0.1f, 100.0f); 
}

//function that initializes window, and connects 
//all functions implemented in file
void visualize(int argc, char *argv[])
{
  int width = 500; 
  int height = 500;
	
  glutInit(&argc, argv); 				    //initialize glut 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //enabled buffered modes
  glutInitWindowSize(width, height); 			    //sets the window's width & height
  glutInitWindowPosition(50, 50); 			    // Position the window's initial top-left corner			    
  glutCreateWindow("Million_body_problem"); 		    //creates window with the given title
  glutDisplayFunc(display); 				    //displays content defined in display function
  glutReshapeFunc(reshape);
  initGL();							    
  glutMainLoop(); 					    //enters the infinite loop
  exit(0);
}

//main function is implemented in the solution.c 
//this one is only for testing 
int main(int argc, char *argv[])
{
	visualize(argc, argv);
	return 0;
}