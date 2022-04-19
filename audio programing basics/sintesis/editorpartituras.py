import math
import matplotlib.pyplot as plt
from Archivar import Archivar

class Partitura:

    def __init__(self, nota, octava, figura, dbfs):

         self.nota = nota; self.octava = octava; self.figura = figura; self.dbfs= dbfs

    def valornota(self,bpm):


        if self.figura == 1:
            redonda = float(4.0 * bpm/60.0)
            return redonda

        elif self.figura == 2:
            blanca = float(2.0* bpm/60.0)
            return blanca
        elif self.figura == 3:
            negra = float(bpm/60.0)

            return negra

        elif self.figura == 4:
            corchea = float((bpm/60.0)*0.5)
            return corchea
        elif self.figura == 5:
            semicorchea = float((bpm/60.0)*0.25)
            return semicorchea
        elif self.figura == 6:
            fusa = float((bpm/60.0)*0.25*0.5)
            return fusa

    def notamusical(self):
        if self.nota == 'C':
            frecuencia = 261

        elif self.nota == 'C#':
            frecuencia = 277

        elif self.nota == 'D':
            frecuencia = 293

        elif self.nota == 'D#':
            frecuencia = 311

        elif self.nota == 'E':
            frecuencia = 329

        elif self.nota == 'F':
            frecuencia = 349

        elif self.nota == 'F#':
            frecuencia = 369

        elif self.nota == 'G':
            frecuencia = 392

        elif self.nota == 'G#':
            frecuencia = 415

        elif self.nota == 'A':
            frecuencia = 440

        elif self.nota == 'A#':
            frecuencia = 466

        elif self.nota == 'B':
            frecuencia = 493

        if self.octava == 4:
            frecuencia = frecuencia
            return frecuencia
        elif self.octava == 3:
            frecuencia = frecuencia/2
            return frecuencia
        elif self.octava == 2:
            frecuencia = frecuencia/4
            return frecuencia
        elif self.octava == 1:
            frecuencia = frecuencia/8
            return frecuencia
        elif self.octava == 5:
            frecuencia = frecuencia*2
            return frecuencia
        elif self.octava == 6:
            frecuencia = frecuencia*4
            return frecuencia
        elif self.octava == 7:
            frecuencia = frecuencia*8
            return frecuencia

    def valorpico(self,bits):
        valorreferencia= ((2**bits)/2);
        valorspl= valorreferencia* (10**(self.dbfs/10))**0.5
        return valorspl

class Tipodeonda:

    def __init__(self,muestreo,frecuencia,tiempo):
        self.muestreo = 1/float(muestreo); self.frecuencia = frecuencia; self.tiempo = int(tiempo* muestreo); #tiempo=tiempo total

    def generarSeno(self,valorspl,tiempos):
        paso = int(self.tiempo/tiempos)
        arregloinstantaneo = []
        for i in range(1,self.tiempo,paso):
            x=valorspl*math.sin(2*math.pi*self.frecuencia* i *self.muestreo)
            arregloinstantaneo.append(x)
        return arregloinstantaneo






profundidadbits = 16; muestreo = 44100;
tipo_onda = input('Que tipo de onda desea generar 1.Sine 2.Square 3.Triangle')
bpm = int(input('Ingrese Bpm de la cancion:'))
i = True
while i:
    a = raw_input('desea continuar: "si", "no": ')
    if a == 'si':
        nota = raw_input('Ingrese nota: C,C#,D,D#,E,F,F#,G,G#,A,A#,B: ')
        octava = input('Ingrese octava, 1,2,3,4... etc ')
        figura = input('Ingrese tipo de nota, Redonda:1, blanca:2, negra:3, corchea:4, semicorchea:5, Fusa:6: ')
        dinamica = input('Ingrese en dBfs la amplitud ')

        instanciador = Partitura(nota,octava,figura,dinamica)

        #obtener valores para generar onda
        frecuencia = instanciador.notamusical()
        tiempos = instanciador.valornota(bpm) ; #print 'tiempo especifico',tiempos;
        valorspl = instanciador.valorpico(profundidadbits)
        tiempotot = int(muestreo*tiempos);relacion = int(tiempotot/tiempos)

        # generar un arreglo en un intervalo especifico de tiempo
        instanciador = Tipodeonda(muestreo,frecuencia,tiempos)
        if tipo_onda == 1:
            arregloinstantaneo = instanciador.generarSeno(valorspl,tiempos)
            print 'arreglo en instante:', arregloinstantaneo
            senalfinal = [] ;j = 0
            for j in range(1,tiempotot,relacion):
                senalfinal.append(arregloinstantaneo)
                tiempotot= tiempotot+tiempos;
                print senalfinal



    elif a == 'no':
        break


#print 'arreglo de audio final', senal
#instancia = Archivar(profundidadbits,muestreo,senal,'partituraJulianNieto')
#instancia.guardar()
#instancia.guardarfast()
#instancia.guardarEstereo()
#plt.plot(senalfinal)
#plt.show()