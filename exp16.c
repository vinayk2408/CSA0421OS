#include <stdio.h>

int main() {
    int nb, np;
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[20], blockFlag[20] = {0};
    printf("Enter sizes of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[20], allocation[20];
    printf("Enter sizes of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    // First Fit
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (!blockFlag[j] && block[j] >= process[i]) {
                allocation[i] = j;
                blockFlag[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("P%d\t%d\tNot allocated\n", i+1, process[i]);
    }

    return 0;
}
