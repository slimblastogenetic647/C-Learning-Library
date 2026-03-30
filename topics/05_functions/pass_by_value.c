/*
 * TOPIC: Functions
 * EXAMPLE: Swap and pass-by-value
 * CONCEPT: C passes arguments by value: the function receives copies, so swapping locals inside does not affect the caller.
 *
 * TRY IT: Later, rewrite swap using pointers so the caller sees exchanged values (preview of pointers).
 */

#include <stdio.h>

static void swap_wrong(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int x = 1;
    int y = 2;
    printf("Before swap_wrong: x=%d y=%d\n", x, y);
    swap_wrong(x, y);
    printf("After  swap_wrong: x=%d y=%d  (unchanged — copies were swapped)\n", x, y);
    return 0;
}
