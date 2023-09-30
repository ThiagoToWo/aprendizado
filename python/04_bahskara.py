from math import sqrt

a = float(input("a = "))
b = float(input("b = "))
c = float(input("c = "))

if a == 0:
    print("não é uma função quadrática")
else:
    d = b * b - 4 * a * c

if d == 0:
    x1 = -b / (2 * a)
    print("x1 = x2 =", x1)
else: 
    if d > 0:
        x1 = (-b + sqrt(d)) / (2 * a)
        x2 = (-b - sqrt(d)) / (2 * a)
        print("x1 =", x1)
        print("x2 =", x2)
    else: 
        print("não possui raízes reais")