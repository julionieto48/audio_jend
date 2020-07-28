/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("12", 1);
    styleMenu.addItem ("11", 2);
    styleMenu.addItem ("10", 3);
    styleMenu.addItem ("9", 4);
    
    addAndMakeVisible (textLabel2);
    textLabel2.setFont (textFont);
    addAndMakeVisible (styleMenu2);
    styleMenu2.addItem ("32", 1);
    styleMenu2.addItem ("64", 2);
    styleMenu2.addItem ("128", 3);
    styleMenu2.addItem ("256", 4);
    styleMenu2.addItem ("512", 5);
    
    addAndMakeVisible (textLabel3);
    textLabel3.setFont (textFont);
    addAndMakeVisible (styleMenu3);
    styleMenu3.addItem ("Linear", 1);
    styleMenu3.addItem ("Logarithmic", 2);
    styleMenu3.addItem ("Bark", 3);
    styleMenu3.addItem ("Mel", 4);

    addAndMakeVisible (textLabel4);
    textLabel4.setFont (textFont);
    addAndMakeVisible (styleMenu4);
    styleMenu4.addItem ("Magnitud", 1);
    styleMenu4.addItem ("Fase", 2);
    styleMenu4.addItem ("Derivada de la Fase", 3);
    
    addAndMakeVisible (textLabel5);
    textLabel5.setFont (textFont);
    addAndMakeVisible (styleMenu5);
    styleMenu5.addItem ("Rectangular", 1);
    styleMenu5.addItem ("Triangular", 2);
    styleMenu5.addItem ("Hann", 3);
    styleMenu5.addItem ("Hamming", 4);
    styleMenu5.addItem ("Blackman", 5);
    styleMenu5.addItem ("Blackman-Harris", 6);
    styleMenu5.addItem ("FlatTop", 7);
    styleMenu5.addItem ("Kaiser", 8);
    
    
    styleMenu.onChange = [this] {styleMenuChanged();};
    styleMenu2.onChange = [this] {styleMenuChanged2();};
    styleMenu3.onChange = [this] {styleMenuChanged3();};
    styleMenu4.onChange = [this] {styleMenuChanged4();};
    styleMenu5.onChange = [this] {styleMenuChanged5();};
    
    styleMenu.setSelectedId (1);
    styleMenu2.setSelectedId (1);
    styleMenu3.setSelectedId (1);
    styleMenu4.setSelectedId (1);
    styleMenu5.setSelectedId (1);
    
    _125.setText("125", dontSendNotification);_125.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_125);
    _250.setText("250", dontSendNotification);_250.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_250);
    _500.setText("500", dontSendNotification);_500.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_500);
    _1000.setText("1000", dontSendNotification);_1000.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_1000);
    _2000.setText("2000", dontSendNotification);_2000.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_2000);
    _4000.setText("4000", dontSendNotification);_4000.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_4000);
    _8000.setText("8000", dontSendNotification);_8000.setFont(Font(11.f, Font::bold));addAndMakeVisible(&_8000);
    _Hz.setText("Hz", dontSendNotification);_Hz.setFont(Font(12.f, Font::bold));addAndMakeVisible(&_Hz);
    
    setOpaque(true);
    setAudioChannels (2, 0);
    startTimerHz(50);
    setSize (800, 600);
}

MainComponent::~MainComponent()
{
    if(scopeData){delete [] scopeData;}
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    
    winBlock = 32;
    mSTFT.setWinSize(winBlock);
    
    setOrder(12);
    mSTFT.setFFTSizes(local_fftOrder);
    
    mSTFT.setArrays();
    outputOption = 0;
    
    //if (scopeData) {delete [] scopeData;}
    scopeData = new float[scopeSize];
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    if (bufferToFill.buffer->getNumChannels() > 0){
        auto* audioData = bufferToFill.buffer->getReadPointer (0, bufferToFill.startSample);
        
        //si bufferToFill.numSamples = 512,
        //512/16=32, 512/8=64, 512/4=128, 512/2=256 || 512/32=16, 512/64=8, 512/128=4, 512/256=2
        
        for (auto winIndex = 0; winIndex < bufferToFill.numSamples/winBlock; winIndex++)
        {
            for (int n = 0; n < winBlock; n++)
            {
                mSTFT.pushNextSampleIntoFifo(audioData[n + winIndex*winBlock]);
            }
        }
        
    }
}

void MainComponent::timerCallback(){
    
    local_nextFFTBlockReady = mSTFT.getBoolBlock();
    
    if (local_nextFFTBlockReady)
    {
        drawNextFrameOfSpectrum();
        mSTFT.setBoolBlock(false);
        repaint();
    }
}

void MainComponent::releaseResources() {}

//==============================================================================

void MainComponent::drawNextFrameOfSpectrum(){
    auto mindB = -100.0f;
    auto maxdB =    0.0f;
    float *local_fftData = mSTFT.processing(outputOption);

    for (int i = 0; i < scopeSize; ++i){
        auto skewedProportionX = 1.0f - std::exp (std::log (1.0f - i / (float) scopeSize) * 0.2f);
        auto fftDataIndex = jlimit (0, local_fftSize / 2, (int) (skewedProportionX * local_fftSize / 2));
        auto level = jmap (jlimit (mindB, maxdB, Decibels::gainToDecibels (local_fftData[fftDataIndex])//(*(local_fftData + fftDataIndex))
                                               - Decibels::gainToDecibels ((float) local_fftSize)),
                           mindB, maxdB, 0.0f, 1.0f);
        scopeData[i] = level;
    }
}

void MainComponent::drawFrame (Graphics& g){
    
    for (int i = 1; i < scopeSize; ++i){
        auto width  = getLocalBounds().getWidth() - 100;
        auto height = getLocalBounds().getHeight();
        
        g.drawLine ({ (float) jmap (i - 1, 0, scopeSize - 1, 100, width),
            jmap (scopeData[i - 1], -0.4f, 1.0f, (float) height, 0.0f),
            (float) jmap (i,     0, scopeSize - 1, 100, width),
            jmap (scopeData[i],     -0.4f, 1.0f, (float) height, 0.0f) });
    }
}

void MainComponent::paint (Graphics& g)
{
    auto width  = getLocalBounds().getWidth()-100;
    auto height = getLocalBounds().getHeight();
    
    //g.fillAll (Colours::blanchedalmond);
    g.fillAll (Colours::black);
    g.setOpacity(1.0f); g.setColour (Colours::white);
    drawFrame(g);
    
    auto min_pos = 0.27f;
    auto max_pos = 0.3f;
    int scopeSize = 512;
    
    g.drawLine ({
        (float) jmap (0, 0, scopeSize , 100, width),
        jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (512, 0, scopeSize , 100, width),
        jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f) });
    
    g.drawLine ({
        (float) jmap (0, 0, scopeSize , 100, width),
        jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (0, 0, scopeSize , 100, width),
        jmap (0.9f,0.0f, 1.0f, (float) height, 0.0f) });
    
    int f = 15; //125 Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 30; //250 Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize, 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 56; //500 Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 108; //1k Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 195;  //2k Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 326; //4k Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
    f = 459; //8k Hz
    g.drawLine ({ (float) jmap (f, 0, scopeSize , 100, width),
        jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (f,0, scopeSize , 100, width),
        jmap (max_pos,0.0f, 1.0f, (float) height, 0.0f) });
}

void MainComponent::resized()
{
    const int border = 50;
    textLabel.setBounds(10, 480, getWidth() - border, 30);
    styleMenu.setBounds(120, 480, getWidth()-border*14, 30);
    
    textLabel2.setBounds(10+280, 480, getWidth() - border, 30);
    styleMenu2.setBounds(120+300, 480, getWidth()-border*14, 30);
    
    textLabel3.setBounds(10, 530, getWidth() - border, 30);
    styleMenu3.setBounds(120, 530, getWidth()-border*14, 30);
    
    textLabel4.setBounds(10+280, 530, getWidth() - border, 30);
    styleMenu4.setBounds(120+300, 530, getWidth()-border*14, 30);
    
    textLabel5.setBounds(10+530, 480, getWidth() - border, 30);
    styleMenu5.setBounds(120+500, 480, getWidth()-border*14, 30);
    
    auto width  = getLocalBounds().getWidth()-100;
    auto height = getLocalBounds().getHeight();
    int scopeSize = 512; int factoy = 10;
    int f = 6;
    _125.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 25;
    _250.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 49;
    _500.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 100;
    _1000.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 187;
    _2000.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 320;
    _4000.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 453;
    _8000.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
    f = 512;
    _Hz.setBounds((float) jmap (f, 0, scopeSize , 100, width), jmap (0.27f, 0.0f, 1.0f, (float) height, 0.0f)-factoy, 80, 40);
}
