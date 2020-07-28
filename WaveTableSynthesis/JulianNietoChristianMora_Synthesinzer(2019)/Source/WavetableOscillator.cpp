/*
  ==============================================================================

    WavetableOscillator.cpp
    Created: 15 Feb 2019 12:22:43pm
    Author:  MAC

  ==============================================================================
*/

#include "WavetableOscillator.h"
#include <iostream>
using namespace std;

void WavetableOscillator::setMode(OscillatorMode mode) {
    mOscillatorMode = mode;
}

void WavetableOscillator::setFrequency(float freq){
    frequency = freq;
}
void WavetableOscillator::setSampleRate(float sampRte){
    sampleRate = sampRte;
}
void WavetableOscillator::setLevel(float amp){
    level = amp;
}
void WavetableOscillator::updateFrequency(){
    increment = frequency * waveTableSize/sampleRate;
    phase = fmod((phase + increment), waveTableSize);
}
void WavetableOscillator::generate(float* buffer, int nFrames){
    synthe();
    for(int n = 0; n < nFrames; n++){
        buffer[n] = level * waveTable[(int) phase];
        updateFrequency();
    }   
}
void WavetableOscillator::synthe(){
    
    waveTable.clear();
    
    switch (mOscillatorMode) {
        case ONDA_SENO:
            for(int n = 0; n < waveTableSize; n++)
                waveTable.insert(n, std::sin(MathConstants<float>::twoPi * n/waveTableSize));
            break;
        case ONDA_SIERRA:
            for(int n = 0; n < waveTableSize; n++)
                waveTable.insert(n, 1.0 - (2.0 * (n/waveTableSize)));
            break;
        case ONDA_CUADRADA:
            for(int n = 0; n < waveTableSize; n++){
                if (n/waveTableSize <= 0.5) {
                    waveTable.insert(n, 1.0);
                } else {
                    waveTable.insert(n, -1.0);
                }
            }
            break;
        case ONDA_TRIANGULAR:
            for(int n = 0; n < waveTableSize; n++){
                double value = -1.0 + (2.0*(n/waveTableSize));
                waveTable.insert(n, 2.0 * (fabs(value) - 0.5));
            }
            break;
        default:
            for(int n = 0; n < waveTableSize; n++)
                waveTable.insert(n, 0);
            break;
    }
}








