#include <stdio.h>
#include <string.h>

void tokenizar(char texto[], char separadores[], char tokens[][20]) {    
    char palavra[20];
    int top = 0;
    int achou = 0;
    int posicao = 0;

    for (int i = 0; i < strlen(texto); i++) {
        for (int j = 0; j < strlen(separadores); j++) {
            if (texto[i] == separadores[j]) {
                achou = 1;
                break;
            }
        }

        if (!achou) {
            palavra[top++] = texto[i];
        } else {
            palavra[top] = '\0';
            strcpy(tokens[posicao], palavra);
            posicao++;
            top = 0;            
            achou = 0;
        }
    }

    palavra[top] = '\0';
    strcpy(tokens[posicao], palavra);
    tokens[posicao + 1][0] = '\0';
}

void main() {
    char texto[128];
    char separadores[20];
    char tokens[128][20];

    printf("Insira um texto (max. 128 palavras): ");
    gets(texto);

    printf("Insira o(s) caractere(s) separadores: ");
    gets(separadores);
    
    tokenizar(texto, separadores, tokens);

    int i = 0;

    while(tokens[i][0] != '\0') {
        printf("%d. %s\n", i, tokens[i]);
        i++;
    }
}