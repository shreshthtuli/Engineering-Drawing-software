// orthofront.h

#ifndef ORTHOFRONT_H
#define ORTHOFRONT_H

#include <QGLWidget>
#include <funcs.h>

class OrthoFront : public QGLWidget
{
    Q_OBJECT
public:
    explicit OrthoFront(QWidget *parent = 0);
    Model3D myModel;
    ~OrthoFront();
signals:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

private:
    void draw();
};

#endif // ORTHOFRONT.H
