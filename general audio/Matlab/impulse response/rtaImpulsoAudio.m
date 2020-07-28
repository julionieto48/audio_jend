clc,clear all , close all
%%
ArchivoA = 'snare.mp3';
[y,fs]=audioread(ArchivoA); 
plot(y); title(ArchivoA); xlabel('muestras[n]'); % senal vs tiempo


b1 = -0.5; h = [];
for (n = 1 : size(y))
    if (n == 1)      
        h(n) = -0.5;
    elseif( n >= 2)
        h(n) = b1 * h(n - 1);
    end 
end
h
out = conv(y,h); 
plot(out);title(ArchivoA); xlabel('muestras[n]');
sound(out,fs);
