/*
 * TOPIC: Structs
 * EXAMPLE: Group related fields
 * CONCEPT: struct bundles named members; dot accesses fields on a value, not through a pointer.
 *
 * TRY IT: Add a double gpa field and print it.
 */

#include <stdio.h>

struct Book {
    char title[48];
    int year;
    int pages;
};

int main(void) {
    struct Book b = {.title = "The C Programming Language", .year = 1988, .pages = 272};

    printf("\"%s\" (%d), %d pages\n", b.title, b.year, b.pages);
    return 0;
}
