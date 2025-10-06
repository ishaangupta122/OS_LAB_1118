// First-Come, First-Served (FCFS) Scheduling Algorithm (Non-preemptive)

#include <stdio.h>

int main() {
  int n, i;
  float bt[20], wt[20], tat[20];
  float total_wt = 0, total_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  printf("Enter burst time for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d - Burst Time: ", i + 1);
    scanf("%d", &bt[i]);
  }

  wt[0] = 0;

  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
  }

  for (i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
  }

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    total_wt += wt[i];
    total_tat += tat[i];
  }

  float avg_wt = total_wt / n;
  float avg_tat = total_tat / n;

  printf("\nAverage Waiting Time: %.2f", avg_wt);
  printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

  return 0;
}