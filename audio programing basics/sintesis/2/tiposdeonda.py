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



class Square:

    def __init__(self,muestreo,frecuencia,tiempo ):
        self.muestreo= 1/float(muestreo);
        self.frecuencia= frecuencia; self.tiempo=int(tiempo*muestreo);

    def generar_funcion(self,A):

        arreglo=[]
        for i in range(self.tiempo):
            x=math.sin(2*math.pi*self.frecuencia* i *self.muestreo);

            if x>=0:
                arreglo.append(A);
            if x<0:
                arreglo.append(-A)


        return arreglo

    def valorpico(self,bits,db):

        valorreferencia= ((2**bits)/2);
        valorpico= valorreferencia* (10**(db/10))**0.5
        print ('El valor de A es:',valorpico);
        return valorpico
    def grafica(self,cuadrado):
        plt.plot(cuadrado)
        plt.show()

class Triangle:

    def __init__(self,muestreo,frecuencia,tiempo ):
        self.muestreo= muestreo;
        self.frecuencia= frecuencia; self.tiempo=int(tiempo*muestreo);

    def generar_funcion(self,A):
        arreglo=[]
        Tm=self.muestreo/self.frecuencia

        contador=0

        for i in range(self.tiempo):

            if contador<= Tm/4.0:
                m=4.0/Tm
                x=m*contador
                arreglo.append(x*A)
                contador+=1
            if (contador >Tm/4.0) & (contador<=3*Tm/4.0) :
                m=-4.0/Tm;b=2;
                x=m*contador+b
                arreglo.append(x*A)
                contador+=1
            if (contador>Tm/4.0)& (contador<Tm):
                m=4.0/Tm;b=-4;
                x=m*contador+b
                arreglo.append(x*A)
                contador+=1
            if contador== Tm:
                contador=0


        return arreglo

    def valorpico(self,bits,db):

        valorreferencia= ((2**bits)/2);
        valorpico= valorreferencia* (10**(db/10))**0.5
        print ('El valor de A es:',valorpico);
        return valorpico
    def grafica(self,seno):
        plt.plot(seno)
        plt.show()

class Saw:

    def __init__(self,muestreo,frecuencia,tiempo ):
        self.muestreo= muestreo;
        self.frecuencia= frecuencia; self.tiempo=int(tiempo*muestreo);

    def generar_funcion(self,A):
        arreglo=[]
        Tm=self.muestreo/self.frecuencia

        contador=0

        for i in range(self.tiempo):
            if contador<= Tm:
                m=4.0/Tm
                x=m*contador
                arreglo.append(x*A)
                contador+=1

            if contador== Tm:
                contador=0
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
    bits= 16;
    db= -3;

    muestreo = 44100;
    tono= input('Digitar frecuencia/tono');
    tiempo= input('tiempo a generar');
    tipo_de_onda_por_generar= input('Que onda desea generar');

    if tipo_de_onda_por_generar== 1:
        corredor=Senoconamplitud(muestreo,tono,tiempo)
        A = corredor.valorpico(bits,db)
        datos= corredor.generar_funcion(A)
        corredor.grafica(datos)
    if tipo_de_onda_por_generar== 2:
        corredor=Square(muestreo,tono,tiempo)
        A = corredor.valorpico(bits,db)
        datos= corredor.generar_funcion(A)
        corredor.grafica(datos)
    if tipo_de_onda_por_generar== 3:
        corredor=Triangle(muestreo,tono,tiempo)
        A = corredor.valorpico(bits,db)
        datos= corredor.generar_funcion(A)
        corredor.grafica(datos)
    if tipo_de_onda_por_generar== 4:
        corredor=Saw(muestreo,tono,tiempo)
        A = corredor.valorpico(bits,db)
        datos= corredor.generar_funcion(A)
        corredor.grafica(datos)

main()



