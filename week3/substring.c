#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int substring(const char* line, const char* substr) {
    int len = strlen(line);
    int sublen = strlen(substr);

    for (int i = 0; i <= len - sublen; i++) {
        int j;
        for (j = 0; j < sublen; j++) {
            if (line[i + j] != substr[j]) {
                break;
            }
        }
        if (j == sublen) {
            return i; // Substring found, return its starting index
        }
    }
    return -1; // Substring not found
}


int main() {
    printf("%d\n", substring("racecar", "car")); //4
    printf("%d\n", substring("telephone", "one")); //6
    printf("%d\n", substring("monkey", "cat")); //-1
    return 0;
}
