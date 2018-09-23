#include<GL/glut.h>
#include<myheader.h>

//GLfloat angleR;
void update()
{
  angleR=angleR+0.5;
    if(angleR>360)
      angleR=0;
}

GLfloat objcolor[]={0.5f,0.5f,0.5f,1.f}; 
GLfloat white[]={1.0f,1.0f,1.0f,1.f};


float diffuseLight[] =
{ 0.8f, 0.8f, 0.8f, 1.0f };
float specularLight[] =
{ 1.0f, 1.0f, 1.0f, 1.0f };
float LightPosition[] =
{ 0.0f, 20.0f, 2.0f, 1.0f };
float local_view[] =
{ 0.0 };
 

void OnInit()
{
 
  glEnable(GL_LIGHTING); // Enable lighting.
 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glClearDepth(1.0f);
 
  // Set light information
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
 
  // Enable light
  glEnable(GL_LIGHT0);
 
  // Set up the material information for objects
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, objcolor);
  glMateriali(GL_FRONT, GL_SHININESS, 128);
}
 void deleteInitial()
{
system("rm temp.obj");
}

GLfloat light0_position[] = {0,0,1.0, 0.0};

void draw()
{


	if(opt2!=1)
  {

 // --------------- LIGHTING 
glEnable(GL_NORMALIZE);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);  
glLightfv(GL_LIGHT0, GL_POSITION, light0_position); 
glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, objcolor);
//---------------LIGHTING



   // OnInit();
    opt2=1;
    glClearColor (0.0,0.0,0.0,1.0); 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(  x, 1.0f, z,
				x+lx, 1.0f, z+lz,
				0.0f, 1.0f, 0.0f);

   	glPushMatrix();
    //glTranslatef(0,0,-10);
    //glTranslatef(0,50,-2);
    //glScalef(0.1,0.1,0.1);
    	initialOBJ();
    	objDraw();
    	optimisationList();
    	deleteInitial();
   	glPopMatrix();
   	glutSwapBuffers();
 	}
  else
  {

    glClearColor (0.0,0.0,0.0,1.0); 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(  x, 1.0f, z,
        x+lx, 1.0f, z+lz,
        0.0f, 1.0f, 0.0f);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glPushMatrix();
    //glColor3f(0.5,0.5,0.5);
    //glTranslatef(0,0,-10);
    //glTranslatef(0,50,-2);
    glScalef(0.4,0.4,0.4);
   // update();
    glRotatef(angleR,0,1,0);
    glRotatef(angleZ,1,0,0);
    glCallList(dlist);
    glPopMatrix();
    glutSwapBuffers();
  }

}

