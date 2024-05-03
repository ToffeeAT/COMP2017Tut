#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void processing(char *batter, char **first_names, char **last_names, int *runs_scored, int index);

int main() {
    char num[128];
    bool num_check = true;
    char *first_names[10];
    char *last_names[10];
    int runs_scored[10];
    int num_batters;

    printf("Enter number of batters: ");
    while (num_check) {
        fgets(num, sizeof(num), stdin);
        num_batters = strtol(num, NULL, 10);
        if (num_batters > 10 || num_batters <= 0) {
            printf("Invalid number of batters. Please enter a number between 1 and 10.\n");
        } else {
            num_check = false;
        }
    }

    for (int i = 0; i < num_batters; i++) {
        char buffer[128];
        printf("Enter Name and Score for batter %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        processing(buffer, first_names, last_names, runs_scored, i);
    }

    for (int i = 0; i < num_batters; i++) {
        printf("Batter %d: %s %s, Runs Scored: %d\n", i, first_names[i], last_names[i], runs_scored[i]);
    }

    return 0;
}

void processing(char *batter, char **first_names, char **last_names, int *runs_scored, int index) {
    char first_name[128];
    char last_name[128];
    int runs;
    int fields_read = sscanf(batter, "%s %s %d", first_name, last_name, &runs);

    // Check the number of fields read
    switch (fields_read) {
        case 3: // All three fields read
            first_names[index] = strdup(first_name);
            last_names[index] = strdup(last_name);
            runs_scored[index] = runs;
            break;
        case 2: // Only first name and last name provided
            first_names[index] = strdup(first_name);
            last_names[index] = strdup(last_name);
            runs_scored[index] = 0; // Default value for runs scored
            break;
        case 1: // Only first name provided
            first_names[index] = strdup(first_name);
            last_names[index] = ""; // Empty string for last name
            runs_scored[index] = 0; // Default value for runs scored
            break;
        default: // No fields read or error
            first_names[index] = "";
            last_names[index] = "";
            runs_scored[index] = 0;
            break;
    }
}
