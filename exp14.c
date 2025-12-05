/* OPTIMAL PAGING */
#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frames[f];
    int faults = 0;

    for (int i = 0; i < f; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], hit = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            faults++;
            int placed = 0;

            for (int j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    placed = 1;
                    break;
                }
            }

            if (!placed) {
                int farthest = -1, pos = -1;
                for (int j = 0; j < f; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }
                    if (k == n) {
                        pos = j;
                        break;
                    }
                }
                frames[pos] = page;
            }
        }

        printf("Frames: ");
        for (int j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
