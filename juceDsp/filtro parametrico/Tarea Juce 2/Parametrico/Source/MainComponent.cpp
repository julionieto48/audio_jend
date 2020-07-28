/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{   addAndMakeVisible (textLabel); textLabel.setFont (textFont);
    addAndMakeVisible (styleMenu);
    
    // combo box principal
    styleMenu.addItem ("Low Pass",  1);
    styleMenu.addItem ("High Pass",   2);
    styleMenu.addItem ("Band Pass ", 3);
    styleMenu.addSeparator();
    styleMenu.addItem ("Parametric ", 4);
    styleMenu.onChange = [this] { styleMenuChanged(); };
    styleMenu.setSelectedId (0);
    



    setSize (800, 600);setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

void MainComponent::resized()
// setBounds (int x, int y, int width, int height)
{
    
    //combo box
    textLabel.setBounds (10, 180, getWidth() - 20, 50);
    styleMenu.setBounds (10, 250, getWidth() - 20, 60);
}


