from Partitura import Partitura



def main():

    figuras, notas, octavas, tiposdeOndas, db_fullss = [], [], [], [], []
    bpm = input('ingrese BPM: ')

    i = True
    while i:

        figura = input('ingrese tipo de figura: redonda:1, blanca:2, negra:3, corchea:4, semicorchea:5: ')
        k = True
        while k:
            if figura == 1 or figura == 2 or figura == 3 or figura == 4 or figura == 5:
                k = False
            else:
                figura = input('Ingrese un numero permitido entre 1 y 5 para la figura musical: ')

        silencio_o_note = raw_input('Ingrese si es nota:"1" o silencio:"2": ')

        if silencio_o_note == '1' or silencio_o_note == 'NOTA' or silencio_o_note == 'nota':

            nota = raw_input('ingrese nota: C C# D D# E F G G# A A# B: ')
            jj = True
            while jj:
                if nota == 'C' or nota == 'C#' or nota == 'D' or nota == 'D#' or nota == 'E' or nota == 'F' or nota == 'F' \
                   or nota == 'F#' or nota == 'G' or nota == 'G#' or nota == 'A' or nota == 'A#' or nota == 'B':
                    jj = False
                else:
                    nota = raw_input('Ingrese la nota musical de nuevo ')
            # rango de 7 octavas
            octava = input('Ingrese una de las siguientes octavas: 1, 2, 3, 4, 5, 6, o 7: ')
            kk = True
            while kk:
                if octava == 1 or octava == 2 or octava == 3 or octava == 4 or octava == 5 or octava == 6 or octava == 7:
                    kk = False
                else:
                    octava = input('Ingrese una octava (numero natural) permitida entre 1 y 7: ')

            tipodeOnda = input('Ingrese forma de onda deseada para su nota: 1:Seno, 2:Cuadrada, 3:Triangular, 4:Sawtooth: ')
            db_fulls = input('Ingrese los dB_fs: ')

            kk = True
            while kk:
                if db_fulls < 0:
                    kk = False
                else:
                    db_fulls = input('Ingrese los dB_fs: ')

        elif silencio_o_note == '2' or silencio_o_note == 'SILENCIO' or silencio_o_note == 'silencio':
            db_fulls = 1; figura = 1; nota = 'C'; octava = '1'
            tipodeOnda = 5

        proxitera = raw_input('Desea ingresar otra nota? "si", "no" o "1", "2": ')
        jjj = True
        while jjj:
            if proxitera == 'si' or proxitera == 'no' or proxitera == 'SI' or proxitera == 'NO' or proxitera == '1' or proxitera == '2':
                jjj = False
            else:
                proxitera = raw_input('Desea ingresar otra nota? "si", "no" o "1", "2": ')

        if proxitera == 'no' or proxitera == 'NO' or proxitera == '2':
            i = False

        db_fullss.append(db_fulls); #print 'db_fullss = ', db_fullss
        figuras.append(figura); print 'figuras = ', figuras
        notas.append(nota); #print 'notas = ', notas; print 'len(figuras) = ', len(figuras)
        octavas.append(octava); #print 'octavas = ', octavas
        tiposdeOndas.append(tipodeOnda); #print 'tiposdeOndas = ', tiposdeOndas

    melodia = []
    instancia = Partitura(bpm)
    #funciona: iterador in range(len(de cualquiera de los append arriba))
    for ii in range(len(figuras)):
        #instancia = Partitura(bpm)

        opcion_fig = instancia.figure()
        fig = opcion_fig[figuras[ii]-1]

        opcion_note = instancia.note(notas[ii], octavas[ii]); print "opcion_note = ", opcion_note, 'Hz'
        amplitud = instancia.amp(db_fullss[ii]); print 'amplitud = ', amplitud

        if tiposdeOndas[ii] == 1:
            signal = instancia.sin(amplitud, fig, opcion_note)
        if tiposdeOndas[ii] == 2:
            signal = instancia.square(amplitud, fig, opcion_note)
        if tiposdeOndas[ii] == 3:
            signal = instancia.triangle(amplitud, fig, opcion_note)
        if tiposdeOndas[ii] == 4:
            signal = instancia.sawtooth(amplitud, fig, opcion_note)
        if tiposdeOndas[ii] == 5:
            signal = instancia.silencio(fig)

        melodia.append(signal)


    senal_final = []
    for x in melodia:
        for xx in x:
            senal_final.append(xx)
    return senal_final

    #bitdepth = 16
    #fs = 44100
    #nombre = raw_input("Ingrese el nombre del archivo a guardar: ")
    #archi = Archivar(bitdepth, fs, senal_final, nombre)
    #archi.guardarEstereo() #se guarda en estereo
    #instancia.muest(senal_final)

if __name__ == "__main__":
    main()
