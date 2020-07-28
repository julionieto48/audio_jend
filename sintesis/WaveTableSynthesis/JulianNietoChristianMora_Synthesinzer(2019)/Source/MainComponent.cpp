/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

using namespace std;

//==============================================================================
MainComponent::MainComponent(){
    
    cpuUsageLabel.setText ("CPU Usage", dontSendNotification);
    cpuUsageText.setJustificationType (Justification::right);
    addAndMakeVisible (cpuUsageLabel);
    addAndMakeVisible (cpuUsageText);
    
    addAndMakeVisible (frequencySlider);
    
    frequencySlider.setRange (50.0, 5000.0);
    frequencySlider.setTextValueSuffix("Hz");
    frequencySlider.setSkewFactorFromMidPoint (500.0);
    frequencySlider.setValue(440.0);
    freqLabel.setText("Frecuencia", dontSendNotification);
    freqLabel.attachToComponent(&frequencySlider, true);
    frequencySlider.onValueChange = [this]
    {
        oscillator.setFrequency(frequencySlider.getValue());
        oscillator.setSampleRate(currentSampleRate);
    };
    
    addAndMakeVisible (nivelSlider);
    nivelSlider.setRange (0, 0.25);
    nivelSlider.setSkewFactorFromMidPoint (0.125); // [4]
    nivelSlider.setValue(0.125);
    nivelLabel.setText("Amplitud", dontSendNotification);
    nivelLabel.attachToComponent(&nivelSlider, true);
    nivelSlider.onValueChange = [this]
    {
        oscillator.setLevel(nivelSlider.getValue());
    };
    
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    
    // add items to the combo-box
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("Sine",1);
    styleMenu.addItem ("Saw-Thooth",2);
    styleMenu.addItem ("Square",3);
    styleMenu.addItem ("Triangular",4);
    styleMenu.onChange = [this] { styleMenuChanged(); };
    styleMenu.setSelectedId (1);
    //==============================================================================

    setSize (450, 200);
    setAudioChannels (0, 2); // no inputs, two outputs
    startTimer (50);
}

MainComponent::~MainComponent(){
    shutdownAudio();
}

void MainComponent::timerCallback() {
    auto cpu = deviceManager.getCpuUsage() * 100;
    cpuUsageText.setText (String (cpu, 6) + " %", dontSendNotification);
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate){
    currentSampleRate = sampleRate;
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
    auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
    
    oscillator.generate(leftBuffer, bufferToFill.numSamples);

    for(int n = 0; n < bufferToFill.numSamples; ++n){
        rightBuffer[n] = leftBuffer[n];
    }
}

void MainComponent::releaseResources(){}

//==============================================================================
void MainComponent::resized(){
    cpuUsageLabel.setBounds (10, 10, getWidth() - 20, 20);
    cpuUsageText .setBounds (10, 10, getWidth() - 20, 20);
    frequencySlider.setBounds (70, 40, getWidth() - 80, 20);
    nivelSlider.setBounds (70, 70, getWidth() - 80, 20);
    
    textLabel.setBounds (20, 85, getWidth() - 20, 60);
    styleMenu.setBounds (20, 135, getWidth() - 40, 30);
    
}
