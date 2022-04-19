__author__ = 'julian'

import wave
import struct
import matplotlib.pylab as plt


class archivar():


    def __init__(self, frecuencia, sampling, bits, time, Nombre, wavearray):
            self.SamplingRate = sampling
            self.NumeroBit = bits
            self.Seconds = time
            self.Frecuencia = frecuencia
            self.tamano = sampling * time
            self.name = Nombre
            self.wavearray = wavearray


    def raw_generator(self):

        archivo = open(self.name + 'deep', "wb")
        archivo.write(struct.pack('h'*len(self.wavearray), *self.wavearray))
        archivo.close()



    def wav_generator(self):
        archivo = wave.open(self.name + '.wav', 'w')
        bits = self.NumeroBit/8

        tamano = self.Seconds*self.SamplingRate
        archivo.setparams((1, bits, self.SamplingRate, 0, 'NONE', 'not compressed'))

        for i in range(0, tamano):
            value = self.wavearray[i]
            packed_value = struct.pack('h', value)
            archivo.writeframes(packed_value)

        archivo.close()
