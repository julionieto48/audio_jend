import numpy as np
import matplotlib.pyplot as plt

# efecto basdo en delays de tiempo, el echo distingue repeticiones o ecos de una senal
# efectos de tiempo son considerados sistemas de memoria, ya qu eal iterar en este sistema la silda depende de una
# entrada procesad aen el pasado que fue guardada en memoria

# metodo 1, procesamiento paralelo una senal e sno procesada o dry y la otra es desplazada en el tiempo, se puede cambiar la amplitud d eambas
# se hace sumatoria muestra a muestra, sin embargo si hay una senal retrasada no coincidiran longitudes de este audio original

#  parametros:
# longitud del delay en tiempo o tempo ( relacion muestras con tiempo y con muestras)
# amplitud de la senal retrasada (dry o wet)
# feedback cantidad de repeticiones


# feed foward echo

# crear una representacion sinusoidal

fs = float(44100)                           # cantidad de mustras tomadas
Ts = float(round( 1 / fs , 20))             # periodo = duracion en tiempo entre muestras
tiempo = float(2)                           # duracion representada en tiempo

t = np.arange(0, tiempo,Ts)

f = 3                                        # 3 Hz w = 2 pi f
y = np.sin(2 * np.pi * f * t)

#calcular tiempo de delay
segundos = 0.25                              # [seg] segundos de retraso
muestraTiempoDelay = int(segundos * fs)           # en 1 seg hay 44100 segundos * (muestras/segundo) = muestras es el valor equivalente al tiempo en muestras

print muestraTiempoDelay

# np.concatenate([a, a])
# test_list3 = test_list3 + test_list4
# for i in test_list2 :
#     test_list1.append(i)  # este queda primero y s ele anade la lista 2

dryPath =  np.concatenate([y,np.zeros(muestraTiempoDelay)]) #concatenarceros al final
wetPath =  np.concatenate([np.zeros(muestraTiempoDelay),y]) #concatenarceros al inicio


#
#concatenarceros al inicio con otro metodo

#espacioPaddinEnMuestras = np.zeros(muestraTiempoDelay) ; wetPath = y

#np.append(wetPath,espacioPaddinEnMuestras)
# for i in espacioPaddinEnMuestras :
#     # wetPath.append(i)
#     np.append(wetPath,i)for i in espacioPaddinEnMuestras :
# #     # wetPath.append(i)
# #     np.append(wetPath,i)
#___________________________________________________________________________



#out = np.zeros(np.size(dryPath)) ; # hace ruqe la salida sea un arreglo de ceros del tamano de la muestra original concaenada
out = [] * len(dryPath)

print len(dryPath), len(wetPath)

wetGain = 0.50
for n in range(len(dryPath)):  # n muestra
    valor = dryPath[n] + wetGain * wetPath[n]
    out.append(valor)



# https://stackoverflow.com/questions/9236926/concatenating-two-one-dimensional-numpy-arrays
# https://www.geeksforgeeks.org/python-ways-to-concatenate-two-lists/