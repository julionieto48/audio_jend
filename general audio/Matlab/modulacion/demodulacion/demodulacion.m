clc , clear all , close all
%%
% Modulacion
%fs = 800 ; Ts = 1/fs ;timeSig = 0.0012 ; n = fs * timeSig ; t = 0: Ts : n - Ts; % t = 0: Ts :(n-1) * timeSig ;  % t = linspace(0,p,f); % muestreo y long de la signal
% fs = 800 ; Ts = 1/fs ; t = linspace(0,Ts,fs) ; % timeSig = 1 ; t = 0 : Ts : timeSig - Ts; % t = linspace(0,Ts,fs);

fs = 441000 ; Ts = 1/fs ; timeSig = 1 ; L = fs * timeSig ;  t = (0: L-1)* Ts ;


fMod = 1000 ; TMod = 1/fMod ; aMod = 0.3;
tMod = linspace(0,TMod  ,fMod); 
moduladora = aMod*sin(2*pi*fMod*t);
 
% figure(1); plot(t , moduladora) ; title(' Moduladora')


fCarri = 4 ; TCarri = 1 / fCarri ; aCarri= 0.3;
tCarry = linspace(0, TCarri  ,fCarri);
portadora = aCarri *cos(2 * pi * fCarri * t);

%figure(2) ; plot(t , portadora) ; title(' Portadora') ; grid on

modulada = portadora .* moduladora ;
% figure(2) ;plot(t , modulada ) ; title(' Senal Modulada') ; grid on 

%%
nfft = length(modulada) ; % longitud de la senal a analizar en fft en tiempo
nfft = 2 ^ nextpow2(nfft) ; % el doble de resolucion en resolucion de potencias https://www.mathworks.com/help/matlab/ref/nextpow2.html

dftModulada = fft(modulada , nfft); % dft de la senal 

mModulada = abs(dftModulada); % magnitud
mModulada = mModulada(1 :nfft / 2); % debido a la simetria d ela fft
mModuladaNormal = mModulada / max(mModulada);

p = unwrap(angle(dftModulada)); % fase

nFft = fs * (0 : nfft/ 2 - 1) / nfft; % nFft = fs * (0 : nfft/ 2) / nfft -> tiene una sample mas
% frec = (0 : length(dftModulada)-1)* 100/length(dftModulada); % frec = f *(0:(t./2))./t; 
%fn = 0 : (length(dftModulada) - 1) * 100 / length(dftModulada); %fn = 0 : fs/n : fs - fs/n ;
% plot(frec,mModulada) ; title('Magnitud') ; grid on ; 



%%
% demodulacion
yDemodulada = moduladora .* (portadora .^(2)) ;

nfftDem = length(yDemodulada) ;  nfftDem = 2 ^ nextpow2(nfftDem) ;
dftDemodulada = fft(yDemodulada , nfftDem); % dft de la senal demodulada

mDemodulada = abs(dftDemodulada); mDemodulada = mDemodulada(1 :nfftDem / 2); 
mDemoduladaNormal = mDemodulada / max(mDemodulada);

nFftDem = fs * (0 : ( nfftDem / 2 - 1 )) / nfftDem ;

% filtrar la senal reconstruida / demodulada
b = filtroLow();
demodFiltrada = filter(b,1,yDemodulada) ;

%%
figure('Name','Modulacion Am') ; 
subplot(5,1,1); plot(t , moduladora) ; title(' Moduladora') ; grid on ; xlabel('tiempo (seg)') ;

subplot(5,1,2); plot(t , portadora) ; title(' Portadora') ; grid on ; xlabel('tiempo (seg)');

subplot(5,1,3); plot(t , modulada ) ; title(' Senal Modulada') ; grid on ; xlabel('tiempo (seg)');

subplot(5,1,4); plot( nFft, mModulada) ; title('Magnitud') ; grid on ; xlabel('f (Hz)') ; ylabel('|Modulada(f)|')

subplot(5,1,5); plot( nFft, mModuladaNormal) ; title('Magnitud') ; grid on ; xlabel('f (Hz)') ; ylabel('|Modulada(f)|')
%%

figure ('Name', 'Demodulacion DSB. sc') ;
subplot(6,1,1); plot(yDemodulada) ; title(' Demodulada') ; grid on ; xlabel('tiempo (seg)') ;
subplot(6,1,2); plot( nFftDem, mDemoduladaNormal) ; title('Magnitud') ; grid on ; xlabel('f (Hz)') ; ylabel('|Modulada(f)|') ;

subplot(6,1,3); plot( demodFiltrada ) ; title(' Moduladora reconstruida') ; grid on ; xlabel('tiempo (seg)') ;

subplot(6,1,4); plot(t , moduladora) ; title(' Moduladora') ; grid on ; xlabel('tiempo (seg)') ;

subplot(6,1,5); plot(t , portadora) ; title(' Portadora') ; grid on ; xlabel('tiempo (seg)');

subplot(6,1,6); plot(t , modulada ) ; title(' Senal Modulada') ; grid on ; xlabel('tiempo (seg)');

%%
% _convertir en audio_ 
filenameModuladora = 'senalModuladora.wav'; audiowrite(filenameModuladora,moduladora,fs);
filenamePortadora = 'senalPortadora.wav'; audiowrite(filenamePortadora,portadora,fs);
filenameModulada = 'senalModulada.wav'; audiowrite(filenameModulada,modulada,fs);
filenameModuladoraReconstruida  = 'senalModuladoraRecons.wav'  ; audiowrite(filenameModuladoraReconstruida,demodFiltrada,fs);