from ClasePrincipal import Suma
import wave
import struct
import math

def main():

    names_audios = []
    dBFS_deseados = []
    for j in range(0, 4):
        a = raw_input('Ingrese el nombre del con la extension .wav: ')
        names_audios.append(a)
        bb = input('Ingrese los dB_FS deseados para el audio individual: ')
        k = True
        while k:
            if bb < 0:
                k = False
                dBFS_deseados.append(bb)
            else:
                bb = input('Ingrese los dB_FS deseados para el audio individual: ')

    nomb = raw_input('Ingrese el nombre de su mezcla: ')
    dB_deseado_MIX = input('Ingrese los dB_FS deseados para la mezcla de los audios: ')
    k = True
    while k:
        if dB_deseado_MIX < -0.11:
            k = False
        else:
            dB_deseado_MIX = input('Ingrese los dB_FS deseados para la mezcla de los audios: ')


    #names_audios = ['audio1.wav', 'audio2.wav', 'audio3.wav', 'audio4.wav']
    AudiosArray = []
    for i in range(len(names_audios)):
        audio = wave.open(names_audios[i])
        cuadros = audio.getnframes()
        adata = []
        for i in range(cuadros):
            x = audio.readframes(1)
            dato = struct.unpack("<h", x)
            adata.append(dato[0])
        AudiosArray.append(adata)

    def dB_FS(A):
        dB_FullScale = 20*math.log10(2*A/float(2**16))
        return dB_FullScale
    def Vol(dB):
        V = ((2**16)/2)*(10**(float(dB)/10))**0.5
        return V

    V_deseados = []
    for i in range(len(AudiosArray)): V_deseados.append(Vol(dBFS_deseados[i]));

    #niveles actuales de las signals en log y en lineal:
    dB = []; Lineal = []
    for i in range(len(AudiosArray)):
        log = dB_FS(max(AudiosArray[i]))
        lin = max(AudiosArray[i])
        dB.append(log); Lineal.append(lin)

    #Obtencion de un factor "alpha" para hallar los niveles Lineales deseados para todas las signals:
    def factorAmplitud(V_des, Lin):
        alpha = []
        for i in range(len(V_des)):
            a = float(V_des[i]/Lin[i])
            alpha.append(a)
        return alpha

    alpha = factorAmplitud(V_deseados, Lineal)
    print 'factores = ', alpha

    #Producto de las signals por el factor "alpha" para nivelar las signals a peticion del usuario

    new_signals = []
    for i in range(len(AudiosArray)):
        for j in range(len(AudiosArray[i][:])):
            new_signals.append(AudiosArray[i][j]*alpha[i])
    g = AudiosArray
    sig_1, sig_2, sig_3, sig_4 = [], [], [], []
    for i in new_signals[0:len(g[0][:])]:
        sig_1.append(i)
    for i in new_signals[len(g[0][:]):len(g[1][:])+len(g[0][:])]:
        sig_2.append(i)
    for i in new_signals[len(g[0][:])+len(g[1][:]):len(g[0][:])+len(g[1][:])+len(g[2][:])]:
        sig_3.append(i)
    for i in new_signals[len(g[0][:])+len(g[1][:])+len(g[2][:]):len(new_signals)]:
        sig_4.append(i)

    print 'dB_FS_Maximos_Originales = ', dB
    print 'max_Lineal_Originales = ', Lineal
    print 'Nuevos dB_FS_MaximoS', [dB_FS(max(sig_1)), dB_FS(max(sig_2)), dB_FS(max(sig_3)), dB_FS(max(sig_4))]
    instanciador = Suma(sig_1, sig_2)
    suma1 = instanciador.proceso_suma()
    instanciador2 = Suma(sig_3, sig_4)
    suma2 = instanciador2.proceso_suma()
    print 'max(suma1) = ', max(suma1)
    print 'max(suma2) = ', max(suma2)
    print 'dBFS(suma1) = ', dB_FS(max(suma1))
    print 'dBFS(suma2) = ', dB_FS(max(suma2))

    instanciador3 = Suma(suma1, suma2)
    mix = instanciador3.proceso_suma()


    Lin_deseado_MIX = Vol(dB_deseado_MIX)
    lin_mix = max(mix)
    delta = float(Lin_deseado_MIX/lin_mix)
    Mix = []
    for i in range(len(mix)):
        Mix.append(mix[i]*delta)
    print 'dB_FS(max(Mix)) = ', dB_FS(max(Mix))
    print 'max(Mix) = ', max(Mix)

    instanciador.guardarfast(Mix, nomb)
if __name__ == '__main__':
    main()
