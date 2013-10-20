/*
 *  Project 1
 *  CSc 474, Computer Graphics
 *  Alexander Kort
 *
 *  
 */


#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

// some function prototypes
void display(void);
void normalize(float[3]);
void normCrossProd(float[3], float[3], float[3]);

// initial viewer position
static GLdouble viewer[] = {0.0, 0.0, 8.0};
// initial viewer angle
static GLfloat theta[] = {0.0, 0.0, 0.0};

// animation variables
static int frame = 0;
static int startFrame = 0;
static int endFrame = 100;
static int increment = 1;
static int count = 0;

// animation transform variables
static GLdouble translate[3] = {0, 1, 1};
static GLdouble translate2[3] = {0,-5,1.7};
static GLdouble translate3[3] = {-20, 0, 0};

//pupils
static GLdouble translate4[3] = {-2,6.3,3.5};
static GLdouble translate5[3] = {2,6.3,3.7};

//brows
static GLdouble translate6[3] = {-2,9.0,3.5};
static GLdouble translate7[3] = {2,9.0,3.5};

static GLdouble rotate[4] = {90, .5, 0.0, 0.0};

//---------------------------------------------------------
//   Set up the view

void setUpView() {
   // this code initializes the viewing transform
   glLoadIdentity();

   // moves viewer along coordinate axes
   gluLookAt(viewer[0], viewer[1], viewer[2], 
             0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   // move the view back some relative to viewer[] position
   glTranslatef(0.0f,0.0f, -6.0f);

   // rotates view
   glRotatef(theta[0], 1.0, 0.0, 0.0);
   glRotatef(theta[1], 0.0, 1.0, 0.0);
   glRotatef(theta[2], 0.0, 0.0, 1.0);

   return;
}

//----------------------------------------------------------
//  Set up the light

void setUpLight() {
   // set up the light sources for the scene
   // a directional light source from over the right shoulder
   GLfloat lightDir[] = {1.0, 1.0, 5.0, 0.0};
   GLfloat diffuseComp[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat amb[] = {1.0, 1.0, 1.0, 1.0};

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT1);
   glEnable(GL_LIGHT2);

   glLightfv(GL_LIGHT1, GL_POSITION, lightDir);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseComp);
   glLightfv(GL_LIGHT2, GL_AMBIENT, amb);

   return;
}

//--------------------------------------------------------
//  Set up the objects

void drawSphere() {
   // draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0.7, 0.3, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   glTranslatef(translate2[0], translate2[1], translate2[2]);
   glRotatef(90, 1.0, 0.0, 0.0);  

   // draw the sphere - the parameters are radius, number of
   //   radial slices (longitude lines) and number of vertical
   //   slices (latitude lines)
   glutSolidSphere(2.0, 20, 20);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawEyeball1() {
   // draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {1, 1, 1, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   glTranslatef(-2,7,2.3);
   glRotatef(90, 1.0, 0.0, 0.0);  

   // draw the sphere - the parameters are radius, number of
   //   radial slices (longitude lines) and number of vertical
   //   slices (latitude lines)
   glutSolidSphere(1.8, 50, 50);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawEyeball2() {
   // draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {1, 1, 1, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   //glTranslatef(translate[0], translate[1], translate[2]);
   glTranslatef(2,7,2.3);
   glRotatef(90, 1.0, 0.0, 0.0);  

   // draw the sphere - the parameters are radius, number of
   //   radial slices (longitude lines) and number of vertical
   //   slices (latitude lines)
   glutSolidSphere(1.9, 50, 50);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawPupil1() {
   // draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0, 0.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   //glTranslatef(translate[0], translate[1], translate[2]);
   glTranslatef(translate4[0],translate4[1],translate4[2]);
   glRotatef(90, 1.0, 0.0, 0.0);  

   // draw the sphere - the parameters are radius, number of
   //   radial slices (longitude lines) and number of vertical
   //   slices (latitude lines)
   glutSolidSphere(.7, 50, 50);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawPupil2() {
   // draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0, 0.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   //glTranslatef(translate[0], translate[1], translate[2]);
   glTranslatef(translate5[0],translate5[1],translate5[2]);
   glRotatef(90, 1.0, 0.0, 0.0);  

   // draw the sphere - the parameters are radius, number of
   //   radial slices (longitude lines) and number of vertical
   //   slices (latitude lines)
   glutSolidSphere(.6, 50, 50);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawClock()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0.8, 0.4, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(translate[0], translate[1], translate[2]);	 
   glRotatef(90, .5, 0.0, 0.0);  
   glScalef(5.0,2,9);

   
   glutSolidCube(2.0);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawHand1()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(0,1.8,4);	 
   //glRotatef(0, .5, 0.0, 0.0);  
   glScalef(.1,1,.2);

   
   glutSolidCube(2.0);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawHand2()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(-1.2,.7,4);	 
   glRotatef(100, 0.0, 0.0, 2.0);  
   glScalef(.1,1.3,.2);

   
   glutSolidCube(2.0);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawBrow1()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(translate6[0], translate6[1], translate6[2]);	 
   glRotatef(90, 0.0, 0.0, 1.0);  
   glScalef(.1,1,.2);

   
   glutSolidCube(2.0);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawBrow2()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0, 0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(translate7[0], translate7[1], translate7[2]);	 
   glRotatef(90, 0.0, 0.0, 1.0);  
   glScalef(.1,1,.2);

   
   glutSolidCube(2.0);

   // recover the transform state
   glPopMatrix();

   return;
}

void drawDod()
{
// draw an object

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0.3, 0.7, 0.9, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the cube
   glTranslatef(translate3[0], translate3[1], translate3[2]);	 
   glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);  
   glScalef(1,1,1);

   
   glutSolidDodecahedron(); 

   // recover the transform state
   glPopMatrix();

   return;
}

void drawCone() {

   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {0.8, 0.8, 0.8, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   // this translation will be used to animate the sphere
   glTranslatef(0, .5, 3);	 
   glRotatef(180, 0.0, 0.0, 1.0);  

   // draw the cone - the parameters are radius, height, number of
   //   radial slices and number of vertical slices
   glutSolidCone(3.5, 1.0, 70, 70);

   // recover the transform state
   glPopMatrix();

   return;
}

//-----------------------------------------------------------
//  Callback functions

void reshapeCallback(int w, int h) {
   // from Angel, p.562

   glViewport(0,0,w,h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w < h) {
      glFrustum(-2.0, 2.0, -2.0*(GLfloat) h / (GLfloat) w,
                2.0*(GLfloat) h / (GLfloat) w, 2.0, 20.0);
   }
   else {
      glFrustum(-2.0, 2.0, -2.0*(GLfloat) w / (GLfloat) h,
                2.0*(GLfloat) w / (GLfloat) h, 2.0, 20.0);
   }

   glMatrixMode(GL_MODELVIEW);
}


void timeStep(int step) {
   // animation code goes here
   
   // This function is called for each frame of animation
   double t = (double) (frame - startFrame) / (endFrame - startFrame);
   
   //this implements linear interpolation on the translation
   //double r = 0+ t * (2 - 3.14);
   //double r = 5 + t*(4.5-5);
   
   double r = 8;
   double r2 = 2.2;
   double r3 = .7*pow(2.71828183, (-.0015*(frame-startFrame)));
   double r4 = -.3*pow(2.71828183, (-.002*(frame-startFrame)));
   double phi = 0 + t * (3.14159 - 0);

   
   //dodec circling
   if (frame < 1200)
   {
	  translate3[0] = r * cos(2*phi);
	  translate3[2] = r * sin(2*phi);
   }
   else if (frame > 1500)
   {
	  translate3[0] = translate3[0] + .1;
   }

   //dodec rotating
   rotate[0] = -10.0 + t * (100.0 - (-100.0));


   //Pendulum Motion
   double phi2 = t*2*3.14159;
   double x = 2*cos(2*phi2 + 3.14159/2);

   translate2[0] = 2*cos(1.5*phi2 + 3.14159/2);
   translate2[1] = sqrt(pow(r2,2) - pow(2*cos(3*t*3.14159), 2))-7;

   
   //pupils moving
   double phi3 = t*3.14159;

   if (frame < 500)
   {
	 translate4[0] = .7*cos(phi2)-2;
	 translate5[0] = .7*cos(phi2)+2;
   }
   else
   {
		translate4[0] = r3 * cos(2*phi) - 2;
		translate4[1] = r3 * sin(2*phi) + 6.5;
		translate5[0] = r3 * -cos(3*phi) + 2;
		translate5[1] = r3 * sin(3*phi) + 6.5;
   }

   //brows raising
   if (frame < 500)
   {
	 translate6[1] = -.3*cos(phi2)+9;
     translate7[1] = -.3*cos(phi2+.3)+9;
   }
   else
   {
	 translate6[1] = r4*cos(phi2)+9;
     translate7[1] = r4*cos(phi2+.3)+9;
   }
   

   if (frame == endFrame) 
   {
	  increment = 1;
   }
   else if (frame == startFrame) 
   {
	   increment = 1;
   }
    
   frame = frame + increment;
 
   display();

   glutTimerFunc(10,timeStep, 0);

}

//---------------------------------------------------------
//  Main routines

void display (void) {
   // this code executes whenever the window is redrawn (when opened,
   //   moved, resized, etc.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // set the viewing transform
   setUpView();

   // set up light source
   setUpLight();

   // start drawing objects
   drawSphere();
   drawClock();
   drawEyeball1();
   drawEyeball2();
   drawDod();
   drawPupil1();
   drawPupil2();
   drawCone();
   drawHand1();
   drawHand2();
   drawBrow2();
   drawBrow1();

   glutSwapBuffers();
}

// create a double buffered 500x500 pixel color window
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Procedural Animation: Lab 1");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
   glutReshapeFunc(reshapeCallback);
	glutTimerFunc(50,timeStep, 0);  // 50 millisecond callback
	glutMainLoop();
	return 0;
}

//---------------------------------------------------------
//  Utility functions

void normalize(float v[3]) {
   // normalize v[] and return the result in v[]
   // from OpenGL Programming Guide, p. 58
   GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
   if (d == 0.0) {
      printf("zero length vector");
      return;
   }
   v[0] = v[0]/d; v[1] = v[1]/d; v[2] = v[2]/d;
}

void normCrossProd(float v1[3], float v2[3], float out[3]) {
   // cross v1[] and v2[] and return the result in out[]
   // from OpenGL Programming Guide, p. 58
   out[0] = v1[1]*v2[2] - v1[2]*v2[1];
   out[1] = v1[2]*v2[0] - v1[0]*v2[2];
   out[2] = v1[0]*v2[1] - v1[1]*v2[0];
   normalize(out);
}
