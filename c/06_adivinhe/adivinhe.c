#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  main() {
    srand(time(NULL));
    int random = 1 + rand() % 100; // RAND_MAX = 32767
    int palpite;
    int tentativas = 1;

    do {
        printf("De seu palpite (sair = -1): ");
        scanf("%d", &palpite);

        if (palpite > random) {
            printf("Tente um menor\n");
        } else if (palpite < random) {
            printf("Tente um maior\n");
        } else {
            printf("Acertou!\nForam %d tentativas", tentativas);
            break;
        }

        tentativas++;
    } while (palpite != -1);
    
}