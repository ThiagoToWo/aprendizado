from math import sqrt
import _modulos.estatistica as e # importa todas as funções

amostra = int(input("Insira o tamanho da amostra: "))

dados = [None]*(amostra + 1) # um elemento indefinido a mais, para a comparação do histograma

for i in range(amostra):
    dados[i] = float(input(f"insira o {i + 1}o dado: "))

print("Dados = ", end="")

for i in range(amostra):
    print(dados[i], end=" ")

print()

print(f"média = {e.media(dados, amostra)}")
print(f"mediana = {e.mediana(dados, amostra)}")
print(f"moda = {e.moda(dados, amostra)}")
print(f"desvio padrão = {sqrt(e.variancia(dados, amostra))}")
print("\nHistograma:")

freq = e.frequencia(dados, amostra)

for i in range(amostra):
    if dados[i] != dados[i + 1]:
        print(dados[i], end=": ")

        for j in range(freq[i]):
            print("*", end="")

        print(" " + str(freq[i]))

print("total = " + str(amostra))