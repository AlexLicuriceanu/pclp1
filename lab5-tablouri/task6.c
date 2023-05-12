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
    int v1[MAX] = {0}, v2[MAX] = {0}, dim1 = 0, dim2 = 0;

    /* int v1[] = {1, 3, 3, 5, 6, 7}, dim1 = 6;
     * int v2[] = {2, 3, 4, 4, 8}, dim2 = 5;
     */

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0)
            break;
        else {
            v1[i] = val;
            dim1++;
        }
    }

    for (int i=0; i<MAX; i++) {
        int val;
        scanf("%d", &val);

        if (val <= 0) break;
        else {
            v2[i] = val;
            dim2++;
        }
    }
    bubble_sort(v1, dim1);
    bubble_sort(v2, dim2);

    int v3[MAX*2] = {0}, i=0, j=0, k=0;
    while (i < dim1 && j < dim2)
        if (v1[i] < v2[j])
            v3[k++] = v1[i++];
        else
            v3[k++] = v2[j++];
    while (i < dim1)
        v3[k++] = v1[i++];
    while (j < dim2)
        v3[k++] = v2[j++];

    print_vector(v3, dim1+dim2);
    return 0;
}
