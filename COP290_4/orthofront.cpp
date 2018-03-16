// orthofront.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "orthofront.h"

OrthoFront::OrthoFront(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
}

OrthoFront::~OrthoFront()
{
}

QSize OrthoFront::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize OrthoFront::sizeHint() const
{
    return QSize(400, 400);
}

void OrthoFront::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    glEnable ( GL_COLOR_MATERIAL );

    static GLfloat lightPosition[4] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightPosition);
}

void OrthoFront::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glRotatef(0.0, 0.0, 0.0, 1.0);
    draw();
}

void OrthoFront::resizeGL(int width, int height)
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

void OrthoFront::draw()
{
    //Axes
    glLineWidth(2);

    glBegin(GL_LINES);
        glColor3f( 1.0f, 0.0f, 0.0f );
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(4, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3f( 0.0f, 1.0f, 0.0f );
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 4.0, 0.0);
    glEnd();

    glLineWidth(4);

    //Pojection
    glDepthFunc(GL_LEQUAL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(1.0);
    Point norm;
    glColor3f( 0.0f, 0.0f, 0.0f );
    int i=0;
    while(i<myModel.Planes.size()){
        glBegin(GL_POLYGON);
        norm=myModel.Planes[i].get_normal();
        glNormal3f(norm.x,norm.y,norm.z);
        for(auto iter1=myModel.Planes[i].Bounds.begin();iter1!=myModel.Planes[i].Bounds.end(); iter1++){
            auto iter2=*iter1;
            glVertex3f(iter2->x,iter2->y,iter2->z);
        }
        i++;
        glEnd();
    }

    glColorMask(0.0, 0.0, 0.0, 0.0);
    glColor4d(0.0, 0.0, 1.0, 1.0);
    i=0;
    while(i<myModel.Edges.size()){
        glBegin(GL_LINES);
        glColor3f( 1.0f, 1.0f, 1.0f );
        glVertex3f(myModel.Edges[i].p1->x,myModel.Edges[i].p1->y,myModel.Edges[i].p1->z);
        glVertex3f(myModel.Edges[i].p2->x,myModel.Edges[i].p2->y,myModel.Edges[i].p2->z);
        i++;
        glEnd();
    }

    glDepthFunc(GL_GREATER);
    glColor4d(0.0, 0.0, 1.0, 1.0); // hidden
    glColorMask(1.0, 1.0, 1.0, 1.0);
    glLineStipple(4, 0xAAAA); // added
    glEnable(GL_LINE_STIPPLE); // added
    glDepthMask(GL_FALSE);
    i=0;
    while(i<myModel.Edges.size()){
        glBegin(GL_LINES);
        glColor3f( 1.0f, 1.0f, 1.0f );
        glVertex3f(myModel.Edges[i].p1->x,myModel.Edges[i].p1->y,myModel.Edges[i].p1->z);
        glVertex3f(myModel.Edges[i].p2->x,myModel.Edges[i].p2->y,myModel.Edges[i].p2->z);
        i++;
        glEnd();
    }

    glDepthMask(GL_TRUE);
    glDisable(GL_LINE_STIPPLE); // added
    glColor4d(1.0, 1.0, 1.0, 1.0); // solid
    glLineWidth(3.0);
    glDepthFunc(GL_LEQUAL);
    i=0;
    while(i<myModel.Edges.size()){
        glBegin(GL_LINES);
        glColor3f( 1.0f, 1.0f, 1.0f );
        glVertex3f(myModel.Edges[i].p1->x,myModel.Edges[i].p1->y,myModel.Edges[i].p1->z);
        glVertex3f(myModel.Edges[i].p2->x,myModel.Edges[i].p2->y,myModel.Edges[i].p2->z);
        i++;
        glEnd();
    }

}
