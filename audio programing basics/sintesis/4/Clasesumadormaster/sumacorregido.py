a = [3, 4, 5, 7, 1]
b = [6, 5]
c = []

if len(a) < len(b):
    mayor = b
    menor = a
else:
    mayor = a
    menor = b

for i in range(len(mayor)):
    if i <= len(menor)-1:
        x = menor[i] + mayor[i]
        c.append(x)
    else:
        c.append(mayor[i])
print 'a = ', a
print 'b = ', b
print 'c = ', c

