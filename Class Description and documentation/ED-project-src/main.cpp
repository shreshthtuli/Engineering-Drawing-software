//! \brief Main.cpp file
/*! Main file for interfacing different classes
 under the file - main.cpp which contains all necessary structs, classes and functions
 for the Engineering drawing software
*/
#include <iostream>
#include <math.h>
#include <list>
#include "./include/GL/glut.h"


using namespace std;


/// Wrapper around the representation of a point 
struct Point {

	public:
		///x coordinate
		float x ; 
		///y coordinate
		float y ;
		///z coordinate
		float z ;
		//default values are not allowed in class or struct

};


/// Wrapper around the representation of an edge
struct Edge {

	public:
		///End point
		Point p1;
		///End point
		Point p2;
		///Whether edge is hidden
		/**Relevant only for orthogonal projections. true if edge is to be depicted by a dashed line. false otherwise.*/
		bool hidden = false;

		///Euclidian length of the edge
		float length() {
			return pow(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2) + pow(p1.z - p2.z,2), 0.5);
		};
};


/// Wrapper around the representation of a plane
class Plane {

	public:
		///Edges binding the plane.
		/**All these edges must be coplanar and must have a complete cyclic decomposition. Further, the largest cycle(in terms of length) must contain all other cycles. These smaller cycles are modelled as holes on the surface */
		list<Edge> Bounds;			
		
		///Get the directional cosine of the normal to the surface
		/**Obtains normal by taking cros product of two binding edges and returns the directional cosine*/
		float get_cosine(/**0 for x, 1 for y, 2 for z, default z*/int direction){

		};

		///Check if lies on the Plane.
		bool contains(Point p){
			
		};
};

///2D Model Class
/**Common internal representation for all types of drawings. Represented as a Euclidian graph on xy plane*/
class Model2D {

	public:

		list<Point> Nodes;					///<Nodes of the graph. Each node identifies a labelled vertex. Z coordinate must be 0.
		list<Edge> Edges;					///<Edges of the graph.

		///Whether the edgeset is complete.
		/**When converting from 3D to 2D, multiple edges may overlap or become degenerate. This value should be set to false if any of these edges have been removed. If this value is set to true, complete_edges is not called by convert_to_3D*/ 
		bool Edges_complete;				

		///Completes the Edgeset of the graph.
		/**Creates all possible edges between nodes of the graph that would not disturb the rendered edges ie edges that might have been lost in the 3D to 2D conversion process.*/
		void complete_edges() {

		};

		///Display the view on the screen		
		void display_2D() {

		};

		///Add new edge between pre-existing nodes p1 and p2.
		void add_edge(Point p1, Point p2) {

		}
		///Add new node to the graph
		void add_node(Point p1) {

		};

		///Check if the model is a valid 2D projection
		/**Runs basic sanity checks like no hanging edges, three faces at each vertex etc. May produce false positives.*/
		bool is_valid() {

		};
};


///3D Model Class
/** Holds the internal representation of the 3D object being worked on in terms of an Euclidean graph.*/  
class Model3D {

	public:
		list<Point> Nodes;					///<Nodes of the graph. Each node identifies a labelled vertex
		list<Edge> Edges;					///<Edges of the graph. Together with the nodes, defines the wireframe of the model
		list<Plane> Planes;					///<Planes differentiate the faces of the graph which are actually present from the ones that are not.

		///Reference origin for the graph.
		/**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/
		Point ref_Origin;					
		///Reference x axis point for the graph.
		/**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/								
		Point ref_x;					    											
		///Reference y axis point for the graph.
		/**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/
		Point ref_y;						
		
		///Rotate the object
		/**Allows rotation of the object in 3D space about a homogeneous axis. Note that this does not affect the reference points, ie the orthogonal projections remain unchanged*/
		void rotate(/**Anti-clockwise angle of rotation in radians*/float theta, float /**Angle between Axis of Rotation and z axis in radians*/alpha, /**Angle between the projection of Axis of Rotation on the xy plane and x axis in radians*/float beta) {

		}

		///Translate the object
		/**Moves the object so that the given coordinates form the new origin. This may be used in conjection with rotate in order to rotate about a non homogeneous axis. Note that this does not affect the reference points, ie the orthogonal projections remain unchanged*/
		void translate(/**x coordinate to map to new origin*/float x, /**x coordinate to map to new origin*/float y, /**x coordinate to map to new origin*/float z){

		};
		///Scales the object by the given factor
		void scale(float factor){

		};
		///Get the orthographic Projection of the Object
		/**Uses reduce function to extract the top, front and side views of the object with the help of the reference points. Restores the object to its original configuration before returning. Side view containing lesser hidden lines is chosen.*/
		Ortho project(){

		};

		///Construct Model3D from Orthogonal Projection
		/**Master method for 2D to 3D conversion. Converges for labelled nodes over 3 views. May or may not converge if some information is missing. Relies on the convert_to_3D function of the Ortho class*/
		void Extract(/**Orthographic projection of object to be extracted*/Ortho ortho){

		};
		///Display object on screen.
		void display_3D(/**false for wireframe, true otherwise*/bool show_planes) {

		};
		///Get the Isometric Projection of the Object.
		/**Uses reduce function to extract an isometric view of the object with the help of the reference points. Hidden lines are removed. Restores the object to its original configuration before returning. Side view containing more detain is chosen.*/
		Model2D getIso() {

		};
		///Obtain Pespective projection in current orientation
		/**Gives the 1-point perspective projection with eye at origin and screen at z=1. Pushes back object should any part of it lie in front of the screen. Restores the object to its original configuration before returning.*/
		Model2D getPerspective() {

		};

	private:
		///Get the front view in the current orientation. Called by all other functions that output Model2D
		Model2D reduce(){

		};
};

/// Orthographic Projection class
/**Wrapper around orthographic projection of an object. Also provides functions to convert from 2D to 3D*/
class Ortho {

	public:
		Model2D Top;			///<Top view
		Model2D Front;			///<Front view
		Model2D Side;			///<Side view. Can be left or right side, depending on Side_Is_Left
		bool Side_Is_Left;

		///Whether all nodes are labelled
		/**While labelling is a must for geometric objects, it is often ommited for machine parts. The 3D conversion may fail if this is false.*/		
		bool Nodes_complete;

		///Save projection as image file
		void export_ortho(){

		};

		///Display all the views on the screen
		void display_ortho(){

		};

		///3D Conversion algorithm.
		/**Master method for 2D to 3D conversion. Converges for labelled nodes over 3 views. May or may not converge if some information is missing. Model3D.Extract relies on this */
		Model3D convert_to_3D() {

		};

	private:
		Model2D generate_probable_wireframe() {

		};

		Model3D generate_probable_faces(Model2D input) {

		};

		Model3D  eliminate_ghosts(Model3D input) {

		};

		
};


// GUI interface
void display() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
 	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5f, -0.5f);    // x, y
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
	glEnd();
 
	glFlush();  // Render now
};


int main(int argc, char** argv){

	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;

};
