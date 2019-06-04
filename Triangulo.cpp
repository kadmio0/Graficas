#include "Triangulo.h"
#include<iostream>
using namespace std;
Triangulo::Triangulo(Punto3D a, Punto3D b, Punto3D c)
{
    A = a;
    B = b;
    C = c;
    color.r = 1.0;
    color.g = 1.0;
    color.b = 1.0;
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

double Triangulo::calcularU(Vector3D& normal,Punto3D& q){
    // double BaryA = ( (B.y-C.y)*(q.x-C.x) + (C.x-B.x)*(q.y-C.y) ) / ( (B.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y) );
    // double BaryB = ( (C.y-A.y)*(q.x-C.x) + (A.x-C.x)*(q.y-C.y) ) / ( (B.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y) );
    // double BaryC = 1 - BaryA - BaryB; 
    // return BaryA;

    /*double a = A.x - B.x, b = A.x - C.x, c = normal.x, d = A.x - normal.x; 
    double e = A.y - B.y, f = A.y - C.y, g = normal.y, h = A.y - normal.y; 
    double i = A.z - B.z, j = A.z - C.z, k = normal.z, l = A.z - normal.z; 

    double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
    double q = g * i - e * k, r = e * l - h * i, s = e * j - f * i;

    double invDem = 1 / (a * m + b * q + c * s);
    double e1 = d * m - b * n - c * p;
    double beta = e1 * invDem;
    double e2 = a * n + d * q  + c * r;
    double gamma = e2 * invDem;
    double e3 = a * p - b * r + d * s;
    double t = e3 * invDem;
    double u = (1 - beta - gamma) * normal.x + beta * normal.y + gamma * normal.z;*/
     
    double ABC = normal * ((B-A)^(C-A));
    double PBC = normal * ((B-q)^(C-q));
    double PCA = normal * ((C-q)^(A-q));
    
    double baryX = PBC /  ABC ; // alpha
    double baryY = PCA /  ABC ; // beta
    double baryZ = 1.0 - baryX - baryY ; // gamma 

    return baryZ;
}

double Triangulo::calcularV(Vector3D& normal,Punto3D& q){
    // double BaryA = ( (B.y-C.y)*(normal.x-C.x) + (C.x-B.x)*(normal.y-C.y) ) / ( (B.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y) );
    // double BaryB = ( (B.y-C.y)*(normal.x-C.x) + (A.x-B.x)*(normal.y-C.y) ) / ( (A.y-C.y)*(A.x-C.x) + (C.x-B.x)*(A.y-C.y) );
    // double BaryC = 1 - BaryA - BaryB; 
    // return BaryC; 
     
    double ABC = normal * ((B-A)^(C-A));
    double PBC = normal * ((B-q)^(C-q));
    double PCA = normal * ((C-q)^(A-q));
    
    double baryX =  PBC / ABC ; // alpha
    double baryY =  PCA / ABC ; // beta
    double baryZ = 1.0 - baryX - baryY ; // gamma 

    return baryX;
}


ColorRGB Triangulo::obtenerColorTextura(double u,double v){
    int column = u * (img.hres);
    int row = v * (img.vres); 
    return img.get_color(row,column);
}

void Triangulo::establecerTextura(Image& img2){
    img = img2;
    if(!img.pixels.empty()){
        textura = true;
    }
}

bool Triangulo::tieneTextura(){
    return textura;
}