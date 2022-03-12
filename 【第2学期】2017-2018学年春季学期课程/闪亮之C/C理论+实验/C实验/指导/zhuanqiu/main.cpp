#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


static int slices = 16;//����������ľ�����
static int stacks = 16;//�����������ά����

/* GLUT callback Handlers */

static void resize(int width, int height)//�����λص�����
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);//���ú���glViewport��������
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);//���ú���glFrustum�����޼���

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)//��ʾ�ص�����
{
    static  double  a=0;//����aΪÿ����ת�ĽǶ�
    a=a+0.4;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�����ɫ����������Ȼ�����
    glColor3d(1,0,0);//��ͼ����ɫΪ��
//����һ��ʵ����
    glPushMatrix();
        glTranslated(0,0,-6); //x��Ϊ0,yֵΪ0,zΪ-6.zֵȡ��ֵ�ſ�����ʾ
        glRotated(60,1,0,0);//��x����ת, �Ƕ�60
        glRotated(a,0,0,1);//��z����ת, �Ƕ�a
        glutSolidSphere(1,slices,stacks);//Բ��뾶��1
    glPopMatrix();

//����һ��ʵ��Բ׶��
    glPushMatrix();//����ǰ����ѹ���ջ��
        glTranslated(0,1.5,-7);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);//glutSolidCone(GLdouble radius�� GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();//��ջ�����󵯳������ָ���ǰ����ԭ����״̬

 glColor3d(0,1,0);//��ͼ����ɫΪ��ɫ
//����һ���߿�Բ��
    glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.5,1.8,slices,stacks);//glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)//���̻ص�����
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

    glutPostRedisplay();//��ǵ�ǰ�������»��ƣ�������display����
}

static void idle(void)//���лص�����
{
    glutPostRedisplay();//��ǵ�ǰ�������»���,������display����
}
//�����������Ĭ�Ϲ�Դ����ɫֵ
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };//��Դ�л��������ɫ����ɫ���죬�̣��������ĸ�����1.0��ʾ��͸����
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };//��Դ����������ɫ����ɫ
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//��Դ�о��淴������ɫ����ɫ
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };//�����Դ��ָ���˹�Դ�ķ���
//����������Ų��ʵ���ɫֵ
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f }; //���ʵĻ�����ɫ
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  //���ʵ��������ɫ
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };//���ʾ��淴������ɫ
const GLfloat high_shininess[] = { 100.0f };//���ʵľ��淴��ָ��

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);//���ô��ڴ�С
    glutInitWindowPosition(10,10);//���ô���λ��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//���ó�ʼ��ʾģʽ

    glutCreateWindow("zhuanqiu");//����ǰ�����õĴ������ڣ���������Ϊ���ڵı��⡣

    glutReshapeFunc(resize);//ע�ᵱǰ���ڵ������λص�����
    glutDisplayFunc(display);//ע�ᵱǰ���ڵ���ʾ�ص�����
    glutKeyboardFunc(key);//ע�ᵱǰ���ڵļ��̻ص�����
    glutIdleFunc(idle);//ע����лص�����


    glClearColor(0,0,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);//����0�Ź�Դ
    glEnable(GL_NORMALIZE);// �����Զ���λ��������
    glEnable(GL_COLOR_MATERIAL);//���ò�����ɫ
    glEnable(GL_LIGHTING);//���ù���

//����0�Ź�Դ
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//���ò���
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();//����glut��������¼�ѭ����

    return EXIT_SUCCESS;
}
