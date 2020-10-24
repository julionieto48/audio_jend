clc, clear all , close all
%%
% * *Tempo Echo* * 
[x,fs] = audioread('inputVoice.wav'); 
xLeft = x(:,1); xRight= x(:,2) ;
xN = [xLeft ; xRight];

% calculo tiempo de delay
bpm = 120; 
beatPerSeg = bpm / 60 ; 
segPerBeat = 1 / beatPerSeg; % esto vale la negra o el pulso

% duracion de la nota en segundos
blanca = segPerBeat*2; negra = segPerBeat; corchea = segPerBeat / 2; semicorchea = segPerBeat / 4;
negraPuntillo = segPerBeat + corchea; corcheaPuntillo = corchea + semicorchea ;

% convertir a muestras

muestraTiempoDelay = fix(negraPuntillo * fs); % de acuerdo al parametro de tempo seleccionado debe se rentero

dryPath = [xN ; zeros(muestraTiempoDelay,1)]; % concatenarceros al final
wetPath = [zeros(muestraTiempoDelay,1); xN] ; % concatenarceros al inicio


out = zeros(size(dryPath)) ; % hace ruqe la salida sea un arreglo de ceros del tamano de la muestra original concaenada
wetGain = 0.5;
for n = 1: length(dryPath) % n = saple
    
    out(n,1) = dryPath(n,1) + wetGain * wetPath(n,1);
end

sound(out,fs);