#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);


	glBegin(GL_TRIANGLES); //Begin quadrilateral coordinates

	//Triangle
	glVertex3f(0.30f, 0.30f, 0.0f);
	glVertex3f(0.70f, 0.30f, 0.0f);
	glVertex3f(0.50f, 0.70f, 0.0f);

	glEnd(); //End quadrilateral coordinates

	glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Triangle");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
