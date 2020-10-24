import math
import matplotlib.pylab as grafica


class dB():

    def __init__(self, dB, bitDepth , frecMuestreo, frecOnda, duracion):
        # frecOnda es la frecuencia deseada
        # 1 / 44100 = 2.26 x 10 ^ -5 es el periodo de muestreo
        # 2seg * 44100 = 88200 muestras
        self.dBFs = dB
        self.bitDepth = bitDepth
        self.muestras = 1 / ( float(frecMuestreo) )
        self.frecOnda = frecOnda
        self.tiempo = int( duracion * frecMuestreo )

    def amplitud(self):
        valorPico = ( (2 ** self.bitDepth)/2 ) * ( 10 ** (self.dBFs/10) ) ** (0.5)
        return valorPico

    def procesoSenal(self, amplitud):
        arreglo = []
        for n in range(self.tiempo):
            x = amplitud * math.sin(2 * math.pi * self.frecOnda * (n * self.muestras)) # muestra a muestra
            arreglo.append(x)
        return arreglo

    def graficar(self, Arreglo):
        grafica.plot(Arreglo)
        grafica.show(Arreglo)