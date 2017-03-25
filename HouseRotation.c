#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLfloat house[3][9]={{250,250,300,350,350,275,275,325,325},{250,400,450,400,250,250,325,325,250},{1,1,1,1,1,1,1,1,1}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=250,k=250;
GLfloat theta,rad;

void draw_house(GLfloat h[][9])
{
  glColor3f(0,1,0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(h[0][5],h[1][5]);
  glVertex2f(h[0][6],h[1][6]);
  glVertex2f(h[0][7],h[1][7]);
  glVertex2f(h[0][8],h[1][8]);
  glEnd();
  glColor3f(1,0,0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(h[0][0],h[1][0]);
  glVertex2f(h[0][1],h[1][1]);
  glVertex2f(h[0][3],h[1][3]);
  glVertex2f(h[0][4],h[1][4]);
  glEnd();
  glColor3f(0,0,1);
  glBegin(GL_LINE_LOOP);
  glVertex2f(h[0][1],h[1][1]);
  glVertex2f(h[0][2],h[1][2]);
  glVertex2f(h[0][3],h[1][3]);                   
  glEnd();
 }
 
 void multiply()
 {
   int i,j,l;
   for(i=0;i<3;i++)
     for(j=0;j<9;j++)
     {
       result[i][j]=0;
       for(l=0;l<3;l++)
         result[i][j]+=rot_mat[i][l]*house[l][j];
     }
 }
 
 void rotate()
 {
   GLfloat m,n;
   m=-h*(cos(theta)-1)+k*(sin(theta));
   n=-k*(cos(theta)-1)-h*(sin(theta));
   rot_mat[0][0]=cos(theta);
   rot_mat[0][1]=-sin(theta);
   rot_mat[0][2]=m;
   rot_mat[1][0]=sin(theta);
   rot_mat[1][1]=cos(theta);
   rot_mat[1][2]=n;
   rot_mat[2][0]=0;
   rot_mat[2][1]=0;
   rot_mat[2][2]=1;
   multiply();
 }
 
 void display()
 {
   glClear(GL_COLOR_BUFFER_BIT);
   theta=rad;
   draw_house(house);
   rotate();
   draw_house(result);
   glEnd();
   glFlush();
 }
 
 void myinit()
 {
   glClearColor(0,0,0,1);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0,500,0,500);
   glMatrixMode(GL_MODELVIEW);
 }
 
 int main(int argc,char **argv)
 {
   glutInit(&argc,argv);
   printf("Enter the angle of rotation: ");
   scanf("%f",&theta);
   rad=theta*(3.14/180);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("House Rotation");
   glutInitWindowSize(500,500);
   glutInitWindowPosition(0,0);
   glutDisplayFunc(display);
   myinit();
   glutMainLoop();
   return 0;
 }    
              
