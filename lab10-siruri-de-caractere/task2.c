#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 128

void sanitizeInput(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (strchr("!?., ", input[i]) != NULL) {
            snprintf(input+i, MAX+1, "%s", input+i+1);
            i--;
        }
    }
}

int sirPalindrom(char *sir) {
    sanitizeInput(sir);
    unsigned long long len = strlen(sir)-1;
    for (int i=0; i<len/2; i++) {
        if (sir[i] != sir[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char *sir = malloc((MAX+1) * sizeof(char));
    fgets(sir, MAX+1, stdin);

    printf("Sirul %s palindrom.", (sirPalindrom(sir)) ? "este" : "nu este");
    free(sir);
    return 0;
}
