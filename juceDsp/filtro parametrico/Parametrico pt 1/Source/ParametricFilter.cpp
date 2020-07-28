/*
  ==============================================================================

    ParametricFilter.cpp
    Created: 26 Apr 2019 2:40:47pm
    Author:  212

  ==============================================================================
*/

#include "ParametricFilter.h"

// y(n) = x(n) + b1 x(n-1) + b2 x(n-2) - a1 y(n-1) - a2 y(n-2)
// x1 = x(n-1)
// en el siguiente ciclo x1 = inputValue

double parametricFilter::process(double inputValue) {
    
    double out = inputValue + b1 * x1 + b2* x2 - a1 * y1 - a2 * y2 ;
    y2 = y1;
    y1 = out;
    x2 = x1;
    x1 = inputValue;

    return out;
    
}
