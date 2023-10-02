from random import randrange
from _modulos.ordenacao import ordenar
from _modulos.busca import buscar

n = 20
numeros = [0]*n

for i in range(n): 
    numeros[i] = randrange(51)

print("Números: ", end="")

for i in range(n):
    print(numeros[i], end=" ") 
    
ordenar(numeros, n)
    
print("\nNúmeros ordenados: ", end="")

for i in range(n): 
    print(numeros[i], end=" ")

m = 4

for i in range(m):
    print()

    x = randrange(51)
    posicao = buscar(x, numeros, n)

    if posicao != -1:
        print(f"O valor {x} está na posição {posicao}.", end="")
    else:
        print(f"O valor {x} não pertence à lista.", end="")