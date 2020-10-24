import numpy as np
import matplotlib.pyplot as plt

# array indexing

# la senal wet va a ser una verison de la senal d eentrada x

fs = float(44100)                           # cantidad de mustras tomadas
Ts = float(round( 1 / fs , 20))             # periodo = duracion en tiempo entre muestras
tiempo = float(2)                           # duracion representada en tiempo

t = np.arange(0, tiempo,Ts)

f = 3                                        # 3 Hz w = 2 pi f
x = np.sin(2 * np.pi * f * t)

segundos = 0.25
muestraTiempoDelay = int(segundos * fs)

out = [] * len(x)
wetGain = 0.50
for n in range(len(x)):
    if n - muestraTiempoDelay < 1:  # como voy a restar el num de muestras n - muestraTiempoDelay debe evitar indices negativos
        valor = x[n]                # sena permanece igual
    else:
        valor = x[n] + wetGain * x[n - muestraTiempoDelay]
    out.append(valor)

# 3. metodo usando el delay buffer
# se cre una memoria donde se guardan la smuestras anteriores,
x_0 = np.sin(2 * np.pi * f * t)

buf = [0] * len(x_0)

outBuff = [] * len(x_0)
# print buf , len(buf) , muestraTiempoDelay - 1

print buf[len(buf) - 1]

for n in  range(len(x_0)):
     valor = x_0[n] + (wetGain * buf[len(buf) - 1]  ) # insertar en la salida el audio junto con el buffer en su ultima posicion
     outBuff.append(valor)

     buf.pop(-1)
     buf = x_0[n] + buf[0 : len(buf) - 1  ]  #se concatena la senal de entrada en el buffer con una version desplazada  (len(buf) - 1) - 1
                                                 # que toma el primer elemento del buffer y no tiene en cuenta su ultimo elemento
     # en cada iteracion el bufer que en un principio era solo seros va empezar a retrasarse por muestras presentes en la entrada



