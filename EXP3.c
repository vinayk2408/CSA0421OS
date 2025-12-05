/* Ex.No 3: FCFS Scheduling */
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nAT for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("BT for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // FCFS
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
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
