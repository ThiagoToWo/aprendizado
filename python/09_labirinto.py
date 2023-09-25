mapa = [['#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'],
        ['#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'],
        ['@', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'],
        ['#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'],
        ['#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'],
        ['#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'],
        ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#']]
linha = 2
coluna = 0
direcao = 1

while direcao != 0:
    for i in range(len(mapa)):
        for j in range(len(mapa[i])):
            print(mapa[i][j], end=" ")
        print()

    direcao = int(input("Escolha a direção (esquerda = 4, cima = 8, " + 
                "direita = 6, baixo = 2, fechar = 0): "))

    if direcao == 4: # esquerda
        if (coluna - 1) >= 0 and mapa[linha][coluna -1] == ".":
            mapa[linha][coluna] = "."
            coluna = coluna - 1
            mapa[linha][coluna] = "@"        
    elif direcao == 8: # cima
        if (linha - 1) >= 0 and mapa[linha - 1][coluna] == ".":
            mapa[linha][coluna] = "."
            linha = linha - 1
            mapa[linha][coluna] = "@"
    elif direcao == 6: # esquerda
        if (coluna + 1) < len(mapa[linha]) and mapa[linha][coluna + 1] == ".":
            mapa[linha][coluna] = "."
            coluna = coluna + 1
            mapa[linha][coluna] = "@"
    elif direcao == 2: # baixo
        if (linha + 1) < len(mapa) and mapa[linha + 1][coluna] == ".":
            mapa[linha][coluna] = "."
            linha = linha + 1
            mapa[linha][coluna] = "@"
    elif direcao == 0:
        print("Fechando o jogo.")
    else:
        print("Valor inválido")