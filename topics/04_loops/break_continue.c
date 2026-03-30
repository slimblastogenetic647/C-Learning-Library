/*
 * TOPIC: Loops
 * EXAMPLE: break vs continue
 * CONCEPT: break leaves the innermost loop entirely; continue skips the rest of the body and starts the next iteration.
 *
 * TRY IT: Rewrite the search using a flag variable instead of break.
 */

#include <stdio.h>

int main(void) {
    printf("continue: skip multiples of 3\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n\n");

    printf("break: stop when we hit 5\n");
    for (int j = 1; j <= 100; j++) {
        if (j == 5) {
            break;
        }
        printf("%d ", j);
    }
    printf("\n");
    return 0;
}
