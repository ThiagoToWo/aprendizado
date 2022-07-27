#include <stdio.h>

void main() {
    int A, B, C, D, E;
    A = B = C = D = E = 0;
    int nota;

    do {
        printf("Insira a nota de 0 a 100 (sair = -1): ");
        scanf("%d", &nota);

        if (nota < 0 && nota > -10) // pois dado -10 < nota < -1, nota/10 = 0, contando em E. 
            break; 

        switch (nota / 10) { // divisão de inteiros é inteiro
            case 10: A++; break;
            case 9:
            case 8:
            case 7: B++; break;
            case 6:
            case 5:
            case 4: C++; break;
            case 3:
            case 2:
            case 1: D++; break;
            case 0: E++; break;
            default: printf("Valor fora dos limites\n");
        }
    } while (nota != -1);

    printf("Perfeito (100): %d\n", A);
    printf("Bom (70 a 99): %d\n", B);
    printf("Médio (40 a 69): %d\n", C);
    printf("Ruim (10 a 39): %d\n", D);
    printf("Pessimo (0 a 9): %d\n", E);
    printf("Total: %d", A + B + C + D + E);
}