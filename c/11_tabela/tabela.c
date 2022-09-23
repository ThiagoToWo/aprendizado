#include <stdio.h> // printf(), scanf()
#include <string.h> // sprintf(), strcat()

void main() {
    int num_linha;
    int num_coluna;    

    printf("Insira a quantidade de linhas da tabela: ");
    scanf("%d", &num_linha);
    printf("Insira a quantidade de colunas da tabela: ");
    scanf("%d", &num_coluna);

    int B = 3;
    char buffer[B];
    char mostra[num_linha * num_coluna * (B - 1) + num_linha + 1];
    mostra[0] = '\0';
    int tabela[num_linha][num_coluna];

    for (int i = 0; i < num_linha; i++) {
       for (int j = 0; j < num_coluna; j++) {
            printf("tabela[%d][%d] = ", i, j);
            scanf("%d", &tabela[i][j]);
            sprintf(buffer, "%d ", tabela[i][j]);
            strcat(mostra, buffer);
       }

       strcat(mostra, "\n");
    } 

    char opcao;  

    do {
        int valores;

        printf("%s", mostra);
        printf("Deseja operar sobre linha (1) ou coluna (2)? ");
        // usando caractere de supressão de atribuição %*c para limpar o buffer de scanf
        scanf("%d%*c", &valores);
        
        if (valores == 1) {
            int linha;
            int total = 0;

            printf("Escolha a linha de 0 ate %d: ", num_linha - 1);
            scanf("%d%*c", &linha);

            if (linha >= 0 && linha < num_linha) {
                for (int i = 0; i < num_coluna; i++) {
                    total += tabela[linha][i];
                }

                printf("O total da linha %d eh %d\n", linha, total);
            } else {
                printf("Valor fora dos limites\n");
            }
        } else if (valores == 2) {
            int coluna;
            int total = 0;

            printf("Escolha a coluna de 0 ate %d: ", num_coluna - 1);
            scanf("%d%*c", &coluna);

            if (coluna >= 0 && coluna < num_coluna) {
                for (int i = 0; i < num_linha; i++) {
                    total += tabela[i][coluna];
                }

                printf("O total da coluna %d eh %d\n", coluna, total);
            } else {
                printf("Valor fora dos limites\n");
            }
        } else {
            printf("Opcao invalida\n");
        }
        
        printf("Deseja sair? (s/n) ");        
        scanf("%c%*c", &opcao); 
    } while (opcao != 's' && opcao != 'S');    
}