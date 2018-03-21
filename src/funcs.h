#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <reconst.h>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QSlider>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QScreen>
#include <QDesktopWidget>
#include <QKeyEvent>
using namespace std;

class Point;
class Model2D;
class Model3D;
class Ortho;
class Plane;
class Edge;

/// Class for the representation of a point
class Point {

    public:
                int targ;
                Point(){
                    x=0.0;
                    y=0.0;
                    z=0.0;
                    label="";
                }
        Point(float x1,float y1,float z1){
            x=x1;
            y=y1;
            z=z1;
                        label="";
        }
                ///Mapping for conversion
                Point *map;
                ///name of the point
                string label;
        ///x coordinate
        float x ;
        ///y coordinate
        float y ;
        ///z coordinate
        float z ;
        //default values are not allowed in class or struct
                void transform(float mat[3][3]){
                    float x1,y1;
                    x1=x*mat[0][0]+y*mat[0][1]+z*mat[0][2];
                    y1=x*mat[1][0]+y*mat[1][1]+z*mat[1][2];
                    z=x*mat[2][0]+y*mat[2][1]+z*mat[2][2];
                    x=x1;
                    y=y1;
                }
                ///Gets the tip of a vector perpendicular to the plane formed by p1, p2 and origin by performing cross product
                static Point get_Perp(Point *p11, Point *p22, Point *p33){
                    Point p1=*p11-*p22;
                    Point p2=*p22-*p33;
                    Point out;
                    out.x=(p1.y*p2.z)-(p2.y*p1.z);
                    out.y=(p1.z*p2.x)-(p2.z*p1.x);
                    out.z=(p1.x*p2.y)-(p2.x*p1.y);
                    return out;
                }
                ///gets the inclination from z axis
                float get_alpha(){
                    return acos(z/sqrt(x*x+y*y+z*z));
                }
                ///gets the azimuthal angle from x axis
                float get_beta(){
                    return acos(x/sqrt(x*x+y*y));
                }
                ///gets the distance from origin
                float get_r(){
                    return sqrt(x*x+y*y+z*z);
                }
                bool operator ==(Point &p){
                    return (x==p.x)&&(y==p.y)&&(z==p.z)&&((label=="")||(label==p.label));
                }
                bool operator ==(string p){
                    return (label==p);
                }
                Point operator -(Point &p){
                    return Point(x-p.x,y-p.y,z-p.z);
                }
                void Shrink(float dest=1.0){
                    float fact=dest/get_r();
                    x*=fact;
                    y*=fact;
                    z*=fact;
                }
};


/// Wrapper around the representation of an edge
class Edge {

    public:
                Edge(Point &P1, Point &P2){
                    p1=&P1;
                    p2=&P2;
                }
                Edge(Point *P1, Point *P2){
                    p1=P1;
                    p2=P2;
                }
        ///End point
        Point *p1;
        ///End point
        Point *p2;
        ///Whether edge is hidden
        /**Relevant only for orthogonal projections. true if edge is to be depicted by a dashed line. false otherwise.*/
        bool hidden;
                ///Random eval for sorting purpose.
                string getcomp(){
                    if((p1->label)>(p2->label))return p1->label+p2->label;
                    return p2->label+p1->label;
                }
        ///Euclidian length of the edge
        float length() {
            return pow(pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2) + pow(p1->z - p2->z,2), 0.5);
        }

};


/// Wrapper around the representation of a plane
class Plane {

    public:
        ///Points binding the plane.
        /**All these Points must be coplanar and must have a complete cyclic decomposition. Further, the largest cycle(in terms of length) must contain all other cycles. These smaller cycles are modelled as holes on the surface */
        vector<Point *> Bounds;

        ///Get an unitnormal to the plane
        /**Obtains normal by taking cross product of two binding edges and returns unit normal*/
        Point get_normal(){
                Point Nor=Point::get_Perp(Bounds[0],Bounds[1],Bounds[2]);
                Nor.Shrink();
                return Nor;
        };

        ///Check if lies on the Plane.
        bool contains(Point p){

        };
};

///2D Model Class
/**Common internal representation for all types of drawings. Represented as a Euclidian graph on xy plane*/
class Model2D {

    public:

        vector<Point> Nodes;                    ///<Nodes of the graph. Each node identifies a labelled vertex. Z coordinate must be 0.
        vector<Edge> Edges;                 ///<Edges of the graph.

        ///Whether the edgeset is complete.
        /**When converting from 3D to 2D, multiple edges may overlap or become degenerate. This value should be set to false if any of these edges have been removed. If this value is set to true, complete_edges is not called by convert_to_3D*/
        bool Edges_complete;

        ///Completes the Edgeset of the graph.
        /**Creates all possible edges between nodes of the graph that would not disturb the rendered edges ie edges that might have been lost in the 3D to 2D conversion process.*/
        void complete_edges() {
                    //Add all edges that would not change the visible edges
                    //edges between points that project to the same point

                    //edges that can be formed by joining collinear edges

                    //edges that can be formed by splitting larger edges at vertices

                    //edges that could have overlapped
        };

        ///Display the view on the screen
        void display_2D() {

        };

        ///Add new edge between pre-existing nodes p1 and p2. May corrupt the execution if p1 or p2 do not belong to nodes.
        void add_edge(Point &p1, Point &p2) {

                    Edges.push_back(Edge(p1,p2));
        }
                ///Add new edge between pre-existing nodes labelled p1 and p2. Does nothing if no such nodes exist.
                void add_edge(string p1, string p2){
                    auto it1=find(Nodes.begin(), Nodes.end(), p1);
                    auto it2=find(Nodes.begin(), Nodes.end(), p2);
                    if(it1!=Nodes.end() and it2!=Nodes.end())
                        Edges.push_back(Edge(*it1,*it2));
                }
        ///Add new node to the graph.
                /**Automatically assigns numerical label if no label is available. MAy corrupt execution if multiple points have same label*/
        void add_node(Point &p1) {
                    if(p1.label=="")
                        p1.label=to_string(Nodes.size());
                    Nodes.push_back(p1);
        };

        ///Check if the model is a valid 2D projection
        /**Runs basic sanity checks like no hanging edges, three faces at each vertex etc. May produce false positives.*/
        bool is_valid() {

        };
};

///3D Model Class
/** Holds the internal representation of the 3D object being worked on in terms of an Euclidean graph.*/
class Model3D {        
private:
    static bool sortZ(pPoint_3d &p1,pPoint_3d &p2){ return (p1.x<p2.x)||(p1.x==p2.x && p1.y<p2.y);}
    static bool sortX(pPoint_3d &p1,pPoint_3d &p2){ return (p1.z<p2.z)||(p1.z==p2.z && p1.y<p2.y);}
    static bool sortY(pPoint_3d &p1,pPoint_3d &p2){ return (p1.x<p2.x)||(p1.x==p2.x && p1.z<p2.z);}
    static bool revert(pPoint_3d &p1,pPoint_3d &p2){return p1.self<p2.self;}
    public:
        vector<Point*> Nodes;                    ///<Nodes of the graph. Each node identifies a labelled vertex
        vector<Edge> Edges;                 ///<Edges of the graph. Together with the nodes, defines the wireframe of the model
        vector<Plane> Planes;                   ///<Planes differentiate the faces of the graph which are actually present from the ones that are not.

        ///Reference origin for the graph.
        /**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/
        Point ref_Origin;
        ///Reference x axis point for the graph.
        /**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/
        Point ref_x;
        ///Reference y axis point for the graph.
        /**The reference origin, reference x and reference y are points used for identifying the viewing angle for the object. While the exact values of ref_x & ref_y doesn't matter, it is advisable to keep them at unit distance from the origin. Further, they must form a right angle at ref_origin. ref_z is infered by assuming right handed coordinate system.*/
        Point ref_y;

        void saveOrtho(QString filename){
            //Convert nodes to pPoints
            vector<pPoint_3d> pPoints;
            int i=0;

            while(i<Nodes.size()){
                cout<<i<<endl;
                pPoint_3d *p=new pPoint_3d();
                p->x=Nodes[i]->x;
                p->y=Nodes[i]->y;
                p->z=Nodes[i]->z;
                p->self=i;
                pPoints.push_back(*p);
                Nodes[i]->targ=i;
                i++;
            }
            //Convert 3d points to 2d points
            vector<pPoint_2d> tp, fr, sd;
            //sort the points in a way that gives least preference to z coordinates. This means all points with equal x and y coordinates would be together. 
            sort(pPoints.begin(),pPoints.end(),sortZ);
            fr.push_back(pPoint_2d());
            cout<<"got here";
            fr[0].x=pPoints[0].x;
            fr[0].y=pPoints[0].y;
            pPoints[0].frv=0;
            fr[0].vects.insert(pPoints[0].self);
            i=1;
            while(i<pPoints.size()){
                //check if new point needs to be created
                if(pPoints[i].x==pPoints[i-1].x && pPoints[i].y==pPoints[i-1].y){
                    //add on to previous point, so do nothing here
                }else{
                    fr.push_back(pPoint_2d());
                    fr[fr.size()-1].x=pPoints[i].x;
                    fr[fr.size()-1].y=pPoints[i].y;
                }
                pPoints[i].frv=(fr.size()-1);
                fr[fr.size()-1].vects.insert(pPoints[i].self);
                i++;
            }
            //now do the same for the other views
            sort(pPoints.begin(),pPoints.end(),sortY);
            tp.push_back(pPoint_2d());
            tp[0].x=pPoints[0].x;
            tp[0].y=0-pPoints[0].z;
            pPoints[0].tpv=0;
            tp[0].vects.insert(pPoints[0].self);
            i=1;
            while(i<pPoints.size()){
                //check if new point needs to be created
                if(pPoints[i].x==pPoints[i-1].x && pPoints[i].z==pPoints[i-1].z){
                    //add on to previous point, so do nothing here
                }else{
                    tp.push_back(pPoint_2d());
                    tp[tp.size()-1].x=pPoints[i].x;
                    tp[tp.size()-1].y=0-pPoints[i].z;
                }
                pPoints[i].tpv=(tp.size()-1);
                tp[tp.size()-1].vects.insert(pPoints[i].self);
                i++;
            }
            sort(pPoints.begin(),pPoints.end(),sortX);
            sd.push_back(pPoint_2d());
            sd[0].x=pPoints[0].z;
            sd[0].y=pPoints[0].y;
            pPoints[0].sdv=0;
            sd[0].vects.insert(pPoints[0].self);
            i=1;
            while(i<pPoints.size()){
                //check if new point needs to be created
                if(pPoints[i].z==pPoints[i-1].z && pPoints[i].y==pPoints[i-1].y){
                    //add on to previous point, so do nothing here
                }else{
                    sd.push_back(pPoint_2d());
                    sd[sd.size()-1].x=pPoints[i].x;
                    sd[sd.size()-1].y=pPoints[i].y;
                }
                pPoints[i].sdv=(sd.size()-1);
                sd[sd.size()-1].vects.insert(pPoints[i].self);
                i++;
            }
            //revert back to original order
            sort(pPoints.begin(),pPoints.end(),revert);
            i=0;
            vector<pEdge> pEdges;
            vector<pEdge_2d> fre,tpe,sde;
            while(i<Edges.size()){
                pEdges.push_back(pEdge());
                pEdges[pEdges.size()-1].p1=Edges[i].p1->targ;
                pEdges[pEdges.size()-1].p2=Edges[i].p2->targ;
                i++;
            }
            //now create the edges and save each view;
            //auto myfile=std::cout;
            //ofstream myfile;
            //myfile.open(filename);
            //save nodes for front

            qInfo() << filename;
            QFile file(filename);
            file.open(QIODevice::WriteOnly);
            QTextStream myfile(&file);
            QString line;
            myfile<<"FRONT\n";
            i=0;
            while(i<fr.size()){
                myfile<<fr[i].x<<" "<<fr[i].y;
                for(auto pt:fr[i].vects)myfile<<" "<<pt+1;
                myfile<<"\n";
                i++;
            }
            //create front edges
            myfile<<"EDGES\n";
            i=0;
            while(i<pEdges.size()){
                fre.push_back(pEdge_2d(pPoints[pEdges[i].p1].frv,pPoints[pEdges[i].p2].frv));
                i++;
            }
            sort(fre.begin(),fre.end());
            //remove duplicates
            i=0;
            while(i<fre.size()){
                if(fre[i].a!=fre[i].b && (i==0||!(fre[i-1]==fre[i])))
                    myfile<<fre[i].a<<" "<<fre[i].b<<"\n";
                i++;
            }
            //save nodes for top
            myfile<<"TOP\n";
            i=0;
            while(i<tp.size()){
                myfile<<tp[i].x<<" "<<tp[i].y;
                for(auto pt:tp[i].vects)myfile<<" "<<pt+1;
                myfile<<"\n";
                i++;
            }
            //create top edges
            myfile<<"EDGES\n";
            i=0;
            while(i<pEdges.size()){
                tpe.push_back(pEdge_2d(pPoints[pEdges[i].p1].tpv,pPoints[pEdges[i].p2].tpv));
                i++;
            }
            sort(tpe.begin(),tpe.end());
            //remove duplicates
            i=0;
            while(i<fre.size()){
                if(tpe[i].a!=tpe[i].b && (i==0||!(tpe[i-1]==tpe[i])))
                    myfile<<tpe[i].a<<" "<<tpe[i].b<<"\n";
                i++;
            }
            //save nodes for side
             myfile<<"SIDE\n";
            i=0;
            while(i<sd.size()){
                myfile<<sd[i].x<<" "<<sd[i].y;
                for(auto pt:sd[i].vects)myfile<<" "<<pt+1;

                myfile<<"\n";
                i++;
            }
            //create side edges
            myfile<<"EDGES\n";
            i=0;
            while(i<pEdges.size()){
                sde.push_back(pEdge_2d(pPoints[pEdges[i].p1].sdv,pPoints[pEdges[i].p2].sdv));
                i++;
            }
            sort(sde.begin(),sde.end());
            //remove duplicates
            i=0;
            while(i<sde.size()){
                if(sde[i].a!=sde[i].b && (i==0||!(sde[i-1]==sde[i])))
                    myfile<<sde[i].a<<" "<<sde[i].b<<"\n";
                i++;
            }
            file.close();
        }

        ///Rotate the object
        /**Allows rotation of the object in 3D space about a homogeneous axis. Note that this does not affect the reference points, ie the orthogonal projections remain unchanged*/
        void rotate(/**Anti-clockwise angle of rotation in radians*/float theta, float /**Angle between Axis of Rotation and z axis in radians*/alpha, /**Angle between the projection of Axis of Rotation on the xy plane and x axis in radians*/float beta) {
                    get_mat(theta,alpha,beta);
                    int i=0;
                    while(i<Nodes.size()){
                        Nodes[i]->transform(rot_mat);
                        i++;
                    }
                    ref_Origin.transform(rot_mat);
                    ref_x.transform(rot_mat);
                    ref_y.transform(rot_mat);
        }

        ///Translate the object
        /**Moves the object so that the given coordinates form the new origin. This may be used in conjection with rotate in order to rotate about a non homogeneous axis. Note that this does not affect the reference points, ie the orthogonal projections remain unchanged*/
        void translate(/**x coordinate to map to new origin*/float x, /**x coordinate to map to new origin*/float y, /**x coordinate to map to new origin*/float z){
                    int i=0;
                    while(i<Nodes.size()){
                        Nodes[i]->x-=x;
                        Nodes[i]->y-=y;
                        Nodes[i]->z-=z;
                        i++;
                    };
                    ref_Origin.x-=x;
                    ref_Origin.y-=y;
                    ref_Origin.z-=z;
                    ref_x.x-=x;
                    ref_x.y-=y;
                    ref_x.z-=z;
                    ref_y.x-=x;
                    ref_y.y-=y;
                    ref_y.z-=z;
        };
        ///Scales the object by the given factor
        void scale(float factor){
                    rot_mat[0][0]=factor;
                    rot_mat[0][1]=0.0;
                    rot_mat[0][2]=0.0;
                    rot_mat[1][0]=0.0;
                    rot_mat[1][1]=factor;
                    rot_mat[1][2]=0.0;
                    rot_mat[2][0]=0.0;
                    rot_mat[2][1]=0.0;
                    rot_mat[2][2]=factor;
                    int i=0;
                    while(i<Nodes.size()){
                        Nodes[i]->transform(rot_mat);
                        i++;
                    }
                    ref_Origin.transform(rot_mat);
                    ref_x.transform(rot_mat);
                    ref_y.transform(rot_mat);
        };
        ///Get the orthographic Projection of the Object
        /**Uses reduce function to extract the top, front and side views of the object with the help of the reference points. Restores the object to its original configuration before returning. Side view containing lesser hidden lines is chosen.*/
        Ortho project(/**whether orientation needs to be preserved*/bool pres=false);

        ///Display object on screen.
        void display_3D(/**false for wireframe, true otherwise*/bool show_planes) {


        };
        ///Get the Isometric Projection of the Object.
        /**Uses reduce function to extract an isometric view of the object with the help of the reference points. Hidden lines are removed. Restores the object to its original configuration before returning. Side view containing more detail is chosen.*/
        Model2D getIso(/**whether orientation needs to be preserved*/bool pres=false) {
                    //create a copy of current object
                    float pi=M_PI;
                    Model3D temp;
                    temp.Nodes=Nodes;
                    temp.Edges=Edges;
                    temp.Planes=Planes;
                    temp.ref_x=ref_x;
                    temp.ref_y=ref_y;
                    temp.ref_Origin=ref_Origin;
                    //if(pres)temp.Normalize();
                    temp.rotate(-pi/4.0,pi/2.0,pi/2.0);        //arbitarily selects right side view. need to change this to select better side view
                    temp.rotate(atan(1/sqrt(2)),pi/2.0,0.0);    //there must be a way of merging this rotation with the previous one to save computation
                    return temp.reduce();
        };
        ///Obtain Pespective projection in current orientation
        /**Gives the 1-point perspective projection with eye at origin and screen at z=1. Pushes back object should any part of it lie in front of the screen. Restores the object to its original configuration before returning.*/
        /*Model2D getPerspective() {
                    Model3D temp;
                    temp.Nodes=Nodes;
                    temp.Edges=Edges;
                    temp.Planes=Planes;
                    float min_z=0.0;
                    for(auto iter=Nodes.begin();iter!=Nodes.end(); iter++){
                        if((iter->z)<min_z)min_z=iter->z;
                    }
                    min_z-=1;
                    if(min_z<0)temp.translate(0.0,0.0,min_z);
                    for(auto iter=temp.Nodes.begin();iter!=temp.Nodes.end(); iter++){
                        (iter->x)/=(iter->z);
                        (iter->y)/=(iter->z);
                    }
                    return temp.reduce();
        };*/
        ///Get the front view in the current orientation. Called by all other functions that output Model2D

        Model2D reduce(){
            Model2D out;
            Point temp1,temp2;
            int i=0;
            while(i<Nodes.size()){
                temp1=*Nodes[i];
                Point temp2(temp1.x,temp1.y,0);
                                temp2.label=temp1.label;
                out.Nodes.push_back(temp2);
                i++;
            };
            out.Edges=Edges;            //Hoping this does a deep copy.
                        //need to do a hidden edge assignment here
            return out;
        };
            private:
                float rot_mat[3][3];
        void get_mat(float theta, float alpha, float beta){
            double ux,uy,uz,ct,st;
            uz=cos(alpha*M_PI/180);
                        ux=sin(alpha*M_PI/180)*cos(beta*M_PI/180);
                        uy=sin(alpha*M_PI/180)*sin(beta*M_PI/180);
                        ct=cos(theta*M_PI/180);
                        st=sin(theta*M_PI/180);
                        rot_mat[0][0]=ct+ux*ux*(1.0-ct);
                        rot_mat[0][1]=ux*uy*(1.0-ct)-uz*st;
                        rot_mat[0][2]=ux*uz*(1.0-ct)+uy*st;
                        rot_mat[1][0]=ux*uy*(1.0-ct)+uz*st;
                        rot_mat[1][1]=ct+uy*uy*(1.0-ct);
                        rot_mat[1][2]=uy*uz*(1.0-ct)-ux*st;
                        rot_mat[2][0]=ux*uz*(1.0-ct)-uy*st;
                        rot_mat[2][1]=uy*uz*(1.0-ct)-ux*st;
                        rot_mat[2][2]=ct+uz*uz*(1.0-ct);
        }
};

/// Orthographic Projection class
/**Wrapper around orthographic projection of an object. Also provides functions to convert from 2D to 3D*/
class Ortho {

    public:
        Model2D Top;            ///<Top view
        Model2D Front;          ///<Front view
        Model2D Side;           ///<Side view. Can be left or right side, depending on Side_Is_Left
        bool Side_Is_Left;

        ///Whether all nodes are labelled
        /**While labelling is a must for geometric objects, it is often ommited for machine parts. The 3D conversion may fail if this is false.*/
        bool Nodes_complete;

        ///Save projection as image file
        void export_ortho(){

        };

        ///Display all the views on the screen
        void display_ortho(){

        };

        ///3D Conversion algorithm.
        /**Master method for 2D to 3D conversion. Converges for labelled nodes over 3 views. May or may not converge if some information is missing. Model3D.Extract relies on this */
        Model3D convert_to_3D() {

        };

    private:
            static bool Edge_comp(Edge e1,Edge e2){
                return e1.getcomp()<e2.getcomp();
            }
        /*Model3D generate_probable_wireframe() {
                    Model3D out;
                    auto it1=Top.Nodes.begin();
                    auto it2=Front.Nodes.begin();
                    while(it1!=Top.Nodes.end() && it2!=Front.Nodes.end()){
                        //we have to assume orderring is always protected. a sanity check can be:
                        //it1->label==it2->label;
                        it2->map=new Point(it2->x,it2->y,-(it1->y));
                        out.Nodes.push_back((it2->map));
                        it1++;
                        it2++;
                    }
                    if((Top.Edges_complete && Front.Edges_complete && Side.Edges_complete) ==false){
                        if(Top.Edges_complete==false)Top.complete_edges();
                        if(Front.Edges_complete==false)Front.complete_edges();
                        if(Side.Edges_complete==false)Side.complete_edges();
                        /*
                         * An edge will exist in the 3D wireframe only if it exists in each of the
                         * views. complete_edges will create all possible edges in every view. To
                         * check if an edge exists in every view would be O(n^3) if done naively.
                         * However, if a strict ordering can be imposed, Things can be improved.
                         * For simplicity, we assume corresponding points would have same labels.
                        *//*
                        sort(Top.Edges.begin(),Top.Edges.end(),Edge_comp);
                        sort(Front.Edges.begin(),Front.Edges.end(),Edge_comp);
                        sort(Side.Edges.begin(),Side.Edges.end(),Edge_comp);
                        auto itt=Top.Edges.begin();
                        auto itf=Front.Edges.begin();
                        auto its=Side.Edges.begin();
                        while(itt!=Top.Edges.end() && itf !=Front.Edges.end() && its!= Side.Edges.end()){
                            //Add edge if all three are equal
                            if(itt->getcomp()==itf->getcomp() && itt->getcomp()==its->getcomp()){
                                out.Edges.push_back(Edge(*(itt->p1->map),*(itt->p2->map)));
                                itt++;
                                its++;
                                itf++;
                            }else{
                            //Otherwise increment the smallest pointer
                                if(itt->getcomp()<itf->getcomp()){
                                    if(itt->getcomp()<its->getcomp()){
                                        itt++;
                                    }else{
                                        its++;
                                    }
                                    }else{
                                    if(itf->getcomp()<its->getcomp()){
                                        itf++;
                                    }else{
                                        its++;
                                    }
                                }
                            }
                        }
                        //this is most likely correct, but I cannot prove it. We might need a sanity check.
                    }else{
                    auto it3=Top.Edges.begin();
                    while(it3!=Top.Edges.end()){
                        out.Edges.push_back(Edge(*(it3->p1->map),*(it3->p2->map)));
                    }
                    //sort the edges for uniformity
                    sort(out.Edges.begin(),out.Edges.end(),Edge_comp);
                    }
                    return out;
        };*/


        Model3D generate_probable_faces(Model3D input) {
                    //here we can assume edges to be sorted
        };

        Model3D  eliminate_ghosts(Model3D input) {

        }
};

#endif // FUNCS_H
