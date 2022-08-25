#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void main() {
    srand(time(NULL));
    int n = 20;
    int numeros[n]; 

    for (int i = 0; i < n; i++) {
        numeros[i] = 1 + rand() % 100;
    }

    printf("Antes de ordenar: ");

    for (int i = 0; i < n; i++) {
        printf("%d ",numeros[i]);
    }

    ordenar(numeros, n);

    printf("\nDepois de ordenar: ");

    for (int i = 0; i < n; i++) {
        printf("%d ",numeros[i]);
    }
}