/*
 * TOPIC: Loops
 * EXAMPLE: goto for error cleanup (and why it is rare)
 * CONCEPT: goto jumps to a label in the same function; it can obscure structure, so prefer loops and functions.
 *
 * TRY IT: Replace this example with the same behavior using a do/while(0) and break pattern.
 */

#include <stdio.h>

int main(void) {
    int ok = 0;

    if (!ok) {
        printf("Taking the error path with goto.\n");
        goto cleanup;
    }

    printf("This line is skipped in the demo.\n");

cleanup:
    printf("cleanup: one place to release resources in larger programs.\n");
    printf("In small programs, structured control flow is usually clearer.\n");
    return 0;
}
