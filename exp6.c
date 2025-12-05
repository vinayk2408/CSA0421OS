/* ROUND ROBIN SCHEDULING (with Arrival Time) */
#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("\nAT for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int done = 0;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 1;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }
        if (!done) time++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
