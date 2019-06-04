#include "Esfera.h"
#include<iostream>
#include <math.h>   
using namespace std; 


Esfera::Esfera(Punto3D v_c, double v_r):c( v_c), r( v_r)
{ 
    color.r = 1.0;
    color.g = 1.0;
    color.b = 0.0;
}

Esfera::~Esfera(){}
bool Esfera::hayImpacto(const Rayo& rayo, double& tmin, Vector3D& n, Punto3D& q) const
{
    double t;
    Vector3D temp = rayo.o - c;
    double a = rayo.d * rayo.d;
    double b = 2 * rayo.d * temp;
    double c = (temp * temp)  -  (r * r) ;
    double discriminante = b * b - 4.0 * a * c;
    if ( discriminante < 0.0 )
    {
        return false;
    } 
    else
    {
       double disc_eval = sqrt(discriminante);
       double denominador = 2.0 * a;
       // smaller root
       t = (-b - disc_eval)/denominador;
       if( t >  0.00000001 )
       {
           q = rayo.o + t * rayo.d; 
           n = (temp + t * rayo.d) / r;
           tmin = t;
           return true;
       }
       // larger root
       t = (-b + disc_eval)/denominador;
       if( t >  0.00000001 )
       {
           q = rayo.o + t * rayo.d; 
           n = (temp + t * rayo.d) / r;
           tmin = t;
           return true;
       }
    }
}

void Esfera::establecerColor(double v_r, double v_g, double v_b)
{
    color.r = v_r;
    color.g = v_g;
    color.b = v_b;
}

ColorRGB Esfera::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}

// double phi = atan2(n2.y, n2.x);
// double theta = asin(n2.z);
// u= phi / (2 * PI);
// v = theta / PI;

double Esfera::calcularU(Vector3D& n,Punto3D& q){
    double PI = 3.14159265358979323846;
    Vector3D normal = n;
    normal.hat();
    double phi  = atan2(normal.z, normal.x);
    
    return  0.5 + phi / (2 * PI);
    //u = 1 - phi / (2*PI);
}

double Esfera::calcularV(Vector3D& n,Punto3D& q){
    double PI = 3.14159265358979323846;
    Vector3D normal = n;
    normal.hat();
    double theta = asin(normal.y);
    // X - theta  X = 0 abajo     X = 1 arriba     
    return  0.5 - theta / PI;
    //v = (theta + PI / 2) / PI;
}


ColorRGB Esfera::obtenerColorTextura(double u,double v){
    int column = u * img.hres;
    int row = v * img.vres; 
    return img.get_color(row,column);
}

void Esfera::establecerTextura(Image& img2){
    img = img2;
    if(!img.pixels.empty()){
        textura = true;
    }
}

bool Esfera::tieneTextura(){
    return textura;
}
