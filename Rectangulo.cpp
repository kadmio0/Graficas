// 	Copyright (C) Kevin Suffern 2000-2007.
//	Revised by mp77 at 2012
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "Rectangulo.h"
using namespace std;
Rectangulo::Rectangulo(const Punto3D _p0, const Vector3D _a, const Vector3D _b)
	:	p0(_p0),
		a(_a),
		b(_b),
		width((_a.x * _a.x + _a.y * _a.y + _a.z * _a.z)), 
		height((_b.x * _b.x + _b.y * _b.y + _b.z * _b.z))
{
	normal= (a ^ b).hat();
	cout<<normal.x<<endl;
	cout<<normal.y<<endl;
	cout<<normal.z<<endl;
	// cout<<"RECwidth: "<<width<<endl;
	// cout<<"RECheight: "<<height<<endl;
	color.r=0.0;	
	color.g=0.0;
	color.b=1.0;
	index=0;
} 
 
Rectangulo::~Rectangulo () {
 
}
 
bool Rectangulo::hayImpacto(const Rayo& rayo, double& tmin, Vector3D& n, Punto3D& q ) const {	
 
	double t = (p0 - rayo.o) * normal / (rayo.d * normal); 
	
	if (t <= 0.001) //0.00000001
		return (false);
			
	Punto3D p = rayo.o + t * rayo.d;
	Vector3D d = p - p0;
	
	double ddota = d * a;
	
	if (ddota < 0.0 || ddota > width)
		return (false);
		
	double ddotb = d * b;
	
	if (ddotb < 0.0 || ddotb > height)
		return (false);
		
	tmin = t;
	n = normal;
	q = p;
	
	return (true);
} 

void Rectangulo::establecerColor(double v_r, double v_g, double v_b)
{
    color.r = v_r;
    color.g = v_g;
    color.b = v_b;
}

ColorRGB Rectangulo::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}
 
double Rectangulo::calcularU(Vector3D& n,Punto3D& q){ 
    return (n.z+1)/2; 
}

double Rectangulo::calcularV(Vector3D& n,Punto3D& q){ 
	return (n.x+1)/2;
}


ColorRGB Rectangulo::obtenerColorTextura(double u,double v){
    int column = (img.hres) * u;
    int row = (img.vres) * v; 
	index++;
    return img.get_color(index);
}

void Rectangulo::establecerTextura(Image& img2){
    img = img2;
    if(!img.pixels.empty()){
        textura = true;
    }
}

bool Rectangulo::tieneTextura(){
    return textura;
}

																			

  