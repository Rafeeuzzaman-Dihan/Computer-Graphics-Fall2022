#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 's':
    speed = 0.0f;
    break;
case 'w':
    speed += 0.1f;
    break;


glutPostRedisplay();


	}
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();


            //sky
            glBegin(GL_QUADS);
            glColor3ub(188,98,98);
            glVertex2f(-1.000f, 1.000f);
            glVertex2f(-1.000f, -0.500f);
            glVertex2f(1.000f, -0.500f);
            glVertex2f(1.000f, 1.000f);
            glEnd();

            //Water
            glBegin(GL_QUADS);
            glColor3ub(135,187,242);
            glVertex2f(1.000f, -1.000f);
            glVertex2f(1.000f, -0.500f);
            glVertex2f(-1.000f, -0.500f);
            glVertex2f(-1.000f, -1.000f);
            glEnd();

            //Boat
            glPushMatrix();
            glTranslatef(position,0.0f, 0.0f);

            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(0.402f, -0.361f);
            glVertex2f(-0.440f, -0.369f);
            glVertex2f(-0.440f, -0.523f);
            glVertex2f(0.404f, -0.515f);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(-0.247f, -0.381f);
            glVertex2f(-0.247f, -0.33f);
            glVertex2f(0.233f, -0.326f);
            glVertex2f(0.233f, -0.401f);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(-0.204f, -0.334f);
            glVertex2f(-0.204f, -0.223f);
            glVertex2f(-0.180f, -0.219f);
            glVertex2f(-0.178f, -0.361f);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(-0.091f, -0.365f);
            glVertex2f(-0.091f, -0.215f);
            glVertex2f(-0.064f, -0.215f);
            glVertex2f(-0.062f, -0.381f);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(0.053f, -0.369f);
            glVertex2f(0.051f, -0.219f);
            glVertex2f(0.027f, -0.219f);
            glVertex2f(0.029f, -0.393f);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex2f(0.160f, -0.377f);
            glVertex2f(0.136f, -0.385f);
            glVertex2f(0.136f, -0.219f);
            glVertex2f(0.158f, -0.219f);
            glEnd();

            glPopMatrix();
            glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1240.0, 0.0, 697.5);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1240, 697.5);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
