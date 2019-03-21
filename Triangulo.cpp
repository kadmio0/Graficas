#include "Triangulo.h"
#include<iostream>
using namespace std;
Triangulo::Triangulo(Punto3D a, Punto3D b, Punto3D c)
{
    A = a;
    B = b;
    C = c;
}

bool Triangulo::hayImpacto(const Rayo& rayo, double& tmin, Vector3D& n, Punto3D& q) const
{
    
    double a = A.x - B.x;
    double b = A.x - C.x;
    double c = rayo.d.x;
    double d = A.x - rayo.o.x;

    double e = A.y - B.y;
    double f = A.y - C.y;
    double g = rayo.d.y;
    double h = A.y - rayo.o.y;

    double i = A.z - B.z;
    double j = A.z - C.z;
    double k = rayo.d.z;
    double l = A.z - rayo.o.z;

    double determinante = a * ( f * k - g * j ) + b * ( g * i - e * k ) + c * ( e * j - f * i );

    double beta = (d * ( f * k - g * j ) + b * (g*l -h *k) + c * ( h * j - f * l )) / determinante;
    double gama = (a * ( h * k - g * l ) - d * ( e * k - g* i ) +c * ( e * l - h * i)) / determinante;
    double t = (a * ( f * l - h * j ) - b * ( e * l - h * i ) + d * ( e * j - f * i ))/determinante;

    if(beta + gama > 1.0 || beta + gama <0.0)
    {
        return false;
    } 
    if(beta < 0.0 || beta >1.0) 
    {
        return false;
    } 
    if(gama < 0.0 || gama>1.0) 
    {
        return false;
    }  
    tmin = t;
    return true;
}

void Triangulo::establecerColor(double v_r, double v_g, double v_b)
{
    color.r = v_r;
    color.g = v_g;
    color.b = v_b;
}

ColorRGB Triangulo::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}
