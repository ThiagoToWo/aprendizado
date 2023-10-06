#include <stdio.h> // printf(), gets(), scanf()
#include <stdlib.h> // malloc()
#include <string.h> // strcpy()
#include "lista_crud.h"

void adicionar();
void listar();
void editar();
void remover();
void carregar();
void salvar();

void main() {
    int opcao;

    do {
        printf("Escolha uma opcao:\n"
            "\t1 - Adicionar\t5 - Carregar\n"
            "\t2 - Listar\t6 - Salvar\n"
            "\t3 - Editar\t7 - Sair\n"
            "\t4 - Remover\n\n"             
            "Sua escolha: ");

        scanf("%d%*c", &opcao);        

        switch (opcao) {
            case 1: adicionar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: remover(); break;
            case 5: carregar(); break;
            case 6: salvar(); break;
            case 7: break;
            default: printf("Valor invalido\n");
        }
    } while (opcao != 7);
}

void adicionar() {
    char opcao;

    do {        
        char nome[20];
        float preco;

        printf("Insira o nome do produto: ");
        gets(nome);
        printf("Insira o preco do produto: ");
        scanf("%f%*c", &preco);        

        struct produto* novo = malloc(sizeof(struct produto));
        strcpy(novo->nome, nome);
        novo->preco = preco;
        novo->proximo = NULL;

        l_inserirEmOrdem(novo);

        printf("Deseja incluir outro produto?(s/n) ");
        scanf("%c%*c", &opcao);        
    } while (opcao == 's' || opcao == 'S');
}

void listar() {
    l_imprimir();
}

void editar() {
    char opcao;

    do {        
        int indice;
        int atributo;
        char novo_nome[20];
        float novo_preco;

        printf("Insira o indice do produto a ser editado (voltar = 0): ");
        scanf("%d%*c", &indice);        

        if (indice == 0) break;
        if (indice < 0 || indice > topo) continue;

        printf("Insira o numero do atributo a ser editado\n"
            "\t1 - nome\t2 - preco\n\t3 - menu inicial\n\n"
            "Sua escolha: ");
        scanf("%d%*c", &atributo);        

        switch (atributo) {
            case 1:
                printf("Digite o novo nome: ");
                gets(novo_nome);
                strcpy(l_obter(indice - 1)->nome, novo_nome);
                break;
            case 2:
                printf("Digite o novo preco: ");
                scanf("%f%*c", &novo_preco);                
                l_obter(indice - 1)->preco = novo_preco;
                break;
            case 3: return;
            default: printf("Valor invalido\n");
        }

        printf("Deseja editar outro produto?(s/n) ");
        scanf("%c%*c", &opcao);        
    } while (opcao == 's' || opcao == 'S');
}

void remover() {
    char opcao;

    do {
        int indice;

        printf("Insira o indice dom produto a ser exclido (voltar = 0): ");
        scanf("%d%*c", &indice);        

        if (indice == 0) break;
        if (indice < 0 || indice > topo) continue;

        l_remover(indice - 1);

        printf("Deseja excluir outro produto?(s/n) ");
        scanf("%c%*c", &opcao);        
    } while (opcao == 's' || opcao == 'S');
}

void carregar() {
    l_carregar();
}

void salvar() {
    l_salvar();
}