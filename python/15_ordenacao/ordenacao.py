def ordenar(vetor, n):
    for i in range(1, n):
        for j in range(n - i):
            if vetor[j] > vetor[j + 1]:
                temp = vetor[j]
                vetor[j] = vetor[j + 1]
                vetor[j + 1] = temp