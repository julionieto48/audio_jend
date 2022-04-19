__author__ = 'Julian&christian '
import scipy.io.wavfile as wavfile
import struct
import wave
import numpy as np

repeticion = 12
delaytap = 750
Frames = 44100*(delaytap/1000.0)

archivo1 = wave.open("t1_be_back.wav", 'rb')
archivo2 = wave.open("collateral_damage_help_me_or_not.wav", 'rb')

archivo = archivo1
archivo = np.append(archivo, np.zeros(repeticion*Frames))



delay = np.zeros([repeticion], dtype=float)

for i in range(0, repeticion):
    archivo = wave._byteswap3(archivo1)
    archivo2 = wave.open("collateral_damage_help_me_or_not.wav", 'rb')
    archivo2 = archivo
    archivo = np.append(archivo, np.zeros(repeticion*Frames))

for i in range(0, repeticion,Frames):
    delay[i] = np.zeros(Frames*i)
    delay[i] = np.append(delay[i],archivo1)
    delay[i].resize(archivo1.shape)
    if i == 0:
        archivo = archivo1*0.5 + (delay[i]*(1/float(i+2)))*0.5
    else:
        archivo = archivo + (delay[i]*(1/float(i+2)))*0.5


archivo1 = archivo.wf.readframes(archivo.CHUNK)
archivo.close(archivo1)
archivo2 = archivo.wf.readframes(archivo.CHUNK)
archivo.close(archivo2)



rango = []

delay_output.writeframes(rango)

delay_output = wave.open('t1_be_back.wav', 'w')
delay_output = wave.open('collateral_damage_help_me_or_not.wav', 'w')