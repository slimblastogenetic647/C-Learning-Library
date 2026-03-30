/*
 * TOPIC: Operators
 * EXAMPLE: Arithmetic expressions
 * CONCEPT: Integer division truncates toward zero; the remainder operator % only applies to integers in C.
 *
 * TRY IT: Print the average of three integers using integer division, then as a double.
 */

#include <stdio.h>

int main(void) {
    int a = 17;
    int b = 5;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d   (integer division)\n", a / b);
    printf("a %% b = %d   (remainder)\n", a % b);

    printf("\nAs floating point: %.2f / %.2f = %.2f\n", (double)a, (double)b, (double)a / (double)b);
    return 0;
}
