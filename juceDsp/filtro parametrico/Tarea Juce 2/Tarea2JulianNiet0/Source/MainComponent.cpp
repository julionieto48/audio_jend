/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // *sliders*
     // frecuencia corte
    addAndMakeVisible(cutfrecuencySlider); cutfrecuencySlider.setRange (0, 1.0);
    cutfrecuencySlider.setSkewFactorFromMidPoint (0.5);
    frecuencyLabel.setText ("Frecuencia: ", dontSendNotification);
    addAndMakeVisible (frecuencyLabel);
    cutfrecuencySlider.onValueChange = [this]
    {   if (currentSampleRate > 0.0)
        mFilter.setCutoff(cutfrecuencySlider.getValue());
    };
      // resonancia
    addAndMakeVisible(filterResonance); filterResonance.setRange (0, 1.0);
    filterResonance.setSkewFactorFromMidPoint (0.5);
    resonanceLabel.setText ("Resonanse: ", dontSendNotification);
    addAndMakeVisible (resonanceLabel);
    
     // dB slider
    decibelSlider.setRange (-50, -12);
    decibelSlider.setTextBoxStyle (Slider::TextBoxRight, false, 100, 20);
    decibelSlider.onValueChange = [this] { level = Decibels::decibelsToGain ((float) decibelSlider.getValue()); };
    decibelSlider.setValue (Decibels::gainToDecibels (level));
    decibelLabel.setText ("Noise Level in dB: ", dontSendNotification);
    addAndMakeVisible (decibelSlider);
    addAndMakeVisible (decibelLabel);
    
    
    // *combo box *
    addAndMakeVisible (textLabel); textLabel.setFont (textFont);
      // anadir elementos al combo box
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("Pasa Bajos",  1);styleMenu.addItem ("Pasa altos",2);
    styleMenu.addItem ("Pasa Banda", 3);
    
    styleMenu.onChange = [this] { styleMenuChanged(); };styleMenu.setSelectedId (0);
    
    
    
    
    
    
    // determinar tamaño e I/O
    setSize (900, 400); setAudioChannels (0, 2);

}

MainComponent::~MainComponent()
{ shutdownAudio(); }

//==============================================================================
void MainComponent::prepareToPlay (int,double sampleRate)
{  currentSampleRate = sampleRate;

}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    auto currentLevel = level;
    auto levelScale = currentLevel * 2.0f;
    
    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);
        
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
            buffer[sample] = mFilter.process(random.nextFloat() * levelScale - currentLevel);
        
    }

}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

void MainComponent::resized()
// setBounds (int x, int y, int width, int height)
{   // frecuencia corte
    frecuencyLabel.setBounds(10, 20, 120, 20);
    cutfrecuencySlider.setBounds (120, 20, getWidth() - 20, 20);
    // resonancia
    resonanceLabel.setBounds(10, 50, 120, 20);
    filterResonance.setBounds (120, 50, getWidth() - 20, 20);
    
    // decibeles
    decibelLabel .setBounds (10, 70, 120, 20);
    decibelSlider.setBounds (130, 70, getWidth() - 140, 20);
    
    //combo box
    textLabel.setBounds (10, 180, getWidth() - 20, 50);
    styleMenu.setBounds (10, 250, getWidth() - 20, 60);
}


