#ifndef ESFERA_H
#define ESFERA_H
#include "Rayo.h"
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
class Esfera : public ObjetoGeometrico
{
    public:
    Esfera(Punto3D, double);
    ~Esfera();
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor();

    Punto3D c;
    double r;
    ColorRGB color;
};
#endif