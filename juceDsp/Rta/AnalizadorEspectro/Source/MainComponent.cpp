/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // COMBOBOX: FFT ORDER
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    addAndMakeVisible (styleMenu);
    styleMenu.addItem ("12", 1);
    styleMenu.addItem ("11", 2);
    styleMenu.addItem ("10", 3);
    styleMenu.addItem ("9", 4);
    // COMBOBOX: WINDOW_SIZE
    addAndMakeVisible (textLabel2);
    textLabel2.setFont (textFont);
    addAndMakeVisible (styleMenu2);
    styleMenu2.addItem ("32", 1);
    styleMenu2.addItem ("64", 2);
    styleMenu2.addItem ("128", 3);
    styleMenu2.addItem ("256", 4);
    styleMenu2.addItem ("512", 5);
    // COMBOBOX: ESCALA DOMINIO
    addAndMakeVisible (textLabel3);
    textLabel3.setFont (textFont);
    addAndMakeVisible (styleMenu3);
    styleMenu3.addItem ("Linear", 1);
    styleMenu3.addItem ("Logarithmic", 2);
    styleMenu3.addItem ("Bark", 3);
    styleMenu3.addItem ("Mel", 4);
    // COMBOBOX: RANGO
    addAndMakeVisible (textLabel4);
    textLabel4.setFont (textFont);
    addAndMakeVisible (styleMenu4);
    styleMenu4.addItem ("Magnitude", 1);
    styleMenu4.addItem ("Phase", 2);
    styleMenu4.addItem ("T_d", 3);
    styleMenu4.addItem ("Unwrapped T_d", 4);
    // COMBOBOX: TIPO DE VENTANA
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
        
    setOpaque(true);
    setAudioChannels (2, 0);
    startTimerHz(50);
    setSize (800, 600);
}

MainComponent::~MainComponent()
{
    delete mGraphics;
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
    
    mGraphics->setConstantes(local_fftSize, dominio, outputOption);
    mGraphics->setScopeData();
    
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    if (bufferToFill.buffer->getNumChannels() > 0){
        auto* audioData = bufferToFill.buffer->getReadPointer (0, bufferToFill.startSample);
        
        //si bufferToFill.numSamples = 512,
        //512/16=32, 512/8=64, 512/4=128, 512/2=256 || 512/32=16, 512/64=8, 512/128=4, 512/256=2
        
        //Se muestra la STFT del tamaño de la Ventana seleccionada a cada winBlock muestras
        for (auto winIndex = 0; winIndex < bufferToFill.numSamples/winBlock; winIndex++){
            for (int n = 0; n < winBlock; n++){
                mSTFT.pushNextSampleIntoFifo(audioData[n + winIndex*winBlock]);
            }
        }
    }
}

void MainComponent::timerCallback(){
    
    local_nextFFTBlockReady = mSTFT.getBoolBlock();
    
    if (local_nextFFTBlockReady)
    {
        mGraphics->setConstantes(local_fftSize, dominio, outputOption);
        mGraphics->setScopeData();
        
        //Envío del arreglo de frecuencias a la clase gráfica
        mGraphics->drawNextFrameOfSpectrum(mSTFT.processing(outputOption));
        mSTFT.setBoolBlock(false);
        
        repaint();
    }
}

void MainComponent::releaseResources() {}

//==============================================================================

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
    g.setOpacity(1.0f); g.setColour (Colours::whitesmoke);
    
    mGraphics->setDims(getLocalBounds().getWidth(), getLocalBounds().getHeight());
    mGraphics->drawSubdivisions(g);
    mGraphics->setDims(getLocalBounds().getWidth(), getLocalBounds().getHeight());
    mGraphics->drawFrame(g);
    mGraphics->setDims(getLocalBounds().getWidth(), getLocalBounds().getHeight());
    mGraphics->drawEjes(g, winBlock);
}

void MainComponent::resized()
{
    const int border = 50;
    textLabel.setBounds(10, 480, getWidth() - border, 30);
    styleMenu.setBounds(120, 480, getWidth()-border*14, 30);
    
    textLabel2.setBounds(10+250, 480, getWidth() - border, 30);
    styleMenu2.setBounds(120+270, 480, getWidth()-border*14, 30);
    
    textLabel3.setBounds(10, 530, getWidth() - border, 30);
    styleMenu3.setBounds(120, 530, getWidth()-border*14, 30);
    
    textLabel4.setBounds(10+250, 530, getWidth() - border, 30);
    styleMenu4.setBounds(120+270, 530, getWidth()-border*14, 30);
    
    textLabel5.setBounds(10+530, 480, getWidth() - border, 30);
    styleMenu5.setBounds(120+500, 480, getWidth()-border*14, 30);
    
}

/*
 void MainComponent::drawNextFrameOfSpectrum(){
    auto mindB = -100.0f;
    auto maxdB =    0.0f;
    float *local_fftData = mSTFT.processing(outputOption);
    setScopeData();
    if (outputOption == 0) //Rango en dB para magnitud
    {
        for (int i = 0; i < scopeSize; ++i){
            auto level = jmap (jlimit (mindB, maxdB, Decibels::gainToDecibels (local_fftData[i])//(*(local_fftData + fftDataIndex))
                                       - Decibels::gainToDecibels ((float) local_fftSize)), mindB, maxdB, 0.0f, 0.858f);
            //auto level = jmap (jlimit (mindB, maxdB, -90.0f), mindB, maxdB, 0.0f, 0.858f);
            scopeData[i] = level;
        }
    }
    else //Rango lineal para fases
    {
        for (int i = 0; i < scopeSize; ++i){
            auto level = jmap (jlimit (-360.0f, 360.0f, local_fftData[i]),
                               -360.0f, 360.0f, 0.0f, 1.0f);
            scopeData[i] = level;
        }
    }
}

void MainComponent::drawFrame (Graphics& g){
    g.setColour (Colours::aliceblue);
    auto width  = getLocalBounds().getWidth()-100;
    auto height = getLocalBounds().getHeight()-172;
    
    switch (dominio){
        case 1: //LINEAL
        {
            float f_lin[scopeSize];
            for (int i = 0; i < scopeSize; ++i)
                f_lin[i] = i; //fk = k*fs/N
            
            for (int i = 1; i < scopeSize; ++i){
                g.drawLine ({ (float) jmap (i - 1, 0, scopeSize - 1, 100, width),
                                      jmap (scopeData[i - 1], 0.0f, 0.858f, (float) height, 0.0f),
                              (float) jmap (i,     0, scopeSize - 1, 100, width),
                                      jmap (scopeData[i],     0.0f, 0.858f, (float) height, 0.0f) });
            };
            
            break;
        }
        case 2: //LOGARÍTMICO
        {
            float f_log[scopeSize];
            for (int i = 1; i < scopeSize + 1; ++i)
                f_log[i - 1] = log10f(i); //logaritmo base 10
            
            for (int i = 1; i < scopeSize; ++i){
                g.drawLine ({ (float) jmap (f_log[i - 1], 0.0f, log10f(scopeSize - 1), 100.0f, (float) width),
                                      jmap (scopeData[i - 1], 0.0f, 0.858f, (float) height, 0.0f),
                              (float) jmap (f_log[i]    , 0.0f, log10f(scopeSize - 1), 100.0f, (float) width),
                                      jmap (scopeData[i],     0.0f, 0.858f, (float) height, 0.0f) });
            }
            break;
        }
        case 3: //BARK
        {
            float f_bark[scopeSize];
            for (int i = 0; i < scopeSize; ++i)
                f_bark[i] = 13*atanf(0.76*i/(float)1000) + 3.5*atanf(powf(i/(float)7500, 2));
            
            for (int i = 1; i < scopeSize; ++i){
                g.drawLine ({ (float) jmap (f_bark[i-1], 0.0f, (float)(13*atanf(0.76*(scopeSize - 1)/(float)1000) + 3.5*atanf(powf((scopeSize - 1)/(float)7500, 2))), 100.0f, (float) width),
                                      jmap (scopeData[i - 1], 0.0f, 0.858f, (float) height, 0.0f),
                              (float) jmap (f_bark[i],  0.0f, (float) (float) (13*atanf(0.76*(scopeSize - 1)/(float)1000) + 3.5*atanf(powf((scopeSize - 1)/(float)7500, 2))), 100.0f, (float) width),
                                      jmap (scopeData[i],     0.0f, 0.858f, (float) height, 0.0f) });
            }
            break;
        }
        case 4: //MEL
        {
            float f_mel[scopeSize];
            for (int i = 0; i < scopeSize; ++i)
                f_mel[i] = 1127.01048*logf(1 + i/700.0f);
            
            for (int i = 1; i < scopeSize; ++i){
                g.drawLine ({ (float) jmap (f_mel[i-1], 0.0f, (float) 1127.01048*logf(1 + (scopeSize - 1)/700.0f), 100.0f, (float) width),
                                      jmap (scopeData[i - 1], 0.0f, 0.858f, (float) height, 0.0f),
                              (float) jmap (f_mel[i]  , 0.0f, (float) 1127.01048*logf(1 + (scopeSize - 1)/700.0f), 100.0f, (float) width),
                                      jmap (scopeData[i],     0.0f, 0.858f, (float) height, 0.0f) });
            }
            break;
        }
    }
    
    g.setOpacity(0.3f);
    
    width  = getLocalBounds().getWidth()-100;
    height = getLocalBounds().getHeight();
    scopeSize = local_fftSize/2;
    auto min_pos = 0.27f; auto max_pos = 0.9f;
    
    int f[] = {10, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000};
    int f_str[] = {1000,5000, 10000, 15000, 20000};
    int f_log_str[] = {10, 100, 500, 1000, 5000, 10000, 20000};
    
    int len_freq = sizeof(f)/sizeof(*f);
    int len_freq_str = sizeof(f_str)/sizeof(*f_str);
    int len_freq_log_str = sizeof(f_log_str)/sizeof(*f_log_str);
    
    String array_freqs[] = {"1000","5000","10000", "15000", "20000"};
    String array_log_freqs[] = {"10", "100", "500", "1000", "5000", "10000", "20000"};
    
    switch (dominio){
        case 1:
        { //LINEAL
            int k_lin[len_freq];
            int k_lin_ref[len_freq_str];
            
            for (int i = 0; i < len_freq; i++){
                k_lin[i] = f[i]*scopeSize/22050;
                g.drawLine ({ (float) jmap (k_lin[i], 0, scopeSize-1, 100, width), jmap (min_pos, 0.0f, 1.0f, (float) height, 0.0f),
                    (float) jmap (k_lin[i], 0, scopeSize-1, 100, width), jmap (max_pos, 0.0f, 1.0f, (float) height, 0.0f) });
            }
            for (int i = 0; i < len_freq_str; i++){
                k_lin_ref[i] = f_str[i]*scopeSize/22050; g.setOpacity(1.0f); g.setFont (12.0f);
                g.drawSingleLineText(array_freqs[i], jmap (k_lin_ref[i], 0, scopeSize-1, 100, width)-15, 450);
            }
            break;
        }
        case 2:
        {   //LOG10
            int f_log[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000};
            int len_freq = sizeof(f_log)/sizeof(*f_log);
            float k_log[len_freq];
            float k_blog_ref[len_freq_log_str];
            
            for (int i = 0; i < len_freq; i++){
                k_log[i] = log10f(f_log[i]*scopeSize/22050); //jlimit (1.0f, (float) scopeSize, log10f(f_log[i]*scopeSize/22050));
                
                g.drawLine ({ (float) jmap (k_log[i], 0.0f, log10f(scopeSize-1), 100.0f, (float) width), jmap (min_pos, 0.0f, 1.0f, (float)height, 0.0f),
                    (float) jmap (k_log[i], 0.0f, log10f(scopeSize-1), 100.0f, (float) width), jmap (max_pos, 0.0f, 1.0f, (float) height, 0.0f) });
            }
            for (int i = 0; i < len_freq_log_str; i++){
                k_blog_ref[i] = log10f(f_log_str[i]*scopeSize/22050);
                g.setOpacity(1.0f); g.setFont (12.0f);
                g.drawSingleLineText(array_log_freqs[i], jmap (k_blog_ref[i], 0.0f, log10f(scopeSize-1), 100.0f, (float) width), 450);
            }
            break;
        }
        case 3:
        {   //BARK
            float k_bark[len_freq];
            float k_bark_ref[len_freq_str];
            float end_num_Bark = 13*atanf(0.76*(scopeSize-1)/(float)1000) + 3.5*atanf(powf((scopeSize-1)/(float)7500, 2));
            
            for (int i = 0; i < len_freq; i++){
                k_bark[i] = 13*atanf(0.76*(f[i]*scopeSize/22050)/(float)1000) + 3.5*atanf(powf((f[i]*scopeSize/22050)/(float)7500, 2));
                
                g.drawLine ({ (float) jmap (k_bark[i], 0.0f, end_num_Bark, 100.0f, (float) width), jmap (min_pos, 0.0f, 1.0f, (float)height, 0.0f),
                    (float) jmap (k_bark[i], 0.0f, end_num_Bark, 100.0f, (float) width), jmap (max_pos, 0.0f, 1.0f, (float) height, 0.0f) });
            }
            for (int i = 0; i < len_freq_str; i++){
                k_bark_ref[i] = 13*atanf(0.76*(f_str[i]*scopeSize/22050)/(float)1000) + 3.5*atanf(powf((f_str[i]*scopeSize/22050)/(float)7500, 2));
                g.setOpacity(1.0f); g.setFont (12.0f);
                g.drawSingleLineText(array_freqs[i], jmap (k_bark_ref[i], 0.0f, end_num_Bark, 100.0f, (float) width)-15, 450);
            }
            break;
        }
        case 4:
        {   //MEL
            float k_mel[len_freq];
            float k_mel_ref[len_freq_str];
            float end_num_Mel = 1127.01048*logf(1 + (scopeSize-1)/700.0f);
            
            for (int i = 0; i < len_freq; i++){
                k_mel[i] = 1127.01048*logf(1 + (f[i]*scopeSize/22050)/700.0f);
                
                g.drawLine ({ (float) jmap (k_mel[i], 0.0f, end_num_Mel, 100.0f, (float) width), jmap (min_pos, 0.0f, 1.0f, (float)height, 0.0f),
                    (float) jmap (k_mel[i], 0.0f, end_num_Mel, 100.0f, (float) width), jmap (max_pos, 0.0f, 1.0f, (float) height, 0.0f) });
            }
            
            for (int i = 0; i < len_freq_str; i++){
                k_mel_ref[i] = 1127.01048*logf(1 + (f_str[i]*scopeSize/22050)/700.0f);
                g.setOpacity(1.0f); g.setFont (12.0f);
                g.drawSingleLineText(array_freqs[i], jmap (k_mel_ref[i], 0.0f, end_num_Mel, 100.0f, (float) width)-15, 450);
            }
            break;
        }
    }
}
*/

