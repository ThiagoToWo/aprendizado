max = int(input("Insira o limite de teste: "))
amplitude = int(input("Insira a amplitude de distribuição: "))

primos = []

primos.append(False)
primos.append(False)

for i in range(2, max):
    primos.append(True)

i = 2
while i * i <= max:
    for j in range(2 * i, max, i):
        primos[j] = False
    i += 1

for i in range(2, max):
    if primos[i]:
        print(i, end=" ")
    
    if i % amplitude == 0:
        print()

