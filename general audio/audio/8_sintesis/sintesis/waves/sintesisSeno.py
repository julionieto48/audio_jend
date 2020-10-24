import math
import matplotlib.pyplot as plt
import numpy as np

# generar y escuchar archivo de audio tipo

class Seno:

    def __init__(self, fs , frec , t , fase , bits , dB):
        self.fs = 1/ float(fs)         # periodo
        self.frec = frec        # frecuencia a genera
        self.t = int(t * fs)
        self.fase = fase ; self.bits = bits ; self.dB = dB

        amplitud =  self.valPico(bits, dB)
        datos = self.generarSine(amplitud)
        self.grafica(datos)


    def valPico(self, bits , db):
        vRef = (2 ** bits )/ 2
        vPico = vRef * (10**(db/10))**0.5
        return vPico

    def generarSine(self, A):
        arreglo = []
        for i in range(self.t):
            x = A * math.sin(2 * math.pi * self.frec * i * self.fs + self.fase);   # forma oscilador a sin(2pi * 1000 * 0 + fase)
            arreglo.append(x);

        return arreglo

    def grafica(self, arreglo):
        plt.plot(arreglo)
        plt.xlabel(' t ')
        plt.title( ' funcion seno digital' )
        plt.grid(True)
        plt.show()

class SenoUno():

    def __init__(self, fs, frec):
        self.fs = float(fs)
        self.frec = frec

        self.generarSine()

    def generarSine(self):
        x = np.arange(self.fs)    #puntos en eje x
        y = np.sin(2 * np.pi * self.frec * (x / self.fs)) # valores de amplitud para cada muestra sin(2pi )
        self.grafica(x , y)

    def grafica(self, x , y):
        plt.stem( x, y, 'r', ) ; plt.plot(x,y)
        plt.xlabel(' t ')
        plt.title(' funcion seno digital b')
        plt.grid(True)
        plt.show()

class SenoDos():

    def __init__(self, fs, frec , t , phi):
        self.fs = fs
        Ts = 1 / float(fs)               #periodo de muestreo

        self.t = t
        #time = range(0, t, 1 / float(44100)) # start stop paso
        time = np.linspace( 0, t, Ts)

        self.frec = frec ; self.phi = phi

        self.generarSine(time)    # generar seno



    def generarSine(self,time):
        #y = np.sin( 2 * math.pi * time )   # 2 * pi * self.time -> hay esa cantidad de ciclos por cada segundo generando correspondendia con el perioo
        y = np.sin(2 * math.pi * time * self.frec + self.phi) # la frecuencia determina el numero de ciclosen este determinado tiempo
        self.grafica(time , y)


    def grafica(self, t , y):
        plt.plot(t, y)
        plt.xlabel(' t ')
        plt.title(' funcion seno digital c')
        plt.grid(True)
        plt.show()










def main():
    bits = 16                   # profundidad en bits
    dB = 3                    # decibeles full scale
    frecMuestreo = 44100       # frecuencia muestreo
    tiempo = 5                # duracion de la senal
    frecuencia = 5         # frecuencia de la senal a construir
    fase = math.pi / 2              # en radianes de 0 a 2pi

    Seno( frecMuestreo, frecuencia, tiempo, fase , bits , dB)
    SenoUno(frecMuestreo,frecuencia)
    SenoDos(frecMuestreo,frecuencia, tiempo, fase)


if __name__ == '__main__':
    main()



