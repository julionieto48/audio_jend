/*
  ==============================================================================

    ParametricFilterFFT.h
    Created: 26 Apr 2019 2:41:16pm
    Author:  212

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <math.h>
#include <complex>

enum{
    fftOrder = 9,
    fftSize = 1 << fftOrder
};


class parametricFilterFFT: public AudioComponentAppComponent,
                           private Timer
{
public:
    
    parametricFilterFFT() :
    cutoff(0.5),
    rz(0.0),
    sizeBlock(fftSize/2),
    fft(fftOrder){};
    
    
    double process(double inputValue);
    inline void setCutoff(double newCutoff) { cutoff = newCutoff; calculateImpulseResponse();};
    inline void setRz(double newRz) {rz = newRz;calculateImpulseResponse();};
    inline void setRp(double newRp) {rp = newRp; calculateImpulseResponse();};
    
    void  calculateImpulseResponse();
    void  pushNextSampleIntoFifo();
    void  process(float* buffer);
    
    
    
private:
    double cutoff, rp, rz;
    int  sizeBlock;
    dsp::FFT fft;
    
    // filtro
    float filterImpulseResponse[fftSize];
    float fftFilter[2*fftSize];
    
    // fifo
    float fifoSignal[fftSize];
    int fifoIndex = 0;
    
    float fftSignal[2*fftSize];

    
};
