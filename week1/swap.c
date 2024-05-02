#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  // Store the value pointed to by 'a' in 'temp'
    *a = *b;        // Assign the value pointed to by 'b' to the memory pointed to by 'a'
    *b = temp;      // Assign the value stored in 'temp' to the memory pointed to by 'b'
}


int main(void) {
    int a = 2;
    int b = 3;
    swap(&a,&b);
    printf("%d %d\n", a, b);

    return 0;
}
