numeros = [5, -1, 3, 7, 4, 3, 18, -5]
max = numeros[0]

for i in range(len(numeros)):
    if numeros[i] > max:
        max = numeros[i]

print(max)