from _modulos.fila import Fila

f = Fila()

print(f.tamanho()) # 0

print("inserir A, B e C")
f.inserir("A")
f.inserir("B")
f.inserir("C")
f.imprimir() # A B C
print(f.tamanho()) # 3

print("Remover")
f.remover()
f.imprimir() # B C
print(f.tamanho()) # 2

print("inserir D")
f.inserir("D")
f.imprimir() # B C D
print(f.tamanho()) # 3

print("Remover")
f.remover()
f.imprimir() # C D
print(f.tamanho()) # 2

print("Remover")
f.remover()
f.imprimir() # D 
print(f.tamanho()) # 1

print("Remover")
f.remover()
f.imprimir() #  
print(f.tamanho()) # 0

print("Remover")
f.remover() # Fila vazia
f.imprimir() # 
print(f.tamanho()) # 0