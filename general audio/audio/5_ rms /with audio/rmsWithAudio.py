import numpy as np
import matplotlib.pyplot as plt
from openAudio import OpenAudio


archivo= 'audioOne.wav'
instance = OpenAudio(archivo)
datosAudio= instance.audioArray()
y = datosAudio



fs = instance.frecMuestreo() ;  Ts = float(round( 1 / fs , 20))
print  Ts
tiempo = float(len(y))
t = np.arange(0, tiempo,Ts)


squares = list() * len(y) ; sum = 0.0
# elevar al cuadado cada elemento
for i in range(0,len(y)) :
    ytu = y[i] ** 2
    squares.append(ytu)

    sum = sum + ytu
print np.sum(squares)
print sum
meanSquare = float(sum/ float(len(y)))
rootMeanSquare = float(meanSquare ** (1/2))


print rootMeanSquare
valorplot = [rootMeanSquare] * len(t)

plt.subplot(211)  # 2 filas 1 coumna posicion 1
plt.plot(t, y)
plt.plot(t, valorplot)
plt.xlabel(' t [seg]')
plt.title( ' seno ' )
plt.grid(True)


plt.subplot(212)  # 2 filas 1 coumna posicion 1
plt.plot(t, squares)
plt.xlabel(' t [seg]')
plt.title( ' squares ' )
plt.grid(True)

plt.show()
