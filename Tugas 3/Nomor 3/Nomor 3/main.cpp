/*Ester Imelda Br Sihotang*/


#include <GLUT/glut.h>
#include <cstdlib>

static int shoulder = 0, elbow = 0, telapak = 0;
static int jempol = 0, jempol1 = 0, jempol2 = 0;
static int telunjuk = 0, telunjuk1 = 0, telunjuk2 = 0;
static int tengah = 0, tengah1 = 0, tengah2 = 0;
static int manis = 0, manis1 = 0, manis2 = 0;
static int kelingking = 0, kelingking1 = 0, kelingking2 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void jari(int ruas, int ruas1, int ruas2, float z) {
    glPushMatrix();
    glTranslatef(0.5, 0.0, z);
    glRotatef((GLfloat)ruas, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)ruas1, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)ruas2, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.2, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)telapak, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.5, 0.5, 2.2);
    glutWireCube(1.0);
    glPopMatrix();

    jari(jempol, jempol1, jempol2, 0.9);
    jari(telunjuk, telunjuk1, telunjuk2, 0.6);
    jari(tengah, tengah1, tengah2, 0.2);
    jari(manis, manis1, manis2, -0.2);
    jari(kelingking, kelingking1, kelingking2, -0.6);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': shoulder = (shoulder + 5) % 360; break;
        case 'A': shoulder = (shoulder - 5 + 360) % 360; break;
        case 'b': elbow = (elbow + 5) % 120; break;
        case 'B': elbow = (elbow - 5 + 120) % 120; break;
        case 'c': telapak = (telapak + 5) % 360; break;
        case 'C': telapak = (telapak - 5 + 360) % 360; break;

        //Jempol
        case 'd': jempol = (jempol + 5) % 70; break;
        case 'D': jempol = (jempol - 5 + 70) % 70; break;
        case 'e': jempol1 = (jempol1 + 5) % 90; break;
        case 'E': jempol1 = (jempol1 - 5 + 90) % 90; break;
        case 'f': jempol2 = (jempol2 + 5) % 90; break;
        case 'F': jempol2 = (jempol2 - 5 + 90) % 90; break;

        //Telunjuk
        case 'g': telunjuk = (telunjuk + 5) % 90; break;
        case 'G': telunjuk = (telunjuk - 5 + 90) % 90; break;
        case 'h': telunjuk1 = (telunjuk1 + 5) % 90; break;
        case 'H': telunjuk1 = (telunjuk1 - 5 + 90) % 90; break;
        case 'i': telunjuk2 = (telunjuk2 + 5) % 90; break;
        case 'I': telunjuk2 = (telunjuk2 - 5 + 90) % 90; break;

        //Tengah
        case 'j': tengah = (tengah + 5) % 90; break;
        case 'J': tengah = (tengah - 5 + 90) % 90; break;
        case 'k': tengah1 = (tengah1 + 5) % 90; break;
        case 'K': tengah1 = (tengah1 - 5 + 90) % 90; break;
        case 'l': tengah2 = (tengah2 + 5) % 90; break;
        case 'L': tengah2 = (tengah2 - 5 + 90) % 90; break;

        //Manis
        case 'm': manis = (manis + 5) % 90; break;
        case 'M': manis = (manis - 5 + 90) % 90; break;
        case 'n': manis1 = (manis1 + 5) % 90; break;
        case 'N': manis1 = (manis1 - 5 + 90) % 90; break;
        case 'o': manis2 = (manis2 + 5) % 90; break;
        case 'O': manis2 = (manis2 - 5 + 90) % 90; break;
        
        //Kelingking
        case 'p': kelingking = (kelingking + 5) % 90; break;
        case 'P': kelingking = (kelingking - 5 + 90) % 90; break;
        case 'q': kelingking1 = (kelingking1 + 5) % 90; break;
        case 'Q': kelingking1 = (kelingking1 - 5 + 90) % 90; break;
        case 'r': kelingking2 = (kelingking2 + 5) % 90; break;
        case 'R': kelingking2 = (kelingking2 - 5 + 90) % 90; break;

        case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 700);
    glutCreateWindow("Tugas Tangan Ester");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


