#include <stdio.h>

#define MAX 20

void print_vector(int v[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble_sort(int v[MAX], int dim) {
    for (int i=0; i<dim-1; i++){
        for (int j=0; j<dim-i-1; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

int main() {
    int v[MAX] = {0}, dim = 0;

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0)
            break;
        else {
            v[i] = val;
            dim++;
        }
    }
    bubble_sort(v, dim);
    print_vector(v, dim);
}
