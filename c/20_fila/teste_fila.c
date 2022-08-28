#include <stdio.h> // printf()
#include "fila.h"

void main() {
    f_criar();
    
    printf("%d\n", f_tamanho());

    printf("Inserir A, B e C\n");
    f_inserir('A');
    f_inserir('B');
    f_inserir('C');
    f_imprimir(); // A B C
    printf("%d\n", f_tamanho()); // 3

    printf("Remover\n");
    f_remover();
    f_imprimir(); // B C
    printf("%d\n", f_tamanho()); // 2

    printf("Inserir D\n");
    f_inserir('D');
    f_imprimir(); // B C D
    printf("%d\n", f_tamanho()); // 3

    printf("Remover\n");
    f_remover();
    f_imprimir(); // C D
    printf("%d\n", f_tamanho()); // 2

    printf("Remover\n");
    f_remover();
    f_imprimir(); // D
    printf("%d\n", f_tamanho()); // 1

    printf("Remover\n");
    f_remover();
    f_imprimir(); //
    printf("%d\n", f_tamanho()); // 0

    printf("Remover\n");
    f_remover(); // Fila vazia\n
    f_imprimir(); //
    printf("%d\n", f_tamanho()); // 0
}