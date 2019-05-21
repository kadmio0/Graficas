#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Rayo.h"
#include "ColorRGB.h"
#include "ObjetoGeometrico.h"
class Triangulo : public ObjetoGeometrico
{
public:
    Triangulo(Punto3D, Punto3D, Punto3D);
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor(); 
    ColorRGB obtenerColorTextura(double u,double v);
    void establecerTextura(Image& img);
    double calcularU(Vector3D& n);
    double calcularV(Vector3D& n);
    bool tieneTextura();


    Punto3D A, B, C;
    ColorRGB color;
    Image img;
    bool textura;
};

#endif