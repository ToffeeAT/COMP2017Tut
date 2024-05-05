#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dyn_array {
    int * arrayptr;
    int size;
    int truesize;
} dyn_array;

struct dyn_array * dyn_array_init() {
    dyn_array * array = malloc(sizeof(dyn_array));
    array->arrayptr = calloc(8, sizeof(int));
    array->size = 0;
    array->truesize = 8;
    return array;
}

void dyn_array_add(struct dyn_array * dyn, int value) {
    if (dyn->size >= dyn->truesize) {
        dyn->truesize += 8;

        dyn->arrayptr = realloc(dyn->arrayptr, dyn->truesize * sizeof(int));
    }

    dyn->arrayptr[dyn->size++] = value;
}

void dyn_array_delete(struct dyn_array * dyn, int index) {
    if (dyn->size == 0 || dyn->size < index) {
        return;
    }
    dyn->size--;

    // Corrected calculation for the size parameter in memmove
    if (index < dyn->size) {
        memmove(&dyn->arrayptr[index], &dyn->arrayptr[index + 1], (dyn->size - index) * sizeof(int));
    }

    // Check if reallocation is necessary after deletion
    if (dyn->truesize - 8 > dyn->size) {
        dyn->arrayptr = realloc(dyn->arrayptr, (dyn->truesize - 8) * sizeof(int));
        dyn->truesize -= 8;
    }
}


void dyn_array_free(dyn_array * dyn) {
    free(dyn->arrayptr);
    free(dyn);
}

int dyn_array_get(struct dyn_array * dyn, int index) {
    if (index >= dyn->size) {
        return 0;
    }
    return dyn->arrayptr[index];
}

int main(){

	//when testing your data types I suggest adding a bunch of deterministically garbage values to them, and then deleting those values
	//just to catch logic errors that arn't caught by valgrind/fsanitize.

    dyn_array* arr = dyn_array_init();
    for (int i = 0; i < 128; i++){
        dyn_array_add(arr,i);
    }
    
    for (int i = 0; i < 24; i++){
        arr->arrayptr[10+i] = i*i;
    }

    printf("\nPrinting before deletion\n");
    for (int i = 0; i < 48; i++){
        printf("%d ",arr->arrayptr[i]);
    }
    
    
    for(int i = 0; i < 24; i++){
        dyn_array_delete(arr,10);
    }
    
    printf("\nPrinting after deletion\n");
    for (int i = 0; i < 48; i++){
        printf("%d ",arr->arrayptr[i]);
    }

    for (int i = 0; i < 128; i++){
        dyn_array_delete(arr,0);
    }
    printf("\n");


    dyn_array_free(arr);


}
