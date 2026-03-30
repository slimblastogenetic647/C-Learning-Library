/*
 * TOPIC: Hello World & Variables
 * EXAMPLE: Common built-in types
 * CONCEPT: Variables hold values; each type tells the compiler how much memory to use and how to interpret bits.
 *
 * TRY IT: Print sizeof(long) and sizeof(long double) on your machine.
 */

#include <stdio.h>

int main(void) {
    int count = 42;
    float pi_approx = 3.14f;
    double precise = 3.1415926535;
    char grade = 'A';

    printf("int count          = %d   (sizeof %zu bytes)\n", count, sizeof count);
    printf("float pi_approx    = %f   (sizeof %zu bytes)\n", pi_approx, sizeof pi_approx);
    printf("double precise     = %.10f (sizeof %zu bytes)\n", precise, sizeof precise);
    printf("char grade         = %c   (ASCII %d, sizeof %zu bytes)\n", grade, grade, sizeof grade);
    return 0;
}
