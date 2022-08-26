#include <stdio.h> // printf(), scanf()

void main() {
    float total = 0;
    float valor;

    for (int i = 0; i < 10; i++) {
        scanf("%f", &valor);
        total += valor;
    }

    printf("a media eh %f", total / 10);
}