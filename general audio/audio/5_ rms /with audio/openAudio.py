import wave, struct
import pyaudio

class OpenAudio :

    def __init__(self,archivo):

        self.archivo = archivo

        audio = wave.open(archivo, 'r')

        # caracteristicas audio
        print  "__________________//______________________"
        print(" Numero de canales : ", audio.getnchannels())
        print(" Sample width : ", audio.getsampwidth())
        print ("Frec muestreo : ", audio.getframerate())
        print ("Numero de frames cuadros : ", audio.getnframes())
        print  "__________________//______________________"


    def audioArray(self):
        audio = wave.open(self.archivo, 'r')
        # audio Sin modificar
        cuadros = audio.getnframes()
        fs = audio.getframerate()
        channels = audio.getnchannels()

        audioData = []
        #print struct.calcsize('<l')  # pendiente a esta estrcutura esta optimizada par ale audio que se esta trabajando
        arregloAudio = []
        for i in range(cuadros):
            x = audio.readframes(1)  # Reads and returns at most n frames of audio, as a bytes object.
            # print x , type(x)
            dato = struct.unpack('<l', x)
            # print dato , type(dato)
            arregloAudio.append(dato[0])

        return arregloAudio

    def frecMuestreo(self):
        audio = wave.open(self.archivo, 'r')
        return float(audio.getframerate())

