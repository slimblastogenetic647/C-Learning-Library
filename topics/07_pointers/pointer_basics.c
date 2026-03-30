/*
 * TOPIC: Pointers
 * EXAMPLE: Address, dereference, NULL
 * CONCEPT: A pointer stores a memory address; * reads the pointed-to value; & takes the address of an object.
 *
 * TRY IT: Print the addresses of two consecutive int locals and see how far apart they are.
 */

#include <stdio.h>

int main(void) {
    int n = 42;
    int *p = &n;

    printf("n  = %d\n", n);
    printf("&n = %p\n", (void *)&n);
    printf("p  = %p (same as &n)\n", (void *)p);
    printf("*p = %d (value through pointer)\n", *p);

    int *q = NULL;
    printf("q is NULL: %s\n", q == NULL ? "yes" : "no");
    return 0;
}
