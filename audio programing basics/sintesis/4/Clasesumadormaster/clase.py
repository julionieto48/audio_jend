
class Suma():
    def __init__(self,a,b):
        self.a = a ; self.b = b



    def procesosuma(self):
        c = []
        for i in range(len(self.b)):
            try:
                x = self.a[i] + self.b[i]
                c.append(x)
            except IndexError:
                c.append(self.b[i])
        print c
    def procesosuma2(self):
        c = []
        if len(self.a) < len(self.b):
            z = len(self.b)
        else:
            z = len(self.a)
        for i in range(z):
            if i <= len(self.a)-1:
                x = self.a[i] + self.b[i]
                c.append(x)
            else:
                c.append(self.b[i])
        print c

a = [15000,20000,5000,4000]
b = [15000,12000,30000,12000,22000,100000]
instanciador = Suma(a,b)
opc = input('Cual metodo desea utilizar')
if opc == 1:
    instanciador.procesosuma()
elif opc == 2:
    instanciador.procesosuma2()




