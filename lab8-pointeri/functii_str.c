#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LIN 10

int str_length(char *sir) {
    int i = 0, len = 0;
    while (sir[i] != '\0') {
        len++;
        i++;
    }
    return len-1;
}

char *strdel(char *sir, int pos, int n) {
    if (n == 0)
        return sir;

    int len = str_length(sir);
    if (n < 0 || pos < 0 || pos+n > len)
        return NULL;

    int rezlen = len-n+1;
    char *rez = malloc(rezlen * sizeof(char));
    if (rez == NULL)
        return NULL;

    char *addr = rez;
    for (int i=0; i<pos; i++) {
        *addr++ = sir[i];
    }
    for (int i=pos+n; i<str_length(sir); i++) {
        *addr++ = sir[i];
    }

    *addr='\0';
    return rez;
}

char *strins(char *s1, int pos, char *s2) {
    if (pos <  0) pos = 0;
    if (pos > str_length(s1)) pos = str_length(s1);

    char *addr  = s1 + pos;
    memmove(addr + str_length(s2), addr, str_length(s1) - pos);
    memcpy (addr, s2, str_length(s2));
    return s1;
}

int eq_mask(char *sir, char *mask) {
    if (str_length(sir) == str_length(mask)) {
        for (int i=0; i< str_length(sir); i++) {
            if (!(sir[i] == mask[i] || mask[i] == '?'))
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

int eqcuv(char *cuv, char **tablou) {
    for (int i=0; tablou[i]; i++) {
        if (strcmp(cuv, tablou[i]) == 0) return 1;
    }
    return 0;
}
