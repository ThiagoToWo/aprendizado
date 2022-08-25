#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"
#include "../15_ordenacao/ordenacao.h" 
// gcc busca.h ../15_ordenacao/ordenacao.h teste_busca.c -o teste_busca

void main() {
    srand(time(NULL));
    int n = 20;
    int numeros[n];

    for (int i = 0; i < n; i++) {
        numeros[i] = 1 + rand() % 50;
    }

    printf("Numeros: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    ordenar(numeros, n);

    printf("\nNumeros ordenados: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    int m = 4;
    int x;
    int posicao;

    for (int i = 0; i < m; i++) {
        printf("\n");
        x = 1 + rand() % 50;
        posicao = buscar(x, numeros, n);

        if (posicao != -1) {
            printf("O valor %d esta na posicao %d.", x, posicao);
        } else {
            printf("O valor %d nao pertence a lista.", x);
        }
    }
}