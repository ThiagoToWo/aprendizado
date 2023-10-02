from math import floor

def buscar(x, vetor, n):
    min = 0
    max = n - 1
    
    while min <= max:
        med = floor((max + min) / 2)
        
        if x == vetor[med]:
            return med        
        
        if x > vetor[med]:
            min = med + 1
        else:
            max = med - 1   
    
    return -1