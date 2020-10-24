clc, clear all , close all
%%
% * *Echo Effect* * 
% efecto basado en el retardo de una senal en el tiempo, se les conoce como sistemas con 
% memoria debido a que al estar calculando la slida de acuerdo a una salida, depende de la entrada y de versiones previas
% como si estuviese guardado en memoria 

% parametros:
% longitud del delay en tiempo o tempo 
% amplitud de la senal retrasada (dry o wet)
% feedback cantidad de repeticiones

%%
% _feed foward echo_
% colcando la entrada el sistema en la salida -> 1 repeticion
[x,fs] = audioread('inputVoice.wav'); 
xLeft = x(:,1); xRight= x(:,2) ;
xN = [xLeft ; xRight];

% calcular tiempo de delay
segundos = 0.25; % [seg]
muestraTiempoDelay = segundos * fs; % en 1 seg hay 44100 segundos * (muestras/segundo) = muestras es el valor equivalente al tiempo en muestras

% zero padding: poner ceros al inicio

dryPath = [xN ; zeros(muestraTiempoDelay,1)]; % concatenarceros al final
wetPath = [zeros(muestraTiempoDelay,1); xN] ; % concatenarceros al inicio


out = zeros(size(dryPath)) ; % hace ruqe la salida sea un arreglo de ceros del tamano de la muestra original concaenada
wetGain = 0.5;
for n = 1: length(dryPath) % n = saple
    
    out(n,1) = dryPath(n,1) + wetGain * wetPath(n,1);
end

%sound(x,fs);
%sound(out,fs);

%%
% array indexing
% wetPath es una version de la senal de entrada x
out = zeros(size(xN)) ;
for n = 1: length(xN) 
    if (n - muestraTiempoDelay < 1) % evitar indice negativo
        out(n,1) = xN(n,1); % la salida va a ser la entrada
    else 
        out(n,1) = xN(n,1) + xN(n - muestraTiempoDelay,1);
    end 
end

% sound(out,fs);

%%
% Delay Buffer
% es un arreglo en memoria que almacena las muestras previas de la senal
% indexar el arreglo del buffer para sacar las muestras retrasada guardadas
% en un arreglo

out = zeros(size(xN)) ;
buffer = zeros(muestraTiempoDelay,1);

for n = 1 : length(xN)
    
    out(n,1) = xN(n,1) + buffer(end,1); % sumar senal de antrada con la ultima muestra del buffer xN(n,1) = muestra actual
    buffer = [xN(n,1); buffer(1:(end - 1), 1) ]; % actualizar el buffer sin que cambie de tamano
end

sound(out,fs);



%%
% |referencia|
% https://www.youtube.com/watch?v=1qAqEu0xnG8&t=24s 