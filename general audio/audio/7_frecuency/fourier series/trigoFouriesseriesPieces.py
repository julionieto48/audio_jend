import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import simps
from sympy import *

iterations = 90

a = -5.0 ; b = 5.0      #limites
# c = 0

ptoInicial = a
periodo_T = float(b - (a) )
# while b < a:
#     c = b
#     b = a
#     a = c
#
# longitudComparacion = b - (a)

xA = np.linspace(a, b)
yA = np.piecewise(xA, [xA<0, xA>=0], [lambda xA: -xA, lambda xA: xA])


# otra forma de hacr funcion a trozos
x1 = np.linspace(-10,0)
x2 = np.linspace(0,10)
y1 = -x1
y2 = x2
x = np.concatenate((x1,x2))
y = np.concatenate((y1,y2))

#print xA , len(xA)
#print yA , len(yA)

#_________________________________________________________________________
#integral

# ratio = int(len(yA) / longitudComparacion)
# downsampled_yA = []
#
# for i in yA :
#     if i % ratio == 0 :
#         print i
#         downsampled_yA.append(i)
#
# print downsampled_yA , len(downsampled_yA)

# prueba integrales
#inte =  simps(yA,xA)   # integrar por rejillas
#print inte
#integrate(yA, xA)
#______________________________________________________
x = np.linspace(0,periodo_T,50)
w = ( 2* np.pi )/ periodo_T

# calculo de coeficientes
a_o = float((1/2*periodo_T) * simps(yA, xA) )

sum = 0
#print range(1,iterations)  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

for k in range(1,iterations):
    exprecionA = yA  * np.cos(k * w * x)
    exprecionB = yA  * np.sin(k * w * x)
    a_k = (2 / periodo_T) * simps(exprecionA, xA)
    b_k = (2 / periodo_T) * simps(exprecionB, xA)
    sum = sum + (a_k * np.cos(k * w * x) + b_k * np.sin(k * w * x))
    # print 'la suma: ', sum , 'en la iteracion ', k
xFourier = a_o + sum
#print xFourier, len(xFourier)

#______________________________________________________
# graficar
plt.subplot(211)  # 2 filas 1 coumna posicion 1
plt.plot(xA , yA)
plt.xlabel(' t ')
plt.ylabel(' value ')
plt.title( ' Grafica de la funcion' )
plt.grid(True)

plt.subplot(212)  # 2 filas 1 coumna posicion 1
plt.plot(x , xFourier)
plt.xlabel(' t ')
plt.ylabel(' value ')
plt.title( ' Grafica de serie Fourier' )
plt.grid(True)


plt.show()










# https://numython.github.io/posts/2016/02/funciones-definidas-trozos-piecewise/
# https://docs.scipy.org/doc/scipy/reference/tutorial/integrate.html
# https://www.tutorialspoint.com/sympy/sympy_integration.htm
# https://stackoverflow.com/questions/16463159/argument-must-be-a-callable-function-when-using-scipy-integrate-quad
# https://www.mathworks.com/help/signal/ref/downsample.html
# https://stackoverflow.com/questions/41518351/what-is-the-difference-between-resize-and-reshape-when-using-arrays-in-numpy
# https://stackoverflow.com/questions/21132758/scipy-interpolation-valueerror-x-and-y-arrays-must-be-equal-in-length-along-int
# https://www.geeksforgeeks.org/python-scipy-integrate-simps-method/