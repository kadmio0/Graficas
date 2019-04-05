#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Plano.h"
#include "Triangulo.h"
#include "Utilitarios.h"
using namespace std;

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
            // color.r = objetos[i]->obtenerColor().r;
            // color.g = objetos[i]->obtenerColor().g;
            // color.b = objetos[i]->obtenerColor().b;

            // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() );
            // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() );
            // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() );

            color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),150000);
            color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),150000);
            color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),150000);

            tmin = t;
        }
    }
    return color;
}

int main() {

    // ESCENA------------------------------------------------------------------
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 90;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.976, 0.474, 0.082);// entre [0-1]

    Punto3D centro2(-125.0, 180.0, -200.0); 
    Esfera esfera2(centro2, radio1);   
    esfera2.establecerColor(0.976, 0.474, 0.082);

    Punto3D centro3(125.0, 180.0, -200.0); 
    Esfera esfera3(centro3, radio1);   
    esfera3.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro4(250.0, 0.0, -200.0); 
    Esfera esfera4(centro4, radio1);   
    esfera4.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro5(-250.0, 0.0, -200.0); 
    Esfera esfera5(centro5, radio1);   
    esfera5.establecerColor(0.976, 0.474, 0.082);

    Punto3D centro6(125.0, -180.0, -200.0); 
    Esfera esfera6(centro6, radio1);   
    esfera6.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro7(-125.0, -180.0, -200.0); 
    Esfera esfera7(centro7, radio1);   
    esfera7.establecerColor(0.976, 0.474, 0.082);

    //7 estrellas---------------------------------------------------------------------
    //centro
    Punto3D A(-10.0,-10.0,-300.0);
    Punto3D B(10.0,-10.0,-300.0);
    Punto3D C(0.0, 10.0, -300.0);
    Triangulo triangulo(A,B,C);
    triangulo.establecerColor(0.709, 0.031, 0.043);
    
    //estrellas arriba
    Punto3D A2(-30.0,20.0,-300.0);
    Punto3D B2(-10.0,20.0,-300.0);
    Punto3D C2(-20.0,40.0, -300.0);
    Triangulo triangulo2(A2,B2,C2);
    triangulo2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A3(10.0,20.0,-300.0);
    Punto3D B3(30.0,20.0,-300.0);
    Punto3D C3(20.0,40.0, -300.0);
    Triangulo triangulo3(A3,B3,C3);
    triangulo3.establecerColor(0.709, 0.031, 0.043);
    
    //estrellas laterales
    Punto3D A4(-50.0,-10.0,-300.0);
    Punto3D B4(-30.0,-10.0,-300.0);
    Punto3D C4(-40.0, 10.0, -300.0);
    Triangulo triangulo4(A4,B4,C4);
    triangulo4.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A5(30.0,-10.0,-300.0);
    Punto3D B5(50.0,-10.0,-300.0);
    Punto3D C5(40.0, 10.0, -300.0);
    Triangulo triangulo5(A5,B5,C5);
    triangulo5.establecerColor(0.709, 0.031, 0.043);
    
    //estrellas abajo    
    Punto3D A6(-30.0,-40.0,-300.0);
    Punto3D B6(-10.0,-40.0,-300.0);
    Punto3D C6(-20.0,-20.0, -300.0);
    Triangulo triangulo6(A6,B6,C6);
    triangulo6.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A7(10.0,-40.0,-300.0);
    Punto3D B7(30.0,-40.0,-300.0);
    Punto3D C7(20.0,-20.0, -300.0);
    Triangulo triangulo7(A7,B7,C7);
    triangulo7.establecerColor(0.709, 0.031, 0.043);

    //1 estrella---------------------------------------------------------------------
    //(-125.0, 180.0, -200.0);
    Punto3D A8(-135.0,170,-300.0);
    Punto3D B8(-115.0,170,-300.0);
    Punto3D C8(-125.0,190,-300.0);
    Triangulo triangulo8(A8,B8,C8);
    triangulo8.establecerColor(0.709, 0.031, 0.043);

    //2 estrellas (125.0, 180.0, -400.0)---------------------------------------------------------------------
    Punto3D A9(90.0,180,-300.0);
    Punto3D B9(110.0,180,-300.0);
    Punto3D C9(100.0,200,-300.0);
    Triangulo triangulo9(A9,B9,C9);
    triangulo9.establecerColor(0.709, 0.031, 0.043);

    Punto3D A10(140.0,160,-300.0);
    Punto3D B10(160.0,160,-300.0);
    Punto3D C10(150.0,180,-300.0);
    Triangulo triangulo10(A10,B10,C10);
    triangulo10.establecerColor(0.709, 0.031, 0.043);

    //5 estrellas (250.0, 0.0, -400.0)-----------------------------------------------------------------
    
    Punto3D A11(-260.0,-10.0,-300.0);
    Punto3D B11(-240.0,-10.0,-300.0);
    Punto3D C11(-250.0,10.0,-300.0);
    Triangulo triangulo11(A11,B11,C11);
    triangulo11.establecerColor(0.709, 0.031, 0.043);

    Punto3D A12(-295.0,0.0,-300.0);
    Punto3D B12(-275.0,0.0,-300.0);
    Punto3D C12(-285.0,20.0,-300.0);
    Triangulo triangulo12(A12,B12,C12);
    triangulo12.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A13(-225.0,0.0,-300.0);
    Punto3D B13(-205.0,0.0,-300.0);
    Punto3D C13(-215.0,20.0,-300.0);
    Triangulo triangulo13(A13,B13,C13);
    triangulo13.establecerColor(0.709, 0.031, 0.043);

    Punto3D A14(-260.0,25.0,-300.0);
    Punto3D B14(-240.0,25.0,-300.0);
    Punto3D C14(-250.0,45.0,-300.0);
    Triangulo triangulo14(A14,B14,C14);
    triangulo14.establecerColor(0.709, 0.031, 0.043);

    Punto3D A15(-280.0,-35.0,-300.0);
    Punto3D B15(-260.0,-35.0,-300.0);
    Punto3D C15(-270.0,-15.0,-300.0);
    Triangulo triangulo15(A15,B15,C15);
    triangulo15.establecerColor(0.709, 0.031, 0.043);

    Punto3D A16(-240.0,-35.0,-300.0);
    Punto3D B16(-220.0,-35.0,-300.0);
    Punto3D C16(-230.0,-15.0,-300.0);
    Triangulo triangulo16(A16,B16,C16);
    triangulo16.establecerColor(0.709, 0.031, 0.043);    
    
    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);
    escena.push_back(&esfera3);
    escena.push_back(&esfera4);
    escena.push_back(&esfera5);
    escena.push_back(&esfera6);
    escena.push_back(&esfera7);
    escena.push_back(&triangulo);
    escena.push_back(&triangulo2);
    escena.push_back(&triangulo3);
    escena.push_back(&triangulo4);
    escena.push_back(&triangulo5);
    escena.push_back(&triangulo6);
    escena.push_back(&triangulo7);
    escena.push_back(&triangulo8);
    escena.push_back(&triangulo9);
    escena.push_back(&triangulo10);
    escena.push_back(&triangulo11);
    escena.push_back(&triangulo12);
    escena.push_back(&triangulo13);
    escena.push_back(&triangulo14);
    escena.push_back(&triangulo15);
    
     // VIEWPLANE
    int hres = 800;
    int vres = 600;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);


     // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];


     // ALGORITMO
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);//x y z  siendo z vector unitario
            double x = vp.s * ( col - vp.hres/2 + 0.5 );
            double y = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z = 100;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
