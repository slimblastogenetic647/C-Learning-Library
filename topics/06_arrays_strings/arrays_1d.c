/*
 * TOPIC: Arrays & Strings
 * EXAMPLE: One-dimensional array
 * CONCEPT: An array stores a fixed number of elements in a row; indices start at 0 and go up to length - 1.
 *
 * TRY IT: Compute the sum of all elements using a loop.
 */

#include <stddef.h>
#include <stdio.h>

int main(void) {
    int scores[5] = {88, 92, 79, 95, 84};

    printf("Individual scores:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("  scores[%zu] = %d\n", i, scores[i]);
    }

    printf("\nLength of this array (elements): %zu\n", sizeof scores / sizeof scores[0]);
    return 0;
}
