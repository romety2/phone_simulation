#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <GL/glut.h>

int okno_w;

 

void ge(int w, int h) {
  glOrtho(-20, 20, -15, 15, -5, 5);
}

void wy(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.5, 0.0);
  glLineWidth(5);


  glTranslated( 0, 5, 0);

  glBegin(GL_POLYGON);
    glVertex2f(-7, 0);
    glVertex2f( 0, 7);
    glVertex2f( 7,0);
  glEnd();
  glTranslated( 0, -5, 0);

  glTranslated( 0, 0, 5);

  glBegin(GL_POLYGON);
    glVertex2f(-8, 0);
    glVertex2f( 0,8);
    glVertex2f( 8,0);
  glEnd();
  glTranslated( 0, 0, -5);

  glTranslated( 0,-6, 0);

  glBegin(GL_POLYGON);
    glVertex2f(-10, 0);
    glVertex2f( 0, 10);
    glVertex2f( 10,0);
  glEnd();
  glTranslated( 0, -1, 0);

  glBegin(GL_POLYGON);
    glVertex2f(3, 3);
    glVertex2f( -3, 3);
    glVertex2f( -3,-3);
    glVertex2f( 3,-3);
  glEnd();
  glTranslated( 0, -6, 0);

  glFlush();


}



void choinka(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glClearColor(0.0, 1.0, 1.0, 0.0);
  glutReshapeFunc(ge);
  glutDisplayFunc(wy);
  glutMainLoop();
}

	void geo2(int w, int h)
	{
  	glMatrixMode(GL_PROJECTION); glLoadIdentity();
 	 glOrtho(-20, 20, -15, 15, -30, 30);
	}

	#define M_PI 3.14159265358979323846
	double przyrost = M_PI/20;

	void  odcinek_okregu(double prom, double kat0, double kat1)
	{
	double kat;
  	for (kat=kat0; kat<=kat1; kat+=przyrost)
    	glVertex3d(prom*cos(kat), prom*sin(kat), 0);
	}

	void  kolo()
	{
  	glColor3d(1, 0.5, 1);
  	glPushMatrix(); glTranslated(7,-3, 1.5);
   	glutSolidSphere(10, 10, 10);
  	glPopMatrix();
	}

	void wyswietl2() {
  	glClear(GL_COLOR_BUFFER_BIT);
  	glClear(GL_DEPTH_BUFFER_BIT);
  	kolo();
  	glFlush();
	}

	double kat_obrotu = M_PI/360;
	void  timer(int v) {
 	static double alfa = 0;
  	alfa += kat_obrotu;
  	if (alfa >= 2*M_PI)  alfa -= 2*M_PI;
  	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
  	gluLookAt(20*cos(alfa), 7, 20*sin(alfa),  0,0,0,  0,1,0);
  	glutPostRedisplay();
  	glutTimerFunc(1, timer, v);
	}

	void kolko(int ile_arg, char* arg[])
	{
 	glutInit(&ile_arg, arg);
  	glutInitWindowSize(200, 200);
  	glutInitWindowPosition(20, 10);
  	glutCreateWindow(arg[0]);
  	glEnable(GL_DEPTH_TEST);
  	glClearColor(1.0, 1.0, 0.0, 0.0);
  	glutReshapeFunc(geo2);
  	glutDisplayFunc(wyswietl2);
  	glutTimerFunc(15, timer, 0);
  	glutMainLoop();
	}

	GLdouble fovy = 90;
	void wyswietl()
	{
    	glClearColor( 0.75, 0.75, 0.75, 0.75 );
    	glClear( GL_COLOR_BUFFER_BIT );
    	glMatrixMode( GL_MODELVIEW );
    	glLoadIdentity();
    	glTranslatef( 0, 0, - 3.0 );
    	glColor3f( 0.0, 0.0, 0.0 );
    	glBegin( GL_LINES );
   	glVertex3f( 2.0, 2.0, 2.0 );
    	glVertex3f( 2.0, -2.0, 2.0 );
   	glVertex3f( 2.0, -2.0, 2.0 );
    	glVertex3f( 2.0, -2.0, -2.0 );
    	glVertex3f( 2.0, -2.0, -2.0 );
    	glVertex3f( 2.0, 2.0, -2.0 );
    	glVertex3f( 2.0, 2.0, -2.0 );
    	glVertex3f( 2.0, 2.0, 2.0 );
    	glVertex3f( -2.0, 2.0, 2.0 );
    	glVertex3f( -2.0, -2.0, 2.0 );
    	glVertex3f( -2.0, -2.0, 2.0 );
    	glVertex3f( -2.0, -2.0, -2.0 );
    	glVertex3f( -2.0, -2.0, -2.0 );
    	glVertex3f( -2.0, 2.0, -2.0 );
    	glVertex3f( -2.0, 2.0, -2.0 );
    	glVertex3f( -2.0, 2.0, 2.0 );
    	glVertex3f( 2.0, 2.0, 2.0 );
    	glVertex3f( -2.0, 2.0, 2.0 );
    	glVertex3f( 2.0, -2.0, 2.0 );
    	glVertex3f( -2.0, -2.0, 2.0 );
    	glVertex3f( 2.0, -2.0, -2.0 );
    	glVertex3f( -2.0, -2.0, -2.0 );
    	glVertex3f( 2.0, 2.0, -2.0 );
    	glVertex3f( -2.0, 2.0, -2.0 );
   	glEnd();
	glFlush();
    	glutSwapBuffers();
	}
	void geo( int width, int height )
	{
    	glViewport( 0, 0, width, height );
    	glMatrixMode( GL_PROJECTION );
    	glLoadIdentity();
    	GLdouble aspect = 1;
    	if( height > 0 )
    	     aspect = width /( GLdouble ) height;
    	gluPerspective( fovy, aspect, 1.0, 5.0 );
    	wyswietl();	
	}


	void szescian(int ile_arg, char* arg[])
	{
 	glutInit(&ile_arg, arg);
  	glutInitWindowSize( 400, 400 );
  	glutInitWindowPosition(20, 10);
   	glutCreateWindow(arg[0]);
    	glutDisplayFunc(wyswietl);
    	glutReshapeFunc(geo);
    	glutMainLoop();
	}
