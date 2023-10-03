from .ordenacao import ordenar

def media(vetor, n):
    soma = 0

    for i in range(n):
        soma += vetor[i]

    return soma / n

def mediana(vetor, n):
    ordenar(vetor, n)

    if n % 2 != 0:
        return vetor[int((n + 1) / 2) - 1] # toda divisão resulta em float, mas índices são int
    else:
        return (vetor[int(n / 2) - 1] + vetor[int(n / 2)]) / 2
    
def frequencia(vetor, n):
    f = [None]*n

    for i in range(n - 1):
        for j in range(i + 1, n):
            if f[i] == None:
                f[i] = 1

            if f[j] == None:
                f[j] = 1

            if vetor[i] == vetor[j]:
                f[i] += 1
                f[j] += 1

    return f

def maximo(vetor, n):
    max = vetor[0]
    
    for i in range(n): 
        if vetor[i] > max:
            max = vetor[i]   
    
    return max

def minimo(vetor, n):
    min = vetor[0]
    
    for i in range(n): 
        if vetor[i] < min:
            min = vetor[i]   
    
    return min

def moda(vetor, n):
    freq = frequencia(vetor, n)
    max = maximo(freq, n)

    for i in range(n):
        if freq[i] == max:
            moda = vetor[i]
            break
    
    return moda

def variancia(vetor, n):
    m = media(vetor, n)
    d2 = 0

    for i in range(n):
        d2 += (vetor[i] - m) * (vetor[i] - m)    
    
    return d2 / n

def aleatorio(semente):
    iteracao = int(semente.valor % 37) # iteradores devem ser inteiros

    for i in range(iteracao + 1):
        semente.valor = (314159265 * semente.valor + 13579) % (2e31 - 1) # Python não tem limite de valor

    return semente.valor / (2e31 - 1)