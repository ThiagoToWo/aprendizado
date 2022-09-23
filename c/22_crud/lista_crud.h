#include <stdio.h> // printf(), FILE, fopen(), fwrite(), ferror(), fclose()
#include <stdlib.h> // malloc(), free()
#include <string.h> // strcmp()

FILE* arquivo;

struct produto {
    char nome[20];
    float preco;
    struct produto* proximo;
};

struct produto* cabeca;
int topo = 0;

struct produto* l_obter(int posicao) {
    struct produto* elemento = cabeca;

    for (int i = 0; i < posicao; i++) {
        elemento = elemento->proximo;
    }

    return elemento;
}

int l_inserir(struct produto* novo, int posicao) {
    if (posicao >= 0 && posicao <= topo) {
        if (posicao == 0) {
            novo->proximo = cabeca;
            cabeca = novo;
        } else {
            struct produto* antecessor = l_obter(posicao - 1);
            struct produto* sucessor = antecessor->proximo;

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
        struct produto* antecessor = l_obter(posicao - 1);
        struct produto* corrente = antecessor->proximo;
        struct produto* sucessor = corrente->proximo;

        antecessor->proximo = sucessor;
    }

    topo--;
}

void l_inserirEmOrdem(struct produto* novo) {
    struct produto* corrente = cabeca;

    if (topo == 0) {
        l_inserir(novo, 0);
        return;
    }

    int i = 0;
    for (; i < topo; i++) {
        if (strcmp(novo->nome, corrente->nome) < 0) {
            break;
        }

        corrente = corrente->proximo;
    }

    l_inserir(novo, i);
}

void l_imprimir() {
    if (topo > 0) {
        int i = 1;
        struct produto* corrente = cabeca;

        printf("-------itens-------\n");

        do {
            printf("%d. %s: %f\n", i, corrente->nome, corrente->preco);
            corrente = corrente->proximo;
            i++;
        } while (corrente != NULL);
    }
}

void l_salvar() {
    arquivo = fopen("produtos.dat", "wb");

    if (!arquivo) {
        printf("Erro na abertura do arquivo\n");
    } else {
        struct produto* corrente = cabeca;

        while(corrente != NULL) {
            fwrite(corrente, sizeof(struct produto), 1, arquivo);
            corrente = corrente->proximo;
        }        

        if (ferror(arquivo)) {
            printf("Erro na gravacao do arquivo\n");
        } else {
            printf("Gravacao efetuada com sucesso\n");
        }

        fclose(arquivo);
    }
}

void l_carregar() {
    arquivo = fopen("produtos.dat", "rb");

    if (!arquivo) {
        printf("Erro na abertura do arquivo\n");
    } else {
        struct produto* corrente;
        cabeca = NULL;
        topo = 0;
        
        corrente = malloc(sizeof(struct produto));        
        
        while (fread(corrente, sizeof(struct produto), 1, arquivo)) { 
            corrente->proximo = NULL;  
            l_inserirEmOrdem(corrente);         
            corrente = malloc(sizeof(struct produto));            
        }

        if (ferror(arquivo)) {
            printf("Erro na leitura do arquivo\n");
        } else {
            printf("Leitura efetuada com sucesso\n");
        }
        
        fclose(arquivo);
    }
}