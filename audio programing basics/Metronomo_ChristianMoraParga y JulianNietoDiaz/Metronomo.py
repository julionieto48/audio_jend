#Tarea repr. Metrono y grabar, Christian R. Mora Parga & Julian E. Nieto Diaz

import pyaudio
import wave


class Metro:

    def __init__(self, bpm):
        self.fs = 44100
        self.sampRate = 1/self.fs
        self.bitdepth = 16
        self.bpm = bpm

    def amp(self, dB):
        ampl = ((2**self.bitdepth)/2)*(10**(float(dB)/10))**0.5
        return ampl

    def tiempo_negra(self):
        corcheapuntillo = int((self.fs*60/self.bpm)*0.5)+int((self.fs*60/self.bpm)*0.25)
        semicorchea = int((self.fs*60/self.bpm)*0.25)
        return corcheapuntillo, semicorchea

    def metronomo(self, figure, amps):
        f = 440
        T_m = self.fs/f; c = 0
        x_metro = []
        for n in range(figure[1]):
            if c <= (T_m/4.0):
                m = 4.0/T_m
                x = m*c
                x_metro.append(amps*x)
                c += 1
            if (c > (T_m/4.0)) & (c <= (3*T_m/4.0)):
                m = -4.0/T_m
                b = 2
                x = m*c + b
                x_metro.append(amps*x)
                c += 1
            if (c > (3*T_m/4.0)) & (c < T_m):
                m = 4.0/T_m; b = -4
                x = m*c + b
                x_metro.append(amps*x)
                c += 1
            if c == int(T_m):
                c = 0
        x_silencio = []
        for i in range(figure[0]):
            x = 0
            x_silencio.append(x)
        #une ambos arreglos:
        for x in x_silencio:
            x_metro.append(x)
        return x_metro

    def muest(self, arreglo):
        t = np.linspace(0, len(arreglo)/self.fs, len(arreglo))
        plt.plot(t, arreglo)
        plt.show()

    def reprod_y_grabar(self, nom_metro, CHANNELS):
        CHUNK = 1024
        wf1 = wave.open(nom_metro, 'rb')
        p1 = pyaudio.PyAudio()
        stream_play = p1.open(format=p1.get_format_from_width(wf1.getsampwidth()),
                        channels=wf1.getnchannels(),
                        rate=wf1.getframerate(),
                        output=True)
        data_play = wf1.readframes(CHUNK)

        FORMAT = pyaudio.paInt16; RATE = 44100
        WAVE_OUTPUT_FILENAME = raw_input('Ingrese el nombre de su grabacion: ') + '.wav'
        p = pyaudio.PyAudio()
        stream = p.open(format=FORMAT,
                        channels=CHANNELS,
                        rate=RATE,
                        input=True,
                        frames_per_buffer=CHUNK)
        print("* recording")
        frames = []
        while data_play != '':
            data = stream.read(CHUNK)
            frames.append(data)
            stream_play.write(data_play)
            data_play = wf1.readframes(CHUNK)

        stream_play.stop_stream(); stream_play.close(); p1.terminate()
        print("* done recording")
        stream.stop_stream(); stream.close()
        p.terminate()
        wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(p.get_sample_size(FORMAT))
        wf.setframerate(RATE)
        wf.writeframes(b''.join(frames))
        wf.close()




