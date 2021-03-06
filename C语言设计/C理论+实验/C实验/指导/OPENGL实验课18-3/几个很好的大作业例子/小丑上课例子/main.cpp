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

static void display(void)//该函数的内容课改动
{
    static  double   a =0;//定义a为每次旋转的角度
    a=a+0.08;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除颜色缓冲区和深度缓冲区
    glColor3d(1,0,0);//画图的颜色为红
//绘制一个实心球，默认原点在屏幕中心与照相机重合
    glPushMatrix();
        glTranslated(0,0,-7); //x中为0,y值为0,z为-7，z值取负值才可以显示
        glRotated(60,1,0,0);//绕x轴转动,角度60，不动点原点
        glRotated(a,0,0,1);//绕z轴旋转,每次调用display时角度a的值都增加了0.08，实现了旋转。
        glutSolidSphere(1,slices,stacks);//画圆球半径是1，经度数，纬度数分别为16
    glPopMatrix();
     glColor3d(1,1,1);//画图的颜色为蓝绿色
    //绘制一个实心球，默认原点在屏幕中心与照相机重合
    glPushMatrix();
        glTranslated(0.5,0.5,-5); //x中为0.5,y值为0.5,z为-5，z值取负值才可以显示
        glRotated(60,1,0,0);//绕x轴转动,角度60，不动点原点
        glRotated(a,0,0,1);//绕z轴旋转,每次调用display时角度a的值都增加了0.08，实现了旋转。
        glutSolidSphere(0.15,slices,stacks);//画圆球半径是1，经度数，纬度数分别为16
    glPopMatrix();
//绘制一个实心圆锥体，默认原点在屏幕中心与照相机重合
 glColor3d(1,1,1);//画图的颜色为蓝绿色
//绘制一个实心球，默认原点在屏幕中心与照相机重合
    glPushMatrix();
        glTranslated(-0.5,0.5,-5); //x中为-0.5,y值为0.5,z为-5，z值取负值才可以显示
        glRotated(60,1,0,0);//绕x轴转动,角度60，不动点原点
        glRotated(a,0,0,1);//绕z轴旋转,每次调用display时角度a的值都增加了0.08，实现了旋转。
        glutSolidSphere(0.15,slices,stacks);//画圆球半径是1，经度数，纬度数分别为16
    glPopMatrix();
//绘制一个实心圆锥体，默认原点在屏幕中心与照相机重合
 glColor3d(1,0,1);//画图的颜色为红蓝色
//绘制一个实心圆锥体，默认原点在屏幕中心与照相机重合
    glPushMatrix();
        glTranslated(0,0,-5);//相对照相机将对象向上移动，向照相机前方移动5
        glRotated(60,1,0,0);//绕x轴转动,角度60
        glRotated(a,0,0,1);//绕z轴旋转, 角度a，不动点原点
        glutSolidCone(0.3,0.3,slices,stacks);//glutSolidCone(GLdouble radius， GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();

 glColor3d(0,1,1);//画图的颜色为蓝绿色
//绘制一个线框圆环
    glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(60,0,1,0);//绕y轴转动60度
        glRotated(a,0,1,0);//绕y轴旋转, 角度a，不动点原点
        glutWireTorus(0.5,1.8,slices,stacks);//glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)//键盘回调函数
{
    switch (key)
    {
        case 27 ://Esc键的ASCII值为27
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

    glutPostRedisplay();//标记当前窗口需要重新绘制
}

static void idle(void)//空闲回调函数
{
    glutPostRedisplay();//标记当前窗口需要重新绘制
}
//定义一个默认的光源的属性值，使用数组来存放光源的颜色值
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };//光源中环境光的颜色，黑色，第四个分量1.0表示不透明。
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };//光源中漫射光的颜色，白色
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//光源中镜面反射光的颜色
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };//定向光源，指定了光源的方向
//定义材质属性值，使用数组来存放材质的颜色值
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f }; //材质的环境颜色
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  //材质的漫射光颜色
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };//材质镜面反射光的颜色
const GLfloat high_shininess[] = { 100.0f };//材质的镜面反射指数

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);//窗口大小
    glutInitWindowPosition(10,10);//窗口位置
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,1,1,1);//参数可以在0、1改动
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);//启用0号光源
    glEnable(GL_NORMALIZE);// 启用自动单位化法向量
    glEnable(GL_COLOR_MATERIAL);//启用材质颜色
    glEnable(GL_LIGHTING);//启用光照

//设置0号光源的特性值
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//设置材质的特性值,本题只设置了物体前面的材质值
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
