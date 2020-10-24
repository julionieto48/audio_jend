import wave
import struct
from Savewav import Archivar

class Sumasenales():
    def __init__(self,a,b,c,d):
        self.a = a; self.b = b;
        self.c = c; self.d = d;

    def distorsionsenal(self):

        adata = []
        for i in self.a:
            if self.a[i] > 0:
                self.a[i] = self.a[i]/2
            else:
                self.a[i] = self.a[i]
        adata.append(self.a[i])

        bdata = []
        for j in self.b:
            if self.b[j] > 0:
                self.b[j] = self.b[j]/2
            else:
                self.b[j] = self.b[j]
        bdata.append(self.b[j])

        cdata = []
        for k in self.c:
            if self.c[k] > 0:
                self.c[k] = self.c[k]/2
            else:
                self.c[k] = self.c[k]
        cdata.append(self.c[k])

        ddata = []
        for l in self.d:
            if self.d[l] > 0:
                self.d[l] = self.d[l]/2
            else:
                self.d[l] = self.d[l]
        ddata.append(self.d[l])

        return adata,bdata,cdata,ddata
    def procesosuma(self,a,b,c,d):
        resultado = []
        if len (a) > len(b) and len (a) > len(c) and len (a) > len(d):
            mayor = a
        elif len (b) > len(a) and len (b) > len(c) and len (b) > len(d):
            mayor = b
        elif len (c) > len(a) and len (c) > len(b) and len (c) > len(d):
            mayor = c
        elif len (d) > len(a) and len (d) > len(b) and len (d) > len(c):
            mayor = d
        if len (a) < len(b) and len (a) < len(c) and len (a) < len(d):
            menor = a
        elif len (b) < len(a) and len (b) < len(c) and len (b) < len(d):
            menor = b
        elif len (c) < len(a) and len (c) < len(b) and len (c) < len(d):
            menor = c
        elif len (d) < len(a) and len (d) < len(b) and len (d) < len(c):
            menor = d
        for i in range(len(mayor)):
            if i <= len(menor)-1:
                x = a[i] + b[i] + c[i] + d[i]
                resultado.append(x)
            else:
                resultado.append(mayor[i])
        return resultado

    def distorsiontotal(self,senaltotal):
        data = []
        for i in senaltotal:
            if senaltotal[i] > 0:
                senaltotal[i] = senaltotal[i]/2
            else:
                senaltotal[i] = senaltotal[i]
        data.append(senaltotal[i])
        return data

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

# revisar la distorsion individual
abcddata = instanciador.distorsionsenal()
abcddata = list (abcddata)

#sumar las señales
senalessumadas = instanciador.procesosuma(abcddata[1],abcddata[2],abcddata[3],abcddata[4])

# revisar distorsion de la senal total

senalfinal = instanciador.distorsiontotal(senalessumadas)

#guardar archivo en wav
nombrearchivo = 'audiototal'
instancia = Archivar(16,441000,senalfinal,nombrearchivo)
instancia.guardarestereo(nombrearchivo)



