
import numpy as np
import matplotlib.pyplot as plt

# crear una representacion sinusoidal

fs = float(44100)                           # cantidad de mustras tomadas
Ts = float(round( 1 / fs , 20))             # periodo = duracion en tiempo entre muestras
tiempo = float(2)                                  # duracion representada en tiempo

#t = np.linspace(0,tiempo,Ts)                # arreglo de tiempo  [0:Ts:tiempo]
# t = range(0,tiempo,)                       solo usa enteros
t = np.arange(0, tiempo,Ts)

# y = np.sin(t)                               # la duracion de un periodo es 6.8 ... 2 pi
# y = np.sin(2* np.pi * t)                      # hay 13 ciclos en 13 segundos con tiempo = 13
#.... anadr frecuencia para que se adependiente de esta

f = 3                                        # 3 Hz w = 2 pi f
y = np.sin(2 * np.pi * f * t)

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





#valor eficaz o rms: se refiere a un amagnitud presente en las ondas periodicas, correspondiente a un valor promedio relacionado a un
# valor DC .. intensidad de la senal , en esta media arimetica es necesario una magnitud promedio ya que al tener
# valores negativos y positivos produce un vlaor promedio cercanoo a 1


# https://es.wikipedia.org/wiki/Valor_eficaz
# https://stackoverflow.com/questions/6683690/making-a-list-of-evenly-spaced-numbers-in-a-certain-range-in-python

# def myArange(menor,mayor, paso):
#     #step = 0.5
#     #mayor = 0
#     #menor = 9
#     t = [x * paso for x in range(menor, mayor)]
#     # [lower + x*(upper-lower)/length for x in range(length)]
#     return t
# myArange(0,tiempo,Ts)
# print t