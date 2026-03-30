/*
 * TOPIC: Control Flow
 * EXAMPLE: Day of the week
 * CONCEPT: switch jumps to a matching case; break exits the switch; without break, execution falls through.
 *
 * TRY IT: Remove one break on purpose and watch the next case run too.
 */

#include <stdio.h>

int main(void) {
    int day = 3;

    printf("day = %d -> ", day);
    switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
    case 7:
        printf("Weekend\n");
        break;
    default:
        printf("Unknown day\n");
        break;
    }

    printf("\nFall-through demo (no breaks): ");
    int code = 1;
    switch (code) {
    case 1:
        printf("one ");
        /* fall through */
    case 2:
        printf("two ");
        /* fall through */
    case 3:
        printf("three\n");
        break;
    default:
        break;
    }
    return 0;
}
