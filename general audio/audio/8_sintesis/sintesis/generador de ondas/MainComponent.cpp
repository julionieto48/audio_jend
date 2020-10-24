/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // sine synth
    addAndMakeVisible (frequencySlider);frequencySlider.setRange (50.0, 5000.0);
    frequencySlider.setSkewFactorFromMidPoint (500.0); 
    frequencySlider.onValueChange = [this]
    {   if (currentSampleRate > 0.0)
        
        mOscillator.setFrequency( frequencySlider.getValue());
        mOscillator.setSampleRate(currentSampleRate);
        
    };
        
	addAndMakeVisible(levelSlider);levelSlider.setRange(0, 0.25);
	levelSlider.setSkewFactorFromMidPoint(0.125);
	levelSlider.onValueChange = [this]
	{ level = levelSlider.getValue();};
    
    // combo box
    addAndMakeVisible (textLabel);textLabel.setFont (textFont);
    
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("Seno",  1);styleMenu.addItem ("Sierra",   2);
    styleMenu.addItem ("Cuadrada", 3);styleMenu.addItem ("Triangular", 4);
    
    styleMenu.onChange = [this] { styleMenuChanged(); };styleMenu.setSelectedId (1);
    
    
    
    
    setSize (600, 300);
    setAudioChannels (0, 2);
}

//------------------------------------------------------------------------------
MainComponent::~MainComponent()
{shutdownAudio();}
//==============================================================================



//------------------------------------------------------------------------------
void MainComponent::prepareToPlay (int,double sampleRate)
{   currentSampleRate = sampleRate;
    
}
//------------------------------------------------------------------------------
void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	auto* leftBuffer  = bufferToFill.buffer-> getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
    mOscillator.generate(leftBuffer, bufferToFill.numSamples);
    for (int s = 0; s < bufferToFill.numSamples ; ++s){
        rightBuffer[s] = leftBuffer[s];
    }
    
/*  synth tutorial
    auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);

    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
          auto currentSample = (float) std::sin (currentAngle);
          currentAngle += angleDelta;
          leftBuffer[sample]  = currentSample * level;
          rightBuffer[sample] = currentSample * level;
        }*/
    // bufferToFill.clearActiveBufferRegion();
}
//------------------------------------------------------------------------------
void MainComponent::releaseResources()
{
}

//==============================================================================

void MainComponent::resized()
{frequencySlider.setBounds (10, 10, getWidth() - 20, 20);levelSlider.setBounds(10, 30, getWidth() - 20, 30);
 //combo box
    textLabel.setBounds (10, 50, getWidth() - 20, 50);
    styleMenu.setBounds (10, 80, getWidth() - 20, 50);
}






