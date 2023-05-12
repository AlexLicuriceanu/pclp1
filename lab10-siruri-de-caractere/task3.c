#include <stdio.h>
#include <string.h>

#define MAX 128

int main() {
    char sir[MAX+1];
    fgets(sir, MAX+1, stdin);

    char *dummy = NULL, *p = strtok_s(sir, " ", &dummy);
    while (p) {
        printf("%s\n", p);
        p = strtok_s(NULL, " ", &dummy);
    }
    return 0;
}
