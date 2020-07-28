/*
  ==============================================================================

    Parametricfilter.h
    Created: 5 Nov 2018 11:50:50pm
    Author:  Julian Esteban Nieto Diaz

  ==============================================================================
*/

#pragma once
#include <iostream>
using namespace std;

class Parametricfilter{
public:
    
    enum Realizacion {
        Forma_Directa_II = 0,};
    
    Parametricfilter(): r_z(0.5), r_p(0.4), f(10000), m1(0),m2(0),w(0),modo(Forma_Directa_II) {};
    
    inline void setRealizacion(Realizacion newMode) {
        modo = newMode;
    }
    
    float *proceso(float *in, int length) ;
    
    inline void setr_z(float rz){r_z = rz; };
    inline void setr_p(float rp){r_p = rp; };
    inline void setf(float freq){f = freq; };
private:
    float r_z, r_p, f;
    double  m1, m2, w;
    Realizacion modo;
};

