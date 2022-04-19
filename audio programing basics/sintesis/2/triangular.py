
import matplotlib.pylab as plt


class triangular:

    def __init__(self, frecuencia, duracion, frecuenciamuestreo, profundidadbits):
        self.frecuencia = frecuencia
        self.duracion = duracion
        self.muestreo = frecuenciamuestreo
        self.profundidadbits = profundidadbits
        self.tiempo = duracion * frecuenciamuestreo
        self.tm = (1 / float(frecuenciamuestreo))

    def generar(self):
        wavearray = []
        T_m = self.muestreo/self.frecuencia
        print 'T_m=', T_m
        periodos = self.frecuencia*self.duracion; print 'periodos', periodos
        print 'Duracion = ', self.tiempo
        c = 0


        for t in range(self.tiempo):

            if c <= T_m/4.0:
                m = 4.0/T_m
                x = m*c
                wavearray.append(x)
                c += 1

            if (c > T_m/4.0) & (c <= 3*T_m/4.0):
                m = -4.0/T_m
                b = 2
                x = m*c + b
                wavearray.append(x)
                c += 1

            if (c > 3*T_m/4.0) & (c < T_m):
                m = 4.0/T_m; b = -4
                x = m*c + b
                wavearray.append(x)
                c += 1

            if c == T_m: #reinicia el contador c, para permitir el dominio de los proximos periodos
                c = 0



        return wavearray


    def graficar(self, arreglo):
        plt.plot(arreglo)
        plt.show()


    self.muestreo= muestreo;
    self.frecuencia= frecuencia; self.tiempo=(tiempo*muestreo)
    self.periodomuestreo=1/float(muestreo)