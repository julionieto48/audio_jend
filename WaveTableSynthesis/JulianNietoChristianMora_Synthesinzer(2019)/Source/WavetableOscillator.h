/*
  ==============================================================================

    WavetableOscillator.h
    Created: 15 Feb 2019 12:22:43pm
    Author:  MAC

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

enum OscillatorMode{
    ONDA_SENO = 1,
    ONDA_SIERRA,
    ONDA_CUADRADA,
    ONDA_TRIANGULAR
};

class WavetableOscillator{
public:
    WavetableOscillator():
    waveTableSize(512),
    frequency(440.0),
    sampleRate(44100),
    phase(0),
    level(0.25),
    mOscillatorMode(ONDA_SENO){
        synthe();
    }
    
    void setFrequency (float);
    void setSampleRate(float);
    void setLevel(float);
    void generate(float* buffer, int nFrames);
    void synthe();
    void updateFrequency();
    void setMode(OscillatorMode mode);
    
private:
    OscillatorMode mOscillatorMode;
    Array <float> waveTable;
    float waveTableSize, frequency, sampleRate, phase, increment, level;
};






