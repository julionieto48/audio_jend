clc , clear all , close all

%%
% * Ventaneo*

% rectangular
M = 8 ; L = 2*M+1 ; % long de la ventana L = 17 canidad de lobulos
wn = [ones(1,L)] ; % ventana rectangular wn  =  [1 1 1] * 17
omega = -pi: 2*pi/200: pi ;  % Frequency range - pi hasta pi
Hd = freqz(wn,1,omega);  mag = 20*log10(abs(Hd));   % Frequency response

M1 = 20;                   % M = 20 cambiando el M
L1 = 2*M1+1;               
wn1 = [ones(1,L1)];        
omega = -pi:2*pi/200:pi;   
Hd1 = freqz(wn1,1,omega);  mag1 = 20*log10(abs(Hd1)); 

figure(1)
subplot(2,1,1), plot((omega/pi),mag), ...
    xlabel('Frec Normalizada'), ylabel('Magnitude(dB)'), grid;
axis([-1 1 -40 40]);
subplot(2,1,2), plot((omega/pi),mag1), ...
    xlabel('Frec Normalizada'), ylabel('Magnitude(dB)'), grid;
axis([-1 1 -40 40]);
%%


% sea una ventana hanning  de funcion w[n] = 0.5 * cos(1 - cos(2pin / L -1))
% donde la longitu L est? definida por L = 2M+1 , en caso en el que n es el
% numero demuestras en el rango n = 0,..., L-1 y donde n es simetrico en el
% medio n = M 
M = 8 ; L = 2*M+1 ; n = 44100 * 1 ;
n  = linspace(0,length(n) - 1); % n = 0 : 512 ; es igual al data in
wnHann = 0.5 * cos(1 - cos(2 * pi * n / L - 1)) % w(n)=0.5(1?cos(2*pi * n / N))   N = L -  1.
omega = -pi: 2*pi/200: pi ;
HdHann= freqz(wnHann,1,omega);  magHann = 20*log10(abs(HdHann));


figure(2)
plot((omega/pi),magHann); hold on ; HdHannTwo= freqz(hann(L),1,omega) ; magHannTwo = 20*log10(abs(HdHannTwo));
plot((omega/pi),magHannTwo); grid on ; 

%% 
% aplicar a senal entrante
fs = 800 ; Ts = 1/fs ; tiempoDeseadoSenal = 0.83 ; n = fs * tiempoDeseadoSenal; t = 0: Ts : n - 1; % t = 0: Ts : n - Ts; % t = 0: Ts :(n-1) * timeSig ;

frec = 100 ; senalIn = 1 *sin(2*pi*frec*t); nIn = length(senalIn);

senalVentaneada = [];
for i = 1 : nIn 
    wnHan = 0.5 * (1 - cos(2*pi*i/nIn - 1));
    senalVentaneada(i)  = wnHan * senalIn(i);
    
end

figure(3)
subplot(3,1,1), plot(senalIn); grid on ;
subplot(3,1,2), plot(senalVentaneada); grid on ;
%%


m=80; % The length of the Karnel%
n= 0:1:m-1; %Defines Range of position value%
p= n-(m-1)/2; %Angle%
fc=0.1; %Define Cutoff frequency%
Z = sin(2*pi*fc*p)./(pi*p); %Define truncated Sinc function%
stem(n,Z);grid %To represent the discrete signal value & draw the grid lines%
title('Unit Sample Response of the sin function') %Define the title of the figure%
xlabel('n') ; ylabel('Z') 

figure(4) 
[h,w] = freqz(Z); %get Frequency Response%
plot(w/pi,abs(h));grid
title('Frequency response of the sin function') ; xlabel('Frequency') ; ylabel('Amplitude')

figure(5)
s = 2*pi*(n/(m-1)); %Angle%
w = 0.54-0.46*cos(s); %Define Hamming window function%
stem(n,w); grid ; title('Hamming Window'); xlabel('n'); ylabel('w')

figure(6)
t=  Z.* w; %Multiplication of Hamming Window and sin function%
stem(n,t);grid
title('Multiplication of Hamming Window and sin function'); xlabel('n') ; ylabel('t')

figure(7)
[h,w]=freqz(t);
plot(w/pi,abs(h));grid
xlabel('Frequency')
ylabel('Magnitude')
title('Frequency response of the windowed sin function')
figure(8); grid
freqz(t)
title('Frequency Response of the windowed sin function in dB')


%%
% https://docs.scipy.org/doc/numpy/reference/generated/numpy.hanning.html
% https://stackoverflow.com/questions/3555318/implement-hann-window
% https://docs.scipy.org/doc/numpy/reference/generated/numpy.hanning.html