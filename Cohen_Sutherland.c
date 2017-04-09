#include<stdlib.h>
#include<GL/glut.h>
#define outcode int
 
double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
const int RIGHT=8;
const int LEFT=2;
const int TOP=4;
const int BOTTOM=1;

outcode computeoutcode(double x,double y)
{
  outcode code=0;
  if(y>ymax)
    code |=TOP;
  if(y<ymin)
  code |=BOTTOM;
  if(x>xmax)
    code |=RIGHT;
  if(x<xmin)
    code |=LEFT;
  return code;
}

void cohensu(double x0,double y0,double x1,double y1)
{
  outcode outcode0,outcode1,outcodeout;
  int accept=0,done=0;
  outcode0=computeoutcode(x0,y0);
  outcode1=computeoutcode(x1,y1);
  do
  {
    if(!(outcode0 | outcode1))
    {
      accept=1;
      done=1;
    }
    else if(outcode0 & outcode1)
      done=1;
    else
    {
      double x,y;
      outcodeout=outcode0?outcode0:outcode1;
      if(outcodeout & TOP)
      {
        x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
        y=ymax;
      }
      else if(outcodeout & BOTTOM)
      {
        x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
        y=ymin;
      }
      else if(outcodeout & RIGHT)
      {
        y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
        x=xmax;
      }
      else if(outcodeout & LEFT)
      {
        y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
        x=xmin;
      }
      if(outcodeout == outcode0)
      {
        x0=x;
        y0=y;
        outcode0=computeoutcode(x0,y0);
      }
      else
      {
        x1=x;
        y1=y;
        outcode1=computeoutcode(x1,y1);
      }  
    }
  }while(!done);
  if(accept)
  {
    double sx=(xvmax-xvmin)/(xmax-xmin);
    double sy=(yvmax-yvmin)/(ymax-ymin);
    double vx0=xvmin+(x0-xmin)*sx;
    double vy0=yvmin+(y0-ymin)*sy;
    double vx1=xvmin+(x1-xmin)*sx;
    double vy1=yvmin+(y1-ymin)*sy;
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xvmin,yvmin);
    glVertex2f(xvmax,yvmin);
    glVertex2f(xvmax,yvmax);
    glVertex2f(xvmin,yvmax);
    glEnd();
    glColor3f(0.1,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(vx0,vy0);
    glVertex2f(vx1,vy1);
    glEnd();
  }
}

void display()
{
  double x0=60,y0=20,x1=80,y1=120;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.1,0.2,1.0); 
  glBegin(GL_LINES);
  glVertex2f(x0,y0);
  glVertex2f(x1,y1);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex2d(xmin,ymin);
  glVertex2d(xmax,ymin);
  glVertex2d(xmax,ymax);
  glVertex2d(xmin,ymax);
  glEnd();
  cohensu(x0,y0,x1,y1);
  glFlush();
}

void myinit()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,499.0,0.0,499.0);
  glutPostRedisplay();
}

int main(int argc,char ** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("COHEN SUTHERLAND");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}
