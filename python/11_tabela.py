num_linha = int(input("Insira a quantidade de linhas da tabela: "))
num_coluna = int(input("Insira a quantidade de colunas da tabela: "))
mostra = ""

tabela = []

for i in range(num_linha):
    tabela.append([])
    for j in range(num_coluna):
        valor = int(input("tabela[" + str(i) + "][" + str(j) + "] = "))
        tabela[i].append(valor)
        mostra += str(tabela[i][j]) + " "
    mostra += "\n"  

opcao = 1

while opcao != 's' and opcao != 'S':
    print(mostra, end="")
    valores = int(input("Deseja operar sobre linha (1) ou coluna (2)? "))
    
    if valores == 1:
        total = 0
        linha = int(input("Escolha a linha de 0 a " + str(num_linha - 1) + ": "))

        if linha >= 0 and linha < num_linha:
            for i in range(num_coluna):
                total += tabela[linha][i]

            print("O total da linha", linha, "é", total)
        else:
            print("Valor fora dos limites")
    elif valores == 2:
        total = 0
        coluna = int(input("Escolha a coluna de 0 a " + str(num_coluna - 1) + ": "))

        if coluna >= 0 and coluna < num_coluna:
            for i in range(num_linha):
                total += tabela[i][coluna]
            
            print("O total da coluna ", coluna, " é ", total)
        else:
            print("Valor fora dos limites")
    else:
        print("Opção inválida")

    opcao = input("Deseja sair?(s/n) ")