#include <stdio.h> // printf(), scanf()

void main() {
    char nome[20];
    printf("Digite seu nome: ");
    scanf("%s", &nome);
	printf("Olá, %s", nome);
}