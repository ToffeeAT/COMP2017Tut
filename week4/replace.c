#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void replaceSubString(char *s, const char *oldword, const char *newword);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: <oldfilename> <newfilename> <oldword> <newword>\n");
        return 1;
    }

    char oldfilename[128];
    char newfilename[128];
    char oldword[128];
    char newword[128];

    strncpy(oldfilename, argv[1], sizeof(oldfilename));
    strncpy(newfilename, argv[2], sizeof(newfilename));
    strncpy(oldword, argv[3], sizeof(oldword));
    strncpy(newword, argv[4], sizeof(newword));

    FILE *oldfile = fopen(oldfilename, "r");
    if (oldfile == NULL) {
        fprintf(stderr, "Unable to open old file: %s\n", oldfilename);
        return 1;
    }

    FILE *newfile = fopen(newfilename, "w");
    if (newfile == NULL) {
        fprintf(stderr, "Unable to open new file: %s\n", newfilename);
        fclose(oldfile);
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), oldfile) != NULL) {
        replaceSubString(buffer, oldword, newword);
        fputs(buffer, newfile);
    }

    fclose(oldfile);
    fclose(newfile);
    return 0;
}

void replaceSubString(char *s, const char *oldword, const char *newword) {
    char *pos = s;
    while((pos = strstr(pos, oldword)) != NULL) {
        if ((pos == s || !isalpha(*(pos - 1))) && !isalpha(*(pos + strlen(oldword)))) {
            memmove(pos + strlen(newword), pos + strlen(oldword), strlen(pos + strlen(oldword)) + 1);
            memcpy(pos, newword, strlen(newword));
            pos += strlen(newword);
        } else {
            pos += strlen(oldword);
        }

    }
}
