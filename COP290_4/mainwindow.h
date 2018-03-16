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

    void on_ScaleVal_valueChanged(double arg1);

    void on_actionOrthographic_projection_triggered();

    void on_actionOrthograhic_projection_triggered();

    void on_action3D_Model_3_triggered();

    void on_actionIsometric_View_triggered();

    void on_actionSolid_View_triggered();

    void on_actionWireframe_View_triggered();

    void on_actionCapture_snapshot_triggered();

private:
    QSlider *createSlider();
    float scalefactor = 1.00;
    QString filename;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    Ui::MainWindow *ui;
    MyGLWidget *glWidget;
    Model3D MyModel;
    Model3D Mod;
};

#endif // MAINWINDOW_H
