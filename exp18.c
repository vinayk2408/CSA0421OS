#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
}

int main() {
    int n, head, disk_size, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[50];
    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter disk size (max cylinder number): ");
    scanf("%d", &disk_size);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 = LEFT, 1 = RIGHT): ");
    scanf("%d", &dir);

    int left[50], right[50];
    int l = 0, r = 0;

    left[l++] = 0;
    right[r++] = disk_size - 1;

    for (int i = 0; i < n; i++) {
        if (req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    sort(left, l);
    sort(right, r);

    int total = 0, current = head;

    if (dir == 1) { // moving to RIGHT first
        for (int i = 0; i < r; i++) {
            total += abs(right[i] - current);
            current = right[i];
        }
        for (int i = l-1; i >= 0; i--) {
            total += abs(left[i] - current);
            current = left[i];
        }
    } else { // moving to LEFT first
        for (int i = l-1; i >= 0; i--) {
            total += abs(left[i] - current);
            current = left[i];
        }
        for (int i = 0; i < r; i++) {
            total += abs(right[i] - current);
            current = right[i];
        }
    }

    printf("\nTotal head movement (SCAN) = %d cylinders\n", total);
    return 0;
}
