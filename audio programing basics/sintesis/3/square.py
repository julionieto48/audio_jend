import math
import matplotlib.pylab as plt


class square:

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
            x = math.sin(2*math.pi*self.Frecuencia*self.Tm*i)
            if x > 0:
                wavearray.append(32000)
            else:
                wavearray.append(-32000)
        return wavearray

    def graficar(self, arreglo):
        plt.plot(arreglo)
        plt.show()
