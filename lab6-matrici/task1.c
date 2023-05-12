#include <stdio.h>

#define MAX	100

void citire_matr (int v[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            scanf("%d", &v[i][j]);
    }
}

void trnsp_matr (int v[MAX][MAX], int lin, int col) {
    for (int i=0; i<col; i++) {
        for (int j=0; j<lin; j++)
            printf("%d ", v[j][i]);
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], lin, col;
    scanf("%d%d", &lin, &col);
    citire_matr(a, lin, col);

    trnsp_matr(a, lin, col);
    return 0;
}