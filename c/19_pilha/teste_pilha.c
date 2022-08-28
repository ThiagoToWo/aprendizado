#include <stdio.h> // printf()
#include "pilha.h"

void main() {
    p_criar();
    
    printf("%d\n", p_tamanho());

    printf("Empilhar A, B e C\n");
    p_empilhar('A');
    p_empilhar('B');
    p_empilhar('C');
    p_imprimir(); // A B C
    printf("%d\n", p_tamanho()); // 3

    printf("Desempilhar\n");
    p_desempilhar();
    p_imprimir(); // A B
    printf("%d\n", p_tamanho()); // 2

    printf("Empilhar D\n");
    p_empilhar('D');
    p_imprimir(); // A B D
    printf("%d\n", p_tamanho()); // 3

    printf("Desempilhar\n");
    p_desempilhar();
    p_imprimir(); // A B
    printf("%d\n", p_tamanho()); // 2

    printf("Desempilhar\n");
    p_desempilhar();
    p_imprimir(); // A
    printf("%d\n", p_tamanho()); // 1

    printf("Desempilhar\n");
    p_desempilhar();
    p_imprimir(); //
    printf("%d\n", p_tamanho()); // 0

    printf("Desempilhar\n");
    p_desempilhar(); // Pilha vazia\n
    p_imprimir(); //
    printf("%d\n", p_tamanho()); // 0
}