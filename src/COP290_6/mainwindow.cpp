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
#include <QKeyEvent>
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(ui->widget_4->create){


    if(event->key() == Qt::Key_D){
        ui->widget_4->xCurr = ui->widget_4->xCurr + 1.00;
    }
    else if (event->key() == Qt::Key_A) {
        ui->widget_4->xCurr = ui->widget_4->xCurr - 1.00;
    }
    else if (event->key() == Qt::Key_W) {
        ui->widget_4->yCurr = ui->widget_4->yCurr + 1.00;
    }
    else if (event->key() == Qt::Key_S) {
        ui->widget_4->yCurr = ui->widget_4->yCurr - 1.00;
    }
    else if (event->key() == Qt::Key_L) {
        ui->widget_4->zCurr = ui->widget_4->zCurr + 1.00;
    }
    else if (event->key() == Qt::Key_O) {
        ui->widget_4->zCurr = ui->widget_4->zCurr - 1.00;
    }
    else if (event->key() == Qt::Key_Space) {

        if(Mod.Nodes.size() != 0){
            if(Mod.Nodes[Mod.Nodes.size()-1]->x != ui->widget_4->xCurr || Mod.Nodes[Mod.Nodes.size()-1]->y != ui->widget_4->yCurr ||Mod.Nodes[Mod.Nodes.size()-1]->z != ui->widget_4->zCurr){
                Mod.Nodes.push_back(new Point(ui->widget_4->xCurr, ui->widget_4->yCurr, ui->widget_4->zCurr));
                ui->widget_4->myModel.Nodes.push_back(new Point(ui->widget_4->xCurr, ui->widget_4->yCurr, ui->widget_4->zCurr));
            }
        }
        else{
            Mod.Nodes.push_back(new Point(ui->widget_4->xCurr, ui->widget_4->yCurr, ui->widget_4->zCurr));
            ui->widget_4->myModel.Nodes.push_back(new Point(ui->widget_4->xCurr, ui->widget_4->yCurr, ui->widget_4->zCurr));
        }

        if(initial){
            xLast = ui->widget_4->xCurr;
            yLast = ui->widget_4->yCurr;
            zLast = ui->widget_4->zCurr;
            initial = false;
        }

        else{
            if (xLast != ui->widget_4->xCurr || yLast != ui->widget_4->yCurr || zLast != ui->widget_4->zCurr){
                Mod.Edges.push_back(Edge(Mod.Nodes[Mod.Nodes.size()-2], Mod.Nodes[Mod.Nodes.size()-1]));
                ui->widget_4->myModel.Edges.push_back(Edge(Mod.Nodes[Mod.Nodes.size()-2], Mod.Nodes[Mod.Nodes.size()-1]));
                initial = true;
            }
        }


    }

    }
    event->accept();

    if(initial){
        ui->initial->setText("Initial Edge Point");
    }
    else{
        ui->initial->setText("Final Edge Point");
    }

    ui->xcurr->setNum(ui->widget_4->xCurr);
    ui->ycurr->setNum(ui->widget_4->yCurr);
    ui->zcurr->setNum(ui->widget_4->zCurr);
    //ui->widget_4->doUpdate(Mod);
    ui->frontortho->myModel=Mod;
    ui->sideortho->myModel=Mod;
    ui->toportho->myModel=Mod;
    ui->widget_4->updateGL();
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
}


void MainWindow::on_UpdateModel_clicked()
{
    cout<<"Translate:"<<ui->XSlider->value()<<endl;
    Mod.translate(ui->XSlider->value(),ui->YSlider->value(),ui->ZSlider->value());
    Mod.rotate(ui->thataSlider->value(),ui->alphaSlider->value(),ui->betaSlider->value());
    Mod.scale(scalefactor);
    //ui->widget_4->myModel.translate(ui->XSlider->value(),ui->YSlider->value(),ui->ZSlider->value());
    //ui->widget_4->myModel.rotate(ui->thataSlider->value(),ui->alphaSlider->value(),ui->betaSlider->value());
    //ui->widget_4->myModel.scale(scalefactor);
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

void MainWindow::on_action3D_Model_2_triggered() //Read 3D Model
{
    filename = QFileDialog::getOpenFileName(this, tr("Open File:"), "C://");
    ui->widget_4->create = false;
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
    ui->widget_4->wireframe = false;
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

void MainWindow::on_actionOrthograhic_projection_triggered() //Read 2D Model
{
    vector<pPoint_2d> fr,tp,sd;

    ui->widget_4->create = false;
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

    //try to retrieve planes
    vector<pPlane> pPlanes;
    if(!planerecons) {
        goto abort_planes;
    }
    while(true){
        //select an edge to look at
        int i=0;
        while(i<pEdges.size() && pEdges[i].pcount>1)i++;
        cout<<endl<<"planes count:"<<pPlanes.size();
        if(i==pEdges.size())break;
        pPlanes.push_back(pPlane());
        auto pp=&pPlanes[pPlanes.size()-1];
        pp->points.push_back(pEdges[i].p1);
        pp->coordinates.push_back(pPoints[pEdges[i].p1]);
        pp->points.push_back(pEdges[i].p2);
        pp->coordinates.push_back(pPoints[pEdges[i].p2]);
        pEdges[i].pcount++;
        //need some logic to avoid retaking edges.
        //the way we add planes, they get naturally sorted according to the lowest index pEgde they are based on. Therefore, we only need to control for the previous edge.
        bool check_last=false;
        if(pPlanes.size()>1 && pPlanes[pPlanes.size()-2].points[0]==pp->points[0] && pPlanes[pPlanes.size()-2].points[0]==pp->points[0])check_last=true;
            //choose third point carefully
            auto ppt=&pPoints[pp->points[1]];
            int j=0;
            while(j<ppt->emans.size()){
                //check if this edge can be included
                if(pEdges[ppt->emans[j]].pcount<2){
                    //check which direction we are moving
                    if(pEdges[ppt->emans[j]].p1==pp->points[1]){
                        //make sure we are not moving back along same edge
                        if(pEdges[ppt->emans[j]].p2!=pp->points[0]){
                            //make sure we are not taking a previously considered plane
                            if(check_last==false || pEdges[ppt->emans[j]].p2!=pPlanes[pPlanes.size()-2].points[2]){
                                //add this point and break execution
                                pEdges[ppt->emans[j]].pcount++;
                                pp->points.push_back(pEdges[ppt->emans[j]].p2);
                                pp->coordinates.push_back(pPoints[pEdges[ppt->emans[j]].p2]);
                                pp->admits(pPoints[pEdges[ppt->emans[j]].p2]);
                                break;
                            }
                        }
                    }else{
                        //make sure we are not moving back along same edge
                        if(pEdges[ppt->emans[j]].p1!=pp->points[0]){
                            //make sure we are not taking a previously considered plane
                            if(check_last==false||pEdges[ppt->emans[j]].p1!=pPlanes[pPlanes.size()-2].points[2]){
                                //add this point and break execution
                                pEdges[ppt->emans[j]].pcount++;
                                pp->points.push_back(pEdges[ppt->emans[j]].p1);
                                pp->coordinates.push_back(pPoints[pEdges[ppt->emans[j]].p1]);
                                pp->admits(pPoints[pEdges[ppt->emans[j]].p1]);
                                break;
                            }
                        }
                    }
                }
                j++;
            }
            //cout<<endl<<"ct";
            if(j==ppt->emans.size())
                //break;
            //if we got here, we should get a full plane


            cout<<" did I get here?\n";
            bool chale_chalo=true;
            while(chale_chalo){
                //cout<<"shit";
                //catch last point in plane
                auto ppt=&pPoints[pp->points[pp->points.size()-1]];
                int j=0;
                while(j<ppt->emans.size()) {
                    int k=0;
                    if(pEdges[ppt->emans[j]].p1==pp->points[pp->points.size()-1])
                        k=pEdges[ppt->emans[j]].p2;
                    else
                        k=pEdges[ppt->emans[j]].p1;
                    //cout<<j<<":"<<pPoints[k].x<<" "<<pPoints[k].y<<" "<<pPoints[k].z<<" ";
                    //cout<<"\n"<<pp->coordinates[0].x<<" "<<pp->coordinates[0].y<<" "<<pp->coordinates[0].z<<"\n"<<pp->coordinates[1].x<<" "<<pp->coordinates[1].y<<" "<<pp->coordinates[1].z<<"\n"<<pp->coordinates[2].x<<" "<<pp->coordinates[2].y<<" "<<pp->coordinates[2].z<<"\n";

                    j++;
                    //check if plane started at this point
                    if(k==pp->points[0]){
                        pEdges[ppt->emans[j-1]].pcount++;
                        chale_chalo=false;
                        break;
                    }
                    //check if plane admits this point
                    if(pp->admits(pPoints[k],false)&& pp->points[pp->points.size()-2]!=k){
                        pEdges[ppt->emans[j-1]].pcount++;
                        pp->points.push_back(k);

                    }
                }
                //cout<<"\nshit";
            }
        }

    //if we got here, some planes were probably retrieved.
    i =0;
    while(i<pPlanes.size()){
        Mod.Planes.push_back(Plane());
        int j=0;
        while(j<pPlanes[i].points.size()){
           Mod.Planes[Mod.Planes.size()-1].Bounds.push_back(Mod.Nodes[pPlanes[i].points[j]]);
           j++;
        }
        i++;
    }
    cout<<"Planes count:"<<Mod.Planes.size();
abort_planes:
    ui->widget_4->wireframe = true;
    ui->widget_4->doUpdate(Mod);
    ui->frontortho->myModel=Mod;
    ui->sideortho->myModel=Mod;
    ui->toportho->myModel=Mod;
    ui->widget_4->updateGL();
    ui->frontortho->updateGL();
    ui->toportho->updateGL();
    ui->sideortho->updateGL();
}

void MainWindow::on_action3D_Model_3_triggered() //Save 3D Model
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

    for(int i = 0; i < ui->widget_4->myModel.Nodes.size(); i++)
        stream << ui->widget_4->myModel.Nodes[i]->x << " " << ui->widget_4->myModel.Nodes[i]->y << " " << ui->widget_4->myModel.Nodes[i]->z << endl;

    stream << "EDGES" << endl;

    for(int i = 0; i < ui->widget_4->myModel.Edges.size(); i++)
        stream << indexOf(ui->widget_4->myModel.Edges[i].p1, ui->widget_4->myModel.Nodes) << " " << indexOf(ui->widget_4->myModel.Edges[i].p2, ui->widget_4->myModel.Nodes) << endl;

    stream << "PLANES" << endl;

    for(int i = 0; i < ui->widget_4->myModel.Planes.size(); i++)
    {
        for(int j = 0; j < ui->widget_4->myModel.Planes[i].Bounds.size(); j++){
            stream << indexOf(ui->widget_4->myModel.Planes[i].Bounds[j], ui->widget_4->myModel.Nodes);
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

void MainWindow::on_actionCreate_new_wireframe_triggered()
{
    Mod.Nodes.clear();
    Mod.Planes.clear();
    Mod.Edges.clear();
    ui->widget_4->xCurr = 0.00;
    ui->widget_4->yCurr = 0.00;
    ui->widget_4->zCurr = 0.00;
    ui->widget_4->wireframe = true;
    ui->widget_4->create = true;
    xLast = 0.00;
    yLast = 0.00;
    zLast = 0.00;
    initial = true;
}

void MainWindow::on_actionAdd_on_wireframe_triggered()
{
    ui->widget_4->xCurr = 0.00;
    ui->widget_4->yCurr = 0.00;
    ui->widget_4->zCurr = 0.00;
    ui->widget_4->wireframe = true;
    ui->widget_4->create = true;
    xLast = 0.00;
    yLast = 0.00;
    zLast = 0.00;
    initial = true;
}

void MainWindow::on_actionOrthographic_Projections_triggered()
{

}

void MainWindow::on_actionOrthographic_Projection_triggered()
{
    QFileDialog fileDlg( this );
    fileDlg.setWindowTitle( "Select diectory to save orthographic file" );
    fileDlg.setDirectory( "C://" );
    fileDlg.setFileMode( QFileDialog::DirectoryOnly );
    fileDlg.setOptions( QFileDialog::ShowDirsOnly );
    fileDlg.setAcceptMode( QFileDialog::AcceptSave );

    if ( fileDlg.exec() == QDialog::Rejected )
        return;

    QString filename = (fileDlg.selectedFiles())[0];
    ui->widget_4->myModel.saveOrtho(filename);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    planerecons = !planerecons;
}
