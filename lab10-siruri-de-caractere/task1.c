#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 128

void swapVectors(char *v1, char *v2) {
    char *aux = malloc((strlen(v1)+1) * sizeof(char));
    snprintf(aux, MAX+1, "%s", v1);
    snprintf(v1, MAX+1, "%s", v2);
    snprintf(v2, MAX+1, "%s", aux);
    free(aux);
}

void ordCresc(char *vectorschar[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(vectorschar[i], vectorschar[j]) > 0) {
                swapVectors(vectorschar[i], vectorschar[j]);
            }
        }
    }
}

int main() {
    int n = 0;
    scanf_s("%d", &n);
    getchar();

    char **arr = malloc(n * sizeof(char*));
    for (int i=0; i<n; i++) {
        arr[i] = malloc((MAX+1) * sizeof(char));
    }

    char temp[MAX+1];
    for (int i=0; i<n; i++) {
        fgets(temp, MAX+1, stdin);
        snprintf(arr[i], MAX+1, "%s", temp);
    }

    ordCresc(arr, n);
    for (int i=0; i<n; i++) {
        printf("%s", arr[i]);
    }

    for (int i=0; i<n; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
