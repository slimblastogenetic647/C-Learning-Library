/*
 * TOPIC: Arrays & Strings
 * EXAMPLE: Two-dimensional array (matrix)
 * CONCEPT: A 2D array is an array of rows; accessing [row][col] maps a grid to memory in row-major order.
 *
 * TRY IT: Print the transpose (swap rows and columns in the output only).
 */

#include <stdio.h>

int main(void) {
    int grid[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    printf("Matrix 3x4:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            printf("%3d ", grid[r][c]);
        }
        printf("\n");
    }
    return 0;
}
