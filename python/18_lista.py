from _modulos.lista import Lista

l = Lista()

print(l.tamanho()) # 0

print("Empilhar A, B, C e D")
l.empilhar("A")
l.empilhar("B")
l.empilhar("C")
l.empilhar("D")
l.imprimir() # A B C D
print(l.tamanho()) # 4

print("Remover da posição 2")
l.remover(2)
l.imprimir() # A B D
print(l.tamanho()) # 3

print("Inserir F na posição 1")
l.inserir("F", 1)
l.imprimir() # A F B D
print(l.tamanho()) # 4

print("Inserir G na posição 0 e H na posição 5")
l.inserir("G", 0)
l.inserir("H", 5)
l.imprimir() # G A F B D H
print(l.tamanho()) # 6

print("Remover da posição 0")
l.remover(0)
l.imprimir() # A F B D H
print(l.tamanho()) # 5

print("Remover da posição 4")
l.remover(4)
l.imprimir() # A F B D
print(l.tamanho()) # 4

print("Remover da posição 0 duas vezes seguidas")
l.remover(0)
l.remover(0)
l.imprimir() # B D
print(l.tamanho()) # 2

print("Inserir em ordem A, C e E")
l.inserirEmOrdem("A")
l.inserirEmOrdem("C")
l.inserirEmOrdem("E")
l.imprimir() # A B C D E
print(l.tamanho()) # 5

print("O valor do elemento na posição 0 é " + l.obter(0).dado) # A
print("O valor do elemento na posição 2 é " + l.obter(2).dado) # C
print("O valor do elemento na posição 4 é " + l.obter(4).dado) # E