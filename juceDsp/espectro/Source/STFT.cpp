/*
  ==============================================================================

    STFT.cpp
    Created: 30 Apr 2019 2:34:17pm
    Author:  MAC

  ==============================================================================
*/

#include "STFT.h"

void STFT::setFFTSizes(int order){
    fftSize = 1 << order; fftOrder = order;
}

void STFT::setWinSize(int winSize){
    // Se actulizan los valores del tamaño de la ventana.
    windowSize = winSize;
    
    //Se debe destruir y re contruir el arreglo fifo al tamaño requerido de la ventana.
    delete [] fifo; fifo = NULL;
    fifo = new float[windowSize];
    
    //Se llama la función setWindow() para actulizar la ventana.
    setWindow();
}

void STFT::setBoolBlock(bool boolBlock){
    nextFFTBlockReady = boolBlock;
}

bool STFT::getBoolBlock(){
    bool boolBlock = nextFFTBlockReady;
    return boolBlock;
}

void STFT::setArrays(){
    
    if (fifo) {delete [] fifo;}
    if (fftData) {delete [] fftData;}
    
    fifo = new float[windowSize];
    memset(fifo, 0, windowSize*sizeof(float));
    
    fftData = new float[2*fftSize];
    memset(fftData, 0, 2*fftSize*sizeof(float));
}


void STFT::setWindow(){
    
    switch (ventana){
        case rectan:    window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::rectangular);     break;
        case trian:     window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::triangular);      break;
        case han:       window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::hann);            break;
        case hamm:      window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::hamming);         break;
        case black:     window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::blackman);        break;
        case blackmanH: window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::blackmanHarris);  break;
        case flat:      window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::flatTop);         break;
        case kais:      window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::kaiser);          break;
        default:        window->fillWindowingTables(windowSize, dsp::WindowingFunction<float>::blackmanHarris);  break;
    }
}

void STFT::pushNextSampleIntoFifo (float sample) noexcept{
    
    if (fifoIndex == windowSize){
        window->multiplyWithWindowingTable (fifo, windowSize);
        if (! nextFFTBlockReady){
            //zeromem (fftData, sizeof (fftData));
            //memcpy (fftData, fifo, sizeof (fifo));
            
            for(int i = 0; i < 2*fftSize; i++)
                fftData[i] = 0;
            for(int i = 0; i < windowSize; i++)
                fftData[i] = fifo[i];
                
            setBoolBlock(true);
            //nextFFTBlockReady = true;
        }
        fifoIndex = 0;
    }
    fifo[fifoIndex++] = sample;
}

float *STFT::processing(int caseOutput){
    
    dsp::FFT forwardFFT(fftOrder);
    
    //fftData[0] = fifo[0]
    //fftData[1] = fifo[1]
    // . . .
    //fftData[fftsize/2-1] = fifo[fftsize/2-1]
    // . . .
    //fftData[fftsize/2] = 0
    //fftData[fftsize/2 + 1] = 0
    //fftData[fftsize/2 + 2] = 0 ...
    
    //- Multiplicación en tiempo de los datos de audio por la ventana seleccionada, dado un tamaño fftSize
    //window.multiplyWithWindowingTable (fftData, windowSize);
    
    //Realización FFT:
    forwardFFT.performRealOnlyForwardTransform(fftData);
    //- Se requiere un tamaño de 2 veces fftSize para almacenar la parte imaginaria junto a la real de la transformación espectral
    //fftData[0] = fft_Re[0]
    //fftData[1] = fft_Im[0]
    //fftData[2] = fft_Re[1]
    //fftData[3] = fft_Im[1]
    // ...
    //fftData[fftSize-1] = fft_Re[fftSize/4 - 1]
    //fftData[fftSize]   = fft_Im[fftSize/4 - 1]
    // ...
    //fftData[2*fftSize-1] = fft_Re[fftSize/2 - 1]
    //fftData[2*fftSize]   = fft_Im[fftSize/2 - 1]
    
    //- Se ordenan los flotantes fftData ya transformados a frecuencias complejas a tipo std::complex (Re[],Im[]):
    auto* fftData_Complex = reinterpret_cast < std::complex <float> * > (fftData);
    //fftData_Complex[0] = (fftData_Re[0], fftData_Im[0])
    //fftData_Complex[1] = (fftData_Re[1], fftData_Im[1])
    //fftData_Complex[2] = (fftData_Re[2], fftData_Im[2])
    // . . .
    //fftData_Complex[fftSize] = (fftData_Re[fftSize], fftData_Im[fftSize])
    //despues de fftSize se dan los datos en espejo y conjugados
    
    //std::complex<float>* fftData_Complex = reinterpret_cast <std::complex<float>*> (fftData);

    switch (caseOutput){
        case 0: //Elección de magnitud:
            for (int i = 0; i < fftSize; i++)
                fftData [i] = std::abs(fftData_Complex[i]);
            break;
            
        case 1: //Elección de fase:
            //for (int i = 0; i < fftSize; i++) fftData[i] = std::arg(fftData_Complex[i]);
            for (int i = 0; i < fftSize; i++) {
                if (i == 0){
                    fftData[i] = arg(fftData_Complex[i]);
                }else{
                    fftData[i] = unwraper(arg(fftData_Complex[i-1]), arg(fftData_Complex[i]));
                }
            }
            break;
            
        case 2: //Elección de Velocidad de Grupo (Derivada de la Fase):
            for (int i = 0; i < fftSize; i++) {
                if (i == 0){
                    fftData[i] = filtroDerivador(arg(fftData_Complex[i]));
                }else{
                    fftData[i] = filtroDerivador(unwraper(arg(fftData_Complex[i-1]), arg(fftData_Complex[i])));
                }
            }
            break;
            
        default:
            for (int i = 0; i < fftSize; i++)
                fftData [i] = std::abs(fftData_Complex[i]);
            break;
    }
    zeromem (&fftData[fftSize], sizeof (float) * static_cast<size_t> (fftSize));

    return fftData;
}

inline float STFT::filtroDerivador(float x){
    // y[n] = 1/T*(x[n] - x[n-1]) //FIR LOW PASS
    // A mayor T, mayor atenuación de y[n] (reducido el Rango de la fase),
    // puede ser arbitrario el valor de T, ya que solo se usará para observar la derivada de la fase
    
    float y = x - x1;
    x1 = x;
    
    return y;
}

inline float STFT::unwraper(float previous_angle, float new_angle){
    float d = new_angle - previous_angle;
    d = d > M_PI ? d - 2 * M_PI : (d < -M_PI ? d + 2 * M_PI : d);
    return previous_angle + d;
}


//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
/*
// Normalize to [-180º, 180º):
inline float STFT::constrainAngle(float x){
    x = fmod(x + M_PI, M_PI_2);
    if (x < 0) x += M_PI_2;
    return x - M_PI;
}
        
// Convert to [-360º, 360º]
inline float STFT::angleConv(float angle){
    return fmod(constrainAngle(angle), M_PI_2);
}
        
inline float STFT::angleDiff(float a,float b){
    float dif = fmod(b - a + M_PI, M_PI_2);
    if (dif < 0)
        dif += M_PI_2;
    return dif - M_PI;
}
        
inline double STFT::unwrap(float previousAngle, float newAngle){
    return previousAngle - angleDiff(newAngle, angleConv(previousAngle));
}*/
        /*
         inline void STFT::pushNextSampleIntoFifo(float *input){
         for(int i = 0; i < fftSize/2; i++)
         fifo[i] = input[i];
         
         for(int j = fftSize/2; j < fftSize; j++)
         fifo[j] = 0;
         
         for(int i = 0; i < fftSize; i++)
         fftData[i] = fifo[i];
         }*/
        
        
        
        

        
        
        
