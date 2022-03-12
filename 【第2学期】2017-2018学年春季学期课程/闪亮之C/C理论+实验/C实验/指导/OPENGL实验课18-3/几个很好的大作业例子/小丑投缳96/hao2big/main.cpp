/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<Windows.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

static double go=-2;


/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    static double a = 1;
    a=a+0.02;
    static int c=1;
    static double b =-2;
    //变量b实现x轴平行的从-2到2之间的来回运动
    if(b>2)c*=-1;   //将c变成负值，控制从右向左移动
    if(b<-2)c*=-1;  //将c变成正值，控制从左向右移动
    b+=c/10.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(2,1,0);

    glPushMatrix();
        glTranslatef(0,-0.8,0);
        glScalef(0.5,1,0.5);
        glTranslated(0,2,-9);//head
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

glColor3d(1,0,0);
    glPushMatrix();

        glScalef(1,1,0.5);
        glTranslated(0,1,-8);//nose
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.3,slices,stacks);
    glPopMatrix();
glColor3d(0.2,0,0);
    glPushMatrix();

        glTranslatef(-3,-0.8,-3);//eye
        glScalef(1,1,0.5);
        glTranslated(3.1,2.3,-2.2);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.2,slices,stacks);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(-3,-0.8,-3);//eye
        glScalef(1,1,0.5);
        glTranslated(2.9,2.3,-2.2);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(0.2,slices,stacks);
    glPopMatrix();
     glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(0,1.5,-5);   //hair
        glRotated(a,0,0,0);

        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();

        glTranslated(b,-1,-6);
        glRotated(0,0,0,0);
        glRotated(a,0,90,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();





    glPushMatrix();
 glColor3d(0,0,1);

     glScalef(1,1,0.8);
        glTranslatef(0,-1.2,-8);
        glRotatef(60,1,0,0);
        glRotatef(a,0,0,1);
        glutSolidSphere(0.3,slices,stacks);
    glPopMatrix();

   glutSwapBuffers();




}



static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':




            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {



                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
