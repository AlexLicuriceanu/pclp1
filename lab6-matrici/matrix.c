#include <stdio.h>

#define N 100


void transpose_matrix(int m[N][N], int n)
{
    int i, j, tmp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}


void print_matrix(int m[N][N], int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void citire (int V[N][N], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            scanf("%d", &V[i][j]);
    }
}

int main(void)
{
    int i, n = 3;
    scanf("%d", &n);

    int V[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    citire(V, n);
    print_matrix(V, n);
    transpose_matrix(V, n);
    print_matrix(V, n);

    int s = 0;
    printf("Suma elem. de deasupra diag. principale: ");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j>i) {
                s += V[i][j];
            }
        }
    }
    printf("%d\n", s);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j+1<n-i)
                V[i][j] = 0;
        }
    }

    print_matrix(V, n);
    return 0;
}