#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Utilitarios.h"
#include "LuzPuntual.h"
#include "Triangulo.h"
#include "Plano.h" 

#include<iostream>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz, LuzPuntual luz_ambiente){
    
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


            // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            
            
            // color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
            // color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
            // color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;
 
            if(i<objetos.size()-2){
                color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
                color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
                color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;
                double t_sombra;
                double t_min_sombra = 2000000;
                Vector3D n_sombra;
                Punto3D q_sombra;
                Rayo rayo_sombra(q, (luz.posicion - q)) ;
                for (int j = 0; j < objetos.size(); j++) {
                    if ((objetos[j]->hayImpacto(rayo_sombra, t_sombra, n_sombra, q_sombra) && t_sombra < t_min_sombra)) {
                        color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        t_min_sombra = t_sombra;
                    }
                }
            }
            else{
                color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                    
                double t_sombra;
                double t_min_sombra = 2000000;
                Vector3D n_sombra;
                Punto3D q_sombra;
                Rayo rayo_sombra(q, (luz.posicion - q)) ;
                for (int j = 0; j < objetos.size(); j++) {
                    if ((objetos[j]->hayImpacto(rayo_sombra, t_sombra, n_sombra, q_sombra) && t_sombra < t_min_sombra)) {
                        color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
                        color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
                        color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;
                        t_min_sombra = t_sombra;
                    }
                }

            }
            tmin = t;
        }
    }
    return color;
}



int main() {
 
    //LuzPuntual luz(1.0,1.0,1.0, -350.0, 200.0, 2500);
    
    LuzPuntual luz(1.0,1.0,1.0, -400.0, 700.0, -100);
    LuzPuntual luz_ambiente(1.0,1.0,1.0, 0.0, 0.0, 0.0);

    
    // ESCENA------------------------------------------------------------------
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 90;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.976, 0.474, 0.082);// entre [0-1]

    Punto3D centro2(-125.0, 180.0, -400.0); 
    Esfera esfera2(centro2, radio1);   
    esfera2.establecerColor(0.976, 0.474, 0.082);

    Punto3D centro3(125.0, 180.0, -400.0); 
    Esfera esfera3(centro3, radio1);   
    esfera3.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro4(250.0, 0.0, -400.0); 
    Esfera esfera4(centro4, radio1);   
    esfera4.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro5(-250.0, 0.0, -400.0); 
    Esfera esfera5(centro5, radio1);   
    esfera5.establecerColor(0.976, 0.474, 0.082);

    Punto3D centro6(125.0, -180.0, -400.0); 
    Esfera esfera6(centro6, radio1);   
    esfera6.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D centro7(-125.0, -180.0, -400.0); 
    Esfera esfera7(centro7, radio1);   
    esfera7.establecerColor(0.976, 0.474, 0.082);

    //7 estrellas---------------------------------------------------------------------

    //centro
    Punto3D A(-10.0,-10.0,-300.0);
    Punto3D B(5.0,-2.0,-300.0);
    Punto3D C(0.0, 12.0, -300.0);
    Triangulo triangulo(A,B,C);
    triangulo.establecerColor(0.709, 0.031, 0.043);
    Punto3D A_1(-13.0, 4.0,-300.0); 
    Punto3D B_1(13.0, 4.0,-300.0);      
    Punto3D C_1(0.0, -4.0, -300.0);   
    Triangulo triangulo_1(A_1,B_1,C_1);
    triangulo_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A_2(-5.0, -2.0,-300.0); 
    Punto3D B_2(10.0, -10.0,-300.0);
    Punto3D C_2(0.0, 12.0, -300.0); 
    Triangulo triangulo_2(A_2,B_2,C_2);
    triangulo_2.establecerColor(0.709, 0.031, 0.043);
    
    //estrellas arriba

    Punto3D A2(-30.0,20.0,-300.0);
    Punto3D B2(-15.0,28.0,-300.0);
    Punto3D C2(-20.0,42.0, -300.0);
    Triangulo triangulo2(A2,B2,C2);
    triangulo2.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A2_1(-33.0, 34.0,-300.0);
    Punto3D B2_1(-7.0, 34.0,-300.0);
    Punto3D C2_1(-20.0, 26.0, -300.0);
    Triangulo triangulo2_1(A2_1,B2_1,C2_1);
    triangulo2_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A2_2(-25.0, 28.0,-300.0);
    Punto3D B2_2(-10.0, 20.0,-300.0);
    Punto3D C2_2(-20.0, 42.0, -300.0);
    Triangulo triangulo2_2(A2_2,B2_2,C2_2);
    triangulo2_2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A3(10.0,20.0,-300.0);
    Punto3D B3(25.0,28.0,-300.0);
    Punto3D C3(20.0,42.0, -300.0);
    Triangulo triangulo3(A3,B3,C3);
    triangulo3.establecerColor(0.709, 0.031, 0.043);
    Punto3D A3_1(7.0, 34.0,-300.0);
    Punto3D B3_1(33.0, 34.0,-300.0);
    Punto3D C3_1(20.0, 26.0,-300.0);
    Triangulo triangulo3_1(A3_1,B3_1,C3_1);
    triangulo3_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A3_2(15.0, 28.0,-300.0);
    Punto3D B3_2(30.0, 20.0,-300.0);
    Punto3D C3_2(20.0, 42.0,-300.0);
    Triangulo triangulo3_2(A3_2,B3_2,C3_2);
    triangulo3_2.establecerColor(0.709, 0.031, 0.043);

    //estrellas laterales

    Punto3D A4(-50.0,-10.0,-300.0);
    Punto3D B4(-35.0,-2.0,-300.0);
    Punto3D C4(-40.0, 12.0, -300.0);
    Triangulo triangulo4(A4,B4,C4);
    triangulo4.establecerColor(0.709, 0.031, 0.043);
    Punto3D A4_1(-53.0, 4.0,-300.0);
    Punto3D B4_1(-27.0, 4.0,-300.0);
    Punto3D C4_1(-40.0, -5.0,-300.0);
    Triangulo triangulo4_1(A4_1,B4_1,C4_1);
    triangulo4_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A4_2(-45.0, -2.0,-300.0);
    Punto3D B4_2(-30.0, -10.0,-300.0);
    Punto3D C4_2(-40.0, 12.0,-300.0);
    Triangulo triangulo4_2(A4_2,B4_2,C4_2);
    triangulo4_2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A5(30.0,-10.0,-300.0);
    Punto3D B5(45.0,-2.0,-300.0);
    Punto3D C5(40.0, 12.0, -300.0);
    Triangulo triangulo5(A5,B5,C5);
    triangulo5.establecerColor(0.709, 0.031, 0.043);
    Punto3D A5_1(27.0, 4.0,-300.0);
    Punto3D B5_1(53.0, 4.0,-300.0);
    Punto3D C5_1(40.0, -5.0,-300.0);
    Triangulo triangulo5_1(A5_1,B5_1,C5_1);
    triangulo5_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A5_2(35.0, -2.0,-300.0);
    Punto3D B5_2(50.0, -10.0,-300.0);
    Punto3D C5_2(40.0, 12.0,-300.0);
    Triangulo triangulo5_2(A5_2,B5_2,C5_2);
    triangulo5_2.establecerColor(0.709, 0.031, 0.043);
    
    //estrellas abajo  

    Punto3D A6(-30.0,-40.0,-300.0);
    Punto3D B6(-15.0,-32.0,-300.0);
    Punto3D C6(-20.0,-18.0, -300.0);
    Triangulo triangulo6(A6,B6,C6);
    triangulo6.establecerColor(0.709, 0.031, 0.043);
    Punto3D A6_1(-33.0, -26.0,-300.0);
    Punto3D B6_1(-7.0, -26.0,-300.0);
    Punto3D C6_1(-20.0, -35.0,-300.0);
    Triangulo triangulo6_1(A6_1,B6_1,C6_1);
    triangulo6_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A6_2(-25.0, -32.0,-300.0);
    Punto3D B6_2(-10.0, -40.0,-300.0);
    Punto3D C6_2(-20.0, -18.0,-300.0);
    Triangulo triangulo6_2(A6_2,B6_2,C6_2);
    triangulo6_2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A7(10.0,-40.0,-300.0);
    Punto3D B7(25.0,-32.0,-300.0);
    Punto3D C7(20.0,-18.0, -300.0);
    Triangulo triangulo7(A7,B7,C7);
    triangulo7.establecerColor(0.709, 0.031, 0.043);
    Punto3D A7_1(7.0, -26.0,-300.0);
    Punto3D B7_1(33.0, -26.0,-300.0);
    Punto3D C7_1(20.0, -35.0,-300.0);
    Triangulo triangulo7_1(A7_1,B7_1,C7_1);
    triangulo7_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A7_2(15.0, -32.0,-300.0);
    Punto3D B7_2(30.0, -40.0,-300.0);
    Punto3D C7_2(20.0, -18.0,-300.0);
    Triangulo triangulo7_2(A7_2,B7_2,C7_2);
    triangulo7_2.establecerColor(0.709, 0.031, 0.043);

    //1 estrella---------------------------------------------------------------------
   
    Punto3D A8(-130.0,180,-300.0);
    Punto3D B8(-115.0,169,-300.0);
    Punto3D C8(-125.0,195,-300.0);
    Triangulo triangulo8(A8,B8,C8);
    triangulo8.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A8_1(-135.0,169,-300.0);
    Punto3D B8_1(-120.0,180,-300.0);
    Punto3D C8_1(-125.0,195,-300.0);
    Triangulo triangulo8_1(A8_1,B8_1,C8_1);
    triangulo8_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A8_2(-140.0,185,-300.0);
    Punto3D B8_2(-125.0,177,-300.0);
    Punto3D C8_2(-110.0,185,-300.0);
    Triangulo triangulo8_2(A8_2,B8_2,C8_2);
    triangulo8_2.establecerColor(0.709, 0.031, 0.043);

    //2 estrellas---------------------------------------------------------------------
    
    Punto3D A9(85.0,200,-300.0);
    Punto3D B9(100.0,189,-300.0);
    Punto3D C9(90.0,214,-300.0);
    Triangulo triangulo9(A9,B9,C9);
    triangulo9.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A9_1(80.0,189,-300.0);
    Punto3D B9_1(95.0,200,-300.0);
    Punto3D C9_1(90.0,214,-300.0);
    Triangulo triangulo9_1(A9_1,B9_1,C9_1);
    triangulo9_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A9_2(75.0,205,-300.0);
    Punto3D B9_2(90.0,197,-300.0);
    Punto3D C9_2(105.0,205,-300.0);
    Triangulo triangulo9_2(A9_2,B9_2,C9_2);
    triangulo9_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A10(155.0,150,-300.0);
    Punto3D B10(170.0,139,-300.0);
    Punto3D C10(160.0,164,-300.0);
    Triangulo triangulo10(A10,B10,C10);
    triangulo10.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A10_1(150.0,139,-300.0);
    Punto3D B10_1(165.0,150,-300.0);
    Punto3D C10_1(160.0,164,-300.0);
    Triangulo triangulo10_1(A10_1,B10_1,C10_1);
    triangulo10_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A10_2(145.0,155,-300.0);
    Punto3D B10_2(160.0,147,-300.0);
    Punto3D C10_2(175.0,155,-300.0);
    Triangulo triangulo10_2(A10_2,B10_2,C10_2);
    triangulo10_2.establecerColor(0.709, 0.031, 0.043);

    //3 estrellas (250.0, 0.0, -400.0)-----------------------------------------------------------------
    
    Punto3D A25(245.0,40.0,-300.0);
    Punto3D B25(260.0,29.0,-300.0);
    Punto3D C25(250.0,54.0,-300.0);
    Triangulo triangulo25(A25,B25,C25);
    triangulo25.establecerColor(0.709, 0.031, 0.043);
    Punto3D A25_1(240.0,29.0,-300.0);
    Punto3D B25_1(255.0,40.0,-300.0);
    Punto3D C25_1(250.0,54.0,-300.0);
    Triangulo triangulo25_1(A25_1,B25_1,C25_1);
    triangulo25_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A25_2(235.0,45.0,-300.0);
    Punto3D B25_2(250.0,37.0,-300.0);
    Punto3D C25_2(265.0,45.0,-300.0);
    Triangulo triangulo25_2(A25_2,B25_2,C25_2);
    triangulo25_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A26(205.0,-30.0,-300.0);
    Punto3D B26(220.0,-41.0,-300.0);
    Punto3D C26(210.0,-16.0,-300.0);
    Triangulo triangulo26(A26,B26,C26);
    triangulo26.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A26_1(200.0,-41.0,-300.0);
    Punto3D B26_1(215.0,-30.0,-300.0);
    Punto3D C26_1(210.0,-16.0,-300.0);
    Triangulo triangulo26_1(A26_1,B26_1,C26_1);
    triangulo26_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A26_2(195.0,-25.0,-300.0);
    Punto3D B26_2(210.0,-33.0,-300.0);
    Punto3D C26_2(225.0,-25.0,-300.0);
    Triangulo triangulo26_2(A26_2,B26_2,C26_2);
    triangulo26_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A27(285.0,-30.0,-300.0);
    Punto3D B27(300.0,-41.0,-300.0);
    Punto3D C27(290.0,-16.0,-300.0);
    Triangulo triangulo27(A27,B27,C27);
    triangulo27.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A27_1(280.0,-41.0,-300.0);
    Punto3D B27_1(295.0,-30.0,-300.0);
    Punto3D C27_1(290.0,-16.0,-300.0);
    Triangulo triangulo27_1(A27_1,B27_1,C27_1);
    triangulo27_1.establecerColor(0.709, 0.031, 0.043);   
    Punto3D A27_2(275.0,-25.0,-300.0);
    Punto3D B27_2(290.0,-33.0,-300.0);
    Punto3D C27_2(305.0,-25.0,-300.0);
    Triangulo triangulo27_2(A27_2,B27_2,C27_2);
    triangulo27_2.establecerColor(0.709, 0.031, 0.043);

    //4 estrellas (125.0, -180.0, -400.0)-----------------------------------------------------------------

    Punto3D A28(95.0,-135.0,-300.0);
    Punto3D B28(110.0,-146.0,-300.0);
    Punto3D C28(100.0,-121.0,-300.0);
    Triangulo triangulo28(A28,B28,C28);
    triangulo28.establecerColor(0.709, 0.031, 0.043);   
    Punto3D A28_1(90.0,-146.0,-300.0);
    Punto3D B28_1(105.0,-135.0,-300.0);
    Punto3D C28_1(100.0,-121.0,-300.0);
    Triangulo triangulo28_1(A28_1,B28_1,C28_1);
    triangulo28_1.establecerColor(0.709, 0.031, 0.043);   
    Punto3D A28_2(85.0,-130.0,-300.0);
    Punto3D B28_2(100.0,-138.0,-300.0);
    Punto3D C28_2(115.0,-130.0,-300.0);
    Triangulo triangulo28_2(A28_2,B28_2,C28_2);
    triangulo28_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A29(75.0,-210.0,-300.0);
    Punto3D B29(90.0,-221.0,-300.0);
    Punto3D C29(80.0,-196.0,-300.0);
    Triangulo triangulo29(A29,B29,C29);
    triangulo29.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A29_1(70.0,-221.0,-300.0);
    Punto3D B29_1(85.0,-210.0,-300.0);
    Punto3D C29_1(80.0,-196.0,-300.0);
    Triangulo triangulo29_1(A29_1,B29_1,C29_1);
    triangulo29_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A29_2(65.0,-205.0,-300.0);
    Punto3D B29_2(80.0,-213.0,-300.0);
    Punto3D C29_2(95.0,-205.0,-300.0);
    Triangulo triangulo29_2(A29_2,B29_2,C29_2);
    triangulo29_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A30(170.0,-155.0,-300.0);
    Punto3D B30(185.0,-166.0,-300.0);
    Punto3D C30(175.0,-141.0,-300.0);
    Triangulo triangulo30(A30,B30,C30);
    triangulo30.establecerColor(0.709, 0.031, 0.043);
    Punto3D A30_1(165.0,-166.0,-300.0);
    Punto3D B30_1(180.0,-155.0,-300.0);
    Punto3D C30_1(175.0,-141.0,-300.0);
    Triangulo triangulo30_1(A30_1,B30_1,C30_1);
    triangulo30_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A30_2(160.0,-150.0,-300.0);
    Punto3D B30_2(175.0,-158.0,-300.0);
    Punto3D C30_2(190.0,-150.0,-300.0);
    Triangulo triangulo30_2(A30_2,B30_2,C30_2);
    triangulo30_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A31(150.0,-230.0,-300.0);
    Punto3D B31(165.0,-240.0,-300.0);
    Punto3D C31(155.0,-216.0,-300.0);
    Triangulo triangulo31(A31,B31,C31);
    triangulo31.establecerColor(0.709, 0.031, 0.043);
    Punto3D A31_1(145.0,-240.0,-300.0);
    Punto3D B31_1(160.0,-230.0,-300.0);
    Punto3D C31_1(155.0,-216.0,-300.0);
    Triangulo triangulo31_1(A31_1,B31_1,C31_1);
    triangulo31_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A31_2(140.0,-225.0,-300.0);
    Punto3D B31_2(155.0,-233.0,-300.0);
    Punto3D C31_2(170.0,-225.0,-300.0);
    Triangulo triangulo31_2(A31_2,B31_2,C31_2);
    triangulo31_2.establecerColor(0.709, 0.031, 0.043);

    //6 estrellas-----------------------------------------------------------------
    
    Punto3D A11(-260.0,-10.0,-300.0);
    Punto3D B11(-245.0,-2.0,-300.0);
    Punto3D C11(-250.0,10.0,-300.0);
    Triangulo triangulo11(A11,B11,C11);
    triangulo11.establecerColor(0.709, 0.031, 0.043);   
    Punto3D A11_1(-263.0,3.0,-300.0);
    Punto3D B11_1(-237.0,3.0,-300.0);
    Punto3D C11_1(-250.0,-5.0,-300.0);
    Triangulo triangulo11_1(A11_1,B11_1,C11_1);
    triangulo11_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A11_2(-255.0,-2.0,-300.0);
    Punto3D B11_2(-240.0,-10.0,-300.0);
    Punto3D C11_2(-250.0,10.0,-300.0);
    Triangulo triangulo11_2(A11_2,B11_2,C11_2);
    triangulo11_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A12(-295.0,0.0,-300.0);
    Punto3D B12(-280.0,8.0,-300.0);
    Punto3D C12(-285.0,20.0,-300.0);
    Triangulo triangulo12(A12,B12,C12);
    triangulo12.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A12_1(-298.0,13.0,-300.0);
    Punto3D B12_1(-272.0,13.0,-300.0);
    Punto3D C12_1(-285.0,5.0,-300.0);
    Triangulo triangulo12_1(A12_1,B12_1,C12_1);
    triangulo12_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A12_2(-290.0,8.0,-300.0);
    Punto3D B12_2(-275.0,0.0,-300.0);
    Punto3D C12_2(-285.0,20.0,-300.0);
    Triangulo triangulo12_2(A12_2,B12_2,C12_2);
    triangulo12_2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A13(-225.0,0.0,-300.0);
    Punto3D B13(-210.0,8.0,-300.0);
    Punto3D C13(-215.0,20.0,-300.0);
    Triangulo triangulo13(A13,B13,C13);
    triangulo13.establecerColor(0.709, 0.031, 0.043);
    Punto3D A13_1(-228.0,13.0,-300.0);
    Punto3D B13_1(-202.0,13.0,-300.0);
    Punto3D C13_1(-215.0,5.0,-300.0);
    Triangulo triangulo13_1(A13_1,B13_1,C13_1);
    triangulo13_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A13_2(-220.0,8.0,-300.0);
    Punto3D B13_2(-205.0,0.0,-300.0);
    Punto3D C13_2(-215.0,20.0,-300.0);
    Triangulo triangulo13_2(A13_2,B13_2,C13_2);
    triangulo13_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A14(-260.0,25.0,-300.0);
    Punto3D B14(-245.0,33.0,-300.0);
    Punto3D C14(-250.0,45.0,-300.0);
    Triangulo triangulo14(A14,B14,C14);
    triangulo14.establecerColor(0.709, 0.031, 0.043);
    Punto3D A14_1(-263.0,38.0,-300.0);
    Punto3D B14_1(-237.0,38.0,-300.0);
    Punto3D C14_1(-250.0,30.0,-300.0);
    Triangulo triangulo14_1(A14_1,B14_1,C14_1);
    triangulo14_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A14_2(-255.0,33.0,-300.0);
    Punto3D B14_2(-240.0,25.0,-300.0);
    Punto3D C14_2(-250.0,45.0,-300.0);
    Triangulo triangulo14_2(A14_2,B14_2,C14_2);
    triangulo14_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A15(-280.0,-35.0,-300.0);
    Punto3D B15(-265.0,-27.0,-300.0);
    Punto3D C15(-270.0,-15.0,-300.0);
    Triangulo triangulo15(A15,B15,C15);
    triangulo15.establecerColor(0.709, 0.031, 0.043);
    Punto3D A15_1(-283.0,-22.0,-300.0);
    Punto3D B15_1(-257.0,-22.0,-300.0);
    Punto3D C15_1(-270.0,-30.0,-300.0);
    Triangulo triangulo15_1(A15_1,B15_1,C15_1);
    triangulo15_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A15_2(-275.0,-27.0,-300.0);
    Punto3D B15_2(-260.0,-35.0,-300.0);
    Punto3D C15_2(-270.0,-15.0,-300.0);
    Triangulo triangulo15_2(A15_2,B15_2,C15_2);
    triangulo15_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A16(-240.0,-35.0,-300.0);
    Punto3D B16(-225.0,-27.0,-300.0);
    Punto3D C16(-230.0,-15.0,-300.0);
    Triangulo triangulo16(A16,B16,C16);
    triangulo16.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A16_1(-243.0,-22.0,-300.0);
    Punto3D B16_1(-217.0,-22.0,-300.0);
    Punto3D C16_1(-230.0,-30.0,-300.0);
    Triangulo triangulo16_1(A16_1,B16_1,C16_1);
    triangulo16_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A16_2(-235.0,-27.0,-300.0);
    Punto3D B16_2(-220.0,-35.0,-300.0);
    Punto3D C16_2(-230.0,-15.0,-300.0);
    Triangulo triangulo16_2(A16_2,B16_2,C16_2);
    triangulo16_2.establecerColor(0.709, 0.031, 0.043);

    //5 estrellas---------------------------------------------------------------
    
    Punto3D A20(-135.0,-155.0,-300.0);
    Punto3D B20(-120.0,-147.0,-300.0);
    Punto3D C20(-125.0,-135.0,-300.0);
    Triangulo triangulo20(A20,B20,C20);
    triangulo20.establecerColor(0.709, 0.031, 0.043);
    Punto3D A20_1(-138.0,-142.0,-300.0);
    Punto3D B20_1(-112.0,-142.0,-300.0);
    Punto3D C20_1(-125.0,-150.0,-300.0);
    Triangulo triangulo20_1(A20_1,B20_1,C20_1);
    triangulo20_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A20_2(-130.0,-147.0,-300.0);
    Punto3D B20_2(-115.0,-155.0,-300.0);
    Punto3D C20_2(-125.0,-135.0,-300.0);
    Triangulo triangulo20_2(A20_2,B20_2,C20_2);
    triangulo20_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A21(-155.0,-210.0,-300.0);
    Punto3D B21(-140.0,-202.0,-300.0);
    Punto3D C21(-145.0,-190.0,-300.0);
    Triangulo triangulo21(A21,B21,C21);
    triangulo21.establecerColor(0.709, 0.031, 0.043);
    Punto3D A21_1(-158.0,-197.0,-300.0);
    Punto3D B21_1(-132.0,-197.0,-300.0);
    Punto3D C21_1(-145.0,-205.0,-300.0);
    Triangulo triangulo21_1(A21_1,B21_1,C21_1);
    triangulo21_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A21_2(-150.0,-202.0,-300.0);
    Punto3D B21_2(-135.0,-210.0,-300.0);
    Punto3D C21_2(-145.0,-190.0,-300.0);
    Triangulo triangulo21_2(A21_2,B21_2,C21_2);
    triangulo21_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A22(-115.0,-210.0,-300.0);
    Punto3D B22(-100.0,-202.0,-300.0);
    Punto3D C22(-105.0,-190.0,-300.0);
    Triangulo triangulo22(A22,B22,C22);
    triangulo22.establecerColor(0.709, 0.031, 0.043);
    Punto3D A22_1(-118.0,-197.0,-300.0);
    Punto3D B22_1(-92.0,-197.0,-300.0);
    Punto3D C22_1(-105.0,-205.0,-300.0);
    Triangulo triangulo22_1(A22_1,B22_1,C22_1);
    triangulo22_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A22_2(-110.0,-202.0,-300.0);
    Punto3D B22_2(-95.0,-210.0,-300.0);
    Punto3D C22_2(-105.0,-190.0,-300.0);
    Triangulo triangulo22_2(A22_2,B22_2,C22_2);
    triangulo22_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A23(-165.0,-180.0,-300.0);
    Punto3D B23(-150.0,-172.0,-300.0);
    Punto3D C23(-155.0,-160.0,-300.0);
    Triangulo triangulo23(A23,B23,C23);
    triangulo23.establecerColor(0.709, 0.031, 0.043);
    Punto3D A23_1(-168.0,-167.0,-300.0);
    Punto3D B23_1(-142.0,-167.0,-300.0);
    Punto3D C23_1(-155.0,-175.0,-300.0);
    Triangulo triangulo23_1(A23_1,B23_1,C23_1);
    triangulo23_1.establecerColor(0.709, 0.031, 0.043);
    Punto3D A23_2(-160.0,-172.0,-300.0);
    Punto3D B23_2(-145.0,-180.0,-300.0);
    Punto3D C23_2(-155.0,-160.0,-300.0);
    Triangulo triangulo23_2(A23_2,B23_2,C23_2);
    triangulo23_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D A24(-105.0,-180.0,-300.0);
    Punto3D B24(-90.0,-172.0,-300.0);
    Punto3D C24(-95.0,-160.0,-300.0);
    Triangulo triangulo24(A24,B24,C24);
    triangulo24.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A24_1(-108.0,-167.0,-300.0);
    Punto3D B24_1(-82.0,-167.0,-300.0);
    Punto3D C24_1(-95.0,-175.0,-300.0);
    Triangulo triangulo24_1(A24_1,B24_1,C24_1);
    triangulo24_1.establecerColor(0.709, 0.031, 0.043);    
    Punto3D A24_2(-100.0,-172.0,-300.0);
    Punto3D B24_2(-85.0,-180.0,-300.0);
    Punto3D C24_2(-95.0,-160.0,-300.0);
    Triangulo triangulo24_2(A24_2,B24_2,C24_2);
    triangulo24_2.establecerColor(0.709, 0.031, 0.043);

    Punto3D tA1( 800, 400, -1500);     
    Punto3D tB1( -800, 400, -1500);
    Punto3D tC1( -800, -600, 0);
    Triangulo ttriangulo1( tB1, tC1, tA1 );
    ttriangulo1.establecerColor(0.21,0.41,0.44);

    Punto3D tA2( -800, -600,  0);     
    Punto3D tB2( 800, -600, 0);
    Punto3D tC2( 800, 400, -1500);
    Triangulo ttriangulo2( tA2, tB2, tC2 );
    ttriangulo2.establecerColor(0.21,0.41,0.44);

 
    
    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);
    escena.push_back(&esfera3);
    escena.push_back(&esfera4);
    escena.push_back(&esfera5);
    escena.push_back(&esfera6);
    escena.push_back(&esfera7);
    escena.push_back(&triangulo);
    escena.push_back(&triangulo_1);
    escena.push_back(&triangulo_2);
    escena.push_back(&triangulo2);
    escena.push_back(&triangulo2_1);
    escena.push_back(&triangulo2_2);
    escena.push_back(&triangulo3);
    escena.push_back(&triangulo3_1);
    escena.push_back(&triangulo3_2);
    escena.push_back(&triangulo4);
    escena.push_back(&triangulo4_1);
    escena.push_back(&triangulo4_2);
    escena.push_back(&triangulo5);
    escena.push_back(&triangulo5_1);
    escena.push_back(&triangulo5_2);
    escena.push_back(&triangulo6);
    escena.push_back(&triangulo6_1);
    escena.push_back(&triangulo6_2);
    escena.push_back(&triangulo7);
    escena.push_back(&triangulo7_1);
    escena.push_back(&triangulo7_2);
    escena.push_back(&triangulo8);
    escena.push_back(&triangulo8_1);
    escena.push_back(&triangulo8_2);
    escena.push_back(&triangulo9);
    escena.push_back(&triangulo9_1);
    escena.push_back(&triangulo9_2);
    escena.push_back(&triangulo10);
    escena.push_back(&triangulo10_1);
    escena.push_back(&triangulo10_2);
    escena.push_back(&triangulo11);
    escena.push_back(&triangulo11_1);
    escena.push_back(&triangulo11_2);
    escena.push_back(&triangulo12);
    escena.push_back(&triangulo12_1);
    escena.push_back(&triangulo12_2);
    escena.push_back(&triangulo13);
    escena.push_back(&triangulo13_1);
    escena.push_back(&triangulo13_2);
    escena.push_back(&triangulo14);
    escena.push_back(&triangulo14_1);
    escena.push_back(&triangulo14_2);
    escena.push_back(&triangulo15);
    escena.push_back(&triangulo15_1);
    escena.push_back(&triangulo15_2);
    escena.push_back(&triangulo16);
    escena.push_back(&triangulo16_1);
    escena.push_back(&triangulo16_2);
    escena.push_back(&triangulo20);
    escena.push_back(&triangulo20_1);
    escena.push_back(&triangulo20_2);
    escena.push_back(&triangulo21);
    escena.push_back(&triangulo21_1);
    escena.push_back(&triangulo21_2);
    escena.push_back(&triangulo22);
    escena.push_back(&triangulo22_1);
    escena.push_back(&triangulo22_2);
    escena.push_back(&triangulo23);
    escena.push_back(&triangulo23_1);
    escena.push_back(&triangulo23_2);
    escena.push_back(&triangulo24);
    escena.push_back(&triangulo24_1);
    escena.push_back(&triangulo24_2);
    escena.push_back(&triangulo25);
    escena.push_back(&triangulo25_1);
    escena.push_back(&triangulo25_2);
    escena.push_back(&triangulo26);
    escena.push_back(&triangulo26_1);
    escena.push_back(&triangulo26_2);
    escena.push_back(&triangulo27);
    escena.push_back(&triangulo27_1);
    escena.push_back(&triangulo27_2);
    escena.push_back(&triangulo28);
    escena.push_back(&triangulo28_1);
    escena.push_back(&triangulo28_2);
    escena.push_back(&triangulo29);
    escena.push_back(&triangulo29_1);
    escena.push_back(&triangulo29_2);
    escena.push_back(&triangulo30);
    escena.push_back(&triangulo30_1);
    escena.push_back(&triangulo30_2);
    escena.push_back(&triangulo31);
    escena.push_back(&triangulo31_1);
    escena.push_back(&triangulo31_2);

    escena.push_back(&ttriangulo1); 
    escena.push_back(&ttriangulo2);

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
            Vector3D direccion(0.0, 0.0, -1.0);
            double x = vp.s * ( col - vp.hres/2 + 0.5 );
            double y = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z = 0;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
