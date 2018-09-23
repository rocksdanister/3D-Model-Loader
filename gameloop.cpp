#include<GL/glut.h>
#include<myheader.h>

void mixedStepLoop()
{
    double now = glutGet(GLUT_ELAPSED_TIME);
    double timeElapsedMs =(now-prev0);
    queuedMilliseconds += timeElapsedMs ;
    while(queuedMilliseconds >= responseTime) 
    {
       // update();
        queuedMilliseconds -= responseTime;
        glutPostRedisplay();
    }
    prev0=now;
}

