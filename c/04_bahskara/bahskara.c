#include <stdio.h>
#include <math.h>

void main() {
    double a, b, c, d, x1, x2;

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("nao eh uma funcao quadratica");
    } else {
        d = b * b - 4 * a * c;

        if (d == 0) {
            x1 = -b / (2 * a);
            printf("x1 = x2 = %lf", x1);
        } else if (d > 0) {
            x1 = (-b + sqrt(d)) / (2 * a);
            x2 = (-b - sqrt(d)) / (2 * a); 
            printf("x1 = %lf e x2 = %lf", x1, x2);
        } else {
            printf("nao possui raizes reais");
        }
    }
}