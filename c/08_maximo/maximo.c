#include <stdio.h>

void main() {
    int numeros[8] = {5, -1, 3, 7, 4, 3, 18, -5};
    int max = numeros[0];

    int numeros_tamanho = sizeof(numeros) / sizeof(int);

    for (int i = 0; i < numeros_tamanho; i++) {
        if (numeros[i] > max) max = numeros[i];
    }

    printf("%d", max);
}