import math # math.floor()

A = B = C = D = E = 0

nota = int(input("Insira a nota de 0 a 100 (sair = -1): "))

while nota != -1:
    # não existe switch em Python
    n = math.floor(nota / 10)
    
    if n == 10:
        A += 1
    elif n == 9 or n == 8 or n == 7:
        B += 1
    elif n == 6 or n == 5 or n == 4:
        C += 1
    elif n == 3 or n == 2 or n == 1:
        D += 1
    elif n == 0:
        E += 1
    else:
        print("Valor fora dos limites.")
    
    nota = int(input("Insira a nota de 0 a 100 (sair = -1): "))
    
print("Perfeito (100):", A)
print("Bom (70 a 99):", B)
print("Médio (40 a 69):", C)
print("Ruim (10 a 39):", D)
print("Péssimo (0 a 9):", E)
print("Total:", A + B + C + D + E)