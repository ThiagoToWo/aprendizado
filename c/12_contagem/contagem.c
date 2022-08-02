#include <stdio.h>
#include <string.h>

void main() {
    char texto[256]; // texto de 255 letras
    int num_palavras = 0;
    int num_letras = 0;
    int tamanho = 0;
    int achou_letra;
    char simbolos[] = {' ', ',', '.', ';', ':', '!', '?', '(', ')', '\0'};

    printf("Insra um texto: ");
    gets(texto); // lê linha

    int i = 0;    
    while (texto[i] != '\0') {
        achou_letra = 1;

        if (texto[i] == ' ') {
            num_palavras++;
        }

        for (int j = 0; j < strlen(simbolos); j++) {
            if (texto[i] == simbolos[j]) {
                achou_letra = 0;
                break;
            }
        }

        if (achou_letra) {
            num_letras++;
        }

        i++;
    }

    printf("Esse texto tem %d palavras, %d caracteres, sendo %d deles letras.", num_palavras + 1, i, num_letras);
}