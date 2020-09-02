

# los cambios de polaridad son utiles cuando hay fase en dos senales
import matplotlib.pyplot as plt
import numpy as np

gain = -1  # se usa una ganancia negativa para invertir los valores

linGain = float(0.5) ; offSet = 2 ; fase = np.pi / 2
fs = float(44100 ) ; Ts = round( float(1 / fs) ,20 )


#time = np.linspace( 0.0, 1.0 , Ts)   # seno de 1 seg
tiemposeg = 1.0 ; time = np.arange( 0.0, tiemposeg , Ts)
#time.transpose
# print range(len(time)) # 0 ..... 44099

frec = 1
# signalA = np.sin(2* np.pi*frec * time) ; out = [0] * len(signalA)



arregloSignal = []
for i in range(len(time)):
    signal =   np.sin(2 * np.pi * frec * time[i] )  # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignal.append(signal)

arregloSignalOut = []
for i in range(len(time)):
    signalOut = gain *  np.sin(2 * np.pi * frec * time[i] )  # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignalOut.append(signalOut)

print arregloSignal

print "senal salida: \n " ,   arregloSignalOut


ax = plt.subplot(111)
ax.plot(arregloSignal, label = 'input ')
ax.plot(arregloSignalOut, label = 'output')
plt.xlabel(' n ')
plt.title( ' inversion polaridad ' )
plt.grid(True)

chartBox = ax.get_position()
ax.set_position([chartBox.x0, chartBox.y0, chartBox.width*0.6, chartBox.height])
ax.legend(loc='upper center', bbox_to_anchor=(1.45, 0.8), shadow=True, ncol=1)
plt.show()