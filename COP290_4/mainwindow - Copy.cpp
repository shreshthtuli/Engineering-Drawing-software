#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"
#include<funcs.h>
#include <QMessageBox>
#include <QDebug>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = new MyGLWidget();
    Model3D Mod;
    //for testing Purposes, create a cube
    Point *temp;
    Plane p;
    temp=new Point(0,0,0);
    p.Bounds.push_back(temp);
    Mod.Nodes.push_back(temp);
    temp=new Point(1,0,0);
    p.Bounds.push_back(temp);
    Mod.Nodes.push_back(temp);
    temp=new Point(1,1,0);
    p.Bounds.push_back(temp);
    Mod.Nodes.push_back(temp);
    Mod.Planes.push_back(p);
    Mod.Nodes[0]->y=1;

    ui->widget_4->doUpdate(Mod);
    //end test code
    connect(ui->thataSlider, SIGNAL(valueChanged(int)),
            ui->valTheta, SLOT(setNum(int)));
    connect(ui->alphaSlider, SIGNAL(valueChanged(int)),
            ui->valAlpha, SLOT(setNum(int)));
    connect(ui->betaSlider, SIGNAL(valueChanged(int)),
            ui->valBeta, SLOT(setNum(int)));
    connect(ui->XSlider, SIGNAL(valueChanged(int)),
            ui->valX, SLOT(setNum(int)));
    connect(ui->YSlider, SIGNAL(valueChanged(int)),
            ui->valY, SLOT(setNum(int)));
    connect(ui->ZSlider, SIGNAL(valueChanged(int)),
            ui->valZ, SLOT(setNum(int)));

    connect(ui->xSlider, SIGNAL(valueChanged(int)), ui->xRotVal, SLOT(setNum(int)));
    connect(ui->ySlider, SIGNAL(valueChanged(int)), ui->yRotVal, SLOT(setNum(int)));
    connect(ui->zSlider, SIGNAL(valueChanged(int)), ui->zRotVal, SLOT(setNum(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_UpdateModel_clicked()
{
    ui->widget_4->myModel.translate(ui->XSlider->value(),ui->YSlider->value(),ui->ZSlider->value());
    ui->widget_4->updateGL();
    //if error then
    //QMessageBox::critical(this, "Error!!", "Error message");
}

void MainWindow::on_AboutQt_clicked()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_quitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quit Application?",
                                  "Are you sure you want to Quit the application?",
                                  QMessageBox::Yes  |  QMessageBox::No);

    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
    else
    {
        qDebug() << "Did not exit";
    }
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quit Application?",
                                  "Are you sure you want to Quit the application?",
                                  QMessageBox::Yes  |  QMessageBox::No);

    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
    else
    {
        qDebug() << "Did not exit";
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}
