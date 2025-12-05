/* SEQUENTIAL (CONTIGUOUS) FILE ALLOCATION */
#include <stdio.h>

int main() {
    int disk[50] = {0};
    int n, start, length;

    printf("Enter total number of disk blocks (max 50): ");
    scanf("%d", &n);

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter file length (number of blocks): ");
    scanf("%d", &length);

    if (start < 0 || start + length > n) {
        printf("Allocation failed: Not enough space on disk.\n");
        return 0;
    }

    for (int i = start; i < start + length; i++) {
        if (disk[i] == 1) {
            printf("Allocation failed: Block %d already allocated.\n", i);
            return 0;
        }
    }

    for (int i = start; i < start + length; i++)
        disk[i] = 1;

    printf("File allocated successfully.\nBlocks allocated: ");
    for (int i = start; i < start + length; i++)
        printf("%d ", i);
    printf("\n");

    return 0;
}
