

# crear un arreglo de longitud 30
A = []
for i in range(50):
    A.append(i)

# limites

a = -5 ; b = 5 ; c = 0
#encontrar el mayor b siempre va a ser el mayor
# mayor = False
# if b > a :
#     mayor = True
# elif a > b :
#     b = c
#     b = a
#     a = c


while b < a:
    c = b
    b = a
    a = c
# print a,b,c

longitudComparacion = b - (a)

ratio = int(len(A) / longitudComparacion)
# print ratio

downsampledA = []

for i in A :
    if i % ratio == 0 :
        downsampledA.append(i)

print downsampledA , len(downsampledA)

# https://www.celeberrima.com/distancia-entre-dos-puntos-geometria-analitica-formula-y-ejemplos/
# https://www.youtube.com/watch?v=Yd9q45wuuFA
# https://www.youtube.com/watch?v=KehyltXMrZE
# https://stackoverflow.com/questions/29085268/resample-a-numpy-array
# https://www.youtube.com/results?search_query=downsample+array+python
# https://www.mathworks.com/help/signal/ref/downsample.html
# https://www.adrian.idv.hk/2018-01-24-downsample/
# https://www.mathworks.com/help/matlab/math/reshaping-and-rearranging-arrays.html