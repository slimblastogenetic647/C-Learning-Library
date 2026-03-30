/*
 * TOPIC: Loops
 * EXAMPLE: Countdown and even numbers
 * CONCEPT: while repeats as long as the condition is true; the condition is checked before each iteration.
 *
 * TRY IT: Print only odd numbers from 1 to 9 using while.
 */

#include <stdio.h>

int main(void) {
    printf("Countdown:\n");
    int t = 5;
    while (t > 0) {
        printf("%d...\n", t);
        t--;
    }
    printf("Go!\n\n");

    printf("Even numbers from 0 to 10:\n");
    int x = 0;
    while (x <= 10) {
        if (x % 2 == 0) {
            printf("%d ", x);
        }
        x++;
    }
    printf("\n");
    return 0;
}
