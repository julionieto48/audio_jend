clc , clear all , close all

%%
% *FILTROS FIR*
%%
% uso de fda tool con audio
archivoAudio = 'inputVoice.wav' ; filtro =  load('b2_dos.mat') ; % realizado en fda tool
[y,fs] = audioread(archivoAudio);


t = ( length(y) - 1 ) / fs ;  T = 0 : 1/fs : t  ; 

nFilter = 12 ; fUno = 20 / (fs/2) ; fDos = 800 / (fs/2) ; b = fir1(nFilter,[fUno fDos]); % dise?o filtro fir fir1(ordenFilfro, [fN1 fN2]), stopband) la frec es normalized , b es los coeficientes de y a es igual a 1
yFiltradoUno = filter(b,1,y) ;

b2 = filtroLowpass() ;
yFiltradoDos = filter(b2,1,y) ;

figure(1)
subplot(3,1,1) ; plot(T, 20 * log10(y) ) ; xlabel(' tiempo [seg]') ; ylabel(' Amplitud ') ; grid on ; title(' Senal Original')
 
subplot(3,1,2) ; plot(T, 20 * log10(yFiltradoUno) ) ; xlabel(' tiempo [seg]') ; ylabel(' Amplitud ') ; grid on ; title(' Senal Filtrada Por Fir Uno')

subplot(3,1,3) ; plot(T, 20 * log10(yFiltradoDos) ) ; xlabel(' tiempo [seg]') ; ylabel(' Amplitud ') ; grid on ; title(' Senal Filtrada Por Fir Dos')

figure(2)
freqz(b,1) ; freqz(b2,1) ;