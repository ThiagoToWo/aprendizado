#include <stdio.h> // printf()
#include <stdlib.h> // malloc(), realloc()

int max = 100;
char* pilha;
int topo = -1;

void p_criar() {
    pilha = malloc(max);
}

void p_empilhar(char valor) {
    topo++;

    if (topo == max) {
        max *= 2;
        pilha = realloc(pilha, max);

        pilha[topo] = valor;
    } else {
        pilha[topo] = valor;
    }
}

char p_desempilhar() {
    if (topo == -1) {
        printf("Pilha vazia\n");
    } else {
        char elemento = pilha[topo];
        topo--;
        return elemento;
    }
}

void p_imprimir() {
    for (int i = 0; i <= topo; i++) {
        printf("%c ", pilha[i]);
    }
}

int p_tamanho() {
    return topo + 1;
}