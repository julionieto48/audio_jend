/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
using namespace std;

MainComponent::MainComponent(){

    //ComboBox
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("Low Pass", 1);
    styleMenu.addItem ("High Pass", 2);
    styleMenu.addItem ("Band Pass", 3);
    styleMenu.addItem ("Parametric", 4);
    
    styleMenu2.addItem ("Forma Directa I", 1);
    styleMenu2.addItem ("Forma Directa II", 2);
    styleMenu2.onChange = [this] {styleMenuChanged2();};
    
    styleMenu.onChange = [this]
    
    {
        styleMenuChanged();
        if (opcion == 0) {
            //cout << "opcion = " << opcion << endl;
            removeAllChildren();
            addAndMakeVisible (textLabel); addAndMakeVisible (styleMenu);
            //CUTOFF_F_Slider
            addAndMakeVisible(cutoff_fSlider);
            cutoff_fSlider.setRange(50, 22000);
            cutoff_fSlider.setSkewFactorFromMidPoint(11000);
            cutoff_fSlider.setValue(10000, dontSendNotification);
            cutoff_fSlider.setTextValueSuffix(" Hz");
            //Label
            addAndMakeVisible(cutoff_fLabel);
            cutoff_fLabel.setText("Frecuencia", dontSendNotification);
            cutoff_fLabel.attachToComponent(& cutoff_fSlider, 1);
            cutoff_fSlider.onValueChange = [this]
            {
                targetFrequency = cutoff_fSlider.getValue();
                mFilter.setCutoff(2*targetFrequency/44100);
            };
            
            //RESONANCE_Slider
            addAndMakeVisible(resonanceSlider);
            resonanceSlider.setRange(0.0, 1.0);
            resonanceSlider.setSkewFactorFromMidPoint(0.5);
            resonanceSlider.setValue (0.5, dontSendNotification);
            //Label
            addAndMakeVisible(resonanceLabel);
            resonanceLabel.setText("Resonancia", dontSendNotification);
            resonanceLabel.attachToComponent(& resonanceSlider, 1);
            resonanceSlider.onValueChange = [this]
            {
                targetResonance = resonanceSlider.getValue();
                mFilter.setResonance(targetResonance);
            };
            //dB Amplitud_Slider ==============================================================================
            decibelSlider.setRange (-100, -12);
            decibelSlider.setTextBoxStyle (Slider::TextBoxRight, false, 100, 20);
            decibelSlider.onValueChange = [this]
            {
                level = Decibels::decibelsToGain ((float) decibelSlider.getValue());
            };
            decibelSlider.setValue (Decibels::gainToDecibels (level));
            decibelLabel.setText ("Nivel de Ruido dB", dontSendNotification);
            addAndMakeVisible (decibelSlider);
            addAndMakeVisible (decibelLabel);
        }
        
        else if (opcion == 1) {
            removeAllChildren();
            addAndMakeVisible (textLabel); addAndMakeVisible (styleMenu); //Visible el comboBox
            //dB Amplitud_Slider ==============================================================================
            decibelSlider.setRange (-100, -12);
            decibelSlider.setTextBoxStyle (Slider::TextBoxRight, false, 100, 20);
            decibelSlider.onValueChange = [this]
            {level = Decibels::decibelsToGain ((float) decibelSlider.getValue());};
            decibelSlider.setValue (Decibels::gainToDecibels (level));
            decibelLabel.setText ("Nivel de Ruido dB", dontSendNotification);
            addAndMakeVisible (decibelSlider);
            addAndMakeVisible (decibelLabel);
            //CUTOFF_F_Slider
            addAndMakeVisible(cutoff_fSlider);
            cutoff_fSlider.setRange(50, 22000);
            cutoff_fSlider.setSkewFactorFromMidPoint(11000);
            cutoff_fSlider.setValue(10000, dontSendNotification);
            cutoff_fSlider.setTextValueSuffix(" Hz");
            //Label
            addAndMakeVisible(cutoff_fLabel);
            cutoff_fLabel.setText("Frecuencia", dontSendNotification);
            cutoff_fLabel.attachToComponent(& cutoff_fSlider, 1);
            cutoff_fSlider.onValueChange = [this]
            {
                targetFrequency = cutoff_fSlider.getValue();
                mParametric.setf(targetFrequency);
            };
            //r_z_Slider
            addAndMakeVisible(r_zSlider);
            r_zSlider.setRange(0.0, 1.0);
            r_zSlider.setSkewFactorFromMidPoint(0.5);
            r_zSlider.setValue (0.5, dontSendNotification);
            //Label
            addAndMakeVisible(r_zLabel);
            r_zLabel.setText("r_z", dontSendNotification);
            r_zLabel.attachToComponent(& r_zSlider, 1);
            r_zSlider.onValueChange = [this]
            {
                target_r_z = r_zSlider.getValue();
                mParametric.setr_z(target_r_z);
            };
            //r_p_Slider
            addAndMakeVisible(r_pSlider);
            r_pSlider.setRange(0.0, 0.99);
            r_pSlider.setSkewFactorFromMidPoint(0.5);
            r_pSlider.setValue (0.3, dontSendNotification);
            //Label
            addAndMakeVisible(r_pLabel);
            r_pLabel.setText("r_p", dontSendNotification);
            r_pLabel.attachToComponent(& r_pSlider, 1);
            r_pSlider.onValueChange = [this]
            {
                target_r_p = r_pSlider.getValue();
                mParametric.setr_p(target_r_p);
            };
            addAndMakeVisible (textLabel2);
            textLabel2.setFont (textFont2);
            addAndMakeVisible (styleMenu2);
        }
    };
    styleMenu.setSelectedId (1);
    styleMenu2.setSelectedId (1);
    
    setSize (800, 290);
    setAudioChannels(0, 2);
}

MainComponent::~MainComponent(){
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate){
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
    bufferToFill.clearActiveBufferRegion();
    
    auto currentLevel = level;
    auto levelScale = currentLevel * 2.0f;
    
    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel){
        
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);
        // arreglo de audio a 512 muestras:
        float x[bufferToFill.numSamples];
        // se crea el arreglo de ruido:
        for (auto n = 0; n < bufferToFill.numSamples; ++n)
            x[n] = random.nextFloat() * levelScale - currentLevel;
        //Procesamiento con Filtros Martin F.:
        if (opcion == 0) {
            for (auto samples = 0; samples < bufferToFill.numSamples; ++samples)
                buffer[samples] = mFilter.process(x[samples]);
        }
        //Procesamiento con Filtro Paramétrico, KUO seccion 5.6.3:
        else if (opcion == 1){
            float *buf = mParametric.proceso(x); //se filtra x de a 512 muestras, length(*buf) = 512
            for (auto samples = 0; samples < bufferToFill.numSamples; ++samples)
                buffer[samples] = *(buf+samples); //buffer[samples] = 0; quitar sonido
        }
    }
}

void MainComponent::releaseResources(){
}

//==============================================================================

void MainComponent::resized(){
    const int border = 100;
    cutoff_fSlider.setBounds(border, 20, getWidth() - border, 20);
    resonanceSlider.setBounds(border, 50, getWidth() - border, 50);
//==============================================================================
    r_zSlider.setBounds(40 , 50, getWidth() - 450, 50);
    r_pSlider.setBounds(440, 50, getWidth() - 450, 50);
//==============================================================================
    textLabel.setBounds(10, 170, getWidth() - border, 40);
    styleMenu.setBounds(border, 170, getWidth() - border, 40);
    
    textLabel2.setBounds(10, 220, getWidth() - border, 40);
    styleMenu2.setBounds(border, 220, getWidth() - border, 40);
//==============================================================================
    decibelLabel .setBounds (10, 100, 120, 50);
    decibelSlider.setBounds (130, 100, getWidth() - 140, 50);
}


/*
void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    auto currentLevel = level;
    auto levelScale = currentLevel * 2.0f;
    
    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        auto* buffer = bufferToFill.buffer->getWritePointer (channel, bufferToFill.startSample);
        
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
            //buffer[sample] = random.nextFloat() * levelScale - currentLevel;
            buffer[sample] = mFilter.process(random.nextFloat() * levelScale - currentLevel);
    }
    //cout << "bufferToFill.numSamples = " << bufferToFill.numSamples << endl;
    // bufferToFill.numSamples = 512
}
 */
