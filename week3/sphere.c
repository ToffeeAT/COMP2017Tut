#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char buffer[128];
    float volume;
    printf("Specify the radius of the sphere: ");
    fgets(buffer, sizeof(buffer), stdin);
    float radius = atof(buffer);
    volume = (4.0 / 3.0) * M_PI * pow(radius, 3); 
    printf("Volume: %.2f\n", volume); 
    return 0;
}
