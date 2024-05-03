#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char buffer[128];
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] == '\n') {
        exit(EXIT_FAILURE);
    }

    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    printf("%s", buffer);

    return 0;

}
