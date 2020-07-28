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

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    

	//[3.1] acceder a la clase random y crear el objeto aleatorio
	Random aleatorio;

	// [4.] añadir control por sliders
	Slider nivelSlider; Label nivelLabel; float nivel = 0.0f;
    Slider nivelRight, nivelLeft; Label leftLabel,rightLabel;float nivelR = 0.0f;float nivelL= 0.0f;
    
    Label textLabel { {}, " Audio Output " }; Font textFont   { 12.0f }; ComboBox styleMenu;
    int opcion; // 1 = stereo fantasma , 2 = stereo left y right, 3 = mono
    
    void menuCambiado(){
        
        switch (styleMenu.getSelectedId())
        {
            case 1:
                opcion = 1;
                break;
                
            case 2:
                opcion = 2;
                break;
            case 3:
                opcion = 3;
                break;
                
        }textLabel.setFont (textFont);
        
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};



/*


Referencias:
la clase MainContentComponent esta tomando por herencia de la clase AudioAppComponent
audio component... dispone de funciones para trabajar con audio y graficas

PrepareTo Play, getNextAudioblock y releaseResources; son tres "Pure virtual" functions que deben ser llamadas
en cad amomento que estamos tomando por herencia de AudioAppComponent.

   
   PrepareToPlay:
   - ocurre cada que la aplicacion es iniciada
   - samples perBlockexpected = Buffer
     
	 conversion A/D -> procesamiento en pc -> conversion D/A   (las conversiones suelen hacerse en la tarjeta de audio)

	            Latencia (tiempo) = Buffer Size/ Freq Muestreo =512/4410 = 0.0116

                           |  Buffer   |                             buffer; es como un almacen con una entrada y una salida 
				A/D	->	   |___________|->D/A
(depende del procesador)   |           |

						   es como si hubiesen dos operarios que trabajan a diferente orden, donde el D/A suele ser muy veloz
						   o "zero latency"

						   - el tamaño del almacen puede cambiar.. - mas pequeño el almacen mas rapido se llena de bloques d einfo = menos latencia
						                                        ...- almacen muy gande mas se demora en llenar

                           - aumentar la frec de muestreo aumenta el procesamiento 
	latencia, tiempo qu ele toma una señal pasar por un sistema.

	Get next Audioblock:
	. audio source channel info -> se obtiene informacion acerca dle buffer y num de canales

	cuando se escribe en un buffer...se tiene un buffer entre 2 canales (el primer valor va a la izda o canal 0, el segundo valor va acnal 1, hasta llenarse)

                
www.youtube.com/watch?v=GjNeYI6-uNE&list=PLLgJJsrdwhPxa6-02-CeHW8ocwSwl2jnu&index=11
www.youtube.com/watch?v=_Q-d4sQ9SPk
www.youtube.com/watch?v=PnDK17zP9BI
[a]docs.juce.com/master/structAudioSourceChannelInfo.html
docs.juce.com/master/classAudioBuffer.html
*/
