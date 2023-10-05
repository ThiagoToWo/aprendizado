class Fila:
    def __init__(self):
        self.max = 100
        self.fila = [None]*self.max
        self.fim = 0
        self.inicio = 0

    def inserir(self, valor):
        if self.fim == self.max:
            self.max *= 2
            temp = [None]*self.max

            for i in range(self.inicio, int(self.max / 2)):
                temp[i - self.inicio] = self.fila[i]

            self.fila = temp
            self.inicio = 0
            self.fila[self.fim] = valor
        else:
            self.fila[self.fim] = valor

        self.fim += 1

    def remover(self):
        if self.fim == self.inicio:
            print("Fila vazia")
        else:
            elemento = self.fila[self.inicio]
            self.inicio += 1
            return elemento
        
    def imprimir(self):
        for i in range(self.inicio, self.fim):
            print(self.fila[i], end=" ")

    def tamanho(self):
        return self.fim - self.inicio