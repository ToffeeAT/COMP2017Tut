#include <stdio.h>

enum TYPE { FIRE, WATER, FLYING, ROCK, ELECTRIC };
struct pokemon {
    const char* name;
    enum TYPE type;
};

void evolve(struct pokemon *mon) {
    mon->name = "Raichu";
    mon->type = ELECTRIC;
}
int main() {
    struct pokemon pikachu = { "Pikachu", ELECTRIC };
    evolve(&pikachu);

    printf("%s\n", pikachu.name);
    printf("%d\n", pikachu.type);

    return 0;
}
