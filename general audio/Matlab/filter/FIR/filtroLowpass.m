function b = filtroLowpass
%FILTROLOWPASS Returns a discrete-time filter object.

% MATLAB Code
% Generated by MATLAB(R) 8.6 and the Signal Processing Toolbox 7.1.
% Generated on: 20-Oct-2019 01:20:25

% FIR Window Lowpass filter designed using the FIR1 function.

% All frequency values are in Hz.
Fs = 44100;  % Sampling Frequency

N             = 10;       % Order
Fc            = 1000;     % Cutoff Frequency
flag          = 'scale';  % Sampling Flag
SidelobeAtten = 100;      % Window Parameter

% Create the window vector for the design algorithm.
win = chebwin(N+1, SidelobeAtten);

% Calculate the coefficients using the FIR1 function.
b  = fir1(N, Fc/(Fs/2), 'low', win, flag);
Hd = dfilt.dffir(b);

% [EOF]
