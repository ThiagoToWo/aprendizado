int buscar(int x, int vetor[], int n) {
    int min = 0;
    int max = n - 1;
    int med;

    while (min <= max) {
        med = (max + min) / 2;

        if (x == vetor[med]) {
            return med;
        } 

        if (x > vetor[med]) {
            min = med + 1;
        } else {
            max = med - 1;
        }
    }

    return -1;
}