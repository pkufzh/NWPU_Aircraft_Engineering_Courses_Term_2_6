#include "stdio.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

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

static void display(void)//���ɻ������Ҫ����
{
    static  double   a =0;//����aΪÿ����ת�ĽǶ�
    a=a+0.08;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�����ɫ����������Ȼ�����

    glColor3d(1,0,0);//��ͼ����ɫΪ��
//����һ��ͷ�������壩
    glPushMatrix();
        glTranslated(0,2,-7); //zֵȡ��ֵ�ſ�����ʾ
        glRotated(100,1,0,0);//��x��ת��,�Ƕ�100��������ԭ��
        glutSolidCube(1.3);//˧����ͷ
    glPopMatrix();

    glColor3d(1,1,1);//��ͼ����ɫΪ����ɫ
//����һ�����۾���Բ��
    glPushMatrix();
        glTranslated(0.3,1.7,-5); //zֵȡ��ֵ�ſ�����ʾ
        glRotated(60,1,0,0);//��x��ת��,�Ƕ�60��������ԭ��
        glRotated(a,0,0,1);//��z����ת,ÿ�ε���displayʱ�Ƕ�a��ֵ��������0.08��ʵ������ת��
        glutSolidSphere(0.08,slices,stacks);//��Բ��뾶��0.08����������γ�����ֱ�Ϊ16
    glPopMatrix();

 glColor3d(1,1,1);//��ͼ����ɫΪ��ɫ
//����һ�����۾���Բ��
    glPushMatrix();
        glTranslated(-0.3,1.7,-5); //zֵȡ��ֵ�ſ�����ʾ
        glRotated(60,1,0,0);//��x��ת��,�Ƕ�60��������ԭ��
        glRotated(a,0,0,1);//��z����ת,ÿ�ε���displayʱ�Ƕ�a��ֵ��������0.08��ʵ������ת��
        glutSolidSphere(0.08,slices,stacks);//��Բ��뾶��0.08����������γ�����ֱ�Ϊ16
    glPopMatrix();

    glColor3d(1,0,1);//��ͼ����ɫΪ����ɫ
//����һ�����ӣ�Բ׶�壩
    glPushMatrix();
        glTranslated(0,1.5,-5);//�������������������ƶ�1.6
        glRotated(60,1,0,0);//��x��ת��,�Ƕ�60
        glRotated(a,0,0,1);//��z����ת, �Ƕ�a��������ԭ��
        glutSolidCone(0.15,0.15,slices,stacks);
    glPopMatrix();

    glColor3d(0,1,1);//��ͼ����ɫΪ����ɫ
//����һ����ͣ���ת���Բ����
    glPushMatrix();
        glTranslated(0,1.4,-6);
        glRotated(80,1,0,0);//��y��ת��80��
        glutSolidTorus(0.08,0.30,slices,stacks);
    glPopMatrix();

    glColor3d(0,1,1);//��ͼ����ɫΪ����ɫ
//����һ������1
    glPushMatrix();
        glTranslated(0,0.9,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(0.5);//glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    glPopMatrix();

glColor3d(0,1,1);//��ͼ����ɫΪ����ɫ
//����һ������
    glPushMatrix();
        glTranslated(0,0.1,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(1.5);
    glPopMatrix();

//��������
    {
        int i;
        double x;
    for(i=1,x=-1;i<=6;i++,x-=0.15){
        glColor3d(0,1,1);//ˮƽ�ֱ�
        glPushMatrix();
        glTranslated(x,0.2,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(0.3);
    glPopMatrix();
        }

    for(i=1,x=-0.1;i<=4;i++,x-=0.25){
        glColor3d(0,1,1);//��ֱ�ֱ�
        glPushMatrix();
        glTranslated(-1.75,x,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(0.3);
    glPopMatrix();
        }
    }

    //��������
    {
        int i;
        double x;
    for(i=1,x=1;i<=6;i++,x+=0.15){
        glColor3d(0,1,1);//ˮƽ�ֱ�
        glPushMatrix();
        glTranslated(x,0.2,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(0.3);
    glPopMatrix();
        }

    for(i=1,x=-0.1;i<=4;i++,x-=0.25){
        glColor3d(0,1,1);//��ֱ�ֱ�
        glPushMatrix();
        glTranslated(1.75,x,-6);
        glRotated(100,1,0,0);//��x��ת��100��
        glutSolidCube(0.3);
    glPopMatrix();
        }
    }

    glColor3d(0,1,1);
    //���
        glPushMatrix();
        glTranslated(1.75,-1.4,-6);
        glRotated(-90,0,0,1);//��z��ת��-90��
        glutSolidTeapot(0.3);
    glPopMatrix();

    glColor3d(1,0,1);//��ͼ����ɫΪ����ɫ
//����һ�����ȣ�Բ׶�壩
    glPushMatrix();
        glTranslated(-0.5,-0.7,-5);
        glRotated(90,1,0,0);//��x��ת��,�Ƕ�90
        glutSolidCone(0.2,2,slices,stacks);
    glPopMatrix();

    //����һ�����ȣ�Բ׶�壩
    glPushMatrix();
        glTranslated(0.5,-0.7,-5);
        glRotated(90,1,0,0);//��x��ת��,�Ƕ�90
        glutSolidCone(0.2,2,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)//���̻ص�����
{
    switch (key)
    {
        case 27 ://Esc����ASCIIֵΪ27
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

    glutPostRedisplay();//��ǵ�ǰ������Ҫ���»���
}

static void idle(void)//���лص�����
{
    glutPostRedisplay();//��ǵ�ǰ������Ҫ���»���
}
//����һ��Ĭ�ϵĹ�Դ������ֵ��ʹ����������Ź�Դ����ɫֵ
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };//��Դ�л��������ɫ����ɫ�����ĸ�����1.0��ʾ��͸����
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };//��Դ����������ɫ����ɫ
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//��Դ�о��淴������ɫ
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };//�����Դ��ָ���˹�Դ�ķ���
//�����������ֵ��ʹ����������Ų��ʵ���ɫֵ
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f }; //���ʵĻ�����ɫ
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  //���ʵ��������ɫ
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };//���ʾ��淴������ɫ
const GLfloat high_shininess[] = { 100.0f };//���ʵľ��淴��ָ��

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);//���ڴ�С
    glutInitWindowPosition(10,10);//����λ��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,1,1,1);//����������0��1�Ķ�
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);//����0�Ź�Դ
    glEnable(GL_NORMALIZE);// �����Զ���λ��������
    glEnable(GL_COLOR_MATERIAL);//���ò�����ɫ
    glEnable(GL_LIGHTING);//���ù���

//����0�Ź�Դ������ֵ
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//���ò��ʵ�����ֵ,����ֻ����������ǰ��Ĳ���ֵ
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
