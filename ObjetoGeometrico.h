#ifndef OBJETO_GEOMETRICO_H
#define OBJETO_GEOMETRICO_H
#include "Rayo.h"
#include "ColorRGB.h"
#include "Image.h"
#include <math.h>
class ObjetoGeometrico{
    public:
    ObjetoGeometrico();
    virtual bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const = 0;
    virtual ColorRGB obtenerColor() = 0;
    virtual ColorRGB obtenerColorTextura(double u,double v) = 0;
    virtual void establecerTextura(Image& img) = 0;
    virtual double calcularU(Vector3D& n) = 0;
    virtual double calcularV(Vector3D& n) = 0; 
    virtual bool tieneTextura() = 0;
};
#endif