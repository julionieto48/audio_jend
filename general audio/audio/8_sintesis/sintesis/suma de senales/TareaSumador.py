
import wave
import struct
import math

class Sumasenales():
    def __init__(self,a,b,c,d):
        self.a = a; self.b = b;
        self.c = c; self.d = d;
    def dBfs(self):
        bits = float(16)
        a = []
        for i in self.a:
            x = ((2**bits)/2)*(10**(float(self.a[i])/10))**0.5
            a.append(x)
        b = []
        for j in self.b:
            x = 10*math.log(2*float(self.b[j-1])/(2** bits),10)**2
            b.append(x)
        c = []
        for k in self.c:
            x = 10*math.log(2*float(self.c[k-1])/(2** bits),10)**2
            c.append(x)
        d = []
        for l in self.d:
            x = 10*math.log(2*float(self.d[l-1])/(2** bits),10)**2
            d.append(x)

        return a,b,c,d
    def distorsionsenal(self,a,b,c,d):

        adata = []
        for i in a:
            if a[i] > 0:
                a[i] = a[i]/2
            else:
                a[i] = a[i]
        adata.append(a[i])

        bdata = []
        for j in b:
            if b[j] > 0:
                b[j] = b[j]/2
            else:
                b[j] = b[j]
        bdata.append(b[j])

        cdata = []
        for k in c:
            if c[k] > 0:
                c[k] = c[k]/2
            else:
                c[k] = c[k]
        cdata.append(c[k])

        ddata = []
        for l in d:
            if d[l] > 0:
                d[l] = d[l]/2
            else:
                d[l] = d[l]
        ddata.append(d[l])

        return adata,bdata,cdata,ddata




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

c = wave.open('audio1.wav', 'r')
cuadros3 = c.getnframes()
cdata = []
for k in range(cuadros3):
    x = c.readframes(1)
    dato3 = struct.unpack("<h", x)
    cdata.append(dato3[0])

d = wave.open('audio2.wav', 'r')
cuadros4 = d.getnframes()
ddata = []
for l in range(cuadros4):
    x = d.readframes(1)
    dato4 = struct.unpack("<h", x)
    ddata.append(dato4[0])

instanciador = Sumasenales(adata,bdata,cdata,ddata)

#convertir a dBFS
abcd = instanciador.dBfs()

# revisar la distorsion individual
abcddata = instanciador.distorsionsenal(abcd[1],abcd[2],abcd[3],abcd[4])
#instanciador.procesosuma()

