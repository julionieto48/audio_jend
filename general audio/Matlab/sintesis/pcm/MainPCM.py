from PCM import dB

def main():

    dBs = input(' Ingrese dB Full Scale: ')
    bitDepth = input(' Ingrese Bit Depth: ')
    frecMuestro = 44100
    frecSignal = input(' Ingrese Frecuencia de la senal periodica ')
    duracion = input(' Ingrese el tiempo de su senal ')

    senal = dB( dBs, bitDepth, frecMuestro, frecSignal, duracion)
    Amplitud = senal.amplitud() ;  print ('Amplitud = ', Amplitud)
    senal.graficar(senal.procesoSenal(Amplitud))


if __name__ == '__main__':
    main()