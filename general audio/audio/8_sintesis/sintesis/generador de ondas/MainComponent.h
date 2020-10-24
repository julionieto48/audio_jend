/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    
    void prepareToPlay (int , double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void resized() override;
    
private:
    // sine synth
    Slider frequencySlider; Slider levelSlider;	
    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0, level = 0.125;
    
    // oscilator
    
    double mFrequency;
    Oscillator mOscillator;
    
    // combo box
    Label textLabel { {}, "Tipos De onda." };
    Font textFont   { 12.0f };
    ComboBox styleMenu;
    
    void styleMenuChanged(){
        switch (styleMenu.getSelectedId()){
            case 1:
                mOscillator.setMode(OSCILLATOR_MODE_SINE);
                break;
            case 2:
                mOscillator.setMode(OSCILLATOR_MODE_SAW);
                break;
            case 3:
                mOscillator.setMode(OSCILLATOR_MODE_SQUARE);
                break;
            case 4:
                mOscillator.setMode(OSCILLATOR_MODE_TRIANGLE);
                break;
            default: break;
        }
        textLabel.setFont (textFont);
    }
    
	  
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
