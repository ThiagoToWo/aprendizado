n = 0
total = 0
valor = float(input())

while valor != -1:
    total += valor
    n += 1
    valor = float(input())

print("a média é", total / n)