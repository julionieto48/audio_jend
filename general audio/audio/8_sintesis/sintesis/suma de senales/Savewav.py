import wave
import struct


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
