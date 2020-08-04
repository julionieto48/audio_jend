import math

class Profundidabits:

    def __init__(self,valorspl,bits):

        self.valorspl= valorspl;
        self.bits = bits;

    def calculo_dB(self):
        valoreferencia= (2**self.bits/2);
        dB = 10*math.log((self.valorspl/float(valoreferencia))**2,10)
        print ('El valor en dB es:',dB);
        print ('Valor de referencia',valoreferencia);
        return dB

    def calculo_valorspl(self,dB):
        vref= (2**self.bits/2);

        valorspl = (10**(dB/20)**(1/2))
        print ('El valor spl es:',valorspl)*vref;






bits= input('Ingresar la profundidad en bits');
spl = input('Ingresar el valor en spl');
ejercicio = Profundidabits(spl,bits)
vref = ejercicio.calculo_dB()

debes= input('Ingrese valor en decibeles')
ejercicio1= Profundidabits(0,bits)
ejercicio1.calculo_valorspl(debes)






