from seno import seno
import matplotlib.pylab as plt
from writefile import archivar
import struct
import wave




def main():

    Tono = int(input("Frecuencia del tono a generar: ")  )
    Tiempo = int(input("Duracion del tono a generar(segundos): ") )
    FrecuenciaSampleo = int(input("Frecuencia de Sampleo: ") )
    BitDepth = int(input("Profundidad en bits: ") )

    onda = seno(Tono, FrecuenciaSampleo, BitDepth, Tiempo)
    datos = onda.generar()

    Nombre = input("Ingrese el nombre del archivo a generar: ")

    archivo = archivar(Tono, FrecuenciaSampleo, BitDepth, Tiempo, Nombre, datos)


    # archivo.raw_generator()
    archivo.wav_generator()

    onda.graficar()

if __name__ == "__main__":
    main()
  