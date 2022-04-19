import math
import matplotlib.pylab as plt


class seno:

    def __init__(self, Frecuencia, duracion, FrecuenciaMuestreo, ProfundidadBits ):
        self.Frecuencia = Frecuencia
        self.duracion = duracion
        self.Muestreo = FrecuenciaMuestreo
        self.Bits = ProfundidadBits
        self.Tiempo = duracion * FrecuenciaMuestreo
        self.Tm = 1 / float(FrecuenciaMuestreo)


    def generar(self):
        wavearray = []
        for i in range(self.Tiempo):
            x = 31000*math.sin(2*math.pi*self.Frecuencia*self.Tm*i)
            wavearray.append(x)
        return wavearray

    def graficar(self, arreglo):
        plt.plot(arreglo)
        plt.show()
