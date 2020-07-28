clc, clear all, close all;
%%
y = linspace(0,2*pi,10);
h = stem(cos(y),'fill','-.');
set(h(3),'Color','r','LineWidth',2) % Set base line properties
axis ([0 11 -1 1])
%%
y_n = [-1 -0.5 -0.25 0 0.25 0.5 1];
n1 = 1:length(y_n);
figure;stem(n1,y_n);grid on

ynr = []; % arreglo de la funcion reversada
ultima_posicion = length(y_n)
for(n = 1:length(y_n))
    
    ynr(n) = y_n(ultima_posicion)
    ultima_posicion = ultima_posicion -1;  
end
figure;stem(n1,ynr);grid on
%%

x_n = [-1 -0.5 -0.25 0 0.25 0.5 1]; xnr = [];

ultima_posicion = length(x_n);
for(nr = 1:length(x_n))
    xnr(nr) = x_n(ultima_posicion);
    ultima_posicion = ultima_posicion -1;  
end

coeficientes = [1 2 1 2 ];
% hacer procesamiento para 4 muestras
y = []; % arreglo de salida final
for(n = 0:length(xnr)-1) % va de 0-6 n equivale al numero de filas- n = 0:length(xnr)-1
    l = 0;
    yn = 0; % resultado de la suma que se hace en cada fila
    while(n ~= l )
        if (l == 0)
            yinst = coeficientes(l)* xnr(n);
        end

        yinst = coeficientes(l)* xnr(n - l);
        yn = yn + yinst;
        l = l + 1;
    end
    y(n) = yn; 
    
end




