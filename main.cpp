#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Plano.h"
#include "Triangulo.h"
#include "Utilitarios.h"
#include "LuzPuntual.h"
using namespace std;


ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz, LuzPuntual luzAmbiente){
    
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

           // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0,n*(luz.posicion - q).hat());
           // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0,n*(luz.posicion - q).hat());
           // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0,n*(luz.posicion - q).hat());

           // h = ((-1)*r.d).hat();
           // color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1500));
           // color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1500));
           // color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1500));

            // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
            // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
            // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
            
            color.r = (objetos[i]->obtenerColor().r * luzAmbiente.color.r) + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10);
            color.g = (objetos[i]->obtenerColor().g * luzAmbiente.color.g) + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10);
            color.b = (objetos[i]->obtenerColor().b * luzAmbiente.color.b) + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10);

            tmin = t;
        }
    }
    return color;
}

int main() {

    LuzPuntual luz(1.0, 1.0, 1.0, -200, 170, -10);
    
    LuzPuntual luzAmbiente(0, 0, 0.80, -200, 170,-10);
    
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
    Punto3D B(10.0,-10.0,-300.0);
    Punto3D C(0.0, 10.0, -300.0);
    Triangulo triangulo(A,B,C);
    triangulo.establecerColor(0.709, 0.031, 0.043);

    Punto3D A_1(-13.0, 3.0,-300.0); 
    Punto3D B_1(13.0, 3.0,-300.0);      
    Punto3D C_1(0.0, -5.0, -300.0);   
    Triangulo triangulo_1(A_1,B_1,C_1);
    triangulo_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A_2(-10.0, -10.0,-299.0); 
    Punto3D B_2(10.0, -10.0,-299.0);
    Punto3D C_2(0.0, -5.0, -299.0); 
    Triangulo triangulo_2(A_2,B_2,C_2);
    triangulo_2.establecerColor(0.976, 0.474, 0.082);
    
    //estrellas arriba

    Punto3D A2(-30.0,20.0,-300.0);
    Punto3D B2(-10.0,20.0,-300.0);
    Punto3D C2(-20.0,40.0, -300.0);
    Triangulo triangulo2(A2,B2,C2);
    triangulo2.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A2_1(-33.0, 33.0,-300.0);
    Punto3D B2_1(-7.0, 33.0,-300.0);
    Punto3D C2_1(-20.0, 25.0, -300.0);
    Triangulo triangulo2_1(A2_1,B2_1,C2_1);
    triangulo2_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A2_2(-30.0, 20.0,-299.0);
    Punto3D B2_2(-10.0, 20.0,-299.0);
    Punto3D C2_2(-20.0, 25.0, -299.0);
    Triangulo triangulo2_2(A2_2,B2_2,C2_2);
    triangulo2_2.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D A3(10.0,20.0,-300.0);
    Punto3D B3(30.0,20.0,-300.0);
    Punto3D C3(20.0,40.0, -300.0);
    Triangulo triangulo3(A3,B3,C3);
    triangulo3.establecerColor(0.709, 0.031, 0.043);

    Punto3D A3_1(7.0, 33.0,-300.0);
    Punto3D B3_1(33.0, 33.0,-300.0);
    Punto3D C3_1(20.0, 25.0,-300.0);
    Triangulo triangulo3_1(A3_1,B3_1,C3_1);
    triangulo3_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A3_2(10.0, 20.0,-299.0);
    Punto3D B3_2(30.0, 20.0,-299.0);
    Punto3D C3_2(20.0, 25.0,-299.0);
    Triangulo triangulo3_2(A3_2,B3_2,C3_2);
    triangulo3_2.establecerColor(0.976, 0.474, 0.082);

    //estrellas laterales

    Punto3D A4(-50.0,-10.0,-300.0);
    Punto3D B4(-30.0,-10.0,-300.0);
    Punto3D C4(-40.0, 10.0, -300.0);
    Triangulo triangulo4(A4,B4,C4);
    triangulo4.establecerColor(0.709, 0.031, 0.043);

    Punto3D A4_1(-53.0, 3.0,-300.0);
    Punto3D B4_1(-27.0, 3.0,-300.0);
    Punto3D C4_1(-40.0, -5.0,-300.0);
    Triangulo triangulo4_1(A4_1,B4_1,C4_1);
    triangulo4_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A4_2(-50.0, -10.0,-299.0);
    Punto3D B4_2(-30.0, -10.0,-299.0);
    Punto3D C4_2(-40.0, -5.0,-299.0);
    Triangulo triangulo4_2(A4_2,B4_2,C4_2);
    triangulo4_2.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D A5(30.0,-10.0,-300.0);
    Punto3D B5(50.0,-10.0,-300.0);
    Punto3D C5(40.0, 10.0, -300.0);
    Triangulo triangulo5(A5,B5,C5);
    triangulo5.establecerColor(0.709, 0.031, 0.043);

    Punto3D A5_1(27.0, 3.0,-300.0);
    Punto3D B5_1(53.0, 3.0,-300.0);
    Punto3D C5_1(40.0, -5.0,-300.0);
    Triangulo triangulo5_1(A5_1,B5_1,C5_1);
    triangulo5_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A5_2(30.0, -10.0,-299.0);
    Punto3D B5_2(50.0, -10.0,-299.0);
    Punto3D C5_2(40.0, -5.0,-299.0);
    Triangulo triangulo5_2(A5_2,B5_2,C5_2);
    triangulo5_2.establecerColor(0.976, 0.474, 0.082);
    
    //estrellas abajo  

    Punto3D A6(-30.0,-40.0,-300.0);
    Punto3D B6(-10.0,-40.0,-300.0);
    Punto3D C6(-20.0,-20.0, -300.0);
    Triangulo triangulo6(A6,B6,C6);
    triangulo6.establecerColor(0.709, 0.031, 0.043);

    Punto3D A6_1(-33.0, -27.0,-300.0);
    Punto3D B6_1(-7.0, -27.0,-300.0);
    Punto3D C6_1(-20.0, -35.0,-300.0);
    Triangulo triangulo6_1(A6_1,B6_1,C6_1);
    triangulo6_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A6_2(-30.0, -40.0,-299.0);
    Punto3D B6_2(-10.0, -40.0,-299.0);
    Punto3D C6_2(-20.0, -35.0,-299.0);
    Triangulo triangulo6_2(A6_2,B6_2,C6_2);
    triangulo6_2.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D A7(10.0,-40.0,-300.0);
    Punto3D B7(30.0,-40.0,-300.0);
    Punto3D C7(20.0,-20.0, -300.0);
    Triangulo triangulo7(A7,B7,C7);
    triangulo7.establecerColor(0.709, 0.031, 0.043);

    Punto3D A7_1(7.0, -27.0,-300.0);
    Punto3D B7_1(33.0, -27.0,-300.0);
    Punto3D C7_1(20.0, -35.0,-300.0);
    Triangulo triangulo7_1(A7_1,B7_1,C7_1);
    triangulo7_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A7_2(10.0, -40.0,-299.0);
    Punto3D B7_2(30.0, -40.0,-299.0);
    Punto3D C7_2(20.0, -35.0,-299.0);
    Triangulo triangulo7_2(A7_2,B7_2,C7_2);
    triangulo7_2.establecerColor(0.976, 0.474, 0.082);

    //1 estrella---------------------------------------------------------------------
   
    Punto3D A8(-135.0,170,-300.0);
    Punto3D B8(-115.0,170,-300.0);
    Punto3D C8(-125.0,190,-300.0);
    Triangulo triangulo8(A8,B8,C8);
    triangulo8.establecerColor(0.709, 0.031, 0.043);

    //2 estrellas---------------------------------------------------------------------
    
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

    //5 estrellas-----------------------------------------------------------------
    
    Punto3D A11(-260.0,-10.0,-300.0);
    Punto3D B11(-240.0,-10.0,-300.0);
    Punto3D C11(-250.0,10.0,-300.0);
    Triangulo triangulo11(A11,B11,C11);
    triangulo11.establecerColor(0.709, 0.031, 0.043);
   
    Punto3D A11_1(-263.0,3.0,-300.0);
    Punto3D B11_1(-237.0,3.0,-300.0);
    Punto3D C11_1(-250.0,-5.0,-300.0);
    Triangulo triangulo11_1(A11_1,B11_1,C11_1);
    triangulo11_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A11_2(-260.0,-10.0,-299.0);
    Punto3D B11_2(-240.0,-10.0,-299.0);
    Punto3D C11_2(-250.0,-5.0,-299.0);
    Triangulo triangulo11_2(A11_2,B11_2,C11_2);
    triangulo11_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A12(-295.0,0.0,-300.0);
    Punto3D B12(-275.0,0.0,-300.0);
    Punto3D C12(-285.0,20.0,-300.0);
    Triangulo triangulo12(A12,B12,C12);
    triangulo12.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A12_1(-298.0,13.0,-300.0);
    Punto3D B12_1(-272.0,13.0,-300.0);
    Punto3D C12_1(-285.0,5.0,-300.0);
    Triangulo triangulo12_1(A12_1,B12_1,C12_1);
    triangulo12_1.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A12_2(-295.0,0.0,-299.0);
    Punto3D B12_2(-275.0,0.0,-299.0);
    Punto3D C12_2(-285.0,5.0,-299.0);
    Triangulo triangulo12_2(A12_2,B12_2,C12_2);
    triangulo12_2.establecerColor(0.976, 0.474, 0.082);
    
    Punto3D A13(-225.0,0.0,-300.0);
    Punto3D B13(-205.0,0.0,-300.0);
    Punto3D C13(-215.0,20.0,-300.0);
    Triangulo triangulo13(A13,B13,C13);
    triangulo13.establecerColor(0.709, 0.031, 0.043);

    Punto3D A13_1(-228.0,13.0,-300.0);
    Punto3D B13_1(-202.0,13.0,-300.0);
    Punto3D C13_1(-215.0,5.0,-300.0);
    Triangulo triangulo13_1(A13_1,B13_1,C13_1);
    triangulo13_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A13_2(-225.0,0.0,-299.0);
    Punto3D B13_2(-205.0,0.0,-299.0);
    Punto3D C13_2(-215.0,5.0,-299.0);
    Triangulo triangulo13_2(A13_2,B13_2,C13_2);
    triangulo13_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A14(-260.0,25.0,-300.0);
    Punto3D B14(-240.0,25.0,-300.0);
    Punto3D C14(-250.0,45.0,-300.0);
    Triangulo triangulo14(A14,B14,C14);
    triangulo14.establecerColor(0.709, 0.031, 0.043);

    Punto3D A14_1(-263.0,38.0,-300.0);
    Punto3D B14_1(-237.0,38.0,-300.0);
    Punto3D C14_1(-250.0,30.0,-300.0);
    Triangulo triangulo14_1(A14_1,B14_1,C14_1);
    triangulo14_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A14_2(-260.0,25.0,-299.0);
    Punto3D B14_2(-240.0,25.0,-299.0);
    Punto3D C14_2(-250.0,30.0,-299.0);
    Triangulo triangulo14_2(A14_2,B14_2,C14_2);
    triangulo14_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A15(-280.0,-35.0,-300.0);
    Punto3D B15(-260.0,-35.0,-300.0);
    Punto3D C15(-270.0,-15.0,-300.0);
    Triangulo triangulo15(A15,B15,C15);
    triangulo15.establecerColor(0.709, 0.031, 0.043);

    Punto3D A15_1(-283.0,-22.0,-300.0);
    Punto3D B15_1(-257.0,-22.0,-300.0);
    Punto3D C15_1(-270.0,-30.0,-300.0);
    Triangulo triangulo15_1(A15_1,B15_1,C15_1);
    triangulo15_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A15_2(-280.0,-35.0,-299.0);
    Punto3D B15_2(-260.0,-35.0,-299.0);
    Punto3D C15_2(-270.0,-30.0,-299.0);
    Triangulo triangulo15_2(A15_2,B15_2,C15_2);
    triangulo15_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A16(-240.0,-35.0,-300.0);
    Punto3D B16(-220.0,-35.0,-300.0);
    Punto3D C16(-230.0,-15.0,-300.0);
    Triangulo triangulo16(A16,B16,C16);
    triangulo16.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A16_1(-243.0,-22.0,-300.0);
    Punto3D B16_1(-217.0,-22.0,-300.0);
    Punto3D C16_1(-230.0,-30.0,-300.0);
    Triangulo triangulo16_1(A16_1,B16_1,C16_1);
    triangulo16_1.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A16_2(-240.0,-35.0,-299.0);
    Punto3D B16_2(-220.0,-35.0,-299.0);
    Punto3D C16_2(-230.0,-30.0,-299.0);
    Triangulo triangulo16_2(A16_2,B16_2,C16_2);
    triangulo16_2.establecerColor(0.976, 0.474, 0.082);
    
    //3 estrellas-----------------------------------------------------------------

    Punto3D A17(240.0,10.0,-300.0);
    Punto3D B17(260.0,10.0,-300.0);
    Punto3D C17(250.0,30.0,-300.0);
    Triangulo triangulo17(A17,B17,C17);
    triangulo17.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A18(220.0,-20.0,-300.0);
    Punto3D B18(240.0,-20.0,-300.0);
    Punto3D C18(230.0,0.0,-300.0);
    Triangulo triangulo18(A18,B18,C18);
    triangulo18.establecerColor(0.709, 0.031, 0.043);

    Punto3D A19(260.0,-20.0,-300.0);
    Punto3D B19(280.0,-20.0,-300.0);
    Punto3D C19(270.0,0.0,-300.0);
    Triangulo triangulo19(A19,B19,C19);
    triangulo19.establecerColor(0.709, 0.031, 0.043);
    
    //5 estrellas---------------------------------------------------------------
    
    Punto3D A20(-135.0,-155.0,-300.0);
    Punto3D B20(-115.0,-155.0,-300.0);
    Punto3D C20(-125.0,-135.0,-300.0);
    Triangulo triangulo20(A20,B20,C20);
    triangulo20.establecerColor(0.709, 0.031, 0.043);

    Punto3D A20_1(-138.0,-142.0,-300.0);
    Punto3D B20_1(-112.0,-142.0,-300.0);
    Punto3D C20_1(-125.0,-150.0,-300.0);
    Triangulo triangulo20_1(A20_1,B20_1,C20_1);
    triangulo20_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A20_2(-135.0,-155.0,-299.0);
    Punto3D B20_2(-115.0,-155.0,-299.0);
    Punto3D C20_2(-125.0,-150.0,-299.0);
    Triangulo triangulo20_2(A20_2,B20_2,C20_2);
    triangulo20_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A21(-155.0,-210.0,-300.0);
    Punto3D B21(-135.0,-210.0,-300.0);
    Punto3D C21(-145.0,-190.0,-300.0);
    Triangulo triangulo21(A21,B21,C21);
    triangulo21.establecerColor(0.709, 0.031, 0.043);

    Punto3D A21_1(-158.0,-197.0,-300.0);
    Punto3D B21_1(-132.0,-197.0,-300.0);
    Punto3D C21_1(-145.0,-205.0,-300.0);
    Triangulo triangulo21_1(A21_1,B21_1,C21_1);
    triangulo21_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A21_2(-155.0,-210.0,-299.0);
    Punto3D B21_2(-135.0,-210.0,-299.0);
    Punto3D C21_2(-145.0,-205.0,-299.0);
    Triangulo triangulo21_2(A21_2,B21_2,C21_2);
    triangulo21_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A22(-115.0,-210.0,-300.0);
    Punto3D B22(-95.0,-210.0,-300.0);
    Punto3D C22(-105.0,-190.0,-300.0);
    Triangulo triangulo22(A22,B22,C22);
    triangulo22.establecerColor(0.709, 0.031, 0.043);

    Punto3D A22_1(-118.0,-197.0,-300.0);
    Punto3D B22_1(-92.0,-197.0,-300.0);
    Punto3D C22_1(-105.0,-205.0,-300.0);
    Triangulo triangulo22_1(A22_1,B22_1,C22_1);
    triangulo22_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A22_2(-115.0,-210.0,-299.0);
    Punto3D B22_2(-95.0,-210.0,-299.0);
    Punto3D C22_2(-105.0,-205.0,-299.0);
    Triangulo triangulo22_2(A22_2,B22_2,C22_2);
    triangulo22_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A23(-165.0,-180.0,-300.0);
    Punto3D B23(-145.0,-180.0,-300.0);
    Punto3D C23(-155.0,-160.0,-300.0);
    Triangulo triangulo23(A23,B23,C23);
    triangulo23.establecerColor(0.709, 0.031, 0.043);

    Punto3D A23_1(-168.0,-167.0,-300.0);
    Punto3D B23_1(-142.0,-167.0,-300.0);
    Punto3D C23_1(-155.0,-175.0,-300.0);
    Triangulo triangulo23_1(A23_1,B23_1,C23_1);
    triangulo23_1.establecerColor(0.709, 0.031, 0.043);

    Punto3D A23_2(-165.0,-180.0,-299.0);
    Punto3D B23_2(-145.0,-180.0,-299.0);
    Punto3D C23_2(-155.0,-175.0,-299.0);
    Triangulo triangulo23_2(A23_2,B23_2,C23_2);
    triangulo23_2.establecerColor(0.976, 0.474, 0.082);

    Punto3D A24(-105.0,-180.0,-300.0);
    Punto3D B24(-85.0,-180.0,-300.0);
    Punto3D C24(-95.0,-160.0,-300.0);
    Triangulo triangulo24(A24,B24,C24);
    triangulo24.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A24_1(-108.0,-167.0,-300.0);
    Punto3D B24_1(-82.0,-167.0,-300.0);
    Punto3D C24_1(-95.0,-175.0,-300.0);
    Triangulo triangulo24_1(A24_1,B24_1,C24_1);
    triangulo24_1.establecerColor(0.709, 0.031, 0.043);
    
    Punto3D A24_2(-105.0,-180.0,-299.0);
    Punto3D B24_2(-85.0,-180.0,-299.0);
    Punto3D C24_2(-95.0,-175.0,-299.0);
    Triangulo triangulo24_2(A24_2,B24_2,C24_2);
    triangulo24_2.establecerColor(0.976, 0.474, 0.082);
    
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
    escena.push_back(&triangulo16);
    escena.push_back(&triangulo17);
    escena.push_back(&triangulo18);
    escena.push_back(&triangulo19);
    escena.push_back(&triangulo20);
    escena.push_back(&triangulo21);
    escena.push_back(&triangulo22);
    escena.push_back(&triangulo23);
    escena.push_back(&triangulo24);
    escena.push_back(&triangulo_1);
    escena.push_back(&triangulo_2);
    escena.push_back(&triangulo2_1);
    escena.push_back(&triangulo2_2);
    escena.push_back(&triangulo3_1);
    escena.push_back(&triangulo3_2);
    escena.push_back(&triangulo4_1);
    escena.push_back(&triangulo4_2);
    escena.push_back(&triangulo5_1);
    escena.push_back(&triangulo5_2);
    escena.push_back(&triangulo6_1);
    escena.push_back(&triangulo6_2);
    escena.push_back(&triangulo7_1);
    escena.push_back(&triangulo7_2);
    escena.push_back(&triangulo11_1);
    escena.push_back(&triangulo11_2);
    escena.push_back(&triangulo12_1);
    escena.push_back(&triangulo12_2);
    escena.push_back(&triangulo13_1);
    escena.push_back(&triangulo13_2);
    escena.push_back(&triangulo14_1);
    escena.push_back(&triangulo14_2);
    escena.push_back(&triangulo15_1);
    escena.push_back(&triangulo15_2);
    escena.push_back(&triangulo16_1);
    escena.push_back(&triangulo16_2);
    escena.push_back(&triangulo20_1);
    escena.push_back(&triangulo20_2);
    escena.push_back(&triangulo21_1);
    escena.push_back(&triangulo21_2);
    escena.push_back(&triangulo22_1);
    escena.push_back(&triangulo22_2);
    escena.push_back(&triangulo23_1);
    escena.push_back(&triangulo23_2);
    escena.push_back(&triangulo24_1);
    escena.push_back(&triangulo24_2);


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

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena, luz, luzAmbiente).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena, luz, luzAmbiente).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena, luz, luzAmbiente).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
