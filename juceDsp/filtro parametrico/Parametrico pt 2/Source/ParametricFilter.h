/*
  ==============================================================================

    ParametricFilter.h
    Created: 26 Apr 2019 2:40:47pm
    Author:  212

  ==============================================================================
*/

#pragma once
#include <stdio.h>
# include <math.h>

class parametricFilter {
public:

    parametricFilter() :
    cutoff(0.5),
    y1(0.0), y2(0.0), x1(0.0) , x2(0.0),
    a1(0.0), a2(0.0) , b1(0.0), b2(0.0)
    
    {};
    double process(double inputValue);
    inline void setCutoff(double newCutoff) { cutoff = newCutoff; setRp(rp); setRz(rz);};
    inline void setRz(double newRz) {rz = newRz; b1 = -2* rz* cos(cutoff); b2 = rz*(rz);};
    inline void setRp(double newRp) {rp = newRp; a1 = -2* rz* cos(cutoff); a2 = rp*(rp);};
        
    

private:
    double cutoff, rp, rz;
    double x1 , x2, y1, y2;
    double a1,a2, b1, b2;
   // double buf0; // estas son y(n-1) y
   //double buf1;
};
