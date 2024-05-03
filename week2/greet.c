#include <stdio.h>

int main() {
    char buffer[128];
    printf("What is your name? ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Yo! %s\n", buffer);
    return 0;
}
