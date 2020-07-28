/*
  ==============================================================================

    Graphics_.h
    Created: 11 May 2019 11:24:02pm
    

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class Graphics_{
public:
    
    Graphics_();
    ~Graphics_();
        
    void setConstantes(int fftSize, int dom, int output);
    
    void setDims(int wid, int hei);
    
    void setScopeData();
    
    void drawNextFrameOfSpectrum(float *local_fftData);
    void drawFrame (Graphics& g);
    void drawEjes (Graphics& g, int);
    void drawSubdivisions(Graphics& g);
    
private:
    int scopeSize, loc_fftSize;
    //Selección de escala de frecuencias (dominio) y magnitud o fases (outputOption)
    int dominio, outputOption;
    int width, height;
    
    //Arreglo dinámico 
    float *scopeData;
};
