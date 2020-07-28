/*
  ==============================================================================

    ParametricFilter.cpp
    Created: 6 Nov 2018 5:05:39pm
    Author:  Christian R. Mora P.

  ==============================================================================
*/

#include "ParametricFilter.h"
#include <math.h>
using namespace std;

float *ParametricFilter::proceso(float x[]) {
    
    float pi = 3.141592;
    //frecuencia de pico digital, 0<omega<pi:
    float omega_0 = 2*pi*f/44100;
    
    //Coeficientes a y b para IIR de segundo orden, KUO sección 5.6.3
    double b[3] = {1 , -2*r_z*cos(omega_0), pow(r_z,2)};
    double a[3] = {1 , -2*r_p*cos(omega_0), pow(r_p,2)};
    
    static float y[512]; //definicion de y a 512 muestras
    
    switch (modo) {
        case Forma_Directa_I:
            //cout << "Forma Directa I" << endl;// si se desea ver que entra a este case
            for (int n = 0; n < 512; n++){
                if (n == 0)
                    y[n] = b[0]*x[n];
                else if (n == 1)
                    y[n] = b[0]*x[n] + b[1]*x[n-1] - a[1]*y[n-1];
                else if (n > 1)
                    y[n] = b[0]*x[n] + b[1]*x[n-1] + b[2]*x[n-2] - a[1]*y[n-1] - a[2]*y[n-2];
            }
            break;
            
        case Forma_Directa_II:
            //cout << "Forma Directa II" << endl; // si se desea ver que entra a este case
            static float w[512]; //definicion de w a 512 muestras
            
            for (int n = 0; n < 512; n++){
                if (n == 0){
                    w[n] = x[n];
                    y[n] = b[0]*w[n];
                }
                else if (n == 1){
                    w[n] = x[n] - a[1]*w[n-1];
                    y[n] = b[0]*w[n] + b[1]*w[n-1];
                }
                else if (n > 1){
                    w[n] = x[n] - a[1]*w[n-1] - a[2]*w[n-2];
                    y[n] = b[0]*w[n] + b[1]*w[n-1] + b[2]*w[n-2];
                }
            }
            break;
        default:
            y[512] = 0.0;
    }
    return y;
}

