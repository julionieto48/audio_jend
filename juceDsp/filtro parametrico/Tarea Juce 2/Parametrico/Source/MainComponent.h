/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

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


public:
    enum filterStyles
    {
        styleLowpass = 1,
        styleHighpass,
        styleBandpass,
        styleParametric,
        numberOfStyles
    };
    enum TextColours
    {
        boost = 1,
        cut,
        numberOfColours
    };
    
    

    
    

    //==============================================================================
        
private:
        Label textLabel { {}, "Tipo de Filtro." }; Font textFont   { 12.0f };
        ComboBox styleMenu;
        ComboBox coloursMenu;
        void styleMenuChanged()
        {
            switch (styleMenu.getSelectedId())
            {
                case styleLowpass:  textFont.setStyleFlags (Font::bold); break;
                case  styleHighpass:  textFont.setStyleFlags (Font::bold); break;
                case  styleBandpass: textFont.setStyleFlags (Font::bold);break;
                default: break;
            }
            textLabel.setFont (textFont);
        }
        




        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
          };
