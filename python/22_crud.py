from _modulos.lista_crud import Lista

l = Lista()

def adicionar():
    opcao = "s"

    while opcao == "s" or opcao == "S":
        nome = input("Insira o nome do produto: ")
        preco = float(input("Insira o preço do produto: "))

        novo = {"nome": nome, "preco": preco, "proximo": None}

        l.inserirEmOrdem(novo)

        opcao = input("Deseja incluir outro produto?(s/n) ")

def listar():
    l.imprimir()

def editar():
    opcao = "s"

    while opcao == "s" or opcao == "S":
        indice = int(input("Insira o índice do produto a ser editado (voltar = 0): "))

        if indice == 0:
            break
        if indice < 0 or indice > l.topo:
            continue

        atributo = int(input("Insira o número do atributo a ser editado\n"
                             + "\t1 - nome\t2 - preço\n\t3 - menu inicial\n\n"
                             + "Sua escolha: "))
        
        if atributo == 1:
            novo_nome = input("Digite o novo nome: ")
            l.obter(indice - 1)["nome"] = novo_nome
        elif atributo == 2:
            novo_preco = float(input("Digite o novo preço: "))
            l.obter(indice - 1)["preco"] = novo_preco
        elif atributo == 3:
            return
        else:
            print("valor inválido")

        opcao = input("Deseja editar outro produto?(s/n) ")

def remover():
    opcao = "s"

    while opcao == "s" or opcao == "S":
        indice = int(input("Insira o índice do produto a ser excluído (voltar = 0): "))

        if indice == 0:
            break
        if indice < 0 or indice > l.topo:
            continue

        l.remover(indice - 1)

        opcao = input("Deseja excluir outro produto?(s/n) ")

def carregar():
    l.carregar()

def salvar():
    l.salvar()

opcao = int(input("Escolha uma opcao:\n"
                + "\t1 - Adicionar\t5 - Carregar\n"
                + "\t2 - Listar\t6 - Salvar\n"
                + "\t3 - Editar\t7 - Sair\n"
                + "\t4 - Remover\n\n"             
                + "Sua escolha: "))

while opcao != 7:
    if opcao == 1:
        adicionar()
    elif opcao == 2:
        listar()
    elif opcao == 3:
        editar()
    elif opcao == 4:
        remover()
    elif opcao == 5:
        carregar()
    elif opcao == 6:
        salvar()
    elif opcao == 7:
        break
    else:
        print("valor inválido")

    opcao = int(input("Escolha uma opcao:\n"
                + "\t1 - Adicionar\t5 - Carregar\n"
                + "\t2 - Listar\t6 - Salvar\n"
                + "\t3 - Editar\t7 - Sair\n"
                + "\t4 - Remover\n\n"             
                + "Sua escolha: "))