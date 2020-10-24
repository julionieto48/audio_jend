import mainParti
#import Openwav

voces =input ('Cuantas voces tiene la partitura')
for i in range(voces):
    print('Ingrese voz',i)
    mainParti.main()
    i= i+1
#Openwav.mainopen()



