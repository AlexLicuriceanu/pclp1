#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int randomNumber(unsigned int low, unsigned int high) {	// :^)
    return (rand() % (high-low+1) + low);
}

void printVector(unsigned int *vec, unsigned int dim) {
    for (int i=0; i<dim; i++)
        printf("%u ", vec[i]);
    printf("\n");
}

void sortVector(unsigned int *vec, unsigned int dim) {
    for (int i=0; i<dim; i++) {
        for (int j=i+1; j<dim; j++) {
            if (*(vec+j) < *(vec+i)) {
                unsigned int aux = *(vec+i);
                *(vec+i) = *(vec+j);
                *(vec+j) = aux;
            }
        }
    }
}

int main() {
    unsigned int n, max;
    scanf_s("%u%u", &n, &max);

    srand(time(NULL));
    unsigned int *v = calloc(n, sizeof(unsigned int));
    for (int i=0; i<n; i++) {
        v[i] = randomNumber(0, max);
    }

    printVector(v, n);
    sortVector(v, n);
    printVector(v, n);

    free(v);
    return 0;
}
