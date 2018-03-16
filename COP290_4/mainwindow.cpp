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
#include <QScreen>
#include <QDesktopWidget>
#include<reconst.h>
#include<algorithm>
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
    Mod.Nodes.clear();
    Mod.Planes.clear();
    Mod.Edges.clear();

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

int indexOf(Point* x, vector<Point*> arr){
    for(int i = 0; i< arr.size(); i++){
        if (arr[i] == x)
            return i;
    }

    return 0;
}

void MainWindow::on_actionSolid_View_triggered()
{
    ui->widget_4->setFill();
}

void MainWindow::on_actionWireframe_View_triggered()
{
    ui->widget_4->setWireframe();
}

void MainWindow::on_actionIsometric_View_triggered()
{
    ui->widget_4->isometric();
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

void MainWindow::on_actionOrthograhic_projection_triggered()
{
    vector<pPoint_2d> fr,tp,sd;

    //get front view from file
    filename = QFileDialog::getOpenFileName(this, tr("Open Front view:"), "C://");
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
        pPoint_2d p;
        p.x=result[0].toFloat();
        p.y=result[1].toFloat();
        int i=2;
        while(i<result.size()){
            if(result[i].toInt()>0)p.vects.insert(result[i].toInt());
            i++;
        }
        p.self=fr.size();
        p.adjs.insert(fr.size());
        fr.push_back(p);
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "TOP"){break;}
        fr[result[0].toInt()].adjs.insert(result[1].toInt());
        fr[result[1].toInt()].adjs.insert(result[0].toInt());
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "EDGES"){break;}
        pPoint_2d p;
        p.x=result[0].toFloat();
        p.y=result[1].toFloat();
        int i=2;
        while(i<result.size()){
            if(result[i].toInt()>0)p.vects.insert(result[i].toInt());
            i++;
        }
        p.self=tp.size();
        p.adjs.insert(tp.size());
        tp.push_back(p);
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "SIDE"){break;}
        tp[result[0].toInt()].adjs.insert(result[1].toInt());
        tp[result[1].toInt()].adjs.insert(result[0].toInt());
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        if(line == "EDGES"){break;}
        pPoint_2d p;
        p.x=result[0].toFloat();
        p.y=result[1].toFloat();
        int i=2;
        while(i<result.size()){
            if(result[i].toInt()>0)p.vects.insert(result[i].toInt());
            i++;
        }
        p.self=sd.size();
        p.adjs.insert(sd.size());
        sd.push_back(p);
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList result = line.split(" ");
        sd[result[0].toInt()].adjs.insert(result[1].toInt());
        sd[result[1].toInt()].adjs.insert(result[0].toInt());
    }
    file.close();
    //retrieve all Points.
    vector<pPoint_3d> pPoints;
    auto it_tp=tp.begin();
    while(it_tp!=tp.end()){
        auto pts=it_tp->vects.begin();
        while(pts!=it_tp->vects.end()){
            pPoint_3d temp;
            temp.src_tp=&*it_tp;
            temp.src_fr=&*(std::find(fr.begin(),fr.end(),*pts));
            temp.src_sd=&*(std::find(sd.begin(),sd.end(),*pts));
            cout<<*pts;
            temp.set();
            pPoints.push_back(temp);
            pts++;
        }
        it_tp++;
    }
    //now look at every pair of points. If an edge exists between them in all views, create an edge
    vector<pEdge> pEdges;
    int i=0;
    int fn,tn,sn;
    while(i<(pPoints.size()-1)){
        fn=pPoints[i].src_fr->self;
        sn=pPoints[i].src_sd->self;
        tn=pPoints[i].src_tp->self;
        int j=i+1;
        while(j<pPoints.size()){
            if(pPoints[j].src_fr->adjs.count(fn)>0 && pPoints[j].src_tp->adjs.count(tn)>0 && pPoints[j].src_sd->adjs.count(sn)>0){
                pEdge p;
                p.p1=i;
                p.p2=j;
                pPoints[i].emans.push_back(pEdges.size());
                pPoints[j].emans.push_back(pEdges.size());
                pEdges.push_back(p);
            }
            j++;
        }
        i++;
    }
    Mod.Nodes.clear();
    Mod.Edges.clear();
    Mod.Planes.clear();
    i=0;
    while(i<pPoints.size()){
        Mod.Nodes.push_back(new Point(pPoints[i].x,pPoints[i].y,pPoints[i].z));
        i++;
    }
    i=0;
    while(i<pEdges.size()){
        Mod.Edges.push_back(Edge(Mod.Nodes[pEdges[i].p1],Mod.Nodes[pEdges[i].p2]));
        i++;
    }
    ui->widget_4->doUpdate(Mod);
    ui->frontortho->myModel=Mod;
    ui->sideortho->myModel=Mod;
    ui->toportho->myModel=Mod;
    ui->widget_4->updateGL();
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
}

void MainWindow::on_action3D_Model_3_triggered()
{
    QFileDialog fileDlg( this );
    fileDlg.setWindowTitle( "Select diectory to save file" );
    fileDlg.setDirectory( "C://" );
    fileDlg.setFileMode( QFileDialog::DirectoryOnly );
    fileDlg.setOptions( QFileDialog::ShowDirsOnly );
    fileDlg.setAcceptMode( QFileDialog::AcceptSave );

    if ( fileDlg.exec() == QDialog::Rejected )
        return;

    QString filename = (fileDlg.selectedFiles())[0];
    qInfo() << filename;
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    QString line;

    stream << "NODES" << endl;

    for(int i = 0; i < Mod.Nodes.size(); i++)
        stream << ui->widget_4->myModel.Nodes[i]->x << " " << Mod.Nodes[i]->y << " " << Mod.Nodes[i]->z << endl;

    stream << "EDGES" << endl;

    for(int i = 0; i < Mod.Edges.size(); i++)
        stream << indexOf(ui->widget_4->myModel.Edges[i].p1, Mod.Nodes) << " " << indexOf(Mod.Edges[i].p2, Mod.Nodes) << endl;

    stream << "PLANES" << endl;

    for(int i = 0; i < ui->widget_4->myModel.Planes.size(); i++)
    {
        for(int j = 0; j < ui->widget_4->myModel.Planes[i].Bounds.size(); j++){
            stream << indexOf(ui->widget_4->myModel.Planes[i].Bounds[j], Mod.Nodes);
            if(j == ui->widget_4->myModel.Planes[i].Bounds.size() - 1){break;}
            else{stream << " ";}
        }
        stream << endl;
    }
    stream << endl;
    file.close();
}


void MainWindow::on_actionCapture_snapshot_triggered()
{
    QScreen *QSCREEN = QGuiApplication::primaryScreen();
    QPixmap qpix = QSCREEN->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                      QApplication::desktop()->height());

    QFileDialog fileDlg( this );
    fileDlg.setWindowTitle( "Select diectory to save file" );
    fileDlg.setDirectory( "C://" );
    fileDlg.setFileMode( QFileDialog::DirectoryOnly );
    fileDlg.setOptions( QFileDialog::ShowDirsOnly );
    fileDlg.setAcceptMode( QFileDialog::AcceptSave );

    if ( fileDlg.exec() == QDialog::Rejected )
        return;

    QString filename = (fileDlg.selectedFiles())[0];
    qInfo() << filename;
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    qpix.save(&file, "PNG");
}
