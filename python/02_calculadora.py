a = int(input("Insira o valor de a "))
b = int(input("Insira o valor de b "))
    
print("soma =", a + b)
print("diferença =", a - b)
print("produto =", a * b)
print("quociente =", a / b)

if a > b:
    print(a, ">", b)
else:
    if a == b:
        print(a, "=", b)
    else: 
        print(a, "<", b)

if a > 0 and a < 10:
    print("0 <", a, "< 10")
else:
    if a < 0 or a > 10:
        print(a, "< 0 ou", a, "> 10")
    else:
        print(a, "= 0 ou", a, "= 10")