#include "./utils.h"

#define MAX 128
#define zece 10

int estePalindrom(int64_t nr) {
    int64_t copie = nr, x = 0;
    while (copie) {
        x = x * zece + copie % zece;
        copie /= zece;
    }

    if (x == nr)
        return 1;
    else
        return 0;
}

int estePrim(int64_t nr) {
    int64_t div = 0;
    for (int i = 2; i <= nr/2; i++) {
        if (nr % i == 0) div++;
    }

    if (div == 0)
        return 1;
    else
        return 0;
}

void SolveTask1() {
    int lin = 0, col = 0;
    scanf("%d %d ", &lin, &col);

    int **a = malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++) {
        a[i] = calloc(col, sizeof(int));
    }
    a[0][0] = 1;
    int contor = 2, current_i = 0, current_j = 0;

    char sir[MAX+1];
    fgets(sir, sizeof(sir), stdin);
    char *dummyPtr = NULL;
    char *p = strtok_r(sir, " ", &dummyPtr);

    while (p) {
        if (p[0] == 'a') {
            int maxi = p[1] - '0', maxi_pos = 1;
            for (int i = 2; i < strlen(p); i++) {
                if (p[i] - '0' > maxi) {
                    maxi = p[i] - '0';
                    maxi_pos = i;
                }
            }


            if (maxi_pos == 1) current_j++;
            else if (maxi_pos == 2) current_i--;
            else if (maxi_pos == 3) current_j--;
            else if (maxi_pos == 4) current_i++;

            a[current_i][current_j] = contor;
            contor++;

        } else if (p[0] == 'b') {
            char *dummy = NULL;
            int64_t numar_K = strtol(p + 1, &dummy, zece);
            int64_t numar_X = numar_K % (zece*zece);

            if (estePalindrom(numar_K) && estePrim(numar_X)) current_j--;
            else if (estePalindrom(numar_K) && !estePrim(numar_X)) current_j++;
            else if (!estePalindrom(numar_K) && estePrim(numar_X)) current_i--;
            else if (!estePalindrom(numar_K) && !estePrim(numar_X)) current_i++;

            a[current_i][current_j] = contor;
            contor++;

        } else if (p[0] == 'c') {
            int S = 0, n = p[1] - '0', k = p[2] - '0', indice = 0;
            char aux[MAX+1];
            snprintf(aux, MAX+1, "%s", p+3);

            for (int i = 0; i < k; i++) {
                S += aux[indice] - '0';
                indice += k;
                if (indice >= n)
                    indice %= n;
            }

            if (S % 4 == 0) current_j--;
            else if (S % 4 == 1) current_i--;
            else if (S % 4 == 2) current_j++;
            else if (S % 4 == 3) current_i++;

            a[current_i][current_j] = contor;
            contor++;
        }

        p = strtok_r(NULL, " ", &dummyPtr);
    }
    int i = 0, j = 0;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < lin; i++)
        free(a[i]);
    free(a);
}