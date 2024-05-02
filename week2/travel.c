#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DIVISOR 1.6099344
// formula km/DIVISOR

int main() {
    char currentspeed[128];
    char hourstravelling[128];
    printf("Enter current speed in km.h\n");
    fgets(currentspeed, sizeof(currentspeed), stdin);
    if (currentspeed[0] == '\n') {
        exit(EXIT_FAILURE);
    }
    float speed_kmh = atof(currentspeed);

    printf("Enter amount of time you will be travelling in hours\n");
    fgets(hourstravelling, sizeof(hourstravelling), stdin);
    if (hourstravelling[0] == '\n') {
        exit(EXIT_FAILURE);
    }
    float hours = atof(hourstravelling);

    float mph = speed_kmh / DIVISOR;

    float total_distance_mph = mph * hours;
    float total_distance_kmh = speed_kmh * hours;

    printf("You will cover: %.2f km (%.2f mi)", total_distance_kmh, total_distance_mph);
    printf("While travelling at %2f km/h (%.2f mph)", speed_kmh, mph);
}
