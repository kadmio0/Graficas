#ifndef PLANO_H
#define PLANO_H
#include "Rayo.h"
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
class Plano : public ObjetoGeometrico
{
    public:
    Plano(Punto3D, Vector3D);
    ~Plano();
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor(); 
    ColorRGB obtenerColorTextura(double u,double v);
    void establecerTextura(Image& img);
    double calcularU(Vector3D& n);
    double calcularV(Vector3D& n);


    Punto3D p;
    Vector3D n;
    ColorRGB color;
    Image img;
};
#endif