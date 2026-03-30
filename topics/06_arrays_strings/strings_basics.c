/*
 * TOPIC: Arrays & Strings
 * EXAMPLE: C strings as char arrays
 * CONCEPT: A C string is a char array ending with '\0'; string.h helpers work on that convention.
 *
 * TRY IT: Use a loop to copy src into dest without calling strcpy.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char src[] = "learn";
    char dest[32];

    strcpy(dest, src);

    printf("src:  \"%s\" (length %zu)\n", src, strlen(src));
    printf("dest: \"%s\"\n", dest);
    printf("Printed with %%s: %s\n", dest);
    return 0;
}
