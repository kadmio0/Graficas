#ifndef ESFERA_H
#define ESFERA_H
#include "Rayo.h"
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
#include "Image.h"
class Esfera : public ObjetoGeometrico
{
    public:
    Esfera(Punto3D, double);
    ~Esfera();
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor();
    ColorRGB obtenerColorTextura(double u,double v);
    void establecerTextura(Image& img);
    double calcularU(Vector3D& n,Punto3D& q);
    double calcularV(Vector3D& n,Punto3D& q);
    bool tieneTextura();

    Punto3D c;
    double r;
    ColorRGB color;
    Image img;
    bool textura = false;
};
#endif