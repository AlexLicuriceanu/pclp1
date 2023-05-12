#include <stdio.h>

#define MAX 20

void print_vector(int v[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[MAX] = {0};

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0)
            break;
        else
            v[i] = val;
    }

    int k = 0;
    for (int i=0; i<MAX; i++) {
        if (v[i]%2) {
            printf("%d : %d\n", i, v[i]);
            k++;
        }
    }
    printf("Nr. elem. impare: %d", k);
    return 0;
}
