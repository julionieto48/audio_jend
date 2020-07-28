/*
  ==============================================================================

    Graphics_.cpp
    Created: 11 May 2019 11:24:02pm
    

  ==============================================================================
*/

#include "Graphics_.h"

Graphics_::Graphics_(){
    scopeData = NULL;
    loc_fftSize = 1 << 12;
    setScopeData();
}

Graphics_::~Graphics_(){
    if(scopeData){delete [] scopeData;}
}

void Graphics_::setConstantes(int fftSize, int dom, int output){
    loc_fftSize = fftSize;
    dominio = dom;
    outputOption = output;
}

void Graphics_::setDims(int wid, int hei){
    width = wid;
    height = hei;
}

void Graphics_::setScopeData(){
    //El tamaño de la ventana gráfica solo debe mostrar el dominio positivo de la FFT:
    scopeSize = loc_fftSize/2;
    if (scopeData) {delete [] scopeData; }
    scopeData = new float[loc_fftSize];
}

void Graphics_::drawNextFrameOfSpectrum(float *local_fftData){
    
    auto mindB = -100.0f;
    auto maxdB =    0.0f;
    setScopeData();
    
    if (outputOption == 0) //Rango en dB para magnitud
    {
        for (int i = 0; i < scopeSize; ++i){
            auto level = jmap (jlimit (mindB, maxdB, Decibels::gainToDecibels(2.0f*local_fftData[i]/loc_fftSize)),
                               mindB, maxdB, 0.0f, 0.858f);
            
            scopeData[i] = level;
            //auto level = jmap (jlimit (mindB, maxdB, -90.0f), mindB, maxdB, 0.0f, 0.858f);
        }
    }//Rango lineal para fases
    else if ((outputOption == 1) || (outputOption == 2)) //Wrapped PHASE and Td
    {
        for (int i = 0; i < scopeSize; ++i){
            auto level = jmap (jlimit ((float)-M_PI, (float)M_PI, local_fftData[i]), (float)-M_PI, (float)M_PI, 0.1f, 0.636f);
            scopeData[i] = level;
        }
    }
    else                                                //unWrapped PHASE and Td
    {
        for (int i = 0; i < scopeSize; ++i){

            auto level = jmap (jlimit ((float)-M_PI_2, (float)M_PI_2, local_fftData[i]), (float)-M_PI_2, (float)M_PI_2, 0.1f, 0.636f);
            scopeData[i] = level;
        }
    }
}

void Graphics_::drawFrame(Graphics& g){
    
    g.setColour (Colours::aliceblue);
    width  += -100;
    height += -172;
    
    switch (dominio){
        case 1: //LINEAL
        {
            float f_lin[scopeSize];g.setOpacity(1.0f);
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
            float f_log[scopeSize];g.setOpacity(1.0f);
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
            float f_bark[scopeSize];g.setOpacity(1.0f);
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
            float f_mel[scopeSize];g.setOpacity(1.0f);
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
    
}

void Graphics_::drawSubdivisions(Graphics &g){
    
    g.setOpacity(0.3f);
    
    width  += -100;
    
    scopeSize = loc_fftSize/2;
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
    g.drawSingleLineText("Hz", width+30, 450);
}

void Graphics_::drawEjes(Graphics &g, int window_size){
    
    width  += - 100;
    int scopeSize = 512;
    
    // Línea Ordenadas (y)
    g.drawLine ({
        (float) jmap (0, 0, scopeSize , 100, width), jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (0, 0, scopeSize , 100, width), jmap (0.9f,0.0f, 1.0f, (float) height, 0.0f) });
    
    g.setOpacity(0.7f);
    // Línea Abscisas (x)
    g.drawLine ({
        (float) jmap (0, 0, scopeSize , 100, width), jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f),
        (float) jmap (512, 0, scopeSize , 100, width), jmap (0.285f,0.0f, 1.0f, (float) height, 0.0f) });
    
    
    if (outputOption == 0) //Rango en dB para magnitud
    {
        String str_array_dB[] = {"0.0","-10","-20", "-30", "-40","-50","-60","-70","-80","-90"};//LABELS
        float array_dB[] = {0.0, -10, -20, -30, -40,-50, -60, -70, -80, -90}; //NIVELES Full Scale
        int len_dB = sizeof(array_dB)/sizeof(*array_dB);
        
        for (int i = 0; i < len_dB; i++){
            float level = jmap (jlimit (-100.0f, 0.0f, array_dB[i]), -100.0f, 0.0f, 0.0f, 0.858f);
            level = jmap (level, -0.4f, 1.0f, (float) height, 0.0f);
            
            //Dibujo de las líneas horizontales de cada nivel
            g.setOpacity(0.3f);
            g.drawLine ({(float) jmap (0, 0, scopeSize , 95, width), level,
                         (float) jmap (512, 0, scopeSize , 95, width), level });
            
            //Dibujo de los labels de cada nivel
            g.setOpacity(1.0f); g.setFont (12.0f);
            g.drawSingleLineText(str_array_dB[i], 75, level);

        }
        g.drawSingleLineText("dB(FS)", 70, 40);
    }
    else if (outputOption == 1)//Rango lineal para fases, entre -pi y pi
    {
        String str_array_rad[] = {"pi","3pi/4","pi/2", "pi/4", "0.0","-pi/4","-pi/2","-3pi/4","-pi"};//LABELS
        float array_rad[] = {(float)M_PI, (float)3.0f*M_PI/4.0f,(float)M_PI/2.0f,(float)M_PI/4.0f, 0.0f, (float)-M_PI/4.0f, (float)-M_PI/2.0f,(float)-3.0f*M_PI/4.0f,(float)-M_PI}; //NIVELES Full Scale
        
        int len_rad = sizeof(array_rad)/sizeof(*array_rad);
        g.setFont (12.0f);
        for (int i = 0; i < len_rad; i++){
            float rads = jmap (jlimit ((float)-M_PI, (float)M_PI, array_rad[i]), (float)-M_PI, (float)M_PI, 0.1f, 0.670f);
            //std::cout << rads << std::endl;
            rads = jmap (rads, -0.3f, 0.9f, (float) height-30, 0.0f);
            
            //Dibujo de las líneas horizontales de cada nivel
            g.setOpacity(0.3f);
            g.drawLine ({(float) jmap (0, 0, scopeSize , 95, width), rads,
                         (float) jmap (512,0, scopeSize, 95, width), rads });
            
            //Dibujo de los labels de cada nivel
            g.setOpacity(1.0f);
            g.drawSingleLineText(str_array_rad[i], 65, rads);
            
        }
        g.drawSingleLineText("rad", 70, 40);
    }
    else
    {
        String str_samp[7];
        if (window_size == 512){
            str_samp[0] = "512";str_samp[1] = "256",str_samp[2] = "128";str_samp[3] = "0";str_samp[4] = "-128"; str_samp[5] = "-256"; str_samp[6] = "-512";
        }else if (window_size == 256){
            str_samp[0] = "256";str_samp[1] = "128",str_samp[2] = "64";str_samp[3] = "0";str_samp[4] = "-64"; str_samp[5] = "-128"; str_samp[6] = "-256";
        }else if(window_size == 128){
            str_samp[0] = "128";str_samp[1] = "64",str_samp[2] = "32";str_samp[3] = "0";str_samp[4] = "-32"; str_samp[5] = "-64"; str_samp[6] = "-128";
        }else if(window_size == 64){
            str_samp[0] = "64";str_samp[1] = "32",str_samp[2] = "16";str_samp[3] = "0";str_samp[4] = "-16"; str_samp[5] = "-32"; str_samp[6] = "-64";
        }else if(window_size == 32){
            str_samp[0] = "32";str_samp[1] = "16",str_samp[2] = "8";str_samp[3] = "0";str_samp[4] = "-8"; str_samp[5] = "-16"; str_samp[6] = "-32";
        }
        
        //[pi,2*pi/3,pi/3,0,-pi/3,-2*pi/3,-pi]
        float array_samp[] = {(float)M_PI, (float)2.0f*M_PI/3.0f,(float)M_PI/3.0f,0.0f,(float)-M_PI/3.0f,(float)-2.0f*M_PI/3.0f,(float)-M_PI}; //NIVELES Full Scale
        
        int len_samp = sizeof(array_samp)/sizeof(*array_samp);
        g.setFont (12.0f);
        for (int i = 0; i < len_samp; i++){
            float samps = jmap (jlimit ((float)-M_PI, (float)M_PI, array_samp[i]), (float)-M_PI, (float)M_PI, 0.1f, 0.670f);
            samps = jmap (samps, -0.3f, 0.9f, (float) height-30, 0.0f);
            
            //Dibujo de las líneas horizontales de cada muestra
            g.setOpacity(0.3f);
            g.drawLine ({(float) jmap (0, 0, scopeSize , 95, width), samps,
                (float) jmap (512,0, scopeSize, 95, width), samps });
            
            //Dibujo de los labels de cada muestra
            g.setOpacity(1.0f);
            g.drawSingleLineText(str_samp[i], 75, samps);
    
        }
        g.drawSingleLineText("Samples", 70, 40);
        
    }
    //jmap (Type sourceValue, Type sourceRangeMin, Type sourceRangeMax, Type targetRangeMin, Type targetRangeMax)
}

