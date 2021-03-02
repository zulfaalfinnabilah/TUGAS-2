#include <GL\glut.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


void init();
void display(void);
void lingkaran(void);


int window_x;
int window_y;

int xcIn,xc,ycIn,yc,rIn,r;


int window_width = 480;
int window_height = 480;


char *judul_window = "Lingkaran Midpoint";

int main(int argc, char **argv)
{
    ulangi:cout<<"Masukkan nilai Jari2(r) : ";cin>>rIn;
    if(rIn<=0){
        cout<<"\nCaution . . . !\nNilai R harus R > 0\n";
        goto ulangi;
    }
    awal:cout<<"\nMasukkan nilai Xc : ";cin>>xcIn;
    cout<<"Masukkan nilai Yc : ";cin>>ycIn;
    if((xcIn >= rIn) && (ycIn >= rIn)){
        r = rIn;
        xc = xcIn;
        yc = ycIn;
    }else{
        cout<<"\nCaution . . . !\nNilai harus Xc > r dan Yc > r\n";
        goto awal;
    }
    cout<<endl;


	glutInit(&argc, argv);


	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(judul_window);

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	lingkaran();
	glutSwapBuffers();
}

void lingkaran(void) {



	int p = 1-r;
	int x = 0;
	int y = r;

	glBegin(GL_POINTS);

	glVertex2i(xc,yc);
	while (x <= y) {
		if (p < 0) {
			p += 2 * x + 1;
		}
		else {
			y--;
			p += 2 * (x - y) + 1;
		}


		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc - y, yc - x);
		x++;
	}

	glEnd();
	glFlush();
}
