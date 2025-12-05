/* Ex.No 4: SJF (Non-preemptive) Scheduling */
#include <stdio.h>
#include <limits.h>

int main() {
    int n, completed = 0, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nAT for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("BT for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        done[i] = 0;
    }

    while (completed < n) {
        int idx = -1, min_bt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
        } else {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt  += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT  = %.2f\n", total_wt / n);
    return 0;
}
