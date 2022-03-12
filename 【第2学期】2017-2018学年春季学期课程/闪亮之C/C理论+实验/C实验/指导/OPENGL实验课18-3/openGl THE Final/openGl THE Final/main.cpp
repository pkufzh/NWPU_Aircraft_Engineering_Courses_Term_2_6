#ifdef __APPLE__
#include <GLUT/glut.h>

#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "stdio.h"
#include<windows.h>
void draw_star1(void);

static int slices=16;
static int stacks=16;

/* GLUT callback Handlers */
/* animation definition  */
static int angle=0,neck=0,lshoulder=0,lelbow=0,rshoulder=0,relbow=0，
           lhips=0 ,rhips=0,lfoot=0,rfoot=0,flagneck=0,flaglshoulder=0,
           flaglelbow=0,flagrshoulder=0,flagrelbow=0,flaglhips=0 ,
           flagrhips=0,flaglfoot=0,flagrfoot=0,b=0,star2=0,star1=0,s2_spin1=0,s1_spin1=0,
           a2=0,b2=0,c2=1,a1=0,b1=0,c1=1;

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
    static  double   a =0;//定义a为每次旋转的角度
    a=a+0.15;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,1);



    glPushMatrix();
        glColor3d(0,0.4,1);
        glTranslated(0.0,0.0,-6);
        glRotated(120,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(0.8,30,stacks);//地球
    glPopMatrix();


    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.0,0.0,-6);
        glRotated(60,1,2,0.0);
        glRotated(a,0,0,-5);
        glutWireTorus(0.0001,2,slices,stacks);//轨道1

    glColor3d(1,1,0);
        glScalef(0.2,0.2,0.2);
        glTranslatef(0,-10,0);
        glRotatef(s1_spin1,a1,b1,c1);
        glutSolidCube(0.5);//卫星1

    glColor3d(0,0,1);
        glTranslatef(0.04,0,0);
        glRotatef(star1,0,0,1);
        glTranslatef(0,0,0);
        glScalef(0.2,0.5,2);
        glutSolidCube(1);//卫星1的太阳能板

    glPopMatrix();


    glPushMatrix();
    glColor3d(1,1,1);
        glTranslated(0.0,0.0,-6);
        glRotated(60,1,-0.5,0.0);
        glRotated(a,0,0,-5);
        glutWireTorus(0.0001,2,slices,stacks);//轨道2

    glColor3d(1,1,0);
        glScalef(0.2,0.2,0.2);
        glTranslatef(0,-10,0);
        glRotatef(s2_spin1,a2,b2,c2);
        glutSolidCube(0.5);//卫星2

    glColor3d(0,0,1);
        glTranslatef(0.04,0,0);
        glRotatef(star2,0,0,1);
        glTranslatef(0,0,0);
        glScalef(0.2,0.5,2);
        glutSolidCube(1);//卫星2的太阳能板



    glPopMatrix();


    glPushMatrix();
    glColor3d(1,1,1);
        glTranslated(0.0,0.0,-6);
        glRotated(120,1,0,0);
        glRotated(a,0,0,-5);
        glutWireTorus(0.001,3,slices,stacks);//月球轨道


    glColor3d(0.7,0.7,0.7);
        glScalef(0.5,0.5,0.5);
        glTranslatef(0,-6,0);
        glRotatef(rhips,1,0,0);
        glutWireSphere(0.4,100,stacks);//月球

    glPopMatrix();


   glPushMatrix();
    glColor3d(0,0,0);
        glTranslated(0.0,0.0,-6);
        glScalef(5,2,5);
        glRotated(70,1,-0.5,0);
        glRotated(a*2,0,0,-5);
        glutWireTorus(0.0001,2,slices,stacks);//轨道

    glColor3d(100,100,100);
        glTranslatef(0,-6,0);
        glRotatef(rhips,1,0,0);
        glutSolidSphere(0.04,100,100);//乱轨小星星1

    glPopMatrix();

   glPushMatrix();
    glColor3d(0,0,0);
        glTranslated(0.0,0.0,-6);
        glScalef(2,5,9);
        glRotated(70,1,-0.5,0);
        glRotated(a*1.5,0,0,-5);
        glutWireTorus(0.0001,2,slices,stacks);//轨道

    glColor3d(180,180,180);
        glTranslatef(0,-6,0);
        glRotatef(rhips,1,0,0);
        glutSolidSphere(0.04,100,100);//乱轨小星星2

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
        case 'z':
            star2=(star2+8)%360;
            glutPostRedisplay();
            break;
        case 'x':
            star2=(star2-8)%360;
            glutPostRedisplay();//卫星2太阳能板姿态调整
        case 'a':
            star1=(star1+8)%360;
            glutPostRedisplay();
            break;
        case 's':
            star1=(star1-8)%360;
            glutPostRedisplay();//卫星1太阳能板姿态调整
        case 'c':
            a2=0;b2=0;c2=1;
            s2_spin1=(s2_spin1+8)%360;
            glutPostRedisplay();
            break;
        case 'v':
            a2=0;b2=0;c2=1;
            s2_spin1=(s2_spin1-8)%360;
            glutPostRedisplay();
            break;                //卫星2的第一种姿态旋转
        case 'd':
            a1=0;b1=0;c1=1;
            s1_spin1=(s1_spin1+8)%360;
            glutPostRedisplay();
            break;
        case 'f':
            a1=0;b1=0;c1=1;
            s1_spin1=(s1_spin1-8)%360;
            glutPostRedisplay();    //卫星1的第一种姿态旋转
            break;
        case 'b':
            a2=1;b2=0;c2=0;
            s2_spin1=(s2_spin1+8)%360;
            glutPostRedisplay();
            break;
        case 'n':
            a2=1;b2=0;c2=0;
            s2_spin1=(s2_spin1-8)%360;
            glutPostRedisplay();//卫星2的第二种姿态旋转
            break;
        case 'g':
            a1=1;b1=0;c1=0;
            s1_spin1=(s1_spin1+8)%360;
            glutPostRedisplay();
            break;
        case 'h':
            a1=1;b1=0;c1=0;
            s1_spin1=(s1_spin1-8)%360;
            glutPostRedisplay();//卫星1的第二种姿态旋转
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
const GLfloat mat_diffuse[]    = { 0.6f, 0.0f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    system("color 0A");
    system("mode con cols=48 lines=30");//设置窗口大小
    printf("*------------------------------------------*\n");
    printf("|          卫星轨道姿态简单模拟            |\n");
    printf("|                                          |\n");
    printf("|              西北工业大学                |\n");
    printf("|            2016301940  孙珂              |\n");
    printf("|                                          |\n");
    printf("+--按键说明--------------------------------+\n");
    printf("|   'a'/'s': 卫星1太阳能板转动（正负）     |\n");
    printf("|   'z'/'x': 卫星2太阳能板转动（正负）     |\n");
    printf("|   'd'/'f': 卫星1姿态调整1（正负）        |\n");
    printf("|   'c'/'v': 卫星2姿态调整1（正负）        |\n");
    printf("|   'g'/'h': 卫星1姿态调整2（正负）        |\n");
    printf("|   'b'/'n': 卫星2姿态调整2（正负）        |\n");
    printf("|   '+'/'-': 抽象————具体                  |\n");
    printf("|                                          |\n");
    printf("*----------------------2016.12.30.---------*\n");
    glutInit(&argc, argv);
    glutInitWindowSize(980,580);
    glutInitWindowPosition(500,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    PlaySound(TEXT("Actium - I Need You.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


    glutCreateWindow("卫星轨道姿态简单模拟");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
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
