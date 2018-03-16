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
class pPoint_3d{
public:
    pPoint_2d *src_tp;
    pPoint_2d *src_fr;
    pPoint_2d *src_sd;
    vector<int> emans;
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
};
#endif // RECONST_H
