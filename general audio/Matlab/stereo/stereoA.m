clc , clear all , close all;
%%
% *audio Stereo* 
% _conversion mono a stereo_

[monoSenal, sampleFrec] = audioread('audio.wav');

% padding
monoPad = zeros( size(monoSenal) );

%concatenar
stereoSenalOnlyLeft = [monoSenal , monoPad] ; % solo est? en un lado
stereoSenal = [monoSenal , monoSenal] ;
%sound(stereoSenal , sampleFrec);

%%
% _amplitude control_ 
% 0 a 100 right y 0 a -100 left

panValue = -100 ;  % ingresado desde el daw

% | paneo lineal| 
% control por medio de expresiones matematicas
amplitudDcha = panValue / 200 + 0.5 ; % 100 / 200 = 0.5  + 0.5 = 1
amplitudIzda = 1 - amplitudDcha ;  

stereoSenal = [amplitudIzda * monoSenal , amplitudDcha * monoSenal ] ;

%sound(stereoSenal , sampleFrec);
%%
% |Square-Law| 
% la escucha esta basad ane la ptencia de la senal mas que en una amplitud

x = panValue / 200 + 0.5 ; % cambio de escala que este entre 0y 1

amplitudDcha = sqrt(x) ; % sqrt(1) = 1 sqrt(1) = 0.7 -> mayor amplitud la percepcion en el centro es mayor
amplitudIzda = sqrt(1 - x); 
stereoSenal = [amplitudIzda * monoSenal , amplitudDcha * monoSenal ] ;

% sound(stereoSenal , sampleFrec);


%%
% |sine - law| 

x = panValue / 200 + 0.5 ; % cambio de escala que este entre 0y 1

amplitudDcha = sin(x * pi / 2) ; % sqrt(1) = 1 sqrt(1) = 0.7 -> mayor amplitud la percepcion en el centro es mayor
amplitudIzda = sin((1 - x) * pi / 2); 
stereoSenal = [amplitudIzda * monoSenal , amplitudDcha * monoSenal ] ;
% sound(stereoSenal , sampleFrec);

%%
% comparacion de lineal vs square vs sine
x = [0: .01 : 1]; % represent alos valores posibles en los cambios de escala
plot(x,x,x,1-x,x,sqrt(x),x,sqrt(1-x),); 
legend('linealRight','linealLeft','squareRight','squareleft'); 
xlabel('pan [R to L'); ylabel('Ampl'); grid on;

figure; 
plot(x , x +(1 - x) , x , sqrt(x) + sqrt(1 - x) ); 
legend('lineal Amplitude', 'square Amplitude');
xlabel('pan [R to L'); ylabel('Ampl of both signals'); grid on;

figure; 
plot(x , (x).^2 +(1 - x).^ 2, x , (sqrt(x)).^2 + (sqrt(1 - x)).^ 2); % la func lineal no transmite potencia lineal
legend('lineal Power', 'square Power');
xlabel('pan [R to L'); ylabel('potencia of both signals'); grid on;
