clc, clear all, close all
%%
% linealidad de la DFT
a1 = 2 ; a2 = 2;

% x1 = [1 2 3 4];
% x2 = [1 2 1 2];

t = 0:1/100:10-1/100;                     % Time vector
x1 = sin(2*pi*t) 
x2 = sin(2*pi*t) 

% computar DFT
X1 = fft(x1)
X2 = fft(x2)

x1 = a1 *  x1;
x2 = a2 *  x2;

X1 = a1 *  X1;
X2 = a2 *  X2;

% tiempo
x = x1 + x2;
uan = fft(x)
mx = abs(uan);
p = unwrap(angle(uan)); 

figure; 
subplot(2,1,1); f = (0:length(uan)-1)*100/length(uan); plot(f,mx); title('Magnitude') 
subplot(2,1,2);plot(f,p*180/pi);title('Phase')
% frecuencia
X = X1 + X2;
frec = fft(X)
mX = abs(frec); 

