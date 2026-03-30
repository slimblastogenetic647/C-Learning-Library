/*
 * TOPIC: Functions
 * EXAMPLE: Factorial and Fibonacci
 * CONCEPT: A recursive function calls itself with simpler input until a base case stops the recursion.
 *
 * TRY IT: Add a simple counter to factorial to print how many calls occur for n = 5.
 */

#include <stdio.h>

static unsigned long factorial(int n) {
    if (n <= 1) {
        return 1UL;
    }
    return (unsigned long)n * factorial(n - 1);
}

static long fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n = 6;
    printf("factorial(%d) = %lu\n", n, factorial(n));
    printf("fibonacci first 12 terms:\n");
    for (int i = 0; i < 12; i++) {
        printf("%ld ", fib(i));
    }
    printf("\n");
    return 0;
}
