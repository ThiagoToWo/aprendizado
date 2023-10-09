from dataclasses import dataclass
@dataclass
class no:
    dado: str
    proximo: dataclass

class Lista:    
    def __init__(self):
        self.cabeca = None
        self.topo = 0

    def empilhar(self, valor):
        novo = no(valor, None)

        if self.topo == 0:
            self.cabeca = novo
        else:
            corrente = self.cabeca

            while corrente.proximo != None:
                corrente = corrente.proximo

            corrente.proximo = novo

        self.topo += 1

    def obter(self, posicao):
        elemento = self.cabeca

        for i in range(posicao):
            elemento = elemento.proximo

        return elemento
    
    def inserir(self, valor, posicao):
        if (posicao >= 0) and (posicao <= self.topo):
            novo = no(valor, None)

            if posicao == 0:
                novo.proximo = self.cabeca
                self.cabeca = novo
            else:
                antecessor = self.obter(posicao - 1)
                sucessor = antecessor.proximo

                antecessor.proximo = novo
                novo.proximo = sucessor

            self.topo += 1
            return True
        
        return False
    
    def remover(self, posicao):
        if posicao == 0:
            self.cabeca = self.cabeca.proximo
        else:
            antecessor = self.obter(posicao - 1)
            corrente = antecessor.proximo
            sucessor = corrente.proximo
            
            antecessor.proximo = sucessor        
        
        self.topo -= 1

    def imprimir(self):
        if self.topo > 0:
            corrente = self.cabeca

            print(corrente.dado, end=" ")

            while corrente.proximo != None:
                corrente = corrente.proximo
                print(corrente.dado, end=" ")

    def tamanho(self):
        return self.topo
    
    def inserirEmOrdem(self, valor):
        corrente = self.cabeca

        if self.topo == 0:
            self.inserir(valor, 0)
            return
        
        i = 0
        while i < self.topo:
            if valor < corrente.dado:
                break

            corrente = corrente.proximo
            i += 1

        self.inserir(valor, i)