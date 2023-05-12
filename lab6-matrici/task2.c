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

int main() {
    int a1[MAX][MAX], lin1, col1;
    scanf("%d %d\n", &lin1, &col1);
    citire_matr(a1, lin1, col1);

    int a2[MAX][MAX], lin2, col2;
    scanf("%d %d\n", &lin2, &col2);
    citire_matr(a2, lin2, col2);
    
    if (lin1!=col2 && lin2!=col1) {
        printf("Nu se pot inmulti.");
        return 0;
    }
    
    if (lin1==col2) {
        int a3[MAX][MAX] = {0};
        printf("A * B:\n");
        inm_matr(a1, lin1, col1, a2, lin2, col2, a3);
        afis_matr(a3, lin1, col2);
    }
    if (lin2==col1) {
        int a3[MAX][MAX] = {0};
        printf("B * A:\n");
        inm_matr(a2, lin2, col2, a1, lin1, col1, a3);
        afis_matr(a3, lin2, col1);
    }
    
    return 0;
}
