clc , clear all , close all
%%
% buscar  amplitud pico

arreglo = [2 4 -1 5 2 5 12 4 2];
valorMayor = 0; valorMenor = 1;

for i = 1 : length(arreglo)
    valorActual = arreglo(i);
    if i == 1
        valorActual = valorMayor;
        valorActual = valorMenor;
    else 
        if valorActual> valorMayor
            valorMayor = valorActual;
        elseif valorActual < valorMenor
            valorMenor = valorActual;
        end
    end    
end
valorMayor
valorMenor

%%
[in,fs] = audioread('inputVoice.wav');
plot(in); hold on; grid on;

% encontrar el vlaor absoluto ... conviert elo negativo a positivo
magnitudSig = abs(in);
maxValue = max(magnitudSig)
plot(magnitudSig);
