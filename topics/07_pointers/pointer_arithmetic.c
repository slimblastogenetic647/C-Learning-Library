/*
 * TOPIC: Pointers
 * EXAMPLE: Walking an array with a pointer
 * CONCEPT: Adding 1 to a pointer moves by sizeof(element) bytes; this matches array indexing.
 *
 * TRY IT: Print the same array backwards using pointer arithmetic only.
 */

#include <stdio.h>

int main(void) {
    int xs[] = {10, 20, 30, 40};
    size_t len = sizeof xs / sizeof xs[0];

    printf("Forward via pointer:\n");
    for (int *it = xs; it < xs + len; it++) {
        printf("%d ", *it);
    }
    printf("\n");

    printf("Same using subscript for comparison:\n");
    for (size_t i = 0; i < len; i++) {
        printf("%d ", *(xs + i));
    }
    printf("\n");
    return 0;
}
