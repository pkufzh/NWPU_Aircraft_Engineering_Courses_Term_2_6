#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
static int slices = 100;
static int stacks = 100;
static double angle=0;
static double c=0;

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
	double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	static int i=0;
    const double a = t*6.0;
    c=t-(int)(t);
    glRotatef(angle,0,0,-1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


//���Ʊ��
    glColor3d(c,1-c,0);//������򽥱�Ч��
    glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(0,1,0,0);
        glRotated(0,0,0,1);
        glutWireTorus(0.1,2,slices,stacks);//glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    glPopMatrix();
//����ָ������
    glColor3d(0,1,1);
    glPushMatrix();
        glTranslated(0,0,-6); //x��Ϊ0,yֵΪ0,zΪ-6.zֵȡ��ֵ�ſ�����ʾ
        glRotated(0,1,0,0);//��x����ת, �Ƕ�60��������ԭ��
        glRotated(0,0,0,1);//��z����ת, �Ƕ�a��������ԭ��
        glutSolidSphere(0.1,slices,stacks);//Բ��뾶��1
    glPopMatrix();
//����ʱ��
    glColor3d(0,0,1);
    glPushMatrix();//����ǰ����ѹ���ջ��
        glTranslated(0,0,-6);
        glRotated(270,1,0,0);
        glRotated(a/3600.0,0,1,0);
        glutSolidCone(0.07,1,slices,stacks);//glutSolidCone(GLdouble radius�� GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();//��ջ�����󵯳������ָ���ǰ����ԭ����״̬
//���Ʒ���
    glColor3d(1,0,0.5);
    glPushMatrix();//����ǰ����ѹ���ջ��
        glTranslated(0,0,-6);
        glRotated(270,1,0,0);
        glRotated(a/60.0,0,1,0);
        glutSolidCone(0.07,1.3,slices,stacks);//glutSolidCone(GLdouble radius�� GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();//��ջ�����󵯳������ָ���ǰ����ԭ����״̬
//��������
    glColor3d(0.5,0,1);
    glPushMatrix();//����ǰ����ѹ���ջ��
        glTranslated(0,0,-6);
        glRotated(270,1,0,0);
        glRotated(a,0,1,0);
        glutSolidCone(0.07,1.5,slices,stacks);//glutSolidCone(GLdouble radius�� GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();//��ջ�����󵯳������ָ���ǰ����ԭ����״̬

//�̶�
    glColor3f(1,0,0);
    glPushMatrix();
        glTranslated(0,1.7,-6);
        glRotated(0,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
        glTranslated(1.7,0,-6);
        glRotated(90,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.7,-6);
        glRotated(0,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.7,0,-6);
        glRotated(90,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3f(c,1,1);
    glPushMatrix();
        glTranslated(0.85,1.47,-6);
        glRotated(-30,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.47,0.85,-6);
        glRotated(-60,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.47,-0.85,-6);
        glRotated(60,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.85,-1.47,-6);
        glRotated(30,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.85,-1.47,-6);
        glRotated(-30,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.47,-0.85,-6);
        glRotated(-60,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-1.47,0.85,-6);
        glRotated(-120,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.85,1.47,-6);
        glRotated(-150,0,0,1);
        glScalef (0.07, 0.3,0);
        glutSolidCube(1);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case '1':
            angle=(angle+0.01);
            glutPostRedisplay();
            break;
        case '2':
            angle=(angle-0.01);
            glutPostRedisplay();
            break;
        case 'q':
            exit(0);
            break;

        case 'a':
            slices++;
            stacks++;
            break;

        case 'd':
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
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("ʱ��  ����1����2����ת���� ��a����d��������γ���� ��q���˳�");

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
