import math
import matplotlib.pylab as graf
class calc():

    def __init__(self, dB, BitDepth, FrecMuestro, Tone, Duration):
        self.dB_fs = dB
        self.bitdepth = BitDepth
        self.Samples = 1/float(FrecMuestro)
        self.FrecOnda = Tone
        self.tiempo = int(Duration*FrecMuestro)

    def Amp(self):
        valor_pico = ((2**self.bitdepth)/2)*(10**(self.dB_fs/10))**(0.5)
        return valor_pico

    def ProcesoSenal(self, Amplitud):
        Rango = []
        for n in range(self.tiempo):
            x = Amplitud*math.sin(2*math.pi*self.FrecOnda*(n*self.Samples))
            Rango.append(x)
        return Rango

    def graficador(self, R):
        graf.plot(R)
        graf.show()

