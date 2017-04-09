#include<GL/glut.h>
#include<stdio.h>
int n;

GLfloat v[4][3]={{0,0,1},{0,1,-1},{-1,-1,-1},{1,-1,-1}};

void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
  glVertex3fv(a);
  glColor3f(0,1,0);
  glVertex3fv(b);
  glColor3f(0,0,1);
  glVertex3fv(c);

}  
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{

  triangle(b,c,d);
  triangle(a,c,d);
  triangle(b,a,d);
  triangle(b,c,a);
}

 void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
 {
   int j;
   GLfloat mid[6][3];
   if(m>0)
   {
     for(j=0;j<3;j++)
     {
       mid[0][j]=(a[j]+b[j])/2;
       mid[1][j]=(b[j]+d[j])/2;
       mid[2][j]=(a[j]+d[j])/2;
       mid[3][j]=(a[j]+c[j])/2;
       mid[4][j]=(d[j]+c[j])/2;
       mid[5][j]=(b[j]+c[j])/2;
     }
     divide_tetra(a,mid[3],mid[0],mid[2],m-1);
     divide_tetra(b,mid[5],mid[0],mid[1],m-1);
     divide_tetra(c,mid[4],mid[3],mid[5],m-1);
     divide_tetra(d,mid[1],mid[2],mid[4],m-1);
   }
   else
     tetra(a,b,c,d);
 }
 
 void display()
 {
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_TRIANGLES);
   divide_tetra(v[0],v[1],v[2],v[3],n);
   glEnd();
   glFlush();
 }
 
 void myinit()
 {
   glClearColor(1,1,1,1);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2,1,-2,1,-2,1);
   glMatrixMode(GL_MODELVIEW);
 }
 
 int main(int argc,char **argv)
 {
   printf("Enter the value: \n");
   scanf("%d",&n);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE);
   glutCreateWindow("Basic");
   glutInitWindowSize(1000,1000);
   glutInitWindowPosition(0,0);
   glutDisplayFunc(display);
   myinit();
   glutMainLoop();
   return 0;
 }                 

