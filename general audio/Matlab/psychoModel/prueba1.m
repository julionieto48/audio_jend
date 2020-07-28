clc, clear all, close all
%%

% generar seno
frec= 2 ; Amp=2 ;
fs = 44100 ; Ts = 1 / fs ;
tiempo = 1 ; t=0: Ts :tiempo ;
y = sin(2*pi*frec*t);

n = fs * tiempo;
time = 0: Ts :n;
yn = sin(2 * pi* frec * time);

plot(t,y);
plot(n,yn);

%%
% *Modelo Psicoacustico 1*
%%

%%
% _step 1_
% n = 1024; % cantidad de puntos de la fft
resolucionFrecuencia = fs / n;

% aplicar ventaneo
L = 1024 ; N = 0 : L-1 ;   % longitud de la ventana
wn = hann(L) ; % plot(N, wn)

hwn = yn.* wn;           % ventaneo
omega = -pi : 2*pi / 200 : pi; Hwindow = freqz(hwn,1,omega);

Y = fft(yn,n);