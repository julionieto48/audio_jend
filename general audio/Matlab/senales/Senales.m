clear all, close all, clc
%%

% Leer una señal de audio
Archivo = 'AudioMusical.mp3';
[y,fs]=audioread(Archivo); %y es datos sampleados fs = frecuencia de muestreo
disp(fs); % frecuencia de muestreo
whos y; % audio en formato nativo

% leer primeros 2 segundos
muestras = [1,2* fs]; clear y fs;
[y,fs]=audioread('AudioMusical.mp3');
% sound(y,fs);

% representacion
plot(y); title(Archivo); xlabel('muestras[n]'); grid on; % señal vs tiempo

%regla de 3 ... 1s->425088; t -> fs;
duracion = length(y)/fs;
t = 1/fs:1/fs:duracion; plot(t,y);
t =0:1/fs:(length(y)-1)/fs; 
plot(t,y); title(Archivo); xlabel('muestras  [n]'); grid on; %grafica lo mismo

figure;
subplot(2,1,1);
plot(y);xlabel('Muestras');ylabel('Amplitud');grid on;title('Muestras');

subplot(2,1,2);
a=(length(y)-1)/(fs);
T=0:1/fs:a; % periodo
plot(T,y); xlabel('tiempo'); ylabel('Amplitud'); grid on;


figure;
subplot(2,1,1);a=(length(y)-1)/(fs);T=0:1/fs:a; 
plot(T,y);xlabel('tiempo');ylabel('Amplitud');grid on;
%sound(y,fs,16)

%fdatool;% crear y dar parametros al filtro par aexportar

subplot(2,1,2);
% como es filtro iir para filtro fir=filter(h,1,y);
[v,a]= sos2tf(h,G);
yfiltrada =filter(v,a,y);plot(T,yfiltrada);title('Filtrado');
% sound(yfiltrada,fs,16);


%Referenciaas:
%https://www.mathworks.com/help/matlab/ref/audioread.html