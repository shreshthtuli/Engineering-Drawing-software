// May need to replace with the absolute path on some systems
///File for GUI interfacing between the user and main.cpp
///Based on OpenGL framework
#define PATH_TO_TEAPOT_OBJ_FILE "teapot.obj"

#include <iostream>
#include "Geometry.h"
#include "shaders.h"
#include "Transform.h"
#include <string>
#include <sstream>
#include <FreeImage.h>

int amount; // The amount of rotation for each arrow press

vec3 eye; // The (regularly updated) vector coordinates of the eye location 
vec3 up;  // The (regularly updated) vector coordinates of the up location 
const vec3 eyeinit(0.0, 0.0, 7.0); // Initial eye position, also for resets
const vec3 upinit(0.0, 1.0, 0.0); // Initial up position, also for resets
const int amountinit = 5; //Initial step amount for camera movement, also for resets

int w = 500, h = 500; // width and height 

					  // Constants to set up lighting on the teapot
const vec4 light_position(0, 5, 10, 1);    // Position of light 0
const vec4 light_position1(0, 5, -10, 1);  // Position of light 1
const vec4 light_specular(0.6, 0.3, 0, 1);    // Specular of light 0
const vec4 light_specular1(0, 0.3, 0.6, 1);   // Specular of light 1
const vec4 one(1, 1, 1, 1);                 // Specular on teapot
const vec4 medium(0.5, 0.5, 0.5, 1);        // Diffuse on teapot
const vec4 small(0.2, 0.2, 0.2, 1);         // Ambient on teapot
const GLfloat high = 100;                      // Shininess of teapot
vec4 light0, light1;

/// Variables to set uniform params for lighting fragment shader 
GLuint islight;
GLuint light0posn;
GLuint light0color;
GLuint light1posn;
GLuint light1color;
GLuint ambient;
GLuint diffuse;
GLuint specular;
GLuint shininess;
GLuint color;

/// Uniform variables used for the transformation matrices
GLuint projectionPosition;
mat4 view, projection;

/// New helper transformation function to transform vector by the view matrix
void transformvec(const vec4 input, vec4& output)
{
	output = view * input;
}

/// Deallocate any dynamically allocated memory here - shader pipelines
void cleanup()
{
	destroyBufferObjects();
}

std::string imgNumber(int num)
{

}

void printHelp()
{

}

void keyboard(unsigned char key, int x, int y)
{

}

// Arrow key functionality
void specialKey(int key, int x, int y)
{

}

// This function gets called when the window size gets changed
void reshape(int width, int height)
{

}



void init()
{

}


//Main Dislpay function which uses other helper functions defined above to display the 3D object and take instruction from user
void display()
{
	transformvec(light_position, light0);
	transformvec(light_position1, light1);
	glUniform4fv(light0posn, 1, &light0[0]);
	glUniform4fv(light0color, 1, &light_specular[0]);
	glUniform4fv(light1posn, 1, &light1[0]);
	glUniform4fv(light1color, 1, &light_specular1[0]);

	glUniform4fv(ambient, 1, &small[0]);
	glUniform4fv(diffuse, 1, &small[0]);
	glUniform4fv(specular, 1, &one[0]);
	glUniform1f(shininess, high);
	glUniform1i(islight, true);

	solidTeapot(4.5f);
	glutSwapBuffers();
}


///Main function including the functions defined for object trandformations with proper shaders
int main(int argc, char* argv[])
{
	//Initialize GLUT
	FreeImage_Initialise();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("HW1: Transformations");

	GLenum err = glewInit();
	if (GLEW_OK != err)
		std::cerr << "Error: " << glewGetString(err) << std::endl;

	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutReshapeWindow(w, h);

	printHelp();
	glutMainLoop();
	FreeImage_DeInitialise();
	cleanup();

	return 0;
}