#include <stdio.h>

#define MAX	100

void citire_matr (int v[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            scanf("%d", &v[i][j]);
    }
}

void inm_matr (int v1[MAX][MAX], int lin1, int col1, int v2[MAX][MAX], int lin2, int col2, int v3[MAX][MAX]) {
    for (int i=0; i<lin1; i++) {
        for (int j=0; j<col2; j++)
            v3[i][j] = 0;
    }

    for (int i=0; i<lin1; i++) {
        for (int j=0; j<col2; j++) {
            for(int h=0; h<lin2; h++) {
                v3[i][j] += v1[i][h]*v2[h][j];
            }
        }
    }
}

void afis_matr(int v[MAX][MAX], int lin, int col) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    printf("\n");
}

void cpy_matr (int v1[MAX][MAX], int v2[MAX][MAX], int lin, int col) {
    for (int i=0; i<lin; i++) {
        for (int j=0; j<col; j++)
            v1[i][j] = v2[i][j];
    }
}

int main() {
    int a1[MAX][MAX], lin, col;
    scanf("%d %d\n", &lin, &col);
    citire_matr(a1, lin, col);

    int p=1;
    scanf("%d", &p);

    if (lin==col) {
        int a2[MAX][MAX] = {0}, a3[MAX][MAX] = {0};

        cpy_matr(a2, a1, lin, col);
        for (int i=p; i>1; i--) {
            inm_matr(a1, lin, col, a2, lin, col, a3);
            cpy_matr(a1, a3, lin, col);
        }
        afis_matr(a1, lin, col);
    }
    else printf("Operatie invalida.");

    return 0;
}