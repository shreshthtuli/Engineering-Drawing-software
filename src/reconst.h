#ifndef RECONST_H
#define RECONST_H
#include<vector>
#include<string>
#include<set>
#include<iostream>
using namespace std;
class pPoint_3d;
class pEdge;
class pPoint_2d{
public:
    set<int> vects;
    set<int> adjs;
    int self;
    float x,y;

    bool operator ==(const int p){
        return vects.count(p)>0;
    }

};
class pEdge_2d{
public:
    int a,b;
    pEdge_2d(int a1, int b1){
        if(a1>b1){
            a=b1;
            b=a1;
        }else{
            a=a1;
            b=b1;
        }
    }
    bool operator==(pEdge_2d &p){
        return p.a==a && p.b==b;
    }
    bool operator<(pEdge_2d &p){
        return a<p.a ||(a==p.a && b<p.b);
    }
};
class pPoint_3d{
public:
    pPoint_2d *src_tp;
    pPoint_2d *src_fr;
    pPoint_2d *src_sd;
    vector<int> emans;
    int self,tpv,frv,sdv;   //to be used only while saving
    float x,y,z;
    void set(){
        x=src_fr->x;
        y=src_fr->y;
        z=-(src_tp->y);
    }
};
class pEdge{
public:
    int p1,p2;
    int pcount;
    pEdge(){
        pcount=0;
    }
};
class pPlane{
public:
    vector<int> points;
    vector<pPoint_3d> coordinates;
    float a,b,c,d;
    bool admits(pPoint_3d pt, bool set=true){
        float err=0.01 ;        //allowed error for co-planarity
        if(points.size()<2){
            return true;
        }
        else if(points.size()==3 && set==true){
            //compute the normal
            int x1=(coordinates[0].x-coordinates[1].x);
            int y1=(coordinates[0].y-coordinates[1].y);
            int z1=(coordinates[0].z-coordinates[1].z);
            int x2=(coordinates[0].x-coordinates[2].x);
            int y2=(coordinates[0].y-coordinates[2].y);
            int z2=(coordinates[0].z-coordinates[2].z);
            a=y1*z2-y2*z1;
            b=z1*x2-z2*x1;
            c=x1*y2-x2*y1;
            d=a*coordinates[0].x+b*coordinates[0].y+c*coordinates[0].z;
            return true;
        }else{
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            cout<<pt.x<<" "<<pt.y<<" "<<pt.z<<endl;
            cout<<(abs(a*pt.x+b*pt.y+c*pt.z-d))<<endl;
            return abs(a*pt.x+b*pt.y+c*pt.z-d)<err;
        }
    }
};
#endif // RECONST_H

