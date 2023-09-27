num_palavras = 0
num_letras = 0
tamanho = 0
achou_letra = False
simbolos = [' ', ',', '.', ';', ':', '!', '?', '(', ')']

texto = input("Insira um texto: ")

i = 0

while i < len(texto):
    achou_letra = True

    if texto[i] == " ":
        num_palavras += 1

    for j in range(len(simbolos)):
        if texto[i] == simbolos[j]:
            achou_letra = False
            break

    if achou_letra:
        num_letras += 1

    i += 1

print("Esse texto tem " + str(num_palavras + 1) + " palavras, " + 
      str(i) + " caracteres, sendo " + str(num_letras) + " deles letras.")  