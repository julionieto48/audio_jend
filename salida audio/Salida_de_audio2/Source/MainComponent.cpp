/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
# include <iostream>
using namespace std;
//==============================================================================
MainComponent::MainComponent()
{
    // constructor
    setSize (800, 600);
    
    
    addAndMakeVisible (textLabel); textLabel.setFont (textFont); addAndMakeVisible (styleMenu);
    styleMenu.addItem (" Stereo Fantasma ", 1); styleMenu.addItem (" Stereo ", 2); styleMenu.addItem (" Mono ", 3);

    
    styleMenu.onChange = [this]
    {
        menuCambiado();
        if(opcion == 1){
            
            setAudioChannels (0, 2);
            addAndMakeVisible(nivelSlider);
            nivelSlider.setSliderStyle(Slider::SliderStyle::Rotary);
            nivelSlider.setRange(0.0, 0.5);
            nivelSlider.onValueChange = [this] {nivel = nivelSlider.getValue(); };
            
            nivelLabel.setText("Nivel", dontSendNotification); nivelLabel.attachToComponent(&nivelSlider, true);
        }
        else if(opcion == 2){
            removeAllChildren();
            setAudioChannels (0, 2);
            addAndMakeVisible(nivelRight);
            nivelRight.setSliderStyle(Slider::SliderStyle::Rotary);
            nivelRight.setRange(0.0, 0.5);
            nivelRight.onValueChange = [this] {nivelR = nivelRight.getValue(); };
            
            addAndMakeVisible(nivelLeft);
            nivelLeft.setSliderStyle(Slider::SliderStyle::Rotary);
            nivelLeft.setRange(0.0, 0.5);
            nivelLeft.onValueChange = [this] {nivelL = nivelLeft.getValue(); };
            
        }
        else if(opcion == 3){
            setAudioChannels (0, 1);
        }
        

    };
    styleMenu.setSelectedId (1);

}

MainComponent::~MainComponent()
{
	// destructor
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    if(opcion == 1){
         // "Stereo Fantasma"
         auto nivelActual = nivel;
         
         for (int channel = 0; channel < bufferToFill.buffer-> getNumChannels(); ++channel) {
             //DBG(channel);
             float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
             for (int muestra = 0; muestra < bufferToFill.numSamples; ++muestra) {
                 buffer[muestra] = (aleatorio.nextFloat() ) * nivelActual  ;
             }
         }
    }

    if(opcion == 2){
        // "Stereo"
        for(int channel = 0; channel < (bufferToFill.buffer-> getNumSamples()) ; ++channel ){
            if(channel == 1){
                auto nivelActualR = nivelR;
                float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
                for(int muestraL = 0; muestraL < bufferToFill.numSamples; ++muestraL){
                    buffer[muestraL] = (aleatorio.nextFloat() ) * nivelActualR  ;
                }
            }else if (channel == 0){
                auto nivelActualL = nivelL;
                float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
                for(int muestraR = 0; muestraR < bufferToFill.numSamples; ++muestraR){
                    buffer[muestraR] = (aleatorio.nextFloat() ) * nivelActualL  ;
                }
            }
        }
    }

}

void MainComponent::releaseResources()
{

}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    const int limite = 120;
    textLabel.setBounds(10, 170, getWidth() - limite, 40);
    styleMenu.setBounds(limite, 170, getWidth() - limite, 40);
    //===============
	nivelSlider.setBounds(getWidth() / 3, getHeight() / 6, getWidth() / 3, getHeight() / 1.5);
	nivelLabel.setBounds(10, 120, 120, 50);
    //===============
    nivelRight.setBounds(600, 200, getWidth() / 3, getWidth() / 3);
    nivelLeft.setBounds(200, 200, getWidth() / 3, getWidth()/ 3);
}
