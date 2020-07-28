clc, clear all, close all
%% 
%% Ejercicios de un FIR
b1 = -0.5;
% prueba
for (n = 1 : 5)
    if (n == 1)      
        h(n) = -0.5;
    elseif( n == 2)
        h(n) = b1 * h(n - 1) ;
    elseif( n == 3)
        h(n) = b1 * h(n - 1) ;
    elseif( n == 4)
        h(n) = b1 * h(n - 1);
    elseif( n == 5)
        h(n) = b1 * h(n - 1) % retorna la rta impulso
    end
    
end


h = []
for (n = 1 : 5)
    if (n == 1)      
        h(n) = -0.5
    elseif( n == 2)
        h(n) = b1 * h(n - 1)
    elseif( n > 2)
        %h_1(n) = h(n - 1)  % n = 3 [0 0 0.25] 0.25 -> h(2)
        h(n) = b1 * h(n - 1)
    end 
end

h = []
for (n = 1 : 5)
    if (n == 1)      
        h(n) = -0.5
    elseif( n >= 2)
        h(n) = b1 * h(n - 1)
    end 
end


%%
h = [] ; b1 = -2;
for (n = 1 : 5)
    if (n == 1)      
        h(n) = -0.5
    elseif( n >= 2)
        h(n) = b1 * h(n - 1)
    end 
end


% double out = inputValue + b1 * x1 + b2* x2 - a1 * y1 - a2 * y2 ;
%     y2 = y1;
%     y1 = out;
%     x2 = x1;
%     x1 = inputValue;
%     
% double out = inputValue + b1 * x1 
%     x1 = inputValue;
  
%%
% implementar y(n) = x(n)+ 1.8 y(n-1)-0.5y(n-2)
% b1 = 1.8; a2 = -0.5
% h = [];
% for (n = 1: 10)
%     if (n == 1)
%         h(n) = 1
%     elseif (n == 2)  
%         h(n) = a1 * h(n-1)
%     elseif (n > 2)
%         n
%         h_1(n) = h(n - 1)
%         h2 (n) = h(n - 2)
%         h(n) = b1* h(n-1) - b2 * h(n - 2)
%         
%     
%     end
% end