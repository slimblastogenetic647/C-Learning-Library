/*
 * TOPIC: Loops
 * EXAMPLE: Counting and a multiplication row
 * CONCEPT: A for loop bundles init, test, and update; it is ideal when you know how many iterations you want.
 *
 * TRY IT: Print a full 5x5 multiplication table with nested for loops.
 */

#include <stdio.h>

int main(void) {
    printf("Count 0..4:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n\nRow of 7 times table:\n");
    int n = 7;
    for (int k = 1; k <= 10; k++) {
        printf("%d x %d = %d\n", n, k, n * k);
    }
    return 0;
}
