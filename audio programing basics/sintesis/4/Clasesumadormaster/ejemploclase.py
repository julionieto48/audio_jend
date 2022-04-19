
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


a = wave.open('audio1.wav', 'r')
cuadros = a.getnframes()
adata = []
for i in range(cuadros):
    x = a.readframes(1)
    dato = struct.unpack("<h", x)
    adata.append(dato[0])


b = wave.open('audio2.wav', 'r')
cuadros2= b.getnframes()
bdata = []
for j in range(cuadros2):
    x = b.readframes(1)
    dato2 = struct.unpack("<h", x)
    bdata.append(dato2[0])


instanciador = Suma(adata, bdata)
instanciador.procesosuma()

# revisar la logica ya que no se está sumando correctamente
