/*
 * TOPIC: Operators
 * EXAMPLE: Relational comparisons
 * CONCEPT: Comparison operators yield 1 if true and 0 if false when used as int values in C.
 *
 * TRY IT: Compare two floats; note when == surprises you and why.
 */

#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 20;

    printf("x = %d, y = %d\n\n", x, y);
    printf("x == y  -> %d\n", x == y);
    printf("x != y  -> %d\n", x != y);
    printf("x < y   -> %d\n", x < y);
    printf("x > y   -> %d\n", x > y);
    printf("x <= y  -> %d\n", x <= y);
    printf("x >= y  -> %d\n", x >= y);
    return 0;
}
