class Pilha:
    def __init__(self):
        self.max = 100
        self.pilha = [None]*self.max
        self.topo = -1

    def empilhar(self, valor):
        self.topo += 1

        if self.topo == self.max:
            self.max *= 2
            temp = [None]*self.max

            for i in range(int(self.max / 2)):
                temp[i] = self.pilha[i]

            self.pilha = temp

            self.pilha[self.topo] = valor
        else:
            self.pilha[self.topo] = valor

    def desempilhar(self):
        if self.topo == -1:
            print("Pilha vazia")
        else:
            elemento = self.pilha[self.topo]
            self.topo -= 1
            return elemento
        
    def imprimir(self):
        for i in range(self.topo + 1):
            print(self.pilha[i], end=" ")

    def tamanho(self):
        return self.topo + 1