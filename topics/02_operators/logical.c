/*
 * TOPIC: Operators
 * EXAMPLE: Logical AND, OR, NOT
 * CONCEPT: && and || short-circuit: the right side is skipped once the result is decided.
 *
 * TRY IT: Build a tiny truth table for (a && b) using nested loops with a and b in {0,1}.
 */

#include <stdio.h>

int main(void) {
    printf("p  q  p && q  p || q  !p\n");
    printf("--------------------------------\n");
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            printf("%d  %d     %d       %d      %d\n", p, q, p && q, p || q, !p);
        }
    }
    return 0;
}
