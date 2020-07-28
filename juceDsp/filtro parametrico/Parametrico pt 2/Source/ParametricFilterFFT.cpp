/*
  ==============================================================================

    ParametricFilterFFT.cpp
    Created: 26 Apr 2019 2:41:16pm
    Author:  212

  ==============================================================================
*/

#include "ParametricFilterFFT.h"

void parametricFilterFFT::calculateImpulseResponse(){
    
    float  dn = 1.0f, d1 = 0.0f, d2 = 0.0f,h1 = 0.0f,
    h2 = 0.0f, b1 = 2* rz * cos(cutoff), b2 = rz * rz,
    a1 = -2* rz* cos(cutoff), a2 = rp*(rp); ;
    
    for(int i = 0;i < fftSize;i++){
        float h = dn - b1 * d1 + b2 * d2 + a1*h1 - a2*h2;
        
        filterImpulseResponse[i] = h;
        h2 = h1;
        h1 = h;
        d2 = d1;
        d1 = dn;
        dn = 0.0;
        
    }
    zeromem(fftFilter,sizeof(fftFilter));
}

void parametricFilterFFT::pushNextSampleIntoFifo(float sample){
    if(fifoIndex == fftSize){
        if(! nextFFTBlockReady){
            zeromem(fftSignal,sizeof(fftSignal));
            memcpy(fftSignal, fifoSignal, sizeof(fifoSignal));
            nextFFTBlockReady = true;
        }
        
    fifoIndex = 0;
    }
    fifoSignal[fifoIndex++] = sample;
 
}

void parametricFilterFFT::process(float* buffer){
    fft.performRealOnlyForwardTransform(fftSignal,true);
    float out[2* fftSize];
    
    for(int i = 0; i < 2*fftSize; i++){
        out[i] = fftSignal[i] * fftFilter[i];
    }
    
    fft.performRealOnlyInverseTransform(out);
    for(int i = 0 ; i < fftSize ;i++ ){
        buffer[i] = out[i];
    }
    nextFFTBlockReady = false;
    
}
