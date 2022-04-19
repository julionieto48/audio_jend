import wave
import struct
import numpy as np
import mainParti


class Archivar:
    def __init__(self,ProfundidadBits,FMuestreo,Datos,Nombre):
        self.Bits = ProfundidadBits
        self.Framerate = FMuestreo
        self.Datos = Datos
        self.Nombre = Nombre

    def guardar(self):
        ArchivoAudio = wave.open(self.Nombre + ".wav", "w")
        nchannels = 1
        sampwidth = self.Bits / 8
        framerate = int(self.Framerate)
        nframes = len(self.Datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels,sampwidth,framerate,nframes,comptype,compname))

        for i in range(len(self.Datos)):
            ArchivoAudio.writeframes(struct.pack("<h", self.Datos[i]))

        ArchivoAudio.close()

    def guardarfast(self):
        ArchivoAudio = wave.open(self.Nombre + "fast.wav", "w")
        nchannels = 1
        sampwidth = self.Bits / 8
        framerate = int(self.Framerate)
        nframes = len(self.Datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels,sampwidth,framerate,nframes,comptype,compname))
        values = []
        for i in range(len(self.Datos)):
            packed_value = struct.pack("<h", self.Datos[i])
            values.append(packed_value)

        values_str = ''.join(values)
        ArchivoAudio.writeframes(values_str)

        ArchivoAudio.close()

    def guardarEstereo(self):
        ArchivoAudio = wave.open(self.Nombre + "stereo.wav", "w")
        nchannels = 2
        sampwidth = self.Bits / 8
        framerate = int(self.Framerate)
        nframes = len(self.Datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels,sampwidth,framerate,nframes,comptype,compname))
        values = []
        for i in range(len(self.Datos)):
            packed_value_L = struct.pack("<h", self.Datos[i])
            values.append(packed_value_L)
            packed_value_R = struct.pack("<h", self.Datos[i])
            values.append(packed_value_R)

        values_str = ''.join(values)
        ArchivoAudio.writeframes(values_str)

        ArchivoAudio.close()

    def guardarIzda(self):
        ArchivoAudio = wave.open(self.Nombre + "stereo.wav", "w")
        nchannels = 2
        sampwidth = self.Bits / 8
        framerate = int(self.Framerate)
        nframes = len(self.Datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels,sampwidth,framerate,nframes,comptype,compname))
        values = []
        for i in range(len(self.Datos)):
            packed_value_L = struct.pack("<h", self.Datos[i])
            values.append(packed_value_L)
            packed_value_R = struct.pack("<h", np.zeros(self.Datos[i]))
            values.append(packed_value_R)


        values_str = ''.join(values)
        ArchivoAudio.writeframes(values_str)

        ArchivoAudio.close()
    def guardarDcha(self):
        ArchivoAudio = wave.open(self.Nombre + "stereo.wav", "w")
        nchannels = 2
        sampwidth = self.Bits / 8
        framerate = int(self.Framerate)
        nframes = len(self.Datos)
        comptype = "NONE"
        compname = "not compressed"

        ArchivoAudio.setparams((nchannels,sampwidth,framerate,nframes,comptype,compname))
        values = []
        for i in range(len(self.Datos)):
            packed_value_R = struct.pack("<h", self.Datos[i])
            values.append(packed_value_R)
            packed_value_L = struct.pack("<h", np.zeros(self.Datos[i]))
            values.append(packed_value_L)


        values_str = ''.join(values)
        ArchivoAudio.writeframes(values_str)

        ArchivoAudio.close()

def main():
    bitdepth = 16
    fs = 44100
    nombre = raw_input("Ingrese el nombre del archivo a guardar: ")

    senalfinal = mainParti.main()
    archi = Archivar(bitdepth, fs, senalfinal, nombre)
    canal =raw_input("En que canal lo desea; L o R")
    if canal =='L':
        archi.guardarIzda()
    elif canal== 'R':
        archi.guardarDcha()
main()

