clc , clear all , close all
%%
% generar seno
%omega = 0.25 * pi ; ampl = 1 ; xn = ampl * sin(omega * n) ;
frec = 10000; fs = 44100 ;
% xn = [];
% for i = 1 : 100
%     xn(i) = sin(2 * pi * frec * i / fs  );
% end
%%


T = 1/fs;                % segundos por muestra / periodo de muestreo
tiempoSenal = 0.25;      % segundos 
t = (0:T:tiempoSenal)';  % segundos

xn = sin(2* pi * frec *t);



% periodo de la senal
 TSenal  = 1/frec ;

 % pasos en tiempo por periodo
tt = 0: T : TSenal + T ;
%d = sin(2*pi*F*tt) ;
%plot(tt,d) ;

%
% [h,w] = freqz(xn); %get Frequency Response%
nfft = length(xn) ; nfft = 2 ^ nextpow2(nfft) ;
dftXn = fft(xn , nfft) ;

magXn = abs(dftXn); magXn = magXn(1 :nfft / 2);  magXnNormal = magXn / max(magXn);
nFft = fs * (0 : nfft/ 2 - 1) / nfft;

%%
M = length(xn) ; 
n = 0 : 1 : M - 1; 


% hacer ventana hamming
s = 2*pi*(n/(M-1))   ;      % argumento
w = 0.54-0.46*cos(s) ;      % funcion de la ventana

%%
% multiplicar senal y ventana
length(xn)
length(w)

senalVentaneada =  xn * w ;




%%
figure(1)
subplot(5,1,1) ; plot(n,w); grid ; title('ventana Hamming '); xlabel('n'); ylabel('w')

subplot(5,1,2) ; plot(xn); grid ; title('funcion seno ')    ; xlabel('n') ;

subplot(5,1,3) ; plot(nFft , magXnNormal ); grid ; title('rta en frec de la senal') ; xlabel('Frequencia') ; ylabel('Amplitud')

subplot(5,1,4) ; stem(n,t);grid ; title('Multiplicacio de la ventana Hamming y funcion seno'); xlabel('n') ; ylabel('Amplitud ')
