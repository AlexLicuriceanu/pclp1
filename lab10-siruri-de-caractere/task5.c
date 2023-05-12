#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char *strrep_s(char *sir, char *find, char *replace) {
    char *final = malloc((strlen(sir)-strlen(find)+strlen(replace)+1) * sizeof(char));
    strcpy(final, sir);

    char *p = strstr(final, find);
    if (p) {
        memmove(p+strlen(replace), p+strlen(find), strlen(p+strlen(find))+1);
        strncpy(p, replace, strlen(replace));
    }

    return final;
}

int main() {
    char sir[MAX+1], cuv[MAX+1], inlocuitor[MAX+1];
    input(sir, MAX+1);
    input(cuv, MAX+1);
    input(inlocuitor, MAX+1);

    printf("%s", strrep_s(sir, cuv, inlocuitor));
    return 0;
}
