/*
 * TOPIC: Functions
 * EXAMPLE: Declare, define, call
 * CONCEPT: A function packages work behind a name; the declaration tells the compiler the signature before use.
 *
 * TRY IT: Add a function int max3(int, int, int) that returns the largest of three values.
 */

#include <stdio.h>

static int square(int x) {
    return x * x;
}

static int twice_square(int x) {
    return 2 * square(x);
}

int main(void) {
    int v = 6;
    printf("square(%d) = %d\n", v, square(v));
    printf("twice_square(%d) = %d\n", v, twice_square(v));
    return 0;
}
