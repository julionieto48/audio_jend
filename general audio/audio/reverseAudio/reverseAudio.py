import wave , struct
from archivarAudio import Archivar
import numpy as np
import matplotlib as plt
from playsound import playsound



# abriendo y reversando audio
#datos del archivo
audio = wave.open('audioOne.wav','r')
print(" Numero de canales : " , audio.getnchannels() )
print(" Sample width : " , audio.getsampwidth() )
print ( "Frec muestreo : " , audio.getframerate() )
print ("Numero de frames  : " , audio.getnframes() )


# guardar en arreglo
cuadros = audio.getnframes()
frecmuestreo = audio.getframerate()

arregloAudio = []
for i in range( cuadros) :
    x = audio.readframes(1)     # Reads and returns at most n frames of audio, as a bytes object.
    dato = struct.unpack('l' , x)
    arregloAudio.append(dato[0])

#guardar archivo en wav
nombreArchivo = 'audioOriginal'
instancia = Archivar(16, frecmuestreo,arregloAudio,nombreArchivo)
instancia.guardarEstereo()

# reversar arreglo

# /////////////////////////////////////////////////////
# metodo 1
# reversadoUno = []
# for i in reversed( arregloAudio):
#     reversadoUno[i] = arregloAudio[i]

# metodo 2
reversadoDos = arregloAudio[::-1]

# #metodo 3  sin utilizar built in functions
# reversadoTres = []
# primerIndice = 0
# ultimoIndice = len(arregloAudio) - 1
# while  primerIndice < ultimoIndice:
#     aux = reversadoTres[primerIndice ]
#     reversadoTres[primerIndice ] = reversadoTres[ultimoIndice]
#     reversadoTres[ultimoIndice] = aux
#     primerIndice  += 1
#     ultimoIndice -= 1


# metodo 4
reversadoCuatro = arregloAudio.reverse()

#__________________________________

# graficar
#x = np.linspace(min(arregloAudio) - 1, max(arregloAudio) + 1)
#plt.plot(x, arregloAudio) ; plt.plot(x, reversadoDos)

# plt.subplot(211)
# plt.plot(arregloAudio) ; plt.xlabel('t') ; plt.ylabel('y') ; plt.grid(True)
# plt.subplot(212)
# plt.plot(reversadoDos) ; plt.xlabel('t') ; plt.ylabel('y') ; plt.grid(True)
# plt.show()


# ////////////////////////////////////////////////////////
#guardar archivo reversado  en wav
nombrearchivo = 'audioReversado'
instancia = Archivar(16,frecmuestreo,reversadoDos,nombrearchivo)
instancia.guardarEstereo()

# escuchar
#playsound('audioReversadostereo.wav')


# referencias
# https://www.tutorialspoint.com/read-and-write-wav-files-using-python-wave
# https://realpython.com/playing-and-recording-sound-python/
# https://stackoverflow.com/questions/3940128/how-can-i-reverse-a-list-in-python
# https://matplotlib.org/gallery/lines_bars_and_markers/cohere.html#sphx-glr-gallery-lines-bars-and-markers-cohere-py
# https://matplotlib.org/3.2.1/api/_as_gen/matplotlib.pyplot.subplot.html
# https://matplotlib.org/3.2.1/gallery/lines_bars_and_markers/psd_demo.html#sphx-glr-gallery-lines-bars-and-markers-psd-demo-py
# https://realpython.com/playing-and-recording-sound-python/

# def reverse(array):
#     n = array
#     first = 0
#     last = len(array) - 1
#     while first < last:
#       holder = n[first]
#       n[first] = n[last]
#       n[last] = holder
#       first += 1
#       last -= 1
#     # return n
#
# input -> [-1 ,1, 2, 3, 4, 5, 6]
# output -> [6, 1, 2, 3, 4, 5, -1]
#
# #/___________________________________________
#
# tamano = len( arregloAudio )
# indice = tamano - 1
# iteraciones = tamano / 2
# for i in xrange(0, iteraciones):
#     # hacer swap de variables
#     temp = arregloAudio[indice]
#     arregloAudio[i] = temp
#     indice -= 1   # decremento del indice myor

