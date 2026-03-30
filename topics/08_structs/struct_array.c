/*
 * TOPIC: Structs
 * EXAMPLE: Array of structs
 * CONCEPT: Arrays and structs compose naturally; each element is a full struct value.
 *
 * TRY IT: Find and print the student with the highest score in the array.
 */

#include <stdio.h>

struct Student {
    char name[24];
    int score;
};

int main(void) {
    struct Student roster[] = {
        {"Ana", 92},
        {"Ben", 88},
        {"Cara", 95},
    };
    size_t n = sizeof roster / sizeof roster[0];

    printf("Roster:\n");
    for (size_t i = 0; i < n; i++) {
        printf("  %-8s %d\n", roster[i].name, roster[i].score);
    }
    return 0;
}
