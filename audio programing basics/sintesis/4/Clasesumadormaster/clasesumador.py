import wave
import struct




class Suma():
    def __init__(self,a,b):
        self.a = a ; self.b = b

    def procesosuma(self):
        c = []
        print 'Longitud a', len(self.a)
        print 'Longitud b', len(self.b)
        for i in range(len(self.b)):
            try:
                x = self.a[i] + self.b[i]
                c.append(x)
            except IndexError:
                c.append(self.b[i])
        print 'Longitud c', len(c)


    def procesosuma2(self):
        c = []
        if len(self.a) < len(self.b):
            z = len(self.a)
        else:
            z = len(self.b)
        print 'Longitud a', len(self.a)
        print 'Longitud b', len(self.b)

        for i in range(z):
            if i <= len(self.a)-1:
                x = self.a[i]+ self.b[i]
                c.append(x)
            else:
                c.append(self.b[i])
        print 'Longitud c', len(c)

    def abrirarchivo(self,variable):
        cuadros = variable.getnframes()
        variabledata = []
        for i in range(cuadros):
            x = variable.readframes(1)
            dato = struct.unpack("<h", x)
            variabledata.append(dato[0])
        return variabledata


instanciador = Suma(a, b)
a = wave.open('audio1.wav', 'r')
instanciador.abrirarchivo(a)
b = wave.open('audio2.wav', 'r')
instanciador.abrirarchivo(a)

instanciador.procesosuma()


#aun no es funcional.... la idea es colocar en un metodo el generador de arrglo de dato deacuerdo al wav
