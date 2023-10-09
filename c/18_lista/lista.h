#include <stdio.h> // printf()
#include <stdlib.h> // malloc()
#include <string.h> // strcpy(), strcmp()

struct no {
    char dado[20];
    struct no* proximo;
};

struct no* cabeca = NULL;

int topo = 0;

void l_empilhar(char valor[]) {
    struct no* novo = malloc(sizeof(struct no));
    strcpy(novo->dado, valor);
    novo->proximo = NULL;

    if (topo == 0) {
        cabeca = novo;
    } else {
        struct no* corrente = cabeca;

        while (corrente->proximo != NULL) {
            corrente = corrente->proximo;
        }

        corrente->proximo = novo;
    }

    topo++;
}

struct no* l_obter(int posicao) {
    struct no* elemento = cabeca;

    for (int i = 0; i < posicao; i++) {
        elemento = elemento->proximo;
    }

    return elemento;
}

int l_inserir(char valor[], int posicao) {
    if (posicao >= 0 && posicao <= topo) {
        struct no* novo = malloc(sizeof(struct no));
        strcpy(novo->dado, valor);
        novo->proximo = NULL;

        if (posicao == 0) {
            novo->proximo = cabeca;
            cabeca = novo;
        } else {
            struct no* antecessor = l_obter(posicao - 1);
            struct no* sucessor = antecessor->proximo;

            antecessor->proximo = novo;
            novo->proximo = sucessor;
        }

        topo++;
        return 1;
    }

    return 0;
}

void l_remover(int posicao) {
    if (posicao == 0) {
        cabeca = cabeca->proximo;
    } else {
        struct no* antecessor = l_obter(posicao - 1);
        struct no* corrente = antecessor->proximo;
        struct no* sucessor = corrente->proximo;

        antecessor->proximo = sucessor;
    }

    topo--;
}

void l_imprimir() {
    if (topo > 0) {
        struct no* corrente = cabeca;

        printf("%s ", corrente->dado);

        while (corrente->proximo != NULL) {
            corrente = corrente->proximo;
            printf("%s ", corrente->dado);
        }
    }
}

int l_tamanho() {
    return topo;
}

void l_inserirEmOrdem(char valor[]) {
    struct no* corrente = cabeca;

    if (topo == 0) {
        l_inserir(valor, 0);
        return;
    }

    int i = 0;
    for (; i < topo; i++) {
        if (strcmp(valor, corrente->dado) == -1) {
            break;
        }

        corrente = corrente->proximo;
    }

    l_inserir(valor, i);
}