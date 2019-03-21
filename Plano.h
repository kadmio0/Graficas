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

    Punto3D p;
    Vector3D n;
    ColorRGB color;
};
#endif