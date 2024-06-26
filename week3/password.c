#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char * cmdarg = argv[1];
    int length = atoi(cmdarg);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <length>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (length <= 0) {
        perror("Invalid length");
        exit(EXIT_FAILURE);
    }

    char *password = malloc(length + 1);

    char *digits = "0123456789";
    int digits_length = strlen(digits);

    char *lowers = "abcdefghijklmnopqrstuvwxyz";
    int lowers_length = strlen(lowers);

    char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int uppers_length = strlen(uppers);

    char *symbols = "!@#$%^&*()";
    int symbols_length = strlen(symbols);

    srand(time(NULL) * getpid());

    for (int i = 0; i < length; i++) {
        int char_type = rand() % 4;

        if (char_type == 0) {
            password[i] = digits[rand() % digits_length];
        } else if (char_type == 1) {
            password[i] = lowers[rand() % lowers_length];
        } else if (char_type == 2) {
            password[i] = uppers[rand() % uppers_length];
        } else if (char_type == 3) {
            password[i] = symbols[rand() % symbols_length];
        } else {
            perror("Password generation failed");
            exit(EXIT_FAILURE);
        }
    }

    password[length] = '\0';

    printf("Password: %s\n", password);



    free(password);
}
