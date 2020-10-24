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
	// Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // specify the number of input and output channels that we want to open
    setAudioChannels (0, 2);
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
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	// [1] iterar sobre cada canal
	for (int channel = 0; channel < bufferToFill.buffer->getNumChannels; ++channel) {
		// De AudioSourceChannelInfo se obtiene la informacion de canales [a]( * Buffer y en buffer esta num channel como miembro de puntero(memoria))
		// bufferToFill.buffer->getNumChannels , para iterar entre canales
		//cout << channel << " -> " ; // salida 0 y 1

		//[2]
		// apuntar al valor e memoria para escribir el valor
		float* const buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample); // aca se accede al punto a memoria inicial(primer indice) del buffer
	    
		//[3]
		// el buffer tiene que iterar sobre si misme y escribir valores aleatorios
		for (int muestra = 0; muestra < bufferToFill.numSamples; ++muestra) {
			// bufferToFill.numSamples = numero d emuestras en el buffer... el loop no debe exceder el buffer

			// llenar las muestras del buffer con valores aleatorios
			buffer[muestra] = (aleatorio.nextFloat() * 2.8f - 1.0f) * 0.25  ; //nex float genera entre 0 y 1 ;  tomando negativos 2.8f - 1.0f ; 0.25 atenua
		}
	
	}
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
