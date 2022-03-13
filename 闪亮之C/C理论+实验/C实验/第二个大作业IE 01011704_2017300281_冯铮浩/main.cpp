#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>
#define maxp_speed 0.350    //控制行星最大公转速度宏
#define minp_speed 0.075    //控制行星最小公转速度宏
#define maxsize 2.50    //控制行星最大尺寸宏
#define minsize 0.50    //控制行星最小尺寸宏

void Rotate(); //声明控制公转函数
    //水星、金星、地球、火星、木星、土星、天王星、海王星
    //adam,hesper,earth,mars,jupiter,saturn,uranus,neptune

static double a=0.08;//定义a为基准的地球公转速度
static double b=1.00;//定义b为基准的地球尺寸

static float year=0, day=0,adamYear=0,hesperYear=0,marsYear=0,
             jupiterYear=0,saturnYear=0,uranusYear=0,
             neptuneYear=0;
    //各行星的公转周期初始化
float light_angle=0;
float light_radius=8.0;
double x=0,y=0;
double aix_x=0.0,aix_y=0.5,aix_z=0.5;
    //八大行星公转平面初始化

GLdouble angle = 100.0;

void lPosition()
{
    float y,z;
    y=light_radius*cos(light_angle);
    z=light_radius*sin(light_angle);
    float light_position[]={3.0,y,z,0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void init(void)  //界面初始化
{
    glClearColor(0.0,0.0,0.0,0.0);
    lPosition();
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void material_sun()       //封装太阳材质包，下面模块功能类似
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

//绘制各个星球并实现公转状态

void sun()                //绘制太阳
{
    glPushMatrix();
        material_sun();
        glTranslatef(-15,0,0);
        glRotatef((GLfloat) day,0.0,1.0,0.0);     //太阳自转
        glutSolidSphere(14,50,32);       //画球体
    glPopMatrix();
}

void adam()               //绘制水星
{
    glPushMatrix();
        material_adam();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) adamYear, aix_x, aix_y, aix_z);    //水星公转周期
        glTranslatef (15,0,0);
        glTranslatef (0.2,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);        //水星自转
        glTranslatef (-0.5,0,0);
        glTranslatef (0.5,0,0);
        glutSolidSphere((b*0.5),20,16);
    glPopMatrix();
}

void hesper()               //绘制金星
{
    glPushMatrix();
        material_hesper();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) hesperYear, aix_x, aix_y, aix_z);    //金星公转周期
        glTranslatef (15,0,0);
        glTranslatef (0.8,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);        //金星自转
        glTranslatef (-1,0,0);
        glTranslatef (1,0,0);
        glutSolidSphere((b*0.8),20,16);
    glPopMatrix();
}

void earth()                //绘制地球
{
    glPushMatrix();
        material_earth();
        glTranslatef (-15,0,0);
        glRotatef ((GLfloat) year, aix_x, aix_y, aix_z); //地球公转周期（基准周期）
        glTranslatef (15,0,0);
        glTranslatef (2,0,0);
        glRotatef ((GLfloat) day,0.0,1.0,0.0);          //地球自转
        glTranslatef (-2,0,0);
        glTranslatef (2,0,0);
        glutSolidSphere(b,20,16);
        material_moon();           //绘制月球，以下以同样方法绘制各行星的卫星
        glTranslatef((b*2.0),0.0,0.0);
        glutSolidSphere((b*0.3),10,10);
    glPopMatrix();
}

void mars()                 //绘制火星
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

void jupiter()              //绘制木星
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

void saturn()               //绘制土星
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

void uranus()               //绘制天王星
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

void neptune()              //绘制海王星
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

void Rotate()          //设置各行星的公转周期
{
    adamYear+=(a+0.04);
    if(adamYear>=360) adamYear-=360;

    hesperYear+=(a+0.02);
    if(hesperYear>=360) hesperYear-=360;

    year+=a;
    if(year>=360) year-=360;     //八大行星公转周期以地球为基准

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

static void display(void) //生成动画核心代码
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
        //控制绘制八大行星
    Rotate();
        //控制八大行星公转
    glutSwapBuffers();
}

void myidle()   //控制各行星环绕卫星运动
{
    day+=10.0;
    if (day>=360) day=day-360;
    glutPostRedisplay();
}

void mykeyboard(unsigned char key, int x, int y) //键盘输入输出控制
{
    switch(key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
            //按"Esc"或"q"退出动画
        case '+':
            if (a<maxp_speed) a+=0.005;
            break;
            //按"+"行星运行加速
        case '-':
            if (a>minp_speed) a-=0.005;
            break;
            //按"-"行星运行减速
        case 'W':
        case 'w':
            if (b<maxsize) b+=0.05;
            break;
            //按"W"或"w"行星尺寸增大
        case 'S':
        case 's':
            if (b>minsize) b-=0.05;
            break;
            //按"S"或"s"行星尺寸缩小
        case 'U':
        case 'u':
            aix_y-=0.01;
            aix_z+=0.01;
            break;
            //按"U"或"u"行星公转平面向内旋转
        case 'D':
        case 'd':
            aix_y+=0.01;
            aix_z-=0.01;
            break;
            //按"D"或"d"行星公转平面向外旋转
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
    system("mode con cols=46 lines=26");//设置菜单窗口大小
    //设置菜单界面
    printf("*------------------------------------------*\n");
    printf("|       太阳系八大行星运行简单模拟演示     |\n");
    printf("|                                          |\n");
    printf("|              西北工业大学                |\n");
    printf("|            2017300281 冯铮浩             |\n");
    printf("|            2017300252 陈晴               |\n");
    printf("|                                          |\n");
    printf("*----------------按键说明------------------*\n");
    printf("|                                          |\n");
    printf("|   '+'/'-': 八大行星旋转速度加快/减慢     |\n");
    printf("|                                          |\n");
    printf("|   'U'/'u': 八大行星公转平面向内旋转      |\n");
    printf("|                                          |\n");
    printf("|   'D'/'d': 八大行星公转平面向外旋转      |\n");
    printf("|                                          |\n");
    printf("|   'W'/'w': 八大行星球体尺寸变大          |\n");
    printf("|                                          |\n");
    printf("|   'S'/'s': 八大行星球体尺寸变小          |\n");
    printf("|                                          |\n");
    printf("|  背景音乐 David Hoffner-Positive Outlook |\n");
    printf("|                                          |\n");
    printf("|                请您欣赏！                |\n");
    printf("|                                          |\n");
    printf("*----------完成作品日期--2018.06.05--------*\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(980,650);//设置动画窗口尺寸
    glutInitWindowPosition(480,10);//设置动画窗口位置
    PlaySound(TEXT("David Hoffner - Positive Outlook.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//设置背景音乐
    glutCreateWindow ("行星组曲");//设置动画窗口标题
    init(); //初始化
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(myidle);
    glutKeyboardFunc(mykeyboard);

    glutMainLoop();
    return 0;
}
