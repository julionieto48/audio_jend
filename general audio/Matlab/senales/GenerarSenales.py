import matplotlib.pyplot as plt
import numpy as np

def SenalAnaloga(amp):
    t = np.linspace(-0.02, 0.05, 1000) # dominio con 1000 puntos

    # funcion a graficar
    funcion = amp * np.sin(2*np.pi*50*t)

    plt.plot(t, funcion ); plt.xlim([-0.02, 0.05])

    plt.xlabel('tiempo [s]'); plt.ylabel('x(t)')

    plt.title(r' senal continua  $x(t)=12 \sin(2\pi 50 t)$');

    plt.show()


SenalAnaloga(12)

def SenalDiscreta(amp):
    n = np.arange(50) # arrange :retorna espacios iguales de a acuerdo a un intervalo 0- 50

    dt = 0.07 / 50

    x = np.sin(2 * np.pi * amp * n * dt)

    plt.xlabel('n'); plt.ylabel('x[n]'); plt.title(r'senal discreta  $x[n] = 12 \sin(2\pi 50 n \Delta t)$');

    plt.stem(n, x)
    np.disp(x)




SenalDiscreta(12)







# Referencia:
# https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.arange.html
# https://staff.fnwi.uva.nl/r.vandenboomgaard/SP20162017/SystemsSignals/plottingsignals.html
