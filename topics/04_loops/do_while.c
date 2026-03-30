/*
 * TOPIC: Loops
 * EXAMPLE: Menu that always runs once
 * CONCEPT: do / while checks the condition after the body, so the body runs at least one time.
 *
 * TRY IT: Change the initial choice so the loop still demonstrates at least one pass.
 */

#include <stdio.h>

int main(void) {
    int choice = 0;
    int guard = 0;

    printf("Simulated menu (typed choice is hard-coded for the demo):\n");
    do {
        printf(" 1) Say hello\n");
        printf(" 2) Say goodbye\n");
        printf(" 0) Quit\n");
        choice = (guard == 0) ? 1 : 0;
        guard++;

        if (choice == 1) {
            printf("-> Hello!\n");
        } else if (choice == 2) {
            printf("-> Goodbye!\n");
        }
    } while (choice != 0);

    printf("Exited menu.\n");
    return 0;
}
