#include<funcs.h>
#ifndef MODEL_PROJECT
#define MODEL_PROJECT
Ortho Model3D::project(/**whether orientation needs to be preserved*/bool pres){
                    float pi=M_PI;
                    Model3D temp;
                    temp.Nodes=Nodes;
                    temp.Edges=Edges;
                    temp.Planes=Planes;
                    Ortho out;
                    out.Front=temp.reduce();
                    temp.rotate(pi/2.0,pi/2.0,0.0);
                    out.Top=temp.reduce();
                    temp.rotate(-pi/2.0,pi/2.0,0.0);
                    temp.rotate(-pi/2.0,pi/2.0,pi/2.0);          //arbitarily selects right side view. need to change this to select better side view
                    out.Side=temp.reduce();
                    out.Side_Is_Left=false;
                    out.Nodes_complete=true;
                    return out;
        }
#endif
