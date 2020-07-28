/*
  ==============================================================================

    STFT.cpp
    Created: 30 Apr 2019 2:34:17pm
    

  ==============================================================================
*/

#include "STFT.h"

STFT::STFT(){
    fftOrder = 11;
    fftSize = 0;
    fifoIndex = 0;
    nextFFTBlockReady = false;
    
    windowSize = 32;
    
    fifo = NULL; fftData = NULL;
    
    x1 = 0;
    ventana = blackmanH;
}

STFT::~STFT(){
    //se destruyen todos los arreglos dinámicos
    if (fifo) {delete [] fifo; fifo = NULL;}
    if (fftData) {delete [] fftData; fftData = NULL;}
    delete window;
}

void STFT::setFFTSizes(int order){
    fftOrder = order;
    fftSize = 1 << order;
}

void STFT::setWinSize(int winSize){
    // Se actulizan los valores del tamaño de la ventana.
    windowSize = winSize;
    
    //Se debe destruir y re construir el arreglo fifo al tamaño requerido de la ventana.
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

            for(int i = 0; i < 2*fftSize; i++)
                fftData[i] = 0;
            for(int i = 0; i < windowSize; i++)
                fftData[i] = fifo[i];
                
            setBoolBlock(true);
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
            for (int i = 0; i < fftSize; i++)
                fftData[i] = arg(fftData_Complex[i]);
            break;
            
        case 2: //Elección de Velocidad de Grupo (Derivada de la Fase):
            for (int i = 0; i < fftSize; i++)
                fftData[i] = filtroDerivador(arg(fftData_Complex[i]));
            break;
            
        /*case 3: //Elección de fase: UNWRAPPED
            
            //for (int i = 1; i < fftSize; i++){fftData[i-1] = unwraper(arg(fftData_Complex[i-1]), arg(fftData_Complex[i]));}
            for (int i = 0; i < fftSize; i++)
                fftData[i] = arg(fftData_Complex[i]);
            
            unwraper(fftData, fftSize);
            break;*/
            
        case 3: //Elección de Velocidad de Grupo (Derivada de la Fase) UNWRAPPED:
            /*for (int i = 1; i < fftSize; i++){
                fftData[i-1] = filtroDerivador(unwraper(arg(fftData_Complex[i-1]), arg(fftData_Complex[i])));
            }*/
            for (int i = 0; i < fftSize; i++)
                fftData[i] = arg(fftData_Complex[i]);
            
            unwraper(fftData, fftSize/2);
            
            for (int i = 0; i < fftSize; i++)
                fftData[i] = filtroDerivador(fftData[i]);
            
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
    
    float y = x - x1; //unidades de la salida "y": muestras o unidad de tiempo
    x1 = x;
    
    return y;
}

void STFT::unwraper(float *p, int N)
{ //http://homepages.cae.wisc.edu/~brodskye/mr/phaseunwrap/unwrap.c
    float dp[fftSize];
    float dps[fftSize];
    float dp_corr[fftSize];
    float cumsum[fftSize];
    float cutoff = M_PI;
    int j;
    
    // incremental phase variation
    // MATLAB: dp = diff(p, 1, 1);
    for (j = 0; j < N-1; j++)
        dp[j] = p[j+1] - p[j];
    
    // equivalent phase variation in [-pi, pi]
    // MATLAB: dps = mod(dp+dp,2*pi) - pi;
    for (j = 0; j < N-1; j++)
        dps[j] = (dp[j]+M_PI) - floor((dp[j]+M_PI) / (2*M_PI))*(2*M_PI) - M_PI;
    
    // preserve variation sign for +pi vs. -pi
    // MATLAB: dps(dps==pi & dp>0,:) = pi;
    for (j = 0; j < N-1; j++)
        if ((dps[j] == -M_PI) && (dp[j] > 0))
            dps[j] = M_PI;
    
    // incremental phase correction
    // MATLAB: dp_corr = dps - dp;
    for (j = 0; j < N-1; j++)
        dp_corr[j] = dps[j] - dp[j];
    
    // Ignore correction when incremental variation is smaller than cutoff
    // MATLAB: dp_corr(abs(dp)<cutoff,:) = 0;
    for (j = 0; j < N-1; j++)
        if (fabs(dp[j]) < cutoff)
            dp_corr[j] = 0;
    
    // Find cumulative sum of deltas
    // MATLAB: cumsum = cumsum(dp_corr, 1);
    cumsum[0] = dp_corr[0];
    for (j = 1; j < N-1; j++)
        cumsum[j] = cumsum[j-1] + dp_corr[j];
    
    // Integrate corrections and add to P to produce smoothed phase values
    // MATLAB: p(2:m,:) = p(2:m,:) + cumsum(dp_corr,1);
    for (j = 1; j < N; j++)
        p[j] += cumsum[j-1];
}


//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

/*
inline float STFT::unwraper(float previous_angle, float new_angle){
    float d = new_angle - previous_angle;
    d = d > M_PI ? d - 2 * M_PI : (d < -M_PI ? d + 2 * M_PI : d);
    return previous_angle + d;
}
*/

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Normalize to [-180º, 180º):
/*
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
        
inline float STFT::unwraper(float previousAngle, float newAngle){
    return previousAngle - angleDiff(newAngle, angleConv(previousAngle));
}
*/




        
        
        
