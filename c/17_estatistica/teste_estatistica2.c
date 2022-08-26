#include <stdio.h>
#include <time.h> // time()
#include <math.h> // sqrt()
#include "estatistica.h"
// gcc estatistica.h teste_estatistica1.c -o teste_estatistica1

void main() {
    int amostra;
    unsigned int semente = time(NULL);

    printf("Insira o tamanho da amostra: ");
    scanf("%d", &amostra);

    int dados[amostra];

    for (int i = 0; i < amostra; i++) {
        dados[i] = (int) (1 + aleatorio(&semente) * 100);
    }

    printf("Dados: ");

    for (int i = 0; i < amostra; i++) {
        printf("%d ", dados[i]);
    }

    printf("\n");

    printf("media = %lf\n", media(dados, amostra));
    printf("mediana = %d\n", mediana(dados, amostra));
    printf("moda = %d\n", moda(dados, amostra));
    printf("desvio padrao = %lf\n", sqrt(variancia(dados, amostra)));
    printf("\nHistograma:\n");

    int freq[amostra];
    frequencia(dados, amostra, freq);

    for (int i = 0; i < amostra; i++) {
        if (dados[i] != dados[i + 1]) {
            printf("%d: ", dados[i]);

            for (int j = 0; j < freq[i]; j++) {
                printf("*");
            }

            printf(" %d\n", freq[i]);
        }
    }

    printf("total = %d", amostra);
}