clc , clear all , close all
%%
% Linear Gain

signal = [0 ; 0.5 ; 1 ; 0.5 ; 0 ; -0.5 ; -1 ; -0.5];
stem(signal); grid on ;hold on
out = [];
gain = 1.2;

for n = 1 : length(signal)
    out(n,1) = signal(n,1)* gain;
end

stem (out); hold off;

% salida = [];
% sample = 1;
% while int(sample) <= length(signal)
%     signal(sample) = signal(signal)* gain;
%     sample = sample + 1;
% end   

%% 
fs = 44100; Ts = 1 / fs; t = 0 : Ts : 1; t = t(:); % t = t(:) columna en 1 seg hay 44100 muestras
frec = 3 ;
in = sin(2 * pi * frec * t); 
out = [];
plot(in );hold on; grid on;
for n = 1 : length(in)
    out(n,1) = in(n,1)* gain;
end

plot(out); hold off;

%%
signal = [0 , 0.5 , 1 , 0.5 , 0 , -0.5 , -1 , -0.5]
output = signal * gain