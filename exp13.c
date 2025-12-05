/* LRU PAGING */
#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

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

    int frames[f], time[f];
    int counter = 0, faults = 0;

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i], hit = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                counter++;
                time[j] = counter;
                hit = 1;
                break;
            }
        }

        if (!hit) {
            int pos;
            for (pos = 0; pos < f; pos++)
                if (frames[pos] == -1)
                    break;

            if (pos == f)
                pos = findLRU(time, f);

            counter++;
            frames[pos] = page;
            time[pos] = counter;
            faults++;
        }

        printf("Frames: ");
        for (int j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
