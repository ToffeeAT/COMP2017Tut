#include <stdio.h>

int string_compare(const char *w1, const char *w2, unsigned int len) {
    const char* startw1 = w1;
    const char* startw2 = w2;

    for (unsigned int i = 0; i < len; i++) {
        printf("string 1: %c , string 2: %c\n", *startw1, *startw2);
        startw1++;
        startw2++;
    }
    return 0;
}

int main() {
    string_compare("Hello", "Goodbye", 4);
    return 0;
}
