#include <iostream>
//#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

bool dato=false;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int w=1000,h=500;
int xi=0,yi=0,xf=0,yf=0;

void Pintar_Pixel(int ix,int iy)
{
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	glVertex2f(ix,iy);
	glEnd();
	glutSwapBuffers();
}
void DDA(int x0,int y0,int x1,int y1)
{
	float ax, ay, x, y, residuo;
	int dx, dy;
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	if(dx>=dy)
	{
		residuo=dx;
	}
	else{
		residuo=dy;
	}
	ax=(x1-x0)/residuo;
	ay=(y1-y0)/residuo;
	x=(float)x0;
	y=(float)y0;
	
	for(int i=0;i<=residuo;i++)
	{
		Pintar_Pixel(roundf(x),round(y));
		x=x+ax;
		y=y+ay;
	}
}
void mause(int btn,int state,int x, int y)
{
	if(dato==false)
	{
		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
		xi=x;
		yi=y;
		Pintar_Pixel(xi,yi);	
		dato=true;
		}
	}
	else{
		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
		xf=x;
		yf=y;
		Pintar_Pixel(xf,yf);	
		dato=false;
		DDA(xi,yi,xf,yf);
		}
	}
	
	

	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}
void IniciarProyeccion()
{
	glClearColor(1.0,1.0,1.0,1.0);
	
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,500.0,0.0);
	
	
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Algoritmo DDA");
	glutDisplayFunc(display);
	IniciarProyeccion();
	glutMouseFunc(mause);
	glutMainLoop();
	return 0;
	
}
