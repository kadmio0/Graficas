// 	Copyright (C) Kevin Suffern 2000-2007.
//	Revised by mp77 at 2012
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "ObjetoGeometrico.h"

class Rectangulo: public ObjetoGeometrico 
{	
	public:  
		Rectangulo(const Punto3D _p0, const Vector3D _a, const Vector3D _b);
		  												
		~Rectangulo();

		bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const;
		void establecerColor(double v_r, double v_g, double v_b);
    	ColorRGB obtenerColor();
    	ColorRGB obtenerColorTextura(double u,double v);
    	void establecerTextura(Image& img);
     	double calcularU(Vector3D& n,Punto3D& q);
	 	double calcularV(Vector3D& n,Punto3D& q); 
    	bool tieneTextura();
	public:
	
		Punto3D 		p0;   			// corner vertex 
		Vector3D		a;				// side
		Vector3D		b;				// side
		Vector3D 		normal;
		double			width;	// square of the length of side a
		double			height;	// square of the length of side b 

		ColorRGB color;
    	Image img;
		int index;
    	bool textura = false;	 
};
#endif