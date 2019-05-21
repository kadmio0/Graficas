#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Utilitarios.h"
#include "LuzPuntual.h"
#include "Triangulo.h"
#include "Plano.h" 
#include "Image.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


//Call shaderay from trace ray function
// index_of_winning_object = index of scene object array
// point = intersection point
/*ColorRGB shadeRay (int index_of_winning_object, Vector3D point, ColorRGB bkgcolor){

    double final_index2;    

    //if no intersection, return the background color (double confirm)
    if (index_of_winning_object == -1) {
        return bkgcolor;
    }
    else
    {

        Vector3D c = scene_objects[index_of_winning_object].getSphereCenter();
        Vector3D p = point;

        //Normal to the intersection point and sphere
        Vector3D N = p.vectSub(c).normalize();

        //Calculating the texture coordinate for a sphere
        double temp = acos(N.getVectZ());
        double temp2 = atan2(N.getVectY(), N.getVectX());
        //u,v 
        double v = temp / 3.141592653589793;

        if (temp2 < 0) {
            temp2 = temp2 + (2 * 3.141592653589793);
        }

        double u = temp2 / (2 * 3.141592653589793);

        // get_ppm_width = width of the sample texture ppm file like (picture.ppm)
        // get_ppm_height = height of the sample texture ppm file like (picture.ppm)

        int width = u * get_ppm_width;
        int height = v * get_ppm_height;        


        //calculating the pixel of the ppm file, I store the pixel in get_array in RGB struct
        // ___ ___ ___ ___ ___ ___ ___
        //  0   1   2   3   4   5   6
        //  7   8   9  10   11  12  13
        // ___ ___ ___ ___ ___ ___ ___
        // above is the example of the get_array. get_array is a one dimensional array of RGB struct

        int px = height + (width * get_ppm_width);

        // Get the color from the get_array 
        ColorRGB final (get_array[px].r, get_array[px].g, get_array[px].b );

        return final;
    }
}*/

ColorRGB obtenerColorPixel( const Rayo& r, 
                            vector<ObjetoGeometrico*> objetos, 
                            LuzPuntual luz, 
                            LuzPuntual luz_ambiente,
                            Image& img){
    
    ColorRGB color;
    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;
    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;
 

    ColorRGB finalColor;
    finalColor.r=1.0;
    finalColor.g=1.0;
    finalColor.b=1.0;
    double u;
    double v;
    int column;
    int row;
    int px;
    double PI = 3.14159265358979323846;
    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){  
             
            u = objetos[i]->calcularU(n);
            v = objetos[i]->calcularV(n);
            if(objetos[i]->tieneTextura()){
                finalColor=objetos[i]->obtenerColorTextura(u,v); 
            }
            else{
                finalColor=objetos[i]->obtenerColor();
            }
            
           // if(i<objetos.size()-2){
                color.r = finalColor.r * luz_ambiente.color.r;
                color.g = finalColor.g * luz_ambiente.color.g;
                color.b = finalColor.b * luz_ambiente.color.b;
                double t_sombra;
                double t_min_sombra = 2000000;
                Vector3D n_sombra;
                Punto3D q_sombra;
                Rayo rayo_sombra(q, (luz.posicion - q)) ;
                for (int j = 0; j < objetos.size(); j++) {
                    if ((objetos[j]->hayImpacto(rayo_sombra, t_sombra, n_sombra, q_sombra) && t_sombra < t_min_sombra)) {
                        color.r = finalColor.r * luz_ambiente.color.r + finalColor.r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + finalColor.r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        color.g = finalColor.g * luz_ambiente.color.g + finalColor.g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + finalColor.g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        color.b = finalColor.b * luz_ambiente.color.b + finalColor.b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + finalColor.b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
                        t_min_sombra = t_sombra;
                    }
                }
           // }
           /* else{
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

            }*/
            tmin = t;
        }
    }
    return color;
}



int main(int argc, char *argv[]) {
 
    //LuzPuntual luz(1.0,1.0,1.0, -350.0, 200.0, 2500);
    
    LuzPuntual luz(1.0,1.0,1.0, -400.0, 700.0, -100);
    LuzPuntual luz_ambiente(1.0,1.0,1.0, 0.0, 0.0, 0.0);

    
    // ESCENA------------------------------------------------------------------
    Punto3D centro1(100.0, -100.0, -400.0);
    double radio1 = 120;
    Esfera esfera1(centro1, radio1);    

    Punto3D centro2(-100.0,100.0,-600.0);
    Esfera esfera2(centro2,radio1);
    esfera1.establecerColor(0.976, 0.474, 0.082);


    Image img,img2,img3; 
    cout<<"LEI LA IMAGEN 1"<<endl;
    img2.read_ppm_file("planeta2.ppm");
    cout<<"LEI LA IMAGEN 2"<<endl;
    img.read_ppm_file("planeta.ppm");

    esfera1.establecerTextura(img);
    esfera2.establecerTextura(img2);
    
    
    Punto3D tA1( 800, 400, -1500);     
    Punto3D tB1( -800, 400, -1500);
    Punto3D tC1( -800, -600, 0);
    Triangulo ttriangulo1( tB1, tC1, tA1 );
    ttriangulo1.establecerColor(0.60,0.41,0.44);

    Punto3D tA2( -800, -600,  0);     
    Punto3D tB2( 800, -600, 0);
    Punto3D tC2( 800, 400, -1500);
    Triangulo ttriangulo2( tA2, tB2, tC2 );
    ttriangulo2.establecerColor(0.60,0.41,0.44);

 
    
    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);
    /*
    escena.push_back(&ttriangulo1); 
    escena.push_back(&ttriangulo2);
    */

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
            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente,img).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente,img).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente,img).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}
