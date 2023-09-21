#include <stdio.h> // printf(), scanf()

void cumprimentar(char pessoa[]) {
    printf("Olá, %s", pessoa);
}

void main() {
    char nome[20];
    printf("Digite seu nome: ");
    scanf("%s", &nome);
	cumprimentar(nome);
}