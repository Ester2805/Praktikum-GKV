//
//  main.cpp
//  Mobil
//
//  Created by Ester Imelda Br Sihotang on 10/03/25.
//

#include <GLUT/glut.h>

void drawMobilSport() {
    // Body mobil sport
    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_POLYGON);
        glVertex2f(-0.6, -0.2);
        glVertex2f(0.6, -0.2);
        glVertex2f(0.5, 0.0);
        glVertex2f(-0.5, 0.0);
    glEnd();

    // Atap mobil sport
    glColor3f(0.8, 0.0, 0.0); // Merah gelap
    glBegin(GL_POLYGON);
        glVertex2f(-0.3, 0.0);
        glVertex2f(0.3, 0.0);
        glVertex2f(0.2, 0.2);
        glVertex2f(-0.2, 0.2);
    glEnd();

    // Roda depan
    glColor3f(0.0, 0.0, 0.0); // Hitam
    glPushMatrix();
        glTranslatef(-0.4, -0.3, 0);
        glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Roda belakang
    glPushMatrix();
        glTranslatef(0.4, -0.3, 0);
        glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

void drawBackground() {
    // Langit
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.8, 1.0); // Biru muda
        glVertex2f(-1, 1);
        glVertex2f(1, 1);
        glColor3f(1.0, 1.0, 1.0); // Putih mendekati horizon
        glVertex2f(1, 0);
        glVertex2f(-1, 0);
    glEnd();

    // Jalan
    glColor3f(0.2, 0.2, 0.2); // Abu-abu gelap
    glBegin(GL_QUADS);
        glVertex2f(-1, -0.2);
        glVertex2f(1, -0.2);
        glVertex2f(1, -1);
        glVertex2f(-1, -1);
    glEnd();

    // Garis tengah jalan
    glColor3f(1.0, 1.0, 1.0); // Putih
    glLineWidth(2);
    glBegin(GL_LINES);
        for (float i = -1; i < 1; i += 0.2) {
            glVertex2f(i, -0.5);
            glVertex2f(i + 0.1, -0.5);
        }
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();
    drawMobilSport();

    glFlush();
}

// Init OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Latar awal hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Sport dengan Background Menarik");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

