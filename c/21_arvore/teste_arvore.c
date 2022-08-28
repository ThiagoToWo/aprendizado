#include <stdio.h> // printf()
#include "arvore.h"

void main() {
    void imprimir(int valor) {
        printf("%d ", valor);
    }

    void metade(int valor) {
        printf("%d ", valor / 2);
    }

    printf("Inserir 10, 6, 14, 4, 8, 12, 2, 20, 18, 26\n");
    a_inserir(10);
    a_inserir(6);
    a_inserir(14);
    a_inserir(4);
    a_inserir(8);
    a_inserir(12);
    a_inserir(2);
    a_inserir(20);
    a_inserir(18);
    a_inserir(26);

    printf("Em ordem: ");
    a_emOrdem(imprimir); // 2 4 6 8 10 12 14 18 20 26
    printf("\n");
    printf("Em pre ordem: ");
    a_preOrdem(imprimir); // 10 6 4 2 8 14 12 20 18 26
    printf("\n");
    printf("Em pos ordem: ");
    a_posOrdem(imprimir); // 2 4 8 6 12 18 26 20 14 10
    printf("\n");

    printf("O valor 3 esta na arvore? %d\n", a_pesquisar(3)); // falso = 0
    printf("O valor 4 esta na arvore? %d\n", a_pesquisar(4)); // verdadeiro = 1

    printf("Remover 4 (somente um filho esquerdo)\n");
    a_remover(4);
    printf("Remover 14 (com dois filhos)\n");
    a_remover(14);
    printf("Remover 20 (somente um filho direito)\n");
    a_remover(20);
    printf("Remover 12 (sem filhos)\n");
    a_remover(12);

    printf("Em ordem: ");
    a_emOrdem(imprimir); // 2 6 8 10 18 26
    printf("\n");
    printf("Em pre ordem: ");
    a_preOrdem(imprimir); // 10 6 2 8 18 26
    printf("\n");
    printf("Em pos ordem: ");
    a_posOrdem(imprimir); // 2 8 6 26 18 10
    printf("\n");

    printf("O valor 4 esta na arvore? %d\n", a_pesquisar(4)); // falso = 0

    printf("O menor valor e %d\n", a_min()->dado); // 2
    printf("O maior valor e %d\n", a_max()->dado); // 26

    printf("A metade dos valores em ordem: ");
    a_emOrdem(metade); // 1 3 4 5 9 13
}