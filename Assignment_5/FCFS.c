// Input: List of processes with arrival time and burst time
// Sort processes by arrival time
// Initialize current_time = 0

// For each process in order:
//     If current_time < arrival_time:
//         current_time = arrival_time
//     waiting_time = current_time - arrival_time
//     turnaround_time = waiting_time + burst_time
//     current_time += burst_time
//     Output process info (waiting_time, turnaround_time)

#include <stdio.h>

int main() {
  int n, i;
  int bt[20], wt[20], tat[20];
  int total_wt = 0, total_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  printf("Enter burst time for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d", &bt[i]);
  }

  wt[0] = 0; // Waiting time for first process is 0

  // Calculate waiting time
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
  }

  // Calculate turnaround time
  for (i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
  }

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    total_wt += wt[i];
    total_tat += tat[i];
  }

  printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

  return 0;
}