clc , clear all , close all
%%

fs = 800 ; Ts = 1/fs ;timeSig = 0.0012 ; n = fs * timeSig ; t = 0: Ts : n - Ts; % t = 0: Ts :(n-1) * timeSig ;  % t = linspace(0,p,f); % muestreo y long de la signal
% fs = 800 ; Ts = 1/fs ;timeSig = 1 ; t = 0: Ts : timeSig ;

fMod = 1000 ; TMod = 1/fMod ; aMod = 1;
tMod = linspace(0,TMod  ,fMod); 
moduladora = aMod*sin(2*pi*fMod*t);
 
% figure(1); plot(t , moduladora) ; title(' Moduladora')


fCarri = 500000 ; TCarri = 1 / fCarri ; aCarri= 1;
tCarry = linspace(0, TCarri  ,fCarri);
portadora = aCarri *cos(2*pi* fCarri * t);

%figure(2) ; plot(t , portadora) ; title(' Portadora') ; grid on

modulada = portadora .* moduladora ;
% figure(2) ;plot(t , modulada ) ; title(' Senal Modulada') ; grid on 

%%
dftModulada = fft(modulada); % dft de la senal 
mModulada = abs(dftModulada); % magnitud
p = unwrap(angle(dftModulada)); % fase
% frec = (0 : length(dftModulada)-1)* 100/length(dftModulada); % frec = f *(0:(t./2))./t; 
fn = 0 : (length(dftModulada) - 1) * 100 / length(dftModulada) %fn = 0 : fs/n : fs - fs/n ;
% plot(frec,mModulada) ; title('Magnitud') ; grid on ; 

%%
figure(1)
subplot(4,1,1); plot(t , moduladora) ; title(' Moduladora') ; grid on

subplot(4,1,2); plot(t , portadora) ; title(' Portadora') ; grid on

subplot(4,1,3); plot(t , modulada ) ; title(' Senal Modulada') ; grid on

subplot(4,1,4); plot(fn, mModulada) ; title('Magnitud') ; grid on ; xlabel('f (Hz)') ; ylabel('|Modulada(f)|')