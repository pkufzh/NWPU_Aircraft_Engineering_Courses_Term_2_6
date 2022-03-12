#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#define maxp_speed 0.350    //�����������ת�ٶȺ�
#define minp_speed 0.075    //����������С��ת�ٶȺ�
#define maxsize 2.50    //�����������ߴ��
#define minsize 0.50    //����������С�ߴ��

void Rotate(); //�������ƹ�ת����
    //ˮ�ǡ����ǡ����򡢻��ǡ�ľ�ǡ����ǡ������ǡ�������
    //adam,hesper,earth,mars,jupiter,saturn,uranus,neptune

static double a=0.08;//����aΪ��׼�ĵ���ת�ٶ�
static double b=1.00;//����bΪ��׼�ĵ���ߴ�

static float year=0, day=0,adamYear=0,hesperYear=0,marsYear=0,
             jupiterYear=0,saturnYear=0,uranusYear=0,
             neptuneYear=0;
    //�����ǵĹ�ת���ڳ�ʼ��
float light_angle=0;
float light_radius=8.0;
double x=0,y=0;
double aix_x=0.0,aix_y=0.5,aix_z=0.5;
    //�˴����ǹ�תƽ���ʼ��

GLdouble angle = 100.0;

void lPosition()
{
    float y,z;
    y=light_radius*cos(light_angle);
    z=light_radius*sin(light_angle);
    float light_position[]={3.0,y,z,0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void init(void)  //�����ʼ��
{
    glClearColor(0.0,0.0,0.0,0.0);
    lPosition();
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void material_sun()       //��װ̫�����ʰ�������ģ�鹦������
{
    GLfloat mat_specular[]={1.0,0.0,0.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.0,0.0,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_adam()
{
    GLfloat mat_specular[]={1.0,0.0,0.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.3,1.0,0.2,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_hesper()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.0,1.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_earth()
{
    GLfloat mat_specular[]={1.0,0.0,0.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.1,0.2,0.6,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_mars()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.0,0.1,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_jupiter()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.8,0.7,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_saturn()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.6,0.6,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_uranus()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.3,0.3,0.7,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_neptune()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.0,0.1,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_moon()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.0,1.0,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_mar_satellite_1()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.0,1.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_mar_satellite_2()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.0,0.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_neptune_satellite_1()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={1.0,0.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_neptune_satellite_2()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.0,0.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_uranus_satellite_1()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.3,0.2,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_uranus_satellite_2()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.3,0.4,0.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_jupiter_satellite()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.3,0.6,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_saturn_satellite()
{
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0};
    GLfloat lmodel_ambient[]={0.3,0.6,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

//���Ƹ�������ʵ�ֹ�ת״̬

void sun()                //����̫��
{
    glPushMatrix();
        material_sun();
        glTranslatef(-15,0,0);
        glRotatef((GLfloat) day,0.0,1.0,0.0);     //̫����ת
        glutSolidSphere(14,50,32);       //������
    glPopMatrix();
}

void adam()               //����ˮ��
{
    glPushMatrix();
        material_adam();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) adamYear, aix_x, aix_y, aix_z);    //ˮ�ǹ�ת����
        glTranslatef (15,0,0);
        glTranslatef (0.2,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);        //ˮ����ת
        glTranslatef (-0.5,0,0);
        glTranslatef (0.5,0,0);
        glutSolidSphere((b*0.5),20,16);
    glPopMatrix();
}

void hesper()               //���ƽ���
{
    glPushMatrix();
        material_hesper();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) hesperYear, aix_x, aix_y, aix_z);    //���ǹ�ת����
        glTranslatef (15,0,0);
        glTranslatef (0.8,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);        //������ת
        glTranslatef (-1,0,0);
        glTranslatef (1,0,0);
        glutSolidSphere((b*0.8),20,16);
    glPopMatrix();
}

void earth()                //���Ƶ���
{
    glPushMatrix();
        material_earth();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) year, aix_x, aix_y, aix_z); //����ת���ڣ���׼���ڣ�
        glTranslatef (15,0,0);
        glTranslatef (2,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);          //������ת
        glTranslatef (-2,0,0);
        glTranslatef (2,0,0);
        glutSolidSphere(b,20,16);
        material_moon();           //��������������ͬ���������Ƹ����ǵ�����
        glTranslatef((b*2.0),0.0,0.0);
        glutSolidSphere((b*0.3),10,10);
    glPopMatrix();
}

void mars()                 //���ƻ���
{
    glPushMatrix();
        material_mars();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) marsYear, aix_x, aix_y, aix_z);
        glTranslatef (15,0,0);
        glTranslatef (7,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);
        glTranslatef (-7,0,0);
        glTranslatef (7,0,0);
        glutSolidSphere((b*0.6),20,16);
    glPushMatrix();
        material_mar_satellite_1();
        glTranslatef((b*1.0),0.0,0.0);
        glutSolidSphere((b*0.1),10,10);
    glPopMatrix();
    glPushMatrix();
        material_mar_satellite_2();
        glTranslatef((b*1.5),0.0,0.0);
        glutSolidSphere((b*0.2),10,10);
    glPopMatrix();
    glPopMatrix();
}

void jupiter()              //����ľ��
{
    glPushMatrix();
        material_jupiter();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) jupiterYear, aix_x, aix_y, aix_z);
        glTranslatef (15,0,0);
        glTranslatef (13,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);
        glTranslatef (-13,0,0);
        glTranslatef (13,0,0);
        glutSolidSphere((b*2.0),20,16);
    glPushMatrix();
        glRotatef(90,1.0,0,0.0);
        glutSolidTorus((b*0.25),(b*5.0),5,64);
        glRotatef(-90,1.0,0,0.0);
        material_jupiter_satellite();
        glRotatef(90,1.0,0,0.0);
        glTranslatef((b*3.0),0.0,0.0);
        glutSolidSphere((b*0.6),10,10);
    glPopMatrix();
    glPopMatrix();
}

void saturn()               //��������
{
    glPushMatrix();
        material_saturn();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) saturnYear, aix_x, aix_y, aix_z);
        glTranslatef (15,0,0);
        glTranslatef (20,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);
        glTranslatef (-20,0,0);
        glTranslatef (20,0,0);
        glRotatef (0.3,1.0,0.0,0.0);
        glutSolidSphere((b*1.4),20,16);
    glPushMatrix();
        glRotatef(90,1.0,0,0.0);
        glutSolidTorus((b*0.1),(b*3.0),5,64);
        glRotatef(-90,1.0,0,0.0);
        material_saturn_satellite();
        glTranslatef((b*2.7),0.0,0.0);
        glutSolidSphere((b*0.4),10,10);
    glPopMatrix();
    glPopMatrix();
}

void uranus()               //����������
{
    glPushMatrix();
        material_uranus();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) uranusYear, aix_x, aix_y, aix_z);
        glTranslatef (15,0,0);
        glTranslatef (28,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);
        glTranslatef (-28,0,0);
        glTranslatef (28,0,0);
        glRotatef (0.5,1.0,0.0,0.0);
        glutSolidSphere((b*1.5),20,16);
    glPushMatrix();
        glRotatef(90,1.0,0,0.0);
        glutSolidTorus((b*0.1),(b*3.0),5,64);
        glRotatef(-90,1.0,0,0.0);
    glPushMatrix();
        material_uranus_satellite_1();
        glTranslatef((b*2.0),0.0,0.0);
        glutSolidSphere((b*0.23),10,10);
    glPopMatrix();
    glPushMatrix();
        material_uranus_satellite_2();
        glTranslatef((b*3.5),0.0,0.0);
        glutSolidSphere((b*0.35),10,10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void neptune()              //���ƺ�����
{
    glPushMatrix();
        material_neptune();
        glTranslatef(-15,0,0);
        glRotatef ((GLfloat) neptuneYear, aix_x, aix_y, aix_z);
        glTranslatef (15,0,0);
        glTranslatef (32,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);
        glTranslatef (-32,0,0);
        glTranslatef (32,0,0);
        glRotatef (0.5,1.0,0.0,0.0);
        glutSolidSphere((b*1.3),20,16);
    glPushMatrix();
        glRotatef(90,1.0,0,0.0);
        glutSolidTorus(0.1,(b*3.0),5,64);
        glRotatef(-90,1.0,0,0.0);
    glPushMatrix();
        material_neptune_satellite_1();
        glTranslatef((b*2.5),0.0,0.0);
        glutSolidSphere((b*0.35),10,10);
    glPopMatrix();
    glPushMatrix();
        material_neptune_satellite_2();
        glTranslatef((b*3.5),0.0,0.0);
        glutSolidSphere((b*0.3),10,10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Rotate()          //���ø����ǵĹ�ת����
{
    adamYear+=(a+0.04);
    if(adamYear>=360) adamYear-=360;

    hesperYear+=(a+0.02);
    if(hesperYear>=360) hesperYear-=360;

    year+=a;
    if(year>=360) year-=360;     //�˴����ǹ�ת�����Ե���Ϊ��׼

    marsYear+=(a-0.02);
    if(marsYear>=360) marsYear-=360;

    jupiterYear+=(a-0.03);
    if(jupiterYear>=360) jupiterYear-=360;

    saturnYear+=(a-0.04);
    if(saturnYear>=360) saturnYear-=360;

    uranusYear+=(a-0.05);
    if(uranusYear>=360) uranusYear-=360;

    neptuneYear+=(a-0.07);
    if(neptuneYear>=360) neptuneYear-=360;

    glutPostRedisplay();
}

static void display(void) //���ɶ������Ĵ���
{
    lPosition();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    sun();
    adam();
    hesper();
    earth();
    mars();
    jupiter();
    saturn();
    uranus();
    neptune();
        //���ƻ��ư˴�����
    Rotate();
        //���ư˴����ǹ�ת
    glutSwapBuffers();
}

void myidle()   //���Ƹ����ǻ��������˶�
{
    day+=10.0;
    if (day>=360) day=day-360;
    glutPostRedisplay();
}

void mykeyboard(unsigned char key, int x, int y) //���������������
{
    switch(key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
            //��"Esc"��"q"�˳�����
        case '+':
            if (a<maxp_speed) a+=0.005;
            break;
            //��"+"�������м���
        case '-':
            if (a>minp_speed) a-=0.005;
            break;
            //��"-"�������м���
        case 'W':
        case 'w':
            if (b<maxsize) b+=0.05;
            break;
            //��"W"��"w"���ǳߴ�����
        case 'S':
        case 's':
            if (b>minsize) b-=0.05;
            break;
            //��"S"��"s"���ǳߴ���С
        case 'U':
        case 'u':
            aix_y-=0.01;
            aix_z+=0.01;
            break;
            //��"U"��"u"���ǹ�תƽ��������ת
        case 'D':
        case 'd':
            aix_y+=0.01;
            aix_z-=0.01;
            break;
            //��"D"��"d"���ǹ�תƽ��������ת
    }
    glutPostRedisplay();
}

void reshape (int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle,(GLfloat)w/(GLfloat)h,1.0,200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-50.0);
}

int main(int argc, char **argv)
{
    system("color 0A");
    system("mode con cols=46 lines=26");//���ò˵����ڴ�С
    //���ò˵�����
    printf("*------------------------------------------*\n");
    printf("|       ̫��ϵ�˴��������м�ģ����ʾ     |\n");
    printf("|                                          |\n");
    printf("|              ������ҵ��ѧ                |\n");
    printf("|            2017300281 ���             |\n");
    printf("|            2017300252 ����               |\n");
    printf("|                                          |\n");
    printf("*----------------����˵��------------------*\n");
    printf("|                                          |\n");
    printf("|   '+'/'-': �˴�������ת�ٶȼӿ�/����     |\n");
    printf("|                                          |\n");
    printf("|   'U'/'u': �˴����ǹ�תƽ��������ת      |\n");
    printf("|                                          |\n");
    printf("|   'D'/'d': �˴����ǹ�תƽ��������ת      |\n");
    printf("|                                          |\n");
    printf("|   'W'/'w': �˴���������ߴ���          |\n");
    printf("|                                          |\n");
    printf("|   'S'/'s': �˴���������ߴ��С          |\n");
    printf("|                                          |\n");
    printf("|  �������� David Hoffner-Positive Outlook |\n");
    printf("|                                          |\n");
    printf("|                �������ͣ�                |\n");
    printf("|                                          |\n");
    printf("*----------�����Ʒ����--2018.06.05--------*\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(980,650);//���ö������ڳߴ�
    glutInitWindowPosition(480,10);//���ö�������λ��
    PlaySound(TEXT("David Hoffner - Positive Outlook.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//���ñ�������
    glutCreateWindow ("��������");//���ö������ڱ���
    init(); //��ʼ��
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(myidle);
    glutKeyboardFunc(mykeyboard);

    glutMainLoop();
    return 0;
}
