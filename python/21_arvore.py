from _modulos.arvore import Arvore

a = Arvore()

def imprimir(valor):
    print(valor, end=" ")

def metade(valor):
    print(valor / 2, end=" ")

print("Inserir 10, 6, 14, 4, 8, 12, 2, 20, 18, 26")
a.inserir(10)
a.inserir(6)
a.inserir(14)
a.inserir(4)
a.inserir(8)
a.inserir(12)
a.inserir(2)
a.inserir(20)
a.inserir(18)
a.inserir(26)

print("Em ordem: ", end="") 
a.emOrdem(imprimir) # 2 4 6 8 10 12 14 18 20 26
print()
print("Em pré ordem: ", end="")
a.preOrdem(imprimir) # 10 6 4 2 8 14 12 20 18 26
print()
print("Em pós ordem: ", end="")
a.posOrdem(imprimir) # 2 4 8 6 12 18 26 20 14 10
print()

print("O valor 3 está na árvore? " + str(a.pesquisar(3))) # falso
print("O valor 4 está na árvore? " + str(a.pesquisar(4))) # verdadeiro

print("Remover 4 (somente um filho esquerdo)")
a.remover(4)
print("Remover 14 (com dois filhos)")
a.remover(14)
print("Remover 20 (somente um filho direito)")
a.remover(20)
print("Remover 12 (sem filhos)")
a.remover(12)

print("Em ordem: ", end="")
a.emOrdem(imprimir) # 2 6 8 10 18 26
print()
print("Em pré ordem: ", end="")
a.preOrdem(imprimir) # 10 6 2 8 18 26
print()
print("Em pós ordem: ", end="")
a.posOrdem(imprimir) # 2 8 6 26 18 10
print()

print("O valor 4 está na árvore? " + str(a.pesquisar(4))) # falso

print("O menor valor é " + str(a.min().dado)) # 2
print("O maior valor é " + str(a.max().dado)) # 26

print("A metade dos valores em ordem: ", end="")
a.emOrdem(metade) # 1 3 4 5 9 13