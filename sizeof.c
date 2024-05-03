#include <stdio.h>
#include <stdint.h>

int main() {
    int a;
    int* b = &a;
    int* c = NULL;
    unsigned d;
    short e;
    long f;
    size_t g;
    long long h;
    uint8_t i;
    uint32_t j;
    struct quoll {
        char name[20];
        uint8_t age;
    };
    struct quokka {
        char* name;
        struct quokka* quokka_father;
        struct quokka* quokka_mother;
    };
    union mammal {
        struct quoll l;
        struct quokka a;
    };

    printf("Size of int: %zu bytes\n", sizeof(a));
    printf("Size of int pointer: %zu bytes\n", sizeof(b));
    printf("Size of NULL pointer: %zu bytes\n", sizeof(c));
    printf("Size of unsigned int: %zu bytes\n", sizeof(d));
    printf("Size of short: %zu bytes\n", sizeof(e));
    printf("Size of long: %zu bytes\n", sizeof(f));
    printf("Size of size_t: %zu bytes\n", sizeof(g));
    printf("Size of long long: %zu bytes\n", sizeof(h));
    printf("Size of uint8_t: %zu bytes\n", sizeof(i));
    printf("Size of uint32_t: %zu bytes\n", sizeof(j));
    printf("Size of struct quoll: %zu bytes\n", sizeof(struct quoll));
    printf("Size of struct quokka: %zu bytes\n", sizeof(struct quokka));
    printf("Size of union mammal: %zu bytes\n", sizeof(union mammal));

    return 0;
}
