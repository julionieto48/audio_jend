/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"
#include "ParametricFilter.h"

#include <iostream>
using namespace std;
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class DecibelSlider : public Slider
{
public:
    DecibelSlider() {}
    
    double getValueFromText (const String& text) override
    {
        auto minusInfinitydB = -100.0;
        auto decibelText = text.upToFirstOccurrenceOf ("dB", false, false).trim();    // [1]
        return decibelText.equalsIgnoreCase ("-INF") ? minusInfinitydB
        : decibelText.getDoubleValue();  // [2]
    }
    
    String getTextFromValue (double value) override
    {
        return Decibels::toString (value);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DecibelSlider)
};
//===============================================================================================================
class MainComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    
    void setFilter(int op) { opcion = op; }
    //==============================================================================
    void resized() override;

private:
    Filter mFilter;
    ParametricFilter mParametric;
    //==============================================================================
    Slider cutoff_fSlider; Label cutoff_fLabel;
    Slider resonanceSlider; Label resonanceLabel;
    float targetResonance = 0.5, targetFrequency = 10000.0;
    //==============================================================================
    Slider r_zSlider; Label r_zLabel;
    Slider r_pSlider; Label r_pLabel;
    float target_r_z = 0.5, target_r_p = 0.3;
    //==============================================================================
    Random random;
    DecibelSlider decibelSlider;
    Label decibelLabel;
    float level = 0.0f;
    //==============================================================================
    Label textLabel { {}, "Filtro" }; //ComboBox 1 
    Font textFont   { 17.0f };
    ComboBox styleMenu;
    int opcion;
    void styleMenuChanged()
    {
        switch (styleMenu.getSelectedId())
        {
            case 1:
                opcion = 0;
                mFilter.setFilterMode(Filter::FILTER_MODE_LOWPASS); break;
            case 2:
                opcion = 0;
                mFilter.setFilterMode(Filter::FILTER_MODE_HIGHPASS); break;
            case 3:
                opcion = 0;
                mFilter.setFilterMode(Filter::FILTER_MODE_BANDPASS); break;
            case 4:
                opcion = 1; break;
        }
        textLabel.setFont (textFont);
    }
    Label textLabel2 { {}, "Realizacion" }; //ComboBox 2
    Font textFont2   { 17.0f }; int forma = 0;
    ComboBox styleMenu2;
    void styleMenuChanged2()
    {
        switch (styleMenu2.getSelectedId())
        {
            case 1:
                forma = 0;
                mParametric.setRealizacion(ParametricFilter::Forma_Directa_I); break;
            case 2:
                forma = 1;
                mParametric.setRealizacion(ParametricFilter::Forma_Directa_II); break;
        }
        textLabel2.setFont (textFont2);
    }
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
