// Allocate 100 bytes of memory
char* buffer = (char *) malloc(100 * sizeof(char));
// Allocate memory for 10 integers
int* values = (int *) malloc(10 * sizeof(int));
// Allocate memory for 10 integers, setting all elements to zero
int* zeroes = (int *) calloc(sizeof(int), 10);
// Returns a pointer to a new block of memory that contains space
// for 200 characters. The values of the elements are preserved.
buffer = (char *) realloc(buffer, 200 * sizeof(char));
// Free allocated memory
free(buffer);
free(values);
free(zeroes);
