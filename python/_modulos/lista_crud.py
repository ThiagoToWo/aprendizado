import json # para salvar dados

class Lista:
    def __init__(self):
        self.cabeca = None
        self.topo = 0

    def obter(self, posicao):
        elemento = self.cabeca

        for i in range(posicao):
            elemento = elemento["proximo"]

        return elemento
    
    def inserir(self, novo, posicao):
        if (posicao >= 0) and (posicao <= self.topo):
            if posicao == 0:
                novo["proximo"] = self.cabeca
                self.cabeca = novo
            else:
                antecessor = self.obter(posicao - 1)
                sucessor = antecessor["proximo"]

                antecessor["proximo"] = novo
                novo["proximo"] = sucessor

            self.topo += 1
            return True
        
        return False
    
    def remover(self, posicao):
        if posicao == 0:
            self.cabeca = self.cabeca["proximo"]
        else:
            antecessor = self.obter(posicao - 1)
            corrente = antecessor["proximo"]
            sucessor = corrente["proximo"]
            
            antecessor["proximo"] = sucessor        
        
        self.topo -= 1

    def inserirEmOrdem(self, novo):
        corrente = self.cabeca

        if self.topo == 0:
            self.inserir(novo, 0)
            return
        
        i = 0
        while i < self.topo:
            if novo["nome"] < corrente["nome"]:
                break

            corrente = corrente["proximo"]
            i += 1

        self.inserir(novo, i)

    def imprimir(self):
        if self.topo > 0:
            i = 1
            corrente = self.cabeca

            print("-------itens-------")

            while corrente != None:
                print(f"{i}. {corrente['nome']}: {corrente['preco']}")
                corrente = corrente["proximo"]
                i += 1

    def salvar(self):
        arquivo = open("produtos.json", "w")
        dados = {"tamanho": self.topo, "produtos": self.cabeca}
        json.dump(dados, arquivo)
        arquivo.close()

    def carregar(self):
        arquivo = open("produtos.json", "r")
        dados = json.load(arquivo)
        self.topo = dados["tamanho"]
        self.cabeca = dados["produtos"]
        arquivo.close()