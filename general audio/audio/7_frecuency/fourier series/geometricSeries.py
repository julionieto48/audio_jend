import matplotlib.pyplot as plt

a = 100
r = -2
sucesion = []
ratios = [0]
n = 50

#print range(0,n) #[0, 1, 2, 3, 4]
for i in range(0,n):
    elemento = a * (r**i)
    sucesion.append(elemento)

    if i >= 1 :
        ratioElement = sucesion[i] / sucesion[i - 1]
        ratios.append(ratioElement)


print sucesion , ratios


plt.subplot(211)  # 2 filas 1 coumna posicion 1
#print range(0 , len(sucesion)) [0, 1, 2, 3, 4]
x = range(0 , n)
plt.scatter(x , sucesion)
plt.xlabel(' n ')
plt.ylabel(' value ')
plt.title( ' a * r ^ n ' )
plt.grid(True)

plt.subplot(212)
plt.scatter(x , ratios)
plt.xlabel(' n ')
plt.ylabel(' ratios')
plt.title( 'ratio ' )
plt.grid(True)

plt.show()

# https://stackoverflow.com/questions/1522825/calculating-sum-of-geometric-series-mod-m