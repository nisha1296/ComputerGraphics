#include<GL/glut.h>
GLfloat v[3][2]={{0,0},{250,500},{500,0}};
int n=2,j;
void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
  glBegin(GL_TRIANGLES);
  glColor3f(0,1,0);
  glVertex2fv(a);
  glColor3f(0,0,1);
  glVertex2fv(b);
  glColor3f(0,0,1);
  glVertex2fv(c);
  glEnd();
}    
void divide_triangle(GLfloat *a,GLfloat *b,GLfloat *c,int m)
{
  GLfloat ab[2],ac[2],bc[2];
  if(m>0)
  {
    for(j=0;j<2;j++)
    {
      ab[j]=(a[j]+b[j])/2;
      ac[j]=(a[j]+c[j])/2;
      bc[j]=(b[j]+c[j])/2;
    }
    divide_triangle(a,ab,ac,m-1);
    divide_triangle(b,ab,bc,m-1);
    divide_triangle(c,ac,bc,m-1);
  }
  else
    triangle(a,b,c);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  divide_triangle(v[0],v[1],v[2],n);
  glEnd();
  glFlush();
}

void myinit()
{
  glClearColor(1,1,1,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("2D-Recursive Gasket");
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
}  
