
clc, clear all, close all
%%


fs = 44100;  % sample rate
time = 1.5 ; % tiempo de la senal

numSamples = fs * time ; % durasion de la senal en muestras 

ruidO = randn(numSamples,1); % de una columna

plot(ruidO) 

%%
% escalar amplitud
ruidO = 0.2 * randn(numSamples,1);
plot(ruidO);
audiowrite('ruidoBlanco.wav',ruidO,fs); % igual amplitud en toda slas frecuencias


% https://www.youtube.com/watch?v=UQxyk1Qs2gU