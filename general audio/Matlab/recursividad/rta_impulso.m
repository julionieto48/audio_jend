function[ ] = rta_impulso(n)
h = [];
for (n = 0: 2)
  
    if (n == 1)
        h(n) = 1; %caso base
    elseif(n < 0 )
        h(n) = 0;
    elseif(n == 2) 
        h(n) = h(n) + -0.75  * rta_impulso(h(n-1) );
 
    end
end


for (n = 2: 0)
    disp(n)
end 