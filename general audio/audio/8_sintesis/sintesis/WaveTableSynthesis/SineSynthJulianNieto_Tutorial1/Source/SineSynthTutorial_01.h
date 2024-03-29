/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2017 - ROLI Ltd.

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             SineSynthTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Simple sine synthesiser.

 dependencies:     juce_audio_basics, juce_audio_devices, juce_audio_formats,
                   juce_audio_processors, juce_audio_utils, juce_core,
                   juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2017, linux_make

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public AudioAppComponent
{
public:
    MainContentComponent()
    {
        
        // constructor ...
        
        // slider frecuencia
        addAndMakeVisible (frequencySlider);
        frequencySlider.setRange (50.0, 5000.0);
        frequencySlider.setSkewFactorFromMidPoint (500.0); // [4]
        frequencySlider.onValueChange = [this]
        {
            if (currentSampleRate > 0.0)
                updateAngleDelta();
        };
        // frecuencySlider.setValue(1000);

        // Nivel
        addAndMakeVisible (nivelSlider); nivelSlider.setRange (0.0, 0.25f); nivelSlider.setValue(0.1);
        
        
        
        setSize (600, 100);
        setAudioChannels (0, 2); // no inputs, two outputs
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    void resized() override
    {
        frequencySlider.setBounds (10, 10, getWidth() - 20, 30);
        nivelSlider.setBounds (10, 50, getWidth() - 20, 30);
        
    }

    void updateAngleDelta()
    {
        auto cyclesPerSample = frequencySlider.getValue() / currentSampleRate;   // w = 2pi f / fs      // [2]
        angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;                // [3]
    }

    void prepareToPlay (int, double sampleRate) override
    {
        currentSampleRate = sampleRate;
        updateAngleDelta();
    }

    void releaseResources() override {}

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // auto level = 0.125f;
        auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
        auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);

        
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            auto currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta; // toma en cada iteracion el angulo instantaneo
            //leftBuffer[sample]  = currentSample * level; // del tutorial original
            //rightBuffer[sample] = currentSample * level;
            
            
            leftBuffer[sample]  = currentSample * nivelSlider.getValue();
            rightBuffer[sample] = currentSample * nivelSlider.getValue();
            
            // y(n) = nivel * sin(w n)   w = 2 pi f / fs
            // currentangle o_(n) =wn
            // o_(n+1) = o_(n) +w (angle delta radianes por muestra)
        }
    }

private:
    Slider frequencySlider; Slider nivelSlider;
    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0; // [1]
    
   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
