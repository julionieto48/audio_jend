/*
  ==============================================================================

    STFT.h
    Created: 30 Apr 2019 2:34:17pm
    Author:  MAC

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

class STFT{
public:
    
    STFT(){
        fftOrder = 11;
        fftSize = 0;
        fifoIndex = 0;
        nextFFTBlockReady = false;
        
        windowSize = 256;
        
        fifo = NULL; fftData = NULL;
        
        x1 = 0;
        ventana = blackmanH;
    }
    
    ~STFT(){
        if (fifo) {delete [] fifo; fifo = NULL;}
        if (fftData) {delete [] fftData; fftData = NULL;}
        delete window;
    }
    
    enum Ventana{
        rectan = 1, trian = 2, han = 3, hamm = 4, black = 5, blackmanH = 6, flat = 7, kais = 8
    };
    
    inline void setVentana(Ventana newVentana) {
        ventana = newVentana;
        setWindow();
    }
    
    void setFFTSizes(int order);
    void setWinSize(int winSize);
    
    void setWindow();
    void setArrays();
    
    void setBoolBlock(bool boolBlock);
    bool getBoolBlock();
    
    void pushNextSampleIntoFifo (float sample) noexcept;
    float *processing(int caseOutput);
    inline float filtroDerivador(float x);

    //Algortimos para desenvolver la fase, tomado de:
    // https://stackoverflow.com/questions/15634400/continous-angles-in-c-eq-unwrap-function-in-matlab
    // https://stackoverflow.com/questions/11498169/dealing-with-angle-wrap-in-c-code
    inline float unwraper(float previous_angle, float new_angle);
    
private:
    //Instancia e inicialización dinámica de la clase WindowingFunction
    dsp::WindowingFunction<float>* window = new dsp::WindowingFunction<float>(512, dsp::WindowingFunction<float>::blackmanHarris);
        
    bool nextFFTBlockReady;
    int fftSize, fftOrder;
    int windowSize;
    int fifoIndex;
    
    Ventana ventana;
    
    //Arreglos dinámicos:
    float *fifo;
    float *fftData;
    
    //Retraso del filtro derivador
    float x1;
};

/*
 inline float constrainAngle(float x);
 inline float angleConv(float angle);
 inline float angleDiff(float a,float b);
 inline double unwrap(float previousAngle,float newAngle);
 
 */
