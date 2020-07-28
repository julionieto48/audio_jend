/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ParametricFilter.h"
#include "ParametricFilterFFT.h"
#include "DecibelSlider.h"
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
    void filterTypeMenuChanged();
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    Slider cutOffSlider, rpSlider, rzSlider;
    DecibelSlider  decibelSlider;
    // Labels
    Label titleLabel {{}, " Solucion " }; Label cutOffLabel {{}, " CutOff" };
    Label levelLabel {{}, " Nivel [dB]" };
    Label rpLabel {{}, " Rp" }; Label rzLabel {{}, " Rz" };
    // Combo box
    ComboBox filterTypeComboBox;
    //================
    // variables internas
    double level = 0.2f;
    double cutOffLevel = 0.0f;
    double rpLevel = 0.0f;
    double rzLevel = 0.0f;
    bool isParametricFilter = true; // verdader = tiempo
    // Filtros
    parametricFilter mParametricFilter;
    //parametricFilterFFT  mparametricFilterFFT;
    // ruido
    Random random;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
