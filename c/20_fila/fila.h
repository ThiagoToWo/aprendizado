#include <stdio.h> // printf()
#include <stdlib.h> // malloc(), realloc()

int max = 100;
char* fila;
int fim = 0;
int inicio = 0;

void f_criar() {
    fila = malloc(max);
}

void f_inserir(char valor) {
    if (fim == max) {
        max *= 2;
        fila = realloc(fila, max);

        fila[fim] = valor;
    } else {
        fila[fim] = valor;
    }

    fim++;
}

char f_remover() {
    if (fim == inicio) {
        printf("Fila vazia\n");
    } else {
        char elemento = fila[inicio];
        inicio++;
        return elemento;
    }
}

void f_imprimir() {
    for (int i = inicio; i < fim; i++) {
        printf("%c ", fila[i]);
    }
}

int f_tamanho() {
    return fim - inicio;
}