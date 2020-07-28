clc, clear all, close all

%%
xn = [2 3 1]
hn = [-1 2 1 3]
lenXn = length(xn);lenHn = length(hn);

N = max(lenXn,lenHn);

yn = zeros(1,N);
yn = cconv(xn,hn,N);

% zero pad
x = [xn zeros(1,N - lenXn)];
h = [hn zeros(1,N - lenHn)];

y = zeros(1,N);

for n = 1 : N
    for m = 1: N
        j = mod(n-m,N);
        j = j + 1;
        y(n) = y(n) + x(m) * h(j);
    end
end

disp(y)

%
% https://dspillustrations.com/pages/posts/misc/circular-convolution-example.html