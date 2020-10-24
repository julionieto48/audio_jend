import math
import matplotlib.pylab as plt
import numpy as np


class Partitura:

    def __init__(self, bpm):
        #beats por minutos en tiempo de negra
        self.bpm = int(bpm)
        self.BitDepth = 16
        self.fs = int(44100)
        self.SampleRate = (1 / float(self.fs))

    def figure(self):

        negra = (self.fs*60/self.bpm); #print 'negra = ', negra
        redonda = 4*negra; #print 'redonda = ', redonda
        blanca = 2*negra; #print 'blanca = ', blanca
        corchea = (negra/2); #print 'corchea = ', corchea
        semicorchea = (negra/4); #print 'semicorchea = ', semicorchea

        return negra, redonda, blanca, corchea, semicorchea

    def note(self, n, octa):

        #Valores de la octava 4
        if n == 'C':
            tono = 261.63
        elif n == 'C#':
            tono = 277.18
        elif n == 'D':
            tono = 293.66
        elif n == 'D#':
            tono = 311.13
        elif n == 'E':
            tono = 329.63
        elif n == 'F':
            tono = 349.23
        elif n == 'F#':
            tono = 369.99
        elif n == 'G':
            tono = 392
        elif n == 'G#':
            tono = 415.3
        elif n == 'A':
            tono = 440
        elif n == 'A#':
            tono = 466
        elif n == 'B':
            tono = 493.88

        if octa == 1:
            tono *= 1/8.0
        elif octa == 2:
            tono *= 1/4.0
        elif octa == 3:
            tono *= 1/2.0
        elif octa == 4:
            tono *= 1
        elif octa == 5:
            tono *= 2
        elif octa == 6:
            tono *= 4
        elif octa == 7:
            tono *= 8

        return tono

    def amp(self, dB):
        ampl = ((2**self.BitDepth)/2)*(10**(float(dB)/10))**0.5
        return ampl

    def sin(self, amps, t, f):
        x_sin = []
        for n in range(t):
            x = amps*math.sin(2*math.pi*f*(n*self.SampleRate))
            x_sin.append(x)
        return x_sin

    def square(self, amps, t, f):
        x_square = []
        for n in range(t):
            x = math.sin(2*math.pi*f*(n*self.SampleRate))
            if x >= 0:
                x_square.append(amps)
            if x < 0:
                x_square.append(-amps)
        return x_square

    def triangle(self, amps, t, f):
        x_triangle = []
        T_m = self.fs/f
        c = 0
        for t in range(t):
            if c <= (T_m/4.0):
                m = 4.0/T_m
                x = m*c
                x_triangle.append(amps*x)
                c += 1
            if (c > (T_m/4.0)) & (c <= (3*T_m/4.0)):
                m = -4.0/T_m
                b = 2
                x = m*c + b
                x_triangle.append(amps*x)
                c += 1
            if (c > (3*T_m/4.0)) & (c < T_m):
                m = 4.0/T_m; b = -4
                x = m*c + b
                x_triangle.append(amps*x)
                c += 1
            if c == int(T_m): #reinicia el contador c, para permitir el dominio de los proximos periodos
                c = 0
        return x_triangle

    def sawtooth(self, amps, t, f):
        x_sawtooth = []
        T_m = self.fs/f
        c = 0
        for t in range(t):

            if c <= T_m/2.0:
                m = 2.0/T_m
                x = m*c
                x_sawtooth.append(amps*x)
                c += 1

            if (c > T_m/2.0) & (c <= T_m):
                m = 2.0/T_m; b = -2
                x = m*c + b
                x_sawtooth.append(amps*x)
                c += 1

            if c == int(T_m):
                c = 0
        return x_sawtooth

    def silencio(self, t):
        x_silencio = []
        for t in range(t):
            x = 0
            x_silencio.append(x)
        return x_silencio

    def muest(self, arreglo):
        t = np.linspace(0, len(arreglo)/self.fs, len(arreglo))
        plt.plot(t, arreglo)
        plt.show()













