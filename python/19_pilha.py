from _modulos.pilha import Pilha

p = Pilha()

print(p.tamanho()) # 0

print("Empilhar A, B e C")
p.empilhar("A")
p.empilhar("B")
p.empilhar("C")
p.imprimir() # A B C
print(p.tamanho()) # 3

print("Desempilhar")
p.desempilhar()
p.imprimir() # A B 
print(p.tamanho()) # 2

print("Empilhar D")
p.empilhar("D")
p.imprimir() # A B D
print(p.tamanho()) # 3

print("Desempilhar")
p.desempilhar()
p.imprimir() # A B 
print(p.tamanho()) # 2

print("Desempilhar")
p.desempilhar()
p.imprimir() # A  
print(p.tamanho()) # 1

print("Desempilhar")
p.desempilhar()
p.imprimir() #  
print(p.tamanho()) # 0

print("Desempilhar")
p.desempilhar() # Pilha vazia
p.imprimir() # 
print(p.tamanho()) # 0