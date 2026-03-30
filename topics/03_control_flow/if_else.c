/*
 * TOPIC: Control Flow
 * EXAMPLE: Grade calculator
 * CONCEPT: if / else if / else chooses one path; conditions are evaluated top to bottom.
 *
 * TRY IT: Add a branch for the letter grade 'F' below 60.
 */

#include <stdio.h>

int main(void) {
    int score = 87;

    printf("Score: %d -> ", score);

    if (score >= 90) {
        printf("A\n");
    } else if (score >= 80) {
        printf("B\n");
    } else if (score >= 70) {
        printf("C\n");
    } else if (score >= 60) {
        printf("D\n");
    } else {
        printf("F\n");
    }
    return 0;
}
