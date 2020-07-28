clc, clear all, close all;
%%
% *Rta Al Impulso* 
n = 0 : 10; % definir muestras de tiempo digital que van a ser computadas

% coeficientes 
a = [1] ; b = [1,0.9];%% b va con los x

d = zeros( size (n) );

%%
% con 2 retrazos
h = []; % crear arreglo vacio de la rta al impulso final
a = [1] ; b = [1.8 -0.5];

for ( n = 0 : 10 )
    
    if (n == 1)
        h(n) = 1
    elseif (n == 2)
        h(n) = b(1)* h(n-1); % el h (n-1) lo hace recursivo matematicamente 
    lseif (n > 2)
    end
    
end

%%
% hacer con n retrazos

%%
% probar con estas ecuaciones de dieferencias I/O
% y(n) = x(n) + 0.9 y(n - 1)
% h(n) = d(n) - 0.75 h(n-1)  -> h(n) = [1 -0.75 ]
% y(n) = x(n)+ 1.8 y(n-1)-0.5y(n-2)  h(n) = [1.0000    1.8000    2.7400    4.0320    5.8876    8.5817  ] 