#include <stdio.h>

int main() {
  int n, i, j;
  int at[20], bt[20], ct[20], wt[20], tat[20], pid[20];
  int total_wt = 0, total_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    pid[i] = i + 1;
    printf("Enter arrival time and burst time for process %d: ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
  }

  // Sort by arrival time
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (at[i] > at[j]) {
        int temp = at[i];
        at[i] = at[j];
        at[j] = temp;
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
        temp = pid[i];
        pid[i] = pid[j];
        pid[j] = temp;
      }
    }
  }

  int current_time = 0;
  for (i = 0; i < n; i++) {
    if (current_time < at[i]) {
      current_time = at[i];
    }
    ct[i] = current_time + bt[i];
    wt[i] = ct[i] - at[i] - bt[i];
    tat[i] = ct[i] - at[i];
    current_time = ct[i];
  }

  printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting "
         "Time\tTurnaround Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i],
           wt[i], tat[i]);
    total_wt += wt[i];
    total_tat += tat[i];
  }

  printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

  return 0;
}