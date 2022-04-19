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

    def dB(self,bits,valorpico):

        valorreferencia= ((2**bits)/2.0);#debe ser flotante
        valordB = 10*math.log10((valorpico/valorreferencia)**2);
        print ('El valor en dB de la primer frecuencia  es:',valordB);
        return valordB
    def grafica(self,seno):
        plt.plot(seno)
        plt.show()

    def dBsegundafrecuencia(self,dB):
        dBf2= dB - 3;
        print ('El valor en dB de la segunda frecuencia es:',dBf2);
        return dBf2
    def dBtercerafrecuencia(self,dB):
        dBf3= dB - 6;
        print ('El valor en dB de la segunda frecuencia es:',dBf3);
        return dBf3






bits= 16;muestreo =44100;
valorpico= input('Ingresar valorPico');
tiempo= input('tiempo a generar');
tono1= input('Digitar primer frecuencia/tono');
tono2= input('Digitar segunda frecuencia/tono');
tono3= input('Digitar de el segundo frecuencia/tono');
#generar el primer tono
corredor1 = Senoconamplitud(muestreo,tono1,tiempo) #define como objeto
A = corredor1.dB(bits,valorpico); #se guarda el valor en dB en A
datos1= corredor1.generar_funcion(A)
#generar el segundo tono
corredor2 = Senoconamplitud(muestreo,tono2,tiempo)
B= corredor2.dBsegundafrecuencia(A); #en B se guarda el valor dB -3
datos2= corredor1.generar_funcion(B)
#generar el tercer tono
corredor3= Senoconamplitud(muestreo,tono3,tiempo)
C= corredor3.dBtercerafrecuencia(A);#en C se guarda el valor dB -6
datos3= corredor3.generar_funcion(B)

#c=datos.append(datos1);d=c.append(datos2);
#e=d.append(datos3);
#plt.plot(e)
#plt.show()

datostotales=[datos1,datos2,datos3]
plt.plot(datostotales)
plt.show()



