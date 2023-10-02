from random import randrange
from modulos.ordenacao import ordenar

n = 20
numeros = [0]*n

for i in range(n):
    numeros[i] = randrange(101)

print("Antes de ordenar: ", end="")

for i in range(n):
    print(numeros[i], end=" ")

ordenar(numeros, n)

print("\nDepois de ordenar: ", end="")

for i in range(n):
    print(numeros[i], end=" ")