
/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "WavetableOscillator.h"
using namespace std;
//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainComponent:public AudioAppComponent, public Timer{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
    
    void timerCallback() override;
    void releaseResources() override;
    
    //==============================================================================
    void resized() override;
    
private:
    //==============================================================================
    WavetableOscillator oscillator;
    
    double currentSampleRate;
    
    
    Label cpuUsageLabel;
    Label cpuUsageText;
    
    Slider frequencySlider, nivelSlider;
    Label freqLabel, nivelLabel;
    
    ComboBox styleMenu;
    void styleMenuChanged(){
        switch (styleMenu.getSelectedId()){
            case 1:
                oscillator.setMode(ONDA_SENO);
                break;
            case 2:
                oscillator.setMode(ONDA_SIERRA);
                break;
            case 3:
                oscillator.setMode(ONDA_CUADRADA);
                break;
            case 4:
                oscillator.setMode(ONDA_TRIANGULAR);
                break;
            default: break;
        }
        textLabel.setFont (textFont);
    }
    Label textLabel {{}, "Tipo de Onda" };
    Font textFont   {12.0f};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

