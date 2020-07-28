/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include "STFT.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent : public AudioAppComponent, private Timer
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
    void drawFrame (Graphics& g);
    void drawNextFrameOfSpectrum();
    
    void timerCallback() override;
    
    void setOrder(int fftOrder){
        local_fftOrder = fftOrder;
        local_fftSize = 1 << local_fftOrder;
    }
    
    enum{
        scopeSize = 1024
    };
    
private:
    //==============================================================================
    STFT mSTFT;
    
    int outputOption, local_fftSize, local_fftOrder;
    int winBlock;
    
    float *scopeData;
    bool local_nextFFTBlockReady;
    
    Label _60;Label _125;Label _250;Label _500;Label _1000;Label _2000;Label _4000;Label _8000; Label _Hz;
    
    //==============================================================================
    Font textFont   { 17.0f };
    Label textLabel { {}, "Orden FFT: N" }; //ComboBox 1
    ComboBox styleMenu; int opcion;
    void styleMenuChanged(){
        switch (styleMenu.getSelectedId()){
            case 1: local_fftOrder = 12; break;
            case 2: local_fftOrder = 11; break;
            case 3: local_fftOrder = 10; break;
            case 4: local_fftOrder = 9; break;
        }
        mSTFT.setFFTSizes(local_fftOrder);
        setOrder(local_fftOrder);
        textLabel.setFont (textFont);
    }
    Label textLabel2 { {}, "Window Size: M" }; //ComboBox 2
    ComboBox styleMenu2;
    void styleMenuChanged2(){
        switch (styleMenu2.getSelectedId()){
            case 1: winBlock = 32; break;
            case 2: winBlock = 64; break;
            case 3: winBlock = 128; break;
            case 4: winBlock = 256;  break;
            case 5: winBlock = 512;  break;
            //default: winBlock = 512; mSTFT.setWinSize(winBlock);break;
        }
        mSTFT.setWinSize(winBlock);
        textLabel2.setFont (textFont);
    }
    
    Label textLabel3 { {}, "Scale Domain:" }; //ComboBox 3
    ComboBox styleMenu3;
    void styleMenuChanged3(){
        switch (styleMenu3.getSelectedId()){
            case 1: opcion = 0; break;
            case 2: opcion = 0; break;
            case 3: opcion = 0; break;
            case 4: opcion = 1; break;
        }
        textLabel3.setFont (textFont);
    }
    Label textLabel4 { {}, "Rango:" }; //ComboBox 4, MAGNITUD, FASE, GROUP DELAY
    ComboBox styleMenu4;
    void styleMenuChanged4(){
        switch (styleMenu4.getSelectedId()){
            case 1: outputOption = 0; break;
            case 2: outputOption = 1; break;
            case 3: outputOption = 2; break;
            default:outputOption = 0; break;
        }
        textLabel4.setFont (textFont);
    }
    Label textLabel5 { {}, "Window:" }; //ComboBox 5
    ComboBox styleMenu5;
    void styleMenuChanged5(){
        std::cout << "Cambio ventana!" << std::endl;
        switch (styleMenu5.getSelectedId()){
            case 1: mSTFT.setVentana(STFT::rectan);break;
            case 2: mSTFT.setVentana(STFT::trian);break;
            case 3: mSTFT.setVentana(STFT::han);break;
            case 4: mSTFT.setVentana(STFT::hamm);break;
            case 5: mSTFT.setVentana(STFT::black);break;
            case 6: mSTFT.setVentana(STFT::blackmanH);break;
            case 7: mSTFT.setVentana(STFT::flat);break;
            case 8: mSTFT.setVentana(STFT::kais);break;
        }
        textLabel5.setFont (textFont);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
