clc, clear all, close all
%%
% inversion de polaridad : cambiar la senal en sus valores de amplitud positivos
% por los negativos (positvo = compresion de la senal).. no depende d ela
% frecuencia

entrada = [0; 0.5;1;0.5;0;-0.5;-1;-0.5;0],amplitud = -1; 

for muestra = 1: length(entrada) 
    salida(muestra,1) = amplitud * entrada(muestra,1); % anadir una amplitud a la senal de entrada que cambia el signo

end
plot(entrada), hold on,plot(salida);

%%
% con senales
fs = 44100, Ts = 1 / fs;
t = 0: Ts : 1 , t = t(:); 
frec = 2;
senal = sin(2 * pi * frec * t), amplitud = -1; 

for muestra = 1: length(senal) 
    salida(muestra,1) = amplitud * senal(muestra,1); % anadir una amplitud a la senal de entrada que cambia el signo

end
plot(senal), hold on,plot(salida);


% https://www.youtube.com/watch?v=S1u3RVdIA-
% https://www.youtube.com/watch?v=Wv_RMhLu_So