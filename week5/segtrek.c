#include <stdio.h>
#include <stdlib.h>

int main() {
    // Correct allocation size
    int* a = (int*)malloc(sizeof(int) * (1 << 3));
    int* b = (int*)malloc(sizeof(int) * 9);
    
    // Check if allocations are successful
    if (a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (size_t i = 0; i < 9; i++) {
        // Access array elements within bounds
        if (i < 8)
            a[i] = i >> 1;
        b[i] = i + ~i;
        
        if (i == 7) {
            // Free a when i reaches 7
            free(a);
        }
    }

    // Free memory for b
    free(b);

    return 0;
}
