#include <stdio.h> // printf()
#include "lista.h"

void main() {
    printf("%d\n", l_tamanho());

    printf("Empilhar A, B, C e D\n");
    l_empilhar("A");
    l_empilhar("B");
    l_empilhar("C");
    l_empilhar("D");
    l_imprimir(); // A B C D
    printf("%d\n", l_tamanho()); // 4

    printf("Remover da posicao 2\n");
    l_remover(2);
    l_imprimir(); // A B D
    printf("%d\n", l_tamanho()); // 3

    printf("Inserir F na posicao 1\n");
    l_inserir("F", 1);
    l_imprimir(); // A F B D
    printf("%d\n", l_tamanho()); // 4

    printf("Inserir G na posicao 0 e H na posicao 5\n");
    l_inserir("G", 0);
    l_inserir("H", 5);
    l_imprimir(); // G A F B D H
    printf("%d\n", l_tamanho()); // 6

    printf("Remover da posicao 0\n");
    l_remover(0);
    l_imprimir(); // A F B D H
    printf("%d\n", l_tamanho()); // 5

    printf("Remover da posicao 4\n");
    l_remover(4);
    l_imprimir(); // A F B D 
    printf("%d\n", l_tamanho()); // 4

    printf("Remover da posicao 0 duas vezes seguidas\n");
    l_remover(0);
    l_remover(0);
    l_imprimir(); // B D 
    printf("%d\n", l_tamanho()); // 2

    printf("Inserir em ordem A, C e E\n");
    l_inserirEmOrdem("A");
    l_inserirEmOrdem("C");
    l_inserirEmOrdem("E");
    l_imprimir(); // A B C D E
    printf("%d\n", l_tamanho()); // 5

    printf("O valor do elemento na posicao 0 eh %s\n", l_obter(0)->dado ); // A
    printf("O valor do elemento na posicao 2 eh %s\n", l_obter(2)->dado ); // C
    printf("O valor do elemento na posicao 4 eh %s\n", l_obter(4)->dado ); // E
}