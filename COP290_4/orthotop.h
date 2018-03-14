// orthotop.h

#ifndef ORTHOTOP_H
#define ORTHOTOP_H

#include <QGLWidget>

class OrthoTop : public QGLWidget
{
    Q_OBJECT
public:
    explicit OrthoTop(QWidget *parent = 0);
    ~OrthoTop();
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

#endif // ORTHOTOP.H
