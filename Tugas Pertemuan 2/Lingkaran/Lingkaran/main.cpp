//
//  main.cpp
//  Lingkaran
//
//  Created by Ester Imelda Br Sihotang on 10/03/25.
//
#include <GLUT/glut.h>
#include <cmath>
#define _USE_MATH_DEFINES  

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Titik pusat
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    drawCircle(0.5f, 50);
    glPopMatrix();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran di OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
