//#include <GL/glu.h>
//#include <GL/glut.h>
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0, 0.5);
//    glutWireIcosahedron();
//    glFlush();
//    return;
//}
//int main(int argc, char *argv[])
//{ glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//    glutInitWindowPosition(0, 0);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("My OpenGL");
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}

//#include <gl\glut.h>
//#include <gl\GLU.h>
//#include <gl\GL.h>
//#include <math.h>
//#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#define PI 3.1415926
//int WinWidth, WinHeight;
//
//// 旋转角度,初始可以随便设置
//float rotateX = 20.0f;
//float rotateY = 30.0f;
//
//void Draw()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glLoadIdentity();
//
//    // 立方体的8个顶点坐标
//    GLfloat vertex_list[][3] = {
//            -0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            -0.5f, 0.5f, -0.5f,
//            0.5f, 0.5f, -0.5f,
//            -0.5f, -0.5f, 0.5f,
//            0.5f, -0.5f, 0.5f,
//            -0.5f, 0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//    };
//
//    GLint index_list[][4] = {
//            0, 2, 3, 1,
//            0, 4, 6, 2,
//            0, 1, 5, 4,
//            4, 5, 7, 6,
//            1, 3, 7, 5,
//            2, 6, 7, 3,
//    };
//
//#if 0
//    // 只有正面，并且只显示边线，不进行填充
//	glFrontFace(GL_CCW);
//	glCullFace(GL_BACK);
//	glEnable(GL_CULL_FACE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//#endif
//
//    // 设置旋转
//    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
//    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
//
//    // 定义不同的颜色
//    GLfloat colors[][3] = { { 0.0, 0.0, 1.0 }, { 0.0, 1.0, 0.0 }, { 1.0, 0.0, 0.0 },
//                            { 1.0, 0.0, 1.0 }, { 1.0, 1.0, 0.0 }, { 0.0, 1.0, 1.0 },
//                            { 1.0, 0.5, 0.5 }, { 0.0, 0.5, 0.5 } };
//
//    int i, j;
//
//    glBegin(GL_QUADS); // 绘制四边形
//    for (i = 0; i < 6; ++i)         // 有六个面，循环六次
//    {
//        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
//        for (j = 0; j < 4; ++j)     // 每个面有四个顶点，循环四次
//        {
//            glVertex3fv(vertex_list[index_list[i][j]]);
//        }
//    }
//    glEnd();
//
//    glutSwapBuffers();
//}
//
//void Reshape(int w, int h)
//{
//    WinWidth = w;
//    WinHeight = h;
//    // //改变显示区域，起始位置为客户端窗口左下角（非坐标原点）
//    glViewport(0, 0, w, h);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    //宽高比改为当前值，视线区域与屏幕大小一致；
//    gluPerspective(45, 1.0*WinWidth / WinHeight, 1, 1000);
//    // 开启更新深度缓冲区的功能
//    glEnable(GL_DEPTH_TEST);
//    // 摄像机视图观看，从 （0，5，20） 往（0，0，0）处看，（0，1，0）为正方向
//    gluLookAt(0, 5, 20, 0, 0, 0, 0, 1, 0);
//}
//
//void SpecialKeys(int key, int x, int y)
//{
//    if (key == GLUT_KEY_UP)   rotateX -= 5.0f;
//    if (key == GLUT_KEY_DOWN)  rotateX += 5.0f;
//    if (key == GLUT_KEY_LEFT)  rotateY -= 5.0f;
//    if (key == GLUT_KEY_RIGHT)  rotateY += 5.0f;
//
//    if (rotateX > 356.0f)  rotateX = 0.0f;
//    if (rotateX < -1.0f)  rotateX = 355.0f;
//    if (rotateY > 356.0f)  rotateY = 0.0f;
//    if (rotateY < -1.0f)  rotateY = 355.0f;
//
//    //刷新窗口
//    glutPostRedisplay();
//}
//
//int main(int argc, char *argv[])
//{
//    WinWidth = 800;
//    WinHeight = 800;
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
//    //glutInitWindowPosition(100, 100);
//    glutInitWindowSize(WinWidth, WinHeight);
//    glutCreateWindow("HelloOpenGL");
//
//    /*
//    目的：当窗口尺寸改变时，图形比例不发生变化
//    思路：窗口宽高比改变时，通过改变窗口显示区域大小，并利用投影矩阵改变观测物体大小使之适应变化。
//    */
//    glutReshapeFunc(&Reshape);
//    glutDisplayFunc(&Draw);
//
//    //glutKeyboardFunc(processNormalKeys);
//    glutSpecialFunc(SpecialKeys);
//
//    glutMainLoop();
//    return 0;
//}
// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
//


#include <GL/glut.h>
#include <math.h>
#define DEG_TO_RAD 0.017453
GLfloat theta = 0.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(sin(DEG_TO_RAD*theta),-cos(DEG_TO_RAD*theta));
    glVertex2f(-cos(DEG_TO_RAD*theta),-sin(DEG_TO_RAD*theta));
    glVertex2f(-sin(DEG_TO_RAD*theta),cos(DEG_TO_RAD*theta));
    glVertex2f(cos(DEG_TO_RAD*theta),sin(DEG_TO_RAD*theta));
    glEnd();
    //flush GL  buffers
    glFlush();
}
void myidle()
{
    theta += 0.2;
    if(theta>360.0)
        theta -= 360.0;
    glutPostRedisplay();
}
void init()
{
    //set color to black
    glClearColor(0.0,0.0,0.0,0.0);
    //set fill color to white
    glColor3f(1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-1.0,1.0,-1.0,1.0);

}
int main(int argc, char *argv[])
{
    /* code */
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("hello");
    glutDisplayFunc(display);
    init();
    glutIdleFunc(myidle);
    glutMainLoop();
    return 0;
}
