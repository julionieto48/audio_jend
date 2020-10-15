import numpy as np
import matplotlib.pyplot as plt
import sympy
from scipy.integrate import quad

iterations = 12
    

ptoInicial = 0
periodo_T = 6
x = np.linspace(0,periodo_T,50)
w = ( 2* np.pi )/ periodo_T

f = lambda x  : x #np.sin(x)
#fun = t



# calculo de coeficientes
a_o = (1/2*periodo_T) * sympy.integrate(f, 0, 1)

sum = 0
print range(1,iterations)
for k in range(1,iterations):
    exprecionA = f * np.cos(k * w * x)
    exprecionB = f * np.sin(k * w * x)
    a_k = (2 / periodo_T) * quad.integrate(exprecionA, 0, 1)
    b_k = (2 / periodo_T) * quad.integrate(exprecionB, 0, 1)
    sum = sum + (a_k * np.cos(k * w * x) + b_k * np.sin(k * w * x))
    print 'la suma: ', sum , 'en la iteracion ', k
X = a_o + sum
# graficar
plt.subplot(211)  # 2 filas 1 coumna posicion 1
plt.scatter(x , f)
plt.xlabel(' t ')
plt.ylabel(' value ')
plt.title( ' Grafica funcion' )
plt.grid(True)


plt.show()


# https://www.youtube.com/watch?v=25ovCm9jKfA
# https://stackoverflow.com/questions/4258106/how-to-calculate-a-fourier-series-in-numpy

