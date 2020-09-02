import matplotlib.pyplot as plt
import numpy as np


senal = [ 0, 0.5 , 1 , 0.5 , 0, -0.5 , -1 , -0.5 , 0 ]
linGain = 0.5
senalSalida = [] ; senalSalidaUno = [0] ; senalSalidaDos= [0] * len(senal)

# print len(senal) ; print range(len(senal))

#forma 1
for muestra in range(len(senal)):
    valor = linGain * senal[muestra]
    senalSalida.append(valor)

# forma 2
#senalSalidaUno = linGain * senal[:]
#senalSalidaUno = linGain * senalSalida


# forma 3
for muestra in range(len(senal)):
  senalSalidaDos[muestra] =  linGain  * senal[muestra]

plt.stem(senal) ; plt.stem(senalSalidaDos)
plt.xlabel(' n ')
plt.title( ' senal ' )
plt.grid(True)
plt.show()

# id(senal) ; id(senalSalidaUno) ; senal is senalSalidaUno   apuntes en memoria

fs = 44100 ; Ts = 1 / fs

time = np.linspace( 0, 1, Ts)   # seno d e1 seg
#time.transpose

frec = 2
signal = np.sin(2*np.pi*frec*time) ; out = [] * len(signal)

for muestra in :                                       # si es un segundo 44100 muestras cad amuestra correpsond ene el tiempo
  senalSalidaDos[muestra] =  linGain  * senal[muestra]



# hacer con matrices y probar las funciones de transposicion de matrices de matlab como built in functions