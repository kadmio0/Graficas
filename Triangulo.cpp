#include "Triangulo.h"
#include<iostream>
using namespace std;
Triangulo::Triangulo(Punto3D a, Punto3D b, Punto3D c)
{
    A = a;
    B = b;
    C = c;
}
bool Triangulo::hayImpacto(const Rayo& r, double& tmin, Vector3D& n, Punto3D& q) const
{
    // Cambio de variables
    double a = A.x - B.x;
    double b = A.x - C.x;
    double c = r.d.x;
    double d = A.x -r.o.x;
    double e = A.y - B.y;
    double f = A.y - C.y;
    double g = r.d.y;
    double h = A.y - r.o.y;
    double i = A.z - B.z;
    double j = A.z - C.z;
    double k = r.d.z;
    double l = A.z - r.o.z;

    double det = a * ( f * k - g * j ) + b * ( g * i - e * k ) + c * ( e * j - f * i );

    double beta = (d * ( f * k - g * j ) + b * (g*l -h *k) + c * ( h * j - f * l )) / det;
    double gama = (a * ( h * k - g * l ) - d * ( e * k - g* i ) +c * ( e * l - h * i)) / det;
    double t = (a * ( f * l - h * j ) - b * ( e * l - h * i ) + d * ( e * j - f * i ))/det;

    if ( beta < 0.0) 
    {
        return false;
    } 
    if ( gama < 0.0 ) 
    {
        return false;
    }
    if ( beta + gama > 1.0)
    {
        return false;
    }
    if ( t < 0.00000001)
    {
        return false;
    }
    tmin = t;
    n = (( B - A )^( C - A)).hat();
    q = r.o + t * r.d;
    // n.mostrar_vector();
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

double Triangulo::calcularU(Vector3D& n){
    return 0;
}

double Triangulo::calcularV(Vector3D& n){
    return 0;
}


ColorRGB Triangulo::obtenerColorTextura(double u,double v){
    int column = u * img.hres;
    int row = v * img.vres; 
    return img.get_color(row,column);
}

void Triangulo::establecerTextura(Image& img2){
    img = img2;
    if(img.pixels.empty()){
        textura=false;
    }
    else
    {
        textura=true;
    } 
}

bool Triangulo::tieneTextura(){
    return textura;
}