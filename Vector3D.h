#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <math.h>
using namespace std;
class Vector3D
{
    public:
    Vector3D();                                              // constructor por defecto
    Vector3D(const Vector3D& v);                             // Constructor copia 
    Vector3D(double n);                                      // constructor 
    Vector3D(double v_x, double v_y, double v_z);            // constructor
    ~Vector3D();
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    Vector3D operator/(double c) const;
    Vector3D operator^(const Vector3D& v) const;
    double operator*(const Vector3D& v) const;
    friend Vector3D operator*(const Vector3D& v,double n);
    friend Vector3D operator*(double n,const Vector3D& v);
    
    Vector3D& hat();
    void mostrar();
    public:
    double x, y, z;
};
#endif