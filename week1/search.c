#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char buffer[128];

    // Read the input string from stdin
    fgets(buffer, sizeof(buffer), stdin);

    fp = fopen("resteraunts.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        // Remove the newline character from the line, if present
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        // Find if buffer exists in the current line
        if (strstr(line, buffer) != NULL) {
            // If found, print the line
            printf("%s\n", line);
        }
    }

    fclose(fp);
    if (line != NULL)
        free(line);
    exit(EXIT_SUCCESS);
}
