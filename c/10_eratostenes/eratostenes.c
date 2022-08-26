#include <stdio.h> // printf(), scanf()

void main() {
    int max;
    int amplitude;

    printf("Insira o limite de teste: ");
    scanf("%d", &max);
    printf("Insira a amplitude de distribuicao: ");
    scanf("%d", &amplitude);

    int primos[max + 1];

    primos[0] = 0;
    primos[1] = 0;

    for (int i = 2; i <= max; i++) {
        primos[i] = 1;
    }

    for (int i = 2; i * i <= max; i++) {
        for (int j = 2 * i; j <= max; j += i) {
            primos[j] = 0;
        }
    }

    for (int i = 2; i <= max; i++) {
        if (primos[i]) {
            printf("%d ", i);
        }
        
        if (i % amplitude == 0) {
            printf("\n");
        }
    }
}