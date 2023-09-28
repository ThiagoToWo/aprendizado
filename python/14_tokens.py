def tokenizar(texto, separadores):
    tokens = [None]*128 # cria um vetor vazio de tamanho 128
    palavra = ""
    achou = False
    posicao = 0

    for i in range(len(texto)):
        for j in range(len(separadores)):
            if texto[i] == separadores[j]:
                achou = True
                break
        
        if not achou:
            palavra += texto[i]
        else:
            tokens[posicao] = palavra
            posicao += 1
            palavra = ""
            achou = False

    tokens[posicao] = palavra

    return tokens

texto = input("Insira um texto (máx. 128 palavras): ")
separadores = input("Insira o(s) caractere(s) separadores: ")

tokens = tokenizar(texto, separadores)

i = 0

while i < len(tokens) and tokens[i] != None:
    print(tokens[i])
    i += 1            