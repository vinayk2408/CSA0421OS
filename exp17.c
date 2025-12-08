#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[50];
    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total = 0, current = head;

    for (int i = 0; i < n; i++) {
        total += abs(req[i] - current);
        current = req[i];
    }

    printf("\nTotal head movement = %d cylinders\n", total);
    return 0;
}
