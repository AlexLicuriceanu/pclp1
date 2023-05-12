#include <stdio.h>

#define MAX	100

void citire_matr (int v[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            scanf("%d", &v[i][j]);
    }
}

int main() {
    int a1[MAX][MAX], lin1, col1;
    scanf("%d %d\n", &lin1, &col1);
    citire_matr(a1, lin1, col1);

    int a2[MAX][MAX], lin2, col2;
    scanf("%d %d\n", &lin2, &col2);
    citire_matr(a2, lin2, col2);

    if (lin2 < lin1 || col2 < col1) {
        printf("Fals.");
        return 0;
    }
    else {
        // bruteforce :^)
        for(int i=0; i<lin2-lin1+1; i++) {
            for(int j=0; j<col2-col1+1; j++) {
                if (a1[0][0] == a2[i][j]) {
                    //debug // printf("Gasit la: %d %d\n", i, j);
                    int ok = 0;
                    for (int p=0; p<lin1; p++) {
                        for (int q=0; q<col2; q++) {
                            if (a1[p][q] == a2[i+p][j+q]) {
                                // debug // printf("Gasit la: %d %d %d\n", i+p, j+q, ok);
                                ok++;
                            }
                            else {
                                break;
                            }
                        }
                    }
                    if (ok==lin1+col1) {
                        printf("Adevarat");
                        return 0;
                    }
                }
            }
        }
    }
    printf("Fals.");
    return 0;
}