#include "Vector3D.h"
#include <iostream>
using namespace std;
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

Vector3D Vector3D::operator +(const Vector3D &v) const
{
    return Vector3D( x + v.x , y + v.y , z + v.z);
}


Vector3D Vector3D::operator -(const Vector3D &v) const
{
    return Vector3D( x - v.x , y - v.y , z - v.z);
}

double Vector3D::operator *(const Vector3D &v) const
{
    return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3D operator *(const Vector3D &v,double c)
{
    return Vector3D (v.x * c, v.y*c, v.z*c);
}

Vector3D operator *(double c,const Vector3D &v)
{
    return Vector3D (c*v.x,c*v.y,c*v.z);
}


Vector3D Vector3D::operator /(double c) const
{
    return Vector3D( x / c , y / c , z / c);
}

Vector3D Vector3D::operator ^(const Vector3D &v) const
{
    return  Vector3D( (y*v.z - v.y*z), - (x*v.z - v.x*z), (x*v.y - v.x*y));
}

Vector3D& Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

void Vector3D::mostrar(){
    cout <<"<"<< x <<","<< y <<","<< z<<">"<<endl;
}