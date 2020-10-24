clc , clear all , close all
%%
% RMS Level 
% promedio de la senal: sin embargo no se usa el promedio aritmetico debido
% a que hay valores negativos y este promedio seria cercano a cero, se hac
% el promedio de la magnitud usado el cuadrado y despues si el promedio
% aritmetico

fs = 44100; Ts = 1 / fs ; tiempoSignal = 1 ; t = Ts : Ts : tiempoSignal;
t = t(:); frec = 1;

signal = sin(2 * pi * frec * t); plot(signal) ; grid on ; hold on ;

%cuadrado de cada elemento
% -2 * -2 = 4 ; 2 * 2 = 4

sigCuad = signal .^2;  %plot(sigCuad); % va de 0 a 1

% promedio arit de la senal al cuadrado
meanSquare = 0;
suma = 0 ;
for i = 1 : length(sigCuad)
    meanSquare = (meanSquare + sigCuad(i)) / i ; % no es asi solo era por probar
    suma = suma + sigCuad(i) ;
end
meanSquare
meanSquareA = suma  / length(sigCuad)
meanSquareB = sum(sigCuad) / length(sigCuad)
meanSquareC = mean(sigCuad)

% sacar la raiz del promedio anterior
rootMeanSquare = sqrt(meanSquareC)
rmuestras = [];
for i = 1 : length(signal)
    rmuestras(i) = rootMeanSquare;
end
plot(rmuestras);
