import matplotlib.pyplot as plt
import numpy as np


dB = - 6  ; linGain = 10 **(dB / 20)

fs = float( 44100 ) ; Ts = round( float(1 / fs) , 20 )

time = np.arange( 0.0, 1.0 , Ts)

frec = 1


# senal de entrada
arregloSignal = []
for i in range(len(time)):
    signal =   np.sin(2 * np.pi * frec * time[i] )  # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignal.append(signal)

# senal salida
arregloSignalOut= []
for i in range(len(time)):
    signalOut = linGain * np.sin(2 * np.pi * frec * time[i] )
    arregloSignalOut.append(signalOut)

ax = plt.subplot(111)
ax.plot(arregloSignal, label = 'input ') ; ax.plot(arregloSignalOut, label = 'output ')

plt.xlabel(' n ')
plt.title( ' cambios en  senal ' )
plt.grid(True)

chartBox = ax.get_position()
ax.set_position([chartBox.x0, chartBox.y0, chartBox.width*0.6, chartBox.height])
ax.legend(loc='upper center', bbox_to_anchor=(1.45, 0.8), shadow=True, ncol=1)
plt.show()
