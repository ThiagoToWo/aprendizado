#include <stdio.h>

void main() {
    int n = 0;
    float total = 0;
    float valor;

    scanf("%f", &valor);

    while (valor != -1) {       
        total += valor;
        n++;
        scanf("%f", &valor);     
    }

    printf("a media eh %f", total / n);
}