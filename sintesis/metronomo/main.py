#Tarea repr. Metrono y grabar, CHRISTIAN R. MORA PARGA & JULIAN E. NIETO DIAZ
from Metronomo import Metro
from WavCreator import Archivar

def main():
    bpm = input('Ingrese el bpm de su metro: ')
    instance = Metro(bpm)

    time_metro = instance.tiempo_negra()
    dB_fs = -10
    Amp = instance.amp(dB_fs)

    tiempo_record = input('Ingrese la duracion en segundos de su grabacion: ')

    metronomoF = []
    for i in range(int(tiempo_record*bpm/60)):
        signal = instance.metronomo(time_metro, Amp)
        metronomoF.append(signal)
    metronomoDefinitivo = []
    for x in metronomoF:
        for xx in x:
            metronomoDefinitivo.append(xx)

    bitdepth = 16; fs = 44100; nom = str(bpm)+' BPM'
    ins2 = Archivar(bitdepth, fs,  metronomoDefinitivo, nom)
    opcion = input('Elija entre los 3 metodos de creacion wav: 1:normal, 2:fast, 3:estereo: ')
    jj = True
    while jj:
        if opcion == 1 or opcion == 2 or opcion == 3:
            jj = False
        else:
            opcion = input('Elija entre los 3 metodos de creacion wav: 1:normal, 2:fast, 3:estereo: ')

    if opcion == 1:
        metronomo_wav = ins2.guardarfast()
        channels = 1
    elif opcion == 2:
        metronomo_wav = ins2.guardar()
        channels = 1
    elif opcion == 3:
        metronomo_wav = ins2.guardarEstereo()
        channels = 2

    instance.reprod_y_grabar(metronomo_wav, channels)

if __name__ == "__main__":
    main()
