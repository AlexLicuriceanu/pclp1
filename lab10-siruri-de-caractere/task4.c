#include <stdio.h>
#include <string.h>

#define MAX 128

void input(char *string, int length) {
    fgets(string, length, stdin);

    for (int i = 0; i <= length; i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
    }
}

int main() {
    char sir[MAX+1], cuv[MAX+1], aux[MAX+1];
    input(sir, MAX+1);
    input(cuv, MAX+1);

    char *dummy, *p = strtok_s(sir, " ", &dummy);
    int k = 0;
    while(p) {
        if (strcmp(cuv, p) == 0) k++;
        p = strtok_s(NULL, " ", &dummy);
    }
    if (k>1)
        printf("Cuvantul apare de %d ori in sir.", k);
    else
        printf("Cuvantul apare o data in sir.");
    return 0;
}
