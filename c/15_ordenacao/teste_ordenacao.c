#include <stdio.h> // printf()
#include <stdlib.h> // srand(), rand()
#include <time.h> // time()
#include "ordenacao.h" // ordenar()

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