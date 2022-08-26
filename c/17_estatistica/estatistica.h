#include <limits.h> // UINT_MAX
#include "..\15_ordenacao\ordenacao.h" // não precisa incluir na hora de compilar

double media(int vetor[], int n) {
    double soma = 0;

    for (int i = 0; i < n; i++) {
        soma += vetor[i];
    }

    return soma / n;
}

int mediana(int vetor[], int n) {
    ordenar(vetor, n);

    if (n % 2 != 0) {
        return vetor[(n + 1) / 2 - 1];
    } else {
        return (vetor[n / 2 - 1] + vetor[n / 2]) / 2;
    }
}

void frequencia(int vetor[], int n, int f[]) { 
    for (int i = 0; i < n; i++) f[i] = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[i] == vetor[j]) {
                f[i]++;
                f[j]++;
            }
        }
    }
}

int maximo(int vetor[], int n) {
    double max = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    return max;
} 

int minimo(int vetor[], int n) {
    double min = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] < min) {
            min = vetor[i];
        }
    }

    return min;
}

int moda(int vetor[], int n) {
    int freq[n];
    frequencia(vetor, n, freq);
    double max = maximo(freq, n);
    double moda;

    for (int i = 0; i < n; i++) {
        if (freq[i] == max) {
            moda = vetor[i];
            break;
        }
    }

    return moda;
}

double variancia(int vetor[], int n) {
    double m = media(vetor, n);
    double d2 = 0;

    for (int i = 0; i < n; i++) {
        d2 += (vetor[i] - m) * (vetor[i] - m);
    }

    return d2 / n;
}

double aleatorio(unsigned int* semente) {
    int iteracao = *semente % 37;

    for (int i = 0; i <= iteracao; i++) {
        *semente = (314159265 * *semente + 13579) % UINT_MAX;
    }

    return (double) *semente / UINT_MAX;
}