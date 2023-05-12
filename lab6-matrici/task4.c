#include <stdio.h>

#define MAX	100

void citire_matr (int v[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            scanf("%d", &v[i][j]);
    }
}

int main() {
    int a[MAX][MAX], lin;
    scanf("%d\n", &lin);
    citire_matr(a, lin, lin);

    for (int i=0; i<lin; i++) {
        for (int j=0; j<lin; j++) {
            if (i<=j && j<lin-i)
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}