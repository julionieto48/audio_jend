clc , clear all , close all
%%
% Los cambios en ganancia se interpretan en una esclaa de decibeles, mas
% que en una escala lineal

dB = -6 ; % entrada correspondiente a 6 dB, la mitad de la amplitud y 6 es el doble amplitud
10 ^(dB / 20) ; % dB = 20 Log(Lin)

%%
signal = [0 ; 0.5 ; 1 ; 0.5 ; 0 ; -0.5 ; -1 ; -0.5];
stem(signal); grid on ;hold on
out = [];
dB = 12;
linGain = 10 ^(dB / 20);

for n = 1 : length(signal)
    out(n,1) = signal(n,1) * linGain;
end

stem (out); hold off; 

% convertirlo a dB
outDB = []; signalDB = [];
for n = 1 : length(signal)
    outDB(n,1) = 20* log10(out(n,1));
    signalDB(n,1) = 20* log10(signal(n,1));
end
outDB
signalDB
%outDB = 20* log10(out); signalDB = 20 * log10(signal);

plot(outDB);set(gca, 'YScale', 'log'); grid on; hold on; plot(signalDB);
%semilog(signalDB);