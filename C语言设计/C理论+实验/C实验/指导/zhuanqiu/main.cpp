#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


static int slices = 16;//画二次曲面的经线数
static int stacks = 16;//画二次曲面的维线数

/* GLUT callback Handlers */

static void resize(int width, int height)//再整形回调函数
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);//利用函数glViewport定义视区
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);//利用函数glFrustum定义修剪区

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)//显示回调函数
{
    static  double  a=0;//定义a为每次旋转的角度
    a=a+0.4;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除颜色缓冲区和深度缓冲区
    glColor3d(1,0,0);//画图的颜色为红
//绘制一个实心球
    glPushMatrix();
        glTranslated(0,0,-6); //x中为0,y值为0,z为-6.z值取负值才可以显示
        glRotated(60,1,0,0);//绕x轴旋转, 角度60
        glRotated(a,0,0,1);//绕z轴旋转, 角度a
        glutSolidSphere(1,slices,stacks);//圆球半径是1
    glPopMatrix();

//绘制一个实心圆锥体
    glPushMatrix();//将当前矩阵压入堆栈；
        glTranslated(0,1.5,-7);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);//glutSolidCone(GLdouble radius， GLdouble height,  GLint slices,  GLint stacks)
    glPopMatrix();//将栈顶矩阵弹出来，恢复当前矩阵到原来的状态

 glColor3d(0,1,0);//画图的颜色为绿色
//绘制一个线框圆环
    glPushMatrix();
        glTranslated(0,0,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.5,1.8,slices,stacks);//glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)//键盘回调函数
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

    glutPostRedisplay();//标记当前窗口重新绘制，即调用display函数
}

static void idle(void)//空闲回调函数
{
    glutPostRedisplay();//标记当前窗口重新绘制,即调用display函数
}
//用数组来存放默认光源的颜色值
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };//光源中环境光的颜色，黑色。红，绿，蓝，第四个分量1.0表示不透明。
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };//光源中漫射光的颜色，白色
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//光源中镜面反射光的颜色，白色
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };//定向光源，指定了光源的方向
//用数组来存放材质的颜色值
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f }; //材质的环境颜色
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  //材质的漫射光颜色
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };//材质镜面反射光的颜色
const GLfloat high_shininess[] = { 100.0f };//材质的镜面反射指数

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);//设置窗口大小
    glutInitWindowPosition(10,10);//设置窗口位置
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//设置初始显示模式

    glutCreateWindow("zhuanqiu");//根据前面设置的创建窗口，参数被作为窗口的标题。

    glutReshapeFunc(resize);//注册当前窗口的再整形回调函数
    glutDisplayFunc(display);//注册当前窗口的显示回调函数
    glutKeyboardFunc(key);//注册当前窗口的键盘回调函数
    glutIdleFunc(idle);//注册空闲回调函数


    glClearColor(0,0,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);//启用0号光源
    glEnable(GL_NORMALIZE);// 启用自动单位化法向量
    glEnable(GL_COLOR_MATERIAL);//启用材质颜色
    glEnable(GL_LIGHTING);//启用光照

//设置0号光源
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//设置材质
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();//启动glut程序进入事件循环。

    return EXIT_SUCCESS;
}
