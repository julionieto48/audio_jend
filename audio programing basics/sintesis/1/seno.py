__author__ = 'julian'


import math
import matplotlib.pylab as plt

class seno:
    wavearray = []

    def __init__(self, frecuencia, sampling, bitdepth, time):
        self.Frecuencia = frecuencia
        self.SamplingRate = sampling
        self.NumeroBit = bitdepth
        self.Seconds = time
        self.tamano = int(sampling * time)

    def generar(self):

        for i in range(0, self.tamano):

                datos = ((2**self.NumeroBit)/2)* math.sin((2*math.pi*self.Frecuencia*i)/self.SamplingRate)
                seno.wavearray.append(datos)
        return seno.wavearray

    def graficar(self):
                plt.plot(seno.wavearray, color="green", linewidth=1.0, linestyle="-")
                plt.show()
