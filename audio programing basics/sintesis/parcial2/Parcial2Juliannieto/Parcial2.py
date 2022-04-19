import mainParti
import Openwav
from Archivar import Archivar

voces =input ('Cuantas voces tiene la partitura')
for i in range(1,voces):
    print('Ingrese melodia de la voz',i)
    mainParti.main()
    Archivar()
    i= i+1
abrirarchive = input('Dese abrir su archivo? 1=si 2=no')

if abrirarchive == 1:
    Openwav.mainopen()
if abrirarchive == 2:
    print ('Suertes pichurria')





