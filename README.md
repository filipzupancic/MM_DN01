# MM_gravitational_million_body_problem

+folder src contains:								<br /> 
 solution.c 		- implemented logic of the problem 			<br />
 visualization.c 	- implemented visualization of the particles in space   <br />
 helper.h 		- header files with helping structs and functions       <br />
										<br />
+folder report contains:							<br />
 solution.tex 		- report written in latex				<br />	 
 solution.pdf		- pdf version of solution.tex   			<br />

+compile code	<br />
 gcc -std=c99 -pedantic -Wall solution.c visualization.c -lm -lGL -lGLU -lglut -g -o helper <br />

+download GLUT on Linux <br />
 sudo apt-get install freeglut3-dev	<br /> 

+if there are unmet dependencies try <br />
 apt --fix-broken install <br />