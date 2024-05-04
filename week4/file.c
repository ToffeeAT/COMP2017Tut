#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char** argv) {
    FILE *file = fopen("missingo.txt", "r");
    if (file == NULL) {
        perror("unable to open file\n");
    }
    fclose(file);

    FILE *filewrite = fopen("example.txt", "w");
    if (filewrite == NULL) {
        perror("unable to open file\n");
    }
    fprintf(filewrite, "Hello world!\n");
    fclose(filewrite);

    FILE *fileread = fopen("readfile.txt", "r");
    if (fileread == NULL) {
        perror("unable to open file\n");
    }
    char buffer[257];
    while (fscanf(fileread, "%256s", buffer) != EOF) {
        printf("%s\n", buffer);
    }
    fclose(fileread);

    FILE *filereadline = fopen("readfileline.txt", "r");
    if (filereadline == NULL){
        perror("unable to open file\n");
    }
    char bufferx[257];
    while (fgets(bufferx, sizeof(bufferx), filereadline) != NULL) {
        printf("%s", bufferx);
    }
    fclose(filereadline);

    return 0;
}
