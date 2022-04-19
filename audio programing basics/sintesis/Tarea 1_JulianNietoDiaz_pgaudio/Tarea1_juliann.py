import math
import matplotlib.pyplot as plt

class Senoconamplitud:

    def __init__(self,muestreo,frecuencia,tiempo ):
        self.muestreo= 1/float(muestreo);
        self.frecuencia= frecuencia; self.tiempo=int(tiempo*muestreo);

    def generar_funcion(self,A):

        arreglo=[]
        for i in range(self.tiempo):
            x=A*math.sin(2*math.pi*self.frecuencia* i *self.muestreo);
            arreglo.append(x);
        return arreglo

    def valorpico(self,bits,db):

        valorreferencia= ((2**bits)/2);
        valorpico= valorreferencia* (10**(db/10))**0.5
        print ('El valor de A es:',valorpico);
        return valorpico
    def grafica(self,seno):
        plt.plot(seno)
        plt.show()

def main():
    bits= input('Ingresar la profundidaf en bits');
    db= input('Ingresar valor en dB FS');

    muestreo = input ('Ingresar Muestreo');
    tono= input('Digitar frecuencia/tono');
    tiempo= input('tiempo a generar');

    corredor = Senoconamplitud(muestreo,tono,tiempo)
    A = corredor.valorpico(bits,db)


    datos= corredor.generar_funcion(A)
    corredor.grafica(datos)
main()