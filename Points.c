#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glext.h>
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  glColor3f(0,1,0);
  glVertex2i(250,280);
  glColor3f(0,0,1);
  glVertex2i(350,250);
  glEnd();
  glFlush();
}

void myinit()
{
  glClearColor(1,0,0,1);
  gluOrtho2D(0,500,0,500);
  glPointSize(10);
}

void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutCreateWindow("Points_Display");
  glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
  glutInitWindowPosition(0,0);
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}      
