import matplotlib.pyplot as plt
import numpy as np


inputSignal = [0, 0.25, 0.5, 0.25, 0, -0.25, -0.5, -0.25, 0]

x = np.linspace(0,len(inputSignal), len(inputSignal))

X = range(0 , len(inputSignal))

#print len(inputSignal) # 9
#print len(x) , len(X)


plt.subplot(211)  # 2 filas 1 coumna posicion 1
plt.stem(x, inputSignal)
plt.xlabel(' n ')
plt.title( ' peak normalization ' )
plt.grid(True)


# 0.5 es el max value , asi que 0.5 / 0.5 = 1 ... se debe encontra run facotr de escalamiento

# encontrar el valor maximo peak de la senal

for i in range(0,len(inputSignal)):
    inputSignal[i] = abs(inputSignal[i])

peak = max(inputSignal)

factor = round( float(1 / peak ) ,20 )
print type(peak)
print type(inputSignal)

# outputSignal = factor * inputSignal no se puede asi... asi que toca iterar
outputSignal = [] * len(inputSignal)

dB = 0   #  normalizar a este valor en dBs
linGain = 10 ^(dB / 20)   # convertir a ganancia lineal dB = 20 log(linGain)

print linGain

i = 0
while i <= len(inputSignal) -1  :
    out = linGain * (1/ peak) * inputSignal[i]
    outputSignal.append(out)
    i += 1

print  outputSignal

plt.subplot(212)
plt.stem(x, outputSignal)
plt.xlabel(' n ')
plt.title( ' peak normalization output ' )
plt.grid(True)

plt.show()