#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    size_t size = 5;

    // Allocate memory for an array of 5 integers
    array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Return an error code
    }

    // Use the allocated memory as needed

    // Don't forget to free the allocated memory when done
    free(array);

    return 0;  // Return success
}
