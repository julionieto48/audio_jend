import wave
import struct


class Suma():
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.Bits = 16
        self.fs = 44100

    def proceso_suma(self):
        c = []
        if len(self.a) < len(self.b):
            mayor = self.b
            menor = self.a
        else:
            mayor = self.a
            menor = self.b
        for i in range(len(mayor)):
            if i <= len(menor)-1:
                x = menor[i] + mayor[i]
                c.append(x)
            else:
                c.append(mayor[i])
        return c

    def guardarfast(self, datos, nombre):
        ArchivoAudio = wave.open(nombre + ".wav", "w")
        nchannels = 1
        sampwidth = self.Bits / 8
        framerate = int(self.fs)
        nframes = len(datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels, sampwidth, framerate, nframes, comptype, compname))
        values = []
        for i in range(len(datos)):
            packed_value = struct.pack("<h", datos[i])
            values.append(packed_value)

        values_str = ''.join(values)
        ArchivoAudio.writeframes(values_str)
        ArchivoAudio.close()



