/*  v1.1 update
 fix mainplane speed
 fix memery waste
 add aniPlanes
*/

#include <gl\freeglut.h>
#include <iostream>
#include "map.h"

void display(); //draw planes according to map
void init();     
void timer(int);       //update 1. fire 2. move 3.check
void key(unsigned char, int, int);
void keyup(unsigned char, int, int);
void reshape(int, int);

map m;
direction d = None;

bool use = false;

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(500, 50);
	glutInitWindowSize(500, 600);

	glutCreateWindow("PlaneWar");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyup);
	init();
	glutTimerFunc(10, timer, 1);
	glutTimerFunc(500, timer, 2);
	glutTimerFunc(150, timer, 3);

	glutMainLoop();
	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 5, 0, 8);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
}

void timer(int v)
{
    if (v == 1) //map update
	{
		//while (use)
		//	continue;
		//use = true;
	    m.update(d);
		m.check();
		//system("cls");    //too slow
		std::cout << "score : " << m.getScore() << std::endl;
		if (m.isOvered())
		    exit(0);
		glutPostRedisplay();
		glutTimerFunc(10, timer, 1);
		//use = false;
	}
	if (v == 2)  //add new plane
	{
		//while (use)
		//	continue;
		//use =  true;
		//m.addPlane();
		//m.addPlane();
		//m.fire();
		int num = m.getScore() / 10 + 1;
		if (num > 10)
			num = 5;

		for (int a = 0; a < num; a++)   //add planes
			m.addPlane();
		
		glutPostRedisplay();
	    glutTimerFunc(500, timer, 2);
		//use = false;
	}
	if (v == 3)
	{
		m.fire();
		glutTimerFunc(150, timer, 3);
	}
}

void key(unsigned char c, int mx, int my)
{
	if (c == 'w')
		d = Forward;
	if (c == 'a')
		d = Left;
	if (c == 's')
		d = Back;
	if (c == 'd')
		d = Right;
	//m.move(d);
}

void keyup(unsigned char c, int x, int y)
{
	unsigned nc;
	if (d == None)
		return;
	if (d == Forward)
		nc = 'w';
	if (d == Back)
		nc = 's';
	if (d == Left)
		nc = 'a';
	if (d == Right)
		nc = 'd';
	if (nc == c)
		d = None;
}

void display()   //draw              planes : 50 * 80 ; fires : 10 * 10
{
    glColor3f(1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto x : m.aniPlanes)   //draw aniplanes
	{
		if (x.visible)
		{
		    GLfloat p1x = x.getLeft() / 100;
		    GLfloat p2x = x.getRight() / 100;
		    GLfloat p3x = (x.getLeft() + x.getRight()) / 200;
		    GLfloat p1y = x.getTop() / 100;
	   	    GLfloat p2y = x.getTop() / 100;
	    	GLfloat p3y = x.getBottom() / 100;
	    	glBegin(GL_TRIANGLES);
		        glVertex2f(p1x, p1y);
		      	glVertex2f(p2x, p2y);
		    	glVertex2f(p3x, p3y);
		    glEnd();
		    glFlush();
		}
	}

	glColor3f(0, 1, 0);
	for (auto x : m.fires)   //draw fires
	{
		if (x.visible)
		{
		    glBegin(GL_QUADS);
			    glVertex2f(x.getLeft() / 100, x.getTop() / 100);
			    glVertex2f(x.getLeft() / 100, x.getBottom() / 100);
			    glVertex2f(x.getRight() / 100, x.getTop() / 100);
			    glVertex2f(x.getRight() / 100, x.getBottom() / 100);
		    glEnd();
		    glFlush();
		}
	}

	glColor3f(0, 0, 1);
	auto & x = m.mainPlane;
	glBegin(GL_TRIANGLES);
		glVertex2f(x.getLeft() / 100, x.getBottom() / 100);
		glVertex2f(x.getRight() / 100, x.getBottom() / 100);
		glVertex2f((x.getLeft() + x.getRight()) / 200, x.getTop() / 100);
	glEnd();
	glFlush();

	glutSwapBuffers(); 
}

