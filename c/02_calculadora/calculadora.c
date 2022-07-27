#include <stdio.h>

void main() {
    int a;
    int b;

    printf("Insira o valor de a: ");
    scanf("%d", &a);
    printf("Insira o valor de b: ");
    scanf("%d", &b);

    printf("soma = %d\n", a + b);
    printf("diferenca = %d\n", a - b);
    printf("produto = %d\n", a * b);
    printf("quociente = %d\n", a / b);

    if (a > b) {
        printf("%d > %d\n", a, b);
    } else if (a == b) {
        printf("%d = %d\n", a, b);
    } else {
        printf("%d < %d\n", a, b);
    }

    if (a > 0 && a < 10) {
        printf("0 < %d < 10\n", a);
    } else if (a < 0 || a > 10) {
        printf("%d < 0 ou %d > 10\n", a, a);
    } else {
        printf("%d = 0 ou %d = 10\n", a, a);
    }
}