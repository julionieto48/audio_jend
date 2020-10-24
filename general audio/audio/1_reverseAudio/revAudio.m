clc, clear all, close all
%%
[x,fs] = audioread('inputVoice.wav');
xLeft= x(:,1);
xRight = x(:,2);

rev = x(end:-1:1); % empezar por el ultimo elemento hasta llegar a la primer muestra
%plot(rev);
%sound(rev,fs);

rev2 = zeros(length(xLeft),1);
lastPost = xLeft(length(xLeft));
for i= length(xLeft): 1
    rev2(i) = lastPost;
    lastPost = lastPost -1;
end
%plot(rev2);
%sound(rev2,fs);

rev3 = zeros(length(xLeft),1);
for i= length(xLeft): -1: 1
    rev3(i) = xLeft(i); 
end
plot(rev3);
sound(rev3,fs);