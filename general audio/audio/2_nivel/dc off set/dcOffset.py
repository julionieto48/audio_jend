import matplotlib.pyplot as plt
import numpy as np



linGain = float(0.5) ; offSet = 2 ; fase = np.pi / 2
fs = float(44100 ) ; Ts = round( float(1 / fs) ,20 )


#time = np.linspace( 0.0, 1.0 , Ts)   # seno de 1 seg
time = np.arange( 0.0, 1.0 , Ts)
#time.transpose
# print range(len(time)) # 0 ..... 44099

frec = 1
# signalA = np.sin(2* np.pi*frec * time) ; out = [0] * len(signalA)



arregloSignal = []
for i in range(len(time)):
    signal =   np.sin(2 * np.pi * frec * time[i] )  # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignal.append(signal)

# senal de salida con off set y ganancia... ver en donde inicia
arregloSignalOutOffset = []
for i in range(len(time)):
    signalOut = (linGain * np.sin(2 * np.pi * frec * time[i] ) ) + offSet # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignalOutOffset.append(signalOut)

# senal original  con fase
arregloSignalOutPhase= []
for i in range(len(time)):
    signalOutph = np.sin(2 * np.pi * frec * time[i] + fase)   # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignalOutPhase.append(signalOutph)

# senal original  variando tiempo
arregloSignalOutTime = []
for i in range(len(time)):
    signalOutTi= (np.sin(2 * np.pi * frec * (2 * time[i]) ))  # forma oscilador a sin(2pi * 1000 * 0 + fase)
    arregloSignalOutTime.append(signalOutTi)

ax = plt.subplot(111)
ax.plot(arregloSignal, label = 'input ') ; ax.plot(arregloSignalOutOffset, label = 'offset ')
ax.plot(arregloSignalOutPhase, label = ' original con fase ')
ax.plot(arregloSignalOutTime, label = ' original con variacio tiempo')
plt.xlabel(' n ')
plt.title( ' cambios en  senal ' )
plt.grid(True)

chartBox = ax.get_position()
ax.set_position([chartBox.x0, chartBox.y0, chartBox.width*0.6, chartBox.height])
ax.legend(loc='upper center', bbox_to_anchor=(1.45, 0.8), shadow=True, ncol=1)
plt.show()