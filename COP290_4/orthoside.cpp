// OrthoSide.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "orthoside.h"

OrthoSide::OrthoSide(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
}

OrthoSide::~OrthoSide()
{
}

QSize OrthoSide::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize OrthoSide::sizeHint() const
{
    return QSize(400, 400);
}

void OrthoSide::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable ( GL_COLOR_MATERIAL );

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void OrthoSide::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glRotatef(0.0, 0.0, 0.0, 1.0);
    draw();
}

void OrthoSide::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void OrthoSide::draw()
{
    //Axes
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f( 0.0f, 1.0f, 0.0f );
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 4.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3f( 0.0f, 0.0f, 1.0f );
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(4.0, 0.0, 0.0);
    glEnd();

    //Pojection
    glLineWidth(2);
    glColor3f( 1.0f, 1.0f, 1.0f );
    glBegin(GL_LINES);
        glVertex2f(0.00, 1.00);
        glVertex2f(0.00, -1.00);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.00, 1.00);
        glVertex2f(1.2, 0.00);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.00, -1.00);
        glVertex2f(1.2, 0.00);
    glEnd();

}
