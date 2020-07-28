clc , clear all , close all
%%
% DC OFFSET
gain = 2; offSet = 1;
fs = 44100; Ts = 1 / fs; t = 0 : Ts : 1; t = t(:); % t = t(:) columna en 1 seg hay 44100 muestras
frec = 3 ;
in = sin(2 * pi * frec * t); 
out = [];
plot(in );hold on; grid on;
for n = 1 : length(in)
    out(n,1) = in(n,1)* gain + offSet;
end

plot(out); hold off;
