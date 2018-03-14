#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <funcs.h>

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE

class MyGLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_UpdateModel_clicked();

    void on_AboutQt_clicked();

    void on_quitButton_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_Qt_triggered();

    void on_action3D_Model_2_triggered();

private:
    QString filename;
    QSlider *createSlider();
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    Ui::MainWindow *ui;
    MyGLWidget *glWidget;
    Model3D MyModel;
};

#endif // MAINWINDOW_H
