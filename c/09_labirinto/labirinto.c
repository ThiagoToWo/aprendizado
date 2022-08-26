#include <stdio.h> // printf(), scanf()
#define LINHA_TAMANHO  12
#define COLUNA_TAMANHO  12

void main() {    
    char mapa[LINHA_TAMANHO][COLUNA_TAMANHO] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'@', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    int linha = 2;
    int coluna = 0;
    int direcao;

    do {
        for (int i = 0; i < LINHA_TAMANHO; i++) {
            for (int j = 0; j < COLUNA_TAMANHO; j++) {
                printf("%c", mapa[i][j]);
            }

            printf("\n");
        }

        printf("Escolha a direcao (esquerda = 4, cima = 8, direita = 6, baixo = 2, fechar = 0): ");
        scanf("%d", &direcao);

        switch (direcao) {
            case 4:
                if ((coluna - 1) >= 0 && mapa[linha][coluna - 1] == '.') {
                    mapa[linha][coluna] = '.';
                    coluna--;
                    mapa[linha][coluna] = '@';
                }

                break;
            case 8:
                if ((linha - 1) >= 0 && mapa[linha - 1][coluna] == '.') {
                    mapa[linha][coluna] = '.';
                    linha--;
                    mapa[linha][coluna] = '@';
                }

                break;
            case 6:
                if ((coluna + 1) < COLUNA_TAMANHO && mapa[linha][coluna + 1] == '.') {
                    mapa[linha][coluna] = '.';
                    coluna++;
                    mapa[linha][coluna] = '@';
                }

                break;
            case 2:
                if ((linha + 1) < LINHA_TAMANHO && mapa[linha + 1][coluna] == '.') {
                    mapa[linha][coluna] = '.';
                    linha++;
                    mapa[linha][coluna] = '@';
                }

                break;
            default:
                if (direcao == 0) {
                    printf("Fechando o jogo");
                    break;
                }

                printf("Valor invalido\n");
        }
    } while (direcao != 0);
}