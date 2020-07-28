/*
  ==============================================================================

    ParametricFilter.h
    Created: 6 Nov 2018 5:05:39pm
 Author:  Christian R. Mora P.
 
  ==============================================================================
*/

#pragma once
#include <iostream>
using namespace std;

class ParametricFilter{
public:
    
    enum Realizacion {
        Forma_Directa_I = 0,
        Forma_Directa_II
    };
    
    ParametricFilter(): r_z(0.5), r_p(0.4), f(10000), modo(Forma_Directa_I) {};
    
    inline void setRealizacion(Realizacion newMode) {
        modo = newMode;
    }
    
    float *proceso(float x[]);
    
    inline void setr_z(float rz){r_z = rz; };
    inline void setr_p(float rp){r_p = rp; };
    inline void setf(float freq){f = freq; };
private:
    float r_z, r_p, f;
    Realizacion modo;
};
