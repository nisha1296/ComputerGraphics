#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>

void myinit()
{
  glClearColor(1,1,1,0);
  glColor3f(1,0,0);

  gluOrtho2D(0,1000,0,1000);

}

void display()
{
  GLfloat v[3][2]={{0,0},{250,500},{500,0}};
  GLfloat p[2]={750,500};
  int j,k;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  for(k=0;k<5000000;k++)
  {
    j=rand()%3;
    p[0]=(p[0]+v[j][0])/2;
    p[1]=(p[1]+v[j][1])/2;
    glVertex2fv(p);
  }
  glEnd();
  glFlush();
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1000,1000);
  glutInitWindowPosition(100,100);
  glutCreateWindow("2D-Seipinski Gasket");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}  
  
      
    
