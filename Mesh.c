#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

#define maxx 20
#define maxy 25
#define dx 15
#define dy 10

GLfloat x[maxx]={0.0},y[maxy]={0.0},x0=50,y10=50;

void display()
{
  int i,j;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  for(i=0;i<maxx;i++)
    x[i]=x0+i*dx;
  for(j=0;j<maxy;j++)
    y[j]=y10+j*dy;
  for(i=0;i<maxx-1;i++)
  {
    for(j=0;j<maxy-1;j++)
    {
      glColor3f(0,1,0);
      glBegin(GL_LINE_LOOP);
      glVertex2f(x[i],y[j]);
      glVertex2f(x[i],y[j+1]);
      glVertex2f(x[i+1],y[j+1]);
      glVertex2f(x[i+1],y[j]);
      glEnd();
    }
  }
  glFlush();
}

void myinit()
{
  glClearColor(0,0,1,1);
  gluOrtho2D(0,500,0,500);
}

void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutCreateWindow("Mesh");
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}  
              
