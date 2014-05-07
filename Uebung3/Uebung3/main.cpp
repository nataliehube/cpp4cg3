#include "stdafx.h"
#include "GL/freeglut.h"


static int wwidth = 640;
static int wheight = 480;


void renderScene(void) {
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();

// Triangle
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();


	// make it appear (before this, it's hidden in the rear buffer)
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {

	w = wwidth / 2;
	h = wheight / 2;
	
	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'y'){
		exit(0);
	}

}

//init GLUT create Window
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	// Note: glutSetOption is only available with freeglut
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(wwidth, wheight);
	glutCreateWindow("cpp4g3-Window");

	// register CALLBACKS --------------------------
	glutDisplayFunc(renderScene);
	//Window resize
	glutReshapeFunc(reshape);

	//----------------------------------------------

	glutKeyboardFunc(keyboard);

	// enter GLUT event processing cycle
	glutMainLoop();


	return 1;
}