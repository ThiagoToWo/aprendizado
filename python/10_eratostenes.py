max = int(input("Insira o limite de teste: "))
amplitude = int(input("Insira a amplitude de distribuição: "))

primos = [None] * (max + 1)

primos[0] = False
primos[1] = False

for i in range(2, max + 1):
    primos[i] = True

i = 2
while i * i <= max:
    for j in range(2 * i, max + 1, i):
        primos[j] = False
    i += 1

for i in range(2, max + 1):
    if primos[i]:
        print(i, end=" ")
    
    if i % amplitude == 0:
        print()