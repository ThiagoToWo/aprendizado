#include <stdio.h> // printf(), scanf()

void main() {
    int ano;

    printf("Insira o ano: ");
    scanf("%d", &ano);

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        printf("O ano %d eh bissexto", ano);
    } else {
        printf("O ano %d nao eh bissexto", ano);
    }
}