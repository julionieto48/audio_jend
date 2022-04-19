
from seno import seno
from square import square
from Archivar import Archivar

def main():
    Frecuencia = input("ingrese la frecuencia del tono deseado: ")
    Duracion = input("ingrese el tiempo en segundos deseado: ")
    FrecuenciaMuestreo = input("ingrese la frecuencia de muestreo: ")
    ProfundidadBits = input("ingrese la profundidad en bits: ")

    entrada = input("seleccione la forma de onda 1-seno 2-cuadrada")



    if entrada == 1:
        audio = seno(Frecuencia,Duracion,FrecuenciaMuestreo,ProfundidadBits)

        arreglo = audio.generar()

        audio.graficar(arreglo)
    if entrada == 2:
        audio = square(Frecuencia,Duracion,FrecuenciaMuestreo,ProfundidadBits)
        arreglo = audio.generar()
        audio.graficar(arreglo)


    Nombre = raw_input("ingrese el nombre del archivo a guardar: ")
    Archivo = Archivar(ProfundidadBits,FrecuenciaMuestreo,arreglo,Nombre)
    Archivo.guardar()
    Archivo.guardarfast()
    Archivo.guardarEstereo()



if __name__  == "__main__":
    main()
