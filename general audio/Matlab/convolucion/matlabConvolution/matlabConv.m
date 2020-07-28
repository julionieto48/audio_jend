clc, clear all, close all
%%
% la convolucion es una operacion matematica, en la que si conozco la respuesta al impulso de un sistem
% puedo procesar esta senal a traves d ela convolucion 

% importar archivo de audio
[xN,Fs] = audioread('inputVoice.wav'); % [y,Fs] = audioread(filename) Lee los datos del archivo denominado filenamey devuelve los datos muestreados, yy una frecuencia de muestreo para esos datos, Fs.
xNLeft = xN(:,1); xNRight = xN(:,2);
% rta al impulso
h = audioread('RubyRoom.wav');
hLeft =  h(:,1); hRight = h(:,2);
hN = [hLeft,hRight];
%%
figure
subplot(3,1,1);
plot(xN); xlabel(' muestras [n]');ylabel(' Amplitud []'); grid on; title('x(n)')
sound(xNLeft,Fs)

subplot(3,1,2);
plot(hN); xlabel(' muestras [n]');ylabel(' Amplitud []'); grid on; title('h(n)')

subplot(3,1,3);
% yN = conv2(xN,h);
yNLeft = conv2(xNLeft,hN);
yNRight = conv2(xNRight,hN);

yN = [yNLeft,yNRight];
plot(fft(yN)); xlabel(' muestras [n]');ylabel(' Amplitud []'); grid on; title('y(n)')
sound(yNLeft,Fs)

figure
subplot(3,1,1);
plot(xN); xlabel(' muestras [n]');ylabel(' Amplitud []'); grid on; title('x(n)')


subplot(3,1,2);
plot(fft(hN)); xlabel(' muestras [n]');ylabel(' Amplitud []'); grid on; title('h(n)')

subplot(3,1,3);
% yN = conv2(xN,h);
yNLeft = conv2(xNLeft,hN);
yNRight = conv2(xNRight,hN);

yN = [yNLeft,yNRight];
plot(fft(yN)); xlabel(' f [hZ]');ylabel(' Amplitud []'); grid on; title('y(n)')





%%
% https://la.mathworks.com/help/matlab/ref/fft.html
% https://en.wikipedia.org/wiki/Convolution
% https://la.mathworks.com/help/matlab/ref/cross.html sound(yN,Fs)
% https://la.mathworks.com/help/matlab/ref/conv.html
% https://la.mathworks.com/matlabcentral/answers/167726-error-using-conv-line-27-a-and-b-must-be-vectors
% https://www.geniolandia.com/13139905/de-matriz-a-vector-en-matlab