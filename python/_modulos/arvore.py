from dataclasses import dataclass

@dataclass
class no:
    dado: str
    direito: dataclass
    esquerdo: dataclass

class Arvore:
    def __init__(self):
        self.raiz = None

    def inserir(self, valor):
        self.raiz = self.inserirNo(self.raiz, valor)

    def remover(self, valor):
        self.raiz = self.removerNo(self.raiz, valor)

    def pesquisar(self, valor):
        return self.pesquisarNo(self.raiz, valor)

    def preOrdem(self, callback):
        self.pre(self.raiz, callback)

    def emOrdem(self, callback):
        self.em(self.raiz, callback)

    def posOrdem(self, callback):
        self.pos(self.raiz, callback)

    def min(self):
        return self.minNo(self.raiz)

    def max(self):
        return self.maxNo(self.raiz)
    
    # funções utilitárias recursivas
    def inserirNo(self, subraiz, valor):
        if subraiz == None:
            novo = no(valor, None, None)
            return novo
        elif valor < subraiz.dado:
            subraiz.esquerdo = self.inserirNo(subraiz.esquerdo, valor)
        elif valor > subraiz.dado:
            subraiz.direito = self.inserirNo(subraiz.direito, valor)

        return subraiz
    
    def removerNo(self, subraiz, valor):
        if valor < subraiz.dado:
            subraiz.esquerdo = self.removerNo(subraiz.esquerdo, valor)
        elif valor > subraiz.dado:
            subraiz.direito = self.removerNo(subraiz.direito, valor)
        else:
            if subraiz.esquerdo == None and subraiz.direito == None:
                subraiz = None
            elif subraiz.direito == None:
                subraiz = subraiz.esquerdo
            elif subraiz.esquerdo == None:
                subraiz = subraiz.direito
            else:
                sucessor = self.minNo(subraiz.direito)
                subraiz.dado = sucessor.dado
                subraiz.direito = self.removerNo(subraiz.direito, sucessor.dado)

        return subraiz
    
    def pesquisarNo(self, subraiz, valor):
        if subraiz == None:
            return False
        elif valor < subraiz.dado:
            return self.pesquisarNo(subraiz.esquerdo, valor)
        elif valor > subraiz.dado:
            return self.pesquisarNo(subraiz.direito, valor)
        else:
            return True
        
    def pre(self, subraiz, callback):
        if subraiz == None:
            return
        
        callback(subraiz.dado)
        self.pre(subraiz.esquerdo, callback)
        self.pre(subraiz.direito, callback)

    def em(self, subraiz, callback):
        if subraiz == None:
            return
        
        self.em(subraiz.esquerdo, callback)
        callback(subraiz.dado)
        self.em(subraiz.direito, callback)

    def pos(self, subraiz, callback):
        if subraiz == None:
            return
        
        self.pos(subraiz.esquerdo, callback)
        self.pos(subraiz.direito, callback)
        callback(subraiz.dado)

    def minNo(self, subraiz):
        if subraiz.esquerdo == None:
            return subraiz
        else:
            return self.minNo(subraiz.esquerdo)
        
    def maxNo(self, subraiz):
        if subraiz.direito == None:
            return subraiz
        else:
            return self.maxNo(subraiz.direito)