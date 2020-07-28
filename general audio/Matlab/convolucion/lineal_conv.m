clc, clear all , close all

xn = input('ingresar secuencia entrada'); %[2 3 1] 
l_in = length(xn);

hn = input('ingresar secuencia rta impulso'); % [-1 2 1 3]
l_imp = length(hn);

m = l_in + l_imp -1 ;  %longitud de la salida
z = zeros(1,m); % una fila varias columnas
z = conv(xn,hn); disp(z)


%%
% zeroPadding de las senalz

xn_z = [xn,zeros(1,l_imp -1)];
hn_z = [hn,zeros(1,l_in -1)];


y = zeros(1,m); % salida

for i = 1: m
    
    for  j = 1 : i 
        %disp(i);disp(j);disp('____')
        y(i) = y(i) + xn_z(j) * hn_z(i - j + 1);
        %disp(i - j + 1);disp('____')
    end
 
end

disp(y); % comparar las salidas