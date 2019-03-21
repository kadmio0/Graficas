/*---------------------------------------------------------------------------------------------------------------------*/    
/*Vector3D.h*/
#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D
{
    public:
    Vector3D();                                              // constructor por defecto
    Vector3D(const Vector3D& v);                             // Constructor copia 
    Vector3D(double n);                                      // constructor 
    Vector3D(double v_x, double v_y, double v_z);            // constructor
    ~Vector3D();

    Vector3D& operator= (const Vector3D& v);                 // Asignacion
    Vector3D operator+ (const Vector3D& v) const;            // Sumar dos vectores
    Vector3D operator- (const Vector3D& v) const;            // Restar dos vectores
    double operator* (const Vector3D& v) const;              // Producto escalar
    Vector3D operator^ (const Vector3D& v) const;            // Producto vectorial
    friend Vector3D operator* (double n, const Vector3D& v); // Multiplicar un escalar por un vector 
    Vector3D operator* (const double n) const;               // Multiplicar un vector por un escalar
    Vector3D operator/ (const double n) const;               // Dividir por un escalar
    
    Vector3D& hat();							             // Convertir el vector a un vector unitario y retornar el vector

    public:
    double x; // componente x
    double y; // componente y
    double z; // componente z

    public:
    void mostrar_vector();
};
#endif
/*Vector3D.cpp*/
#include <iostream>
#include <math.h>
using namespace std;
#include "Vector3D.h"

Vector3D::Vector3D():x(0.0), y(0.0), z(0.0)
{}
Vector3D::Vector3D(const Vector3D& v): x(v.x), y(v.y), z(v.z) 
{}
Vector3D::Vector3D(double n): x(n), y(n), z(n)
{}
Vector3D::Vector3D(double v_x, double v_y, double v_z): x(v_x), y(v_y), z(v_z)
{}
Vector3D::~Vector3D()
{}
//  Asignacion ---------------------------------------------------------------------------------------------------------
Vector3D& Vector3D::operator= (const Vector3D& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
//  Sumar dos vectores -------------------------------------------------------------------------------------------------
Vector3D Vector3D::operator+ (const Vector3D& v) const
{
    return(Vector3D( x + v.x, y + v.y, z + v.z));
}

//  Restar dos vectores -----------------------------------------------------------------------------------------------
Vector3D Vector3D::operator- (const Vector3D& v) const 
{
    return (Vector3D(x - v.x, y - v.y, z - v.z));
}
// Producto escalar ---------------------------------------------------------------------------------------------------
double Vector3D::operator* (const Vector3D& v) const
{
    return (x * v.x + y * v.y + z * v.z);
}
// Producto vectorial -------------------------------------------------------------------------------------------------
Vector3D Vector3D::operator^ (const Vector3D& v) const
{
    return (Vector3D( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}
// Multiplicar un escalar por un vector -------------------------------------------------------------------------------
Vector3D operator*(double n, const Vector3D& v)
{
    return( Vector3D(n*v.x, n*v.y, n*v.z));
}

// Multiplicar un vector por un escalar -------------------------------------------------------------------------------
Vector3D Vector3D::operator*(const double n) const
{
    return(Vector3D(x * n, y * n, z* n));
}

// Dividir un vector entre un numero ----------------------------------------------------------------------------------
Vector3D Vector3D::operator/ (const double n) const 
{
    return(Vector3D( x / n, y / n, z / n));
}


Vector3D& Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

// Utilitarios --------------------------------------------------------------------------------------------------------
void Vector3D::mostrar_vector()
{
    cout <<"<"<< x <<","<< y <<","<< z<<">"<<endl;
}





/*---------------------------------------------------------------------------------------------------------------------*/    
/*Punto3D.h*/
#ifndef PUNTO3D_H
#define PUNTO3D_H
#include "Vector3D.h"
class Punto3D
{
    public:
    Punto3D();                                             // Constructor por defecto
    Punto3D(double n);                                     // Constructor
    Punto3D(double v_x, double v_y, double v_z);           // Constructor
    Punto3D(const Punto3D& p);                             // Constructor copia
    ~Punto3D();                                            // Destructor
    Vector3D operator- (const Punto3D& p) const;           // Restar dos puntos
    Punto3D operator+ (const Vector3D& v) const;           // Sumar al punto un vector
    Punto3D operator- (const Vector3D& v) const;           // Restar al punto un vector
    Punto3D operator* (const double n) const;              // Multiplicar un punto por un numero
    friend Punto3D operator* (double n, const Punto3D& p); // Multiplicar un mumero por un punto
    public:    
    double x, y, z;
};
#endif


/*Punto3D.cpp*/
#include"Punto3D.h"
Punto3D::Punto3D(): x(0), y(0), z(0)
{}
Punto3D::Punto3D(double n): x(n), y(n), z(n)
{}
Punto3D::Punto3D(double v_x, double v_y, double v_z): x(v_x), y(v_y), z(v_z)
{}
Punto3D::Punto3D(const Punto3D& p): x(p.x), y(p.y), z(p.z)
{}
Punto3D::~Punto3D()
{}

// Restar dos puntos --------------------------------------------------------------------------------------------------
Vector3D Punto3D::operator-(const Punto3D& p) const{
    return (Vector3D(x - p.x, y - p.y, z - p.z));
}
// Sumar al punto un vector -------------------------------------------------------------------------------------------
Punto3D Punto3D::operator+(const Vector3D& v) const
{
    return (Punto3D(x + v.x, y + v.y, z + v.z));
}
// Retar al punto un vector -------------------------------------------------------------------------------------------
Punto3D Punto3D::operator-(const Vector3D& v) const
{
    return (Punto3D(x - v.x, y - v.y, z - v.z));
}
// Multiplicar un punto por un numero ---------------------------------------------------------------------------------
Punto3D Punto3D::operator*(const double n) const 
{
    return (Punto3D( x * n, y * n, z * n));
}
// Multiplicar un numero por un punto ---------------------------------------------------------------------------------
Punto3D operator*(double n, const Punto3D& p)
{
    return (Punto3D(n * p.x , n * p.y, n * p.z));
}




/*---------------------------------------------------------------------------------------------------------------------*/    
/*Rayo.h*/


#ifndef RAYO_H
#define RAYO_H
#include "Punto3D.h"
class Rayo
{   
    public:
    Rayo();
    Rayo(const Punto3D& origen, const Vector3D& direccion);
    ~Rayo();
    
    public:
    Punto3D o;
    Vector3D d;

};
#endif

/*Rayo.cpp*/
#include "Rayo.h"
Rayo::Rayo(): o(0.0), d(0.0, 0.0, 1.0)
{}
Rayo::Rayo(const Punto3D& origen, const Vector3D& direccion): o(origen), d(direccion)
{}
Rayo::~Rayo(){}















