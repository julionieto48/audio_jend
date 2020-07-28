/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"
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
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    
    void resized() override;
    //==============================================================================
 
   
    class DecibelSlider : public Slider
    {
    public:
        DecibelSlider() {}
        
        double getValueFromText (const String& text) override
        {
            auto minusInfinitydB = -100.0;
            
            auto decibelText = text.upToFirstOccurrenceOf ("dB", false, false).trim();    
            
            return decibelText.equalsIgnoreCase ("-INF") ? minusInfinitydB
            : decibelText.getDoubleValue();
        }
        
        String getTextFromValue (double value) override
        {
            return Decibels::toString (value);
        }
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DecibelSlider)
    };
    //==============================================================================

private:
    
    // * sliders *
    double currentSampleRate = 0.0;
    Slider cutfrecuencySlider; Slider filterResonance;
    Label frecuencyLabel; Label resonanceLabel;
      // level in dB
    Random random; DecibelSlider decibelSlider; Label decibelLabel;float level = 0.0f;
    
    
    // * combo box *
    Label textLabel { {}, "Tipo de Filtro." };
    Font textFont   { 12.0f };
    ComboBox styleMenu;
    
    void styleMenuChanged()
    {
        switch (styleMenu.getSelectedId())
        {
            case 1: textFont.setStyleFlags (Font::bold);  break;
            case 2: textFont.setStyleFlags (Font::bold);   break;
            case 3: textFont.setStyleFlags (Font::bold); break;
            default: break;
        }
        
        textLabel.setFont (textFont);
    }

    // * filter *
    Filter mFilter;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
