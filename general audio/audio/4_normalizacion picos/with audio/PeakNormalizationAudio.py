import wave, struct
import pyaudio
import matplotlib.pyplot as plt

from guardarWav import Archivar


archivo = 'audioOne.wav'
audio = wave.open(archivo, 'r')

# caracteristicas audio
print  "__________________//______________________"
print(" Numero de canales : " , audio.getnchannels() )
print(" Sample width : " , audio.getsampwidth() )
print ( "Frec muestreo : " , audio.getframerate() )
print ("Numero de frames cuadros : " , audio.getnframes() )
print  "__________________//______________________"


# audio Sin modificar
cuadros = audio.getnframes()
fs = audio.getframerate()
channels = audio.getnchannels()
audioData = []

#print struct.calcsize('bxbx')
print struct.calcsize('<l')
arregloAudio = []
for i in range( cuadros) :
    x = audio.readframes(1)     # Reads and returns at most n frames of audio, as a bytes object.
    #print x , type(x)
    dato = struct.unpack('<l' , x)
    #print dato , type(dato)
    arregloAudio.append(dato[0])

# print  arregloAudio, type(arregloAudio)


inputSignal = []
inputSignal= arregloAudio



#normalizacion



# encontrar el valor maximo peak de la senal

for i in range(0,len(inputSignal)):
    inputSignal[i] = abs(inputSignal[i])

peak = max(inputSignal)

factor = round( float(1 / peak ) ,20 )

#senal salida
outputSignal = [] * len(inputSignal)

dB = 0   #  normalizar a este valor en dBs
linGain = 10 ^(dB / 20)   # convertir a ganancia lineal dB = 20 log(linGain)

print linGain

i = 0
while i <= len(inputSignal) -1  :
    out = linGain * (1/ peak) * inputSignal[i]
    outputSignal.append(out)
    i += 1



#ploting
X = range(0 , len(inputSignal))
plt.subplot(211)  # 2 filas 1 coumna posicion 1
plt.plot(X, inputSignal)
plt.xlabel(' n ')
plt.title( ' original signal ' )
plt.grid(True)

plt.subplot(212)
plt.plot(X, outputSignal)
plt.xlabel(' n ')
plt.title( ' peak normalization output ' )
plt.grid(True)

plt.show()



#guardar archivo modificado en wav
nombreArchivoGuardar = 'audioNormalizado'
instancia = Archivar(16, fs,outputSignal,nombreArchivoGuardar)
instancia.guardarEstereo()





# reproduccion de audio en la compilacion

def playAudio(archivo):
    CHUNK = 1024
    # create an audio object
    wf = wave.open(archivo, 'rb')
    p = pyaudio.PyAudio()

    # open stream based on the wave object which has been input.
    stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                    channels=wf.getnchannels(),
                    rate=wf.getframerate(),
                    output=True)

    # read data (based on the chunk size)
    data = wf.readframes(CHUNK)

    # play stream (looping from beginning of file to the end)
    while len(data) > 0:
        # writing to the stream is what *actually* plays the sound.
        stream.write(data)
        data = wf.readframes(CHUNK)

    return data

    # cleanup stuff
    stream.close()
    p.terminate()



#guardar audio modificado


# reproduccion de archivos
#playAudio(archivo)
playAudio('audioNormalizadostereo.wav')