clc , clear all , close all
%%
% Normalizacion RMS 
% se escala el volumen de la senal, d emanera que el rms de la sena de
% salida satisface ciertos criterios, d emanera que determinan el factor
% lineal de escalamiento de la senal de entrada

fs = 44100; Ts = 1 / fs ; tiempoSignal = 1 ; t = Ts : Ts : tiempoSignal;
t = t(:); frec = 1;

signal = sin(2 * pi * frec * t); plot(signal) ; grid on ; hold on ;


% calculo del rms (1)
sigCuad = signal .^2; 
meanSquareC = mean(sigCuad);
rootMeanSquare = sqrt(meanSquareC)


% encontrar en dB (2)

rootMeanSquaredB = 20 * log10(rootMeanSquare/1) %1 @ full scale

%%
% en la senal de salida
% obtener un rms deseado de acuerdo a una entrada en dB
fs = 44100; Ts = 1 / fs ; tiempoSignal = 1 ; t = Ts : Ts : tiempoSignal;
t = t(:); frec = 1;

signal = sin(2 * pi * frec * t); plot(signal) ; grid on ; hold on ;



% poner el nivel deseado en dB (4) y convertirlo a lineal
rDB = -6 ; r = 10 ^(rDB / 20);

% determinar el factor de escalamiento de la salida (5)
num = length(signal * r ^2 ); den = sum(signal.^2) ; a = sqrt ( (num) / (den) );
% escalar la amlitud dentrada (3)
out = signal * a;


% calculo del rms (1)
sigCuad = out .^2; 
meanSquareC = mean(sigCuad);
rootMeanSquare = sqrt(meanSquareC)


% encontrar en dB (2)
rootMeanSquaredB = 20 * log10(rootMeanSquare/1) %1 @ full scale

plot(out); 

% https://www.noisehelp.com/decibel-scale.html