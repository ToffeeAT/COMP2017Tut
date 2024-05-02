#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int len = strlen(str);
    char* start = str;
    char* end = start + (len - 1);

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char buffer[128];
    fgets(buffer, sizeof(buffer), stdin);
    reverse(buffer);
    printf("%s\n", buffer); // Use %s to print string
    return 0;
}
