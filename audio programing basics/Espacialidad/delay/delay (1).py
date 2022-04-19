


import scipy.io.wavfile as wavfile
import struct
import wave
import numpy as np


NUMEROREPETICIONES = 12 #numero de repeticiones
TIEMPODELAY = 750 #tiempo en milisegundos
NumeroFramesDelay = 44100*(TIEMPODELAY/1000.0) #Numero de frames


rate, data = wavfile.read("t1_be_back.wav")  #Abrir Archivo usando la scipy.io.wavfile
data1 = data
data = np.append(data, np.zeros(NUMEROREPETICIONES*NumeroFramesDelay))


delay = np.zeros([NUMEROREPETICIONES], dtype=object)

for i in range(0, NUMEROREPETICIONES):
    delay[i] = np.zeros(NumeroFramesDelay*i)
    delay[i] = np.append(delay[i],data1)
    delay[i].resize(data.shape)

    if i == 0:
        data = data*0.5 + (delay[i]*(1/float(i+2)))*0.5 #sumatoria ajustada para evitar saturacion
    else:
        data = data + (delay[i]*(1/float(i+2)))*0.5 #sumatoria ajustada para evitar saturacion


delay_output = wave.open('delay.wav', 'w')
delay_output.setparams((1, 2, 44100, 0, 'NONE', 'not compressed'))

values = []


for i in range(0, len(data)):
        packed_value = struct.pack('<h', data[i])
        values.append(packed_value)


value_str = ''.join(values)
delay_output.writeframes(value_str)

delay_output.close()
