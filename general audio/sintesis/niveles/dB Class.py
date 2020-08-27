import matplotlib.pyplot as plt
import numpy as np


class DBSine :

    def __init__(self, dB):

        fs = float(44100)
        Ts = round(float(1 / fs), 20)

        seg = 1
        self.time = np.arange(0.0, seg , Ts)

        self.frec = 2 # frecuencia a reproducir pre definida

        self.dB = dB ; self.linGain = 10 **(dB / 10)

    def senales(self):
        arregloSignal = []

        for i in range(len(self.time)):
            signal = np.sin(2 * np.pi * self.frec * self.time[i])
            arregloSignal.append(signal)

        arregloSignalOut = []
        for i in range(len(self.time)):
            signalOut = self.linGain * np.sin(2 * np.pi * self.frec * self.time[i])
            arregloSignalOut.append(signalOut)

        return arregloSignal, arregloSignalOut




    def graficar(self, entrada , salida,i):
        plt.figure(i + 1)
        ax = plt.subplot(111)
        ax.plot(entrada, label='input ');
        ax.plot(salida, label='output ')

        plt.xlabel(' n ')
        plt.title(' cambios en  senal ')
        plt.grid(True)

        chartBox = ax.get_position()
        ax.set_position([chartBox.x0, chartBox.y0, chartBox.width * 0.6, chartBox.height])
        ax.legend(loc='upper center', bbox_to_anchor=(1.45, 0.8), shadow=True, ncol=1)
        plt.show()









def main():
    # valores dBs
    lineal = [1, 2, 3, 4, 5]; par = [2, 4, 6] ; impar = [1, 3, 5, 7]
    negativos = [-2, -1, 0, 1, 2] ; negativosPar = [-4, -2, 0, 2, 4]


    for i in range(len(lineal)) :
        instancia = DBSine( negativos[i])
        entri , out = instancia.senales()
        instancia.graficar(entri , out, i)

        print lineal[i]








if __name__ == '__main__':
    main()