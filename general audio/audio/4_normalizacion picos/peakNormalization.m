clc , clear all , close all
%%
% buscar normalizacion de picos
% el pico max de la senal alcanza un nivel normalizado (0dB), los demas
% picos mantienen la relacion
signal = [0 ; 0.5 ; 1 ; 0.5 ; 0 ; -0.5 ; -1 ; -0.5];
stem(signal); grid on ;

% medir el pico max de la senal

signalPeak = max( abs(signal) );

% normalizar la amplitud usando el pico dela senal

out = (1 / signalPeak) * signal; % (1 / signalPeak) ->factor de escalamiento
% 0.5 / 0.5 = 1 , 1 / 1 = 1 se dividie en el mayor en si mismo y este es el
% que va a establecer la normalizacion (la referencia es uno)
stem(out) ; grid on;


%%
[in,fs] = audioread('inputVoice.wav');
plot(in);  grid on;
signalPeak = max( abs(in(:,1)) );
out = (1 / signalPeak) .* in;
plot(out);

%%
% anadir un factor de escalamiento en dB

[in,fs] = audioread('inputVoice.wav');
plot(in);  grid on;
signalPeak = max( abs(in(:,1)) );

dB = 0 ; % normalizar a este valor
linGain = 10 ^(dB / 20)
out = linGain * (1 / signalPeak) .* in;
plot(out); grid on;


%%
% usando diferencias
signal = [0 ; 0.5 ; 0.8 ; 0.5 ; 0 ; -0.5 ; -0.8 ; -0.5];
stem(signal); grid on ;

nivelDeseado = 1;
signalPeak = max( abs(signal) );
diferencia = nivelDeseado - signalPeak;

salida = [];

for i = 1 : length(signal)
    salida(i) = signal(i) + diferencia;
end
stem(salida); grid on;