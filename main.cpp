
#include <GL/glut.h>
#include <stdio.h>
#include <myheader.h>
#include<vector>
#include<string>

using namespace std;
GLfloat angleR,angleZ;
int opt2;
class data p;
double queuedMilliseconds,prev0,fps,responseTime;
GLuint dlist;
int imageNo,elements;

void initialSetup()
{
	elements=0;
	FILE *filename;
	char temp[50];
	vector<string> name;
	// HIGHLY DANGEROUS, DO NOT PASS VARIABLE TO SYSTEM CALL, THIS IS JUST A QUICK FEATURE I ADDED FOR PRESENTATION
	system("(ls | grep .obj)>filelist");
	filename=fopen("filelist","r");

	while(!(feof(filename)))
	{	
		elements++;
		fscanf(filename,"%s",temp);
		name.push_back(temp);
	}

	string systemtext = "cp " + name[imageNo] + " temp.obj";
	system(systemtext.c_str());
	fclose(filename);
	system("rm filelist");
}


void handleResize(int w,int h)
{
    glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();  
	glViewport(0,0,w,h);
	gluPerspective (60, (GLfloat)w / (GLfloat)h, 1, 1000.0);
	glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

}

void processKeyboard(unsigned char key,int x,int y)
{

if(key==65||key==97)
{
	if(imageNo!=0)
	imageNo--;
}
if(key==68||key==100)
{	
	if(imageNo<(elements-2))
	imageNo++;

}

opt2=0;
clearp_data();
angleR=0;angleZ=0;
initialSetup();
}

int main(int argc, char** argv)
{
	//..gameLoop setup
	queuedMilliseconds=0;
	prev0=0;
	fps=60;
	responseTime=(1/fps)*1000;

initialSetup();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
glutInitWindowSize(800,800);
glutInitWindowPosition(100,100);
glutCreateWindow("OBJ Loader");
glutReshapeFunc(handleResize);
glutDisplayFunc(draw);
glutIdleFunc(mixedStepLoop);
glutSpecialFunc(processSpecialKeys);
glutKeyboardFunc(processKeyboard);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}

