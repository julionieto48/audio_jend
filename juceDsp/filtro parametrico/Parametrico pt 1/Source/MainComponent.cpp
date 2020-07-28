/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

    setSize (600, 600);
    setAudioChannels (0, 2);
    
    addAndMakeVisible (cutOffSlider); cutOffSlider.setRange (0.0, 0.9999);
    //cutOffSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80 ,20);
    cutOffSlider.onValueChange = [this]{
        cutOffLevel = ((float) cutOffSlider.getValue() )  ;
        if(isParametricFilter){
            mParametricFilter.setCutoff(cutOffLevel);
        }
    };
    
    addAndMakeVisible (rpSlider); rpSlider.setRange (0.0, 0.999);
    //rpSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80 ,20);
    rpSlider.setValue(rpLevel);
    rzSlider.onValueChange = [this]{
        rpLevel = ((float) cutOffSlider.getValue() ) ;
        if(isParametricFilter){
            mParametricFilter.setRp(rpLevel);
        }
    };
    
    addAndMakeVisible (rzSlider); rzSlider.setRange (0.0, 1.0);
    //rpSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80 ,20);
    rzSlider.onValueChange = [this]{
        rzLevel = ((float) cutOffSlider.getValue() ) ;
        if(isParametricFilter){
            mParametricFilter.setRp(rzLevel);
            
        }
    };
    
     addAndMakeVisible (decibelSlider); decibelSlider.setRange (-100.0, -12.0);
    decibelSlider.setValue(-24);
     decibelSlider.onValueChange = [this]{
         level = Decibels::decibelsToGain((float)  decibelSlider.getValue() ) ;
    };
    
    addAndMakeVisible (filterTypeComboBox);
    filterTypeComboBox.addItem((" Parametric Filter"), 1);
    filterTypeComboBox.addItem((" Parametric Filter"), 2);
    filterTypeComboBox.setSelectedId(2);
    filterTypeComboBox.onChange = [this]{
        filterTypeMenuChanged();

    };
    
}
void MainComponent::filterTypeMenuChanged(){
    switch(filterTypeComboBox.getSelectedItemIndex()){
        case 1:
            // fft
            isParametricFilter = true ; break;
        case 2:
            isParametricFilter = false; break;
            
    }
    
}


MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{

}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // ajuste de nivel
    auto currentLevel = level; // num aleatoriovan entre 0 1 y audio de -1 y 1
    auto levelScale = 2* currentLevel;
    
    for(auto channel = 0; channel < bufferToFill.buffer -> getNumChannels(); ++channel ){
        
        auto* buffer = bufferToFill.buffer ->getWritePointer(channel, bufferToFill.startSample);
        for(auto sample = 0; sample < bufferToFill.numSamples; ++sample){
            buffer[sample] = mParametricFilter.process(random.nextDouble()* levelScale - currentLevel);
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
    cutOffSlider.setBounds (10, 20, getWidth() - 20, 20);
    rpSlider.setBounds (10, 60, getWidth() - 20, 20);
    rzSlider.setBounds (10, 100, getWidth() - 20, 20);
    decibelSlider.setBounds (10, 140, getWidth() - 20, 20);
    
    titleLabel.setBounds(10, 170, getWidth() - 20, 40);
    filterTypeComboBox.setBounds(30, 220, getWidth() - 20, 40);

}
