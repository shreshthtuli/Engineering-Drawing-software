#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"
#include<funcs.h>
#include <QMessageBox>
#include <QDebug>
#include <QSlider>
#include <QFileDialog>
#include <QFile>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    glWidget = new MyGLWidget();
    Mod.Nodes.clear();
    Mod.Planes.clear();
    Mod.Edges.clear();
    /*
    //for testing Purposes, create a cube
    Mod.Nodes.push_back(new Point(0,0,0));
    Mod.Nodes.push_back(new Point(1,0,0));
    Mod.Nodes.push_back(new Point(1,1,0));
    Mod.Nodes.push_back(new Point(0,1,0));
    Mod.Nodes.push_back(new Point(0,0,1));
    Mod.Nodes.push_back(new Point(1,0,1));
    Mod.Nodes.push_back(new Point(1,1,1));
    Mod.Nodes.push_back(new Point(0,1,1));
    Plane p;
    p.Bounds.push_back(Mod.Nodes[3]);
    p.Bounds.push_back(Mod.Nodes[2]);
    p.Bounds.push_back(Mod.Nodes[1]);
    p.Bounds.push_back(Mod.Nodes[0]);
    Mod.Planes.push_back(p);
    p.Bounds.clear();
    p.Bounds.push_back(Mod.Nodes[4]);
    p.Bounds.push_back(Mod.Nodes[5]);
    p.Bounds.push_back(Mod.Nodes[6]);
    p.Bounds.push_back(Mod.Nodes[7]);
    Mod.Planes.push_back(p);
    p.Bounds.clear();
    p.Bounds.push_back(Mod.Nodes[0]);
    p.Bounds.push_back(Mod.Nodes[4]);
    p.Bounds.push_back(Mod.Nodes[7]);
    p.Bounds.push_back(Mod.Nodes[3]);
    Mod.Planes.push_back(p);
    p.Bounds.clear();
    p.Bounds.push_back(Mod.Nodes[2]);
    p.Bounds.push_back(Mod.Nodes[6]);
    p.Bounds.push_back(Mod.Nodes[5]);
    p.Bounds.push_back(Mod.Nodes[1]);
    Mod.Planes.push_back(p);
    p.Bounds.clear();
    p.Bounds.push_back(Mod.Nodes[0]);
    p.Bounds.push_back(Mod.Nodes[1]);
    p.Bounds.push_back(Mod.Nodes[5]);
    p.Bounds.push_back(Mod.Nodes[4]);
    Mod.Planes.push_back(p);
    p.Bounds.clear();
    p.Bounds.push_back(Mod.Nodes[7]);
    p.Bounds.push_back(Mod.Nodes[6]);
    p.Bounds.push_back(Mod.Nodes[2]);
    p.Bounds.push_back(Mod.Nodes[3]);
    Mod.Planes.push_back(p);
    Mod.Edges.push_back(Edge(Mod.Nodes[0],Mod.Nodes[1]));
    Mod.Edges.push_back(Edge(Mod.Nodes[2],Mod.Nodes[1]));
    Mod.Edges.push_back(Edge(Mod.Nodes[3],Mod.Nodes[2]));
    Mod.Edges.push_back(Edge(Mod.Nodes[0],Mod.Nodes[3]));
    Mod.Edges.push_back(Edge(Mod.Nodes[4],Mod.Nodes[5]));
    Mod.Edges.push_back(Edge(Mod.Nodes[6],Mod.Nodes[5]));
    Mod.Edges.push_back(Edge(Mod.Nodes[6],Mod.Nodes[7]));
    Mod.Edges.push_back(Edge(Mod.Nodes[4],Mod.Nodes[7]));
    Mod.Edges.push_back(Edge(Mod.Nodes[0],Mod.Nodes[4]));
    Mod.Edges.push_back(Edge(Mod.Nodes[5],Mod.Nodes[1]));
    Mod.Edges.push_back(Edge(Mod.Nodes[6],Mod.Nodes[2]));
    Mod.Edges.push_back(Edge(Mod.Nodes[7],Mod.Nodes[3]));
    ui->widget_4->doUpdate(Mod);
    //Ortho o=ui->widget_4->myModel.project();
    ui->frontortho->myModel=Mod;
    ui->sideortho->myModel=Mod;
    ui->toportho->myModel=Mod;
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
    //end test code
    */
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
    ui->widget_4->myModel.rotate(ui->thataSlider->value(),ui->alphaSlider->value(),ui->betaSlider->value());
    ui->widget_4->myModel.scale(scalefactor);
    //Ortho o=ui->widget_4->myModel.project();
    ui->frontortho->myModel=ui->widget_4->myModel;
    ui->sideortho->myModel=ui->widget_4->myModel;
    ui->toportho->myModel=ui->widget_4->myModel;
    ui->widget_4->updateGL();
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
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

void MainWindow::on_action3D_Model_2_triggered()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open File:"), "C://");

    qInfo() << filename;
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readLine();

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "EDGES"){break;}
        Mod.Nodes.push_back(new Point(result[0].toFloat(), result[1].toFloat(), result[2].toFloat()));
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "PLANES"){break;}
        Mod.Edges.push_back(Edge(Mod.Nodes[result[0].toInt()],Mod.Nodes[result[1].toInt()]));
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line.length() == 0){break;}
        Plane p;
        p.Bounds.clear();
        for(int i = 0; i < result.size(); i++){
            p.Bounds.push_back(Mod.Nodes[result[i].toInt()]);
        }
        Mod.Planes.push_back(p);
    }
    ui->widget_4->doUpdate(Mod);
    file.close();


}

void MainWindow::on_ScaleVal_valueChanged(double arg1)
{
    if (ui->ScaleVal->value() > 0.00){
        scalefactor = ui->ScaleVal->value();
    }
}

void MainWindow::on_actionOrthographic_projection_triggered()
{
    ui->frontortho->myModel=Mod;
    ui->sideortho->myModel=Mod;
    ui->toportho->myModel=Mod;
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
}
