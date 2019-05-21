#include "Plano.h"
#include<iostream>
#include <math.h>
using namespace std;

Plano::Plano(Punto3D v_p, Vector3D v_n):p(v_p), n(v_n)
{ 
}
Plano::~Plano(){}
bool Plano::hayImpacto(const Rayo& rayo, double& tmin, Vector3D& n, Punto3D& q) const
{
    double t;
    Vector3D  tempVector = rayo.o - p; 
    double temp2 = rayo.d * n;
    t = (tempVector * n) / temp2;
    if(t>0.0)
    {
        tmin = t;
        return true;
    }
    return false;
    
}
void Plano::establecerColor(double v_r, double v_g, double v_b)
{
    color.r = v_r;
    color.g = v_g;
    color.b = v_b;
}

ColorRGB Plano::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}
 

double Plano::calcularU(Vector3D& n){
    return 0;
}

double Plano::calcularV(Vector3D& n){
    return 0;
}


ColorRGB Plano::obtenerColorTextura(double u,double v){
    int column = u * img.hres;
    int row = v * img.vres; 
    return img.get_color(row,column);
}

void Plano::establecerTextura(Image& img2){
    img = img2;
}