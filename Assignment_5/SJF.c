// Pre - emptive Shortest Job First
#include <limits.h>
#include <stdio.h>

// a code without calculating tat wt cat

void sjf(int pid[], int burst[], int arrival[], int n) {
  int remaining_time[n];
  char gantt_char[100] = "";
  int gantt_index = 0;

  for (int i = 0; i < n; i++) {
    remaining_time[i] = burst[i];
  }

  int time = 0, completed = 0;

  while (completed < n) {
    int idx = -1;
    int min_burst = INT_MAX;

    // 1. at th given time rn, find the process with the minimum BT that has
    // already arrived
    for (int i = 0; i < n; i++) {
      if (arrival[i] <= time && remaining_time[i] > 0 &&
          remaining_time[i] < min_burst) {
        min_burst = remaining_time[i];
        idx = i;
      }
    }

    // 2. if at given time no idx updation happens means that time ++ no process
    // arrived or is available rn
    if (idx == -1) {
      time++;
      continue;
    }

    // 3. execute the selected process
    gantt_char[gantt_index++] = 'P'; // add a placeholder for process ID
    gantt_char[gantt_index++] = '0' + pid[idx]; // add the process ID
    gantt_char[gantt_index++] = ' ';            // space for better output

    remaining_time[idx]--;
    // of that particular arrived process remaining time decrement krdo uska

    // 4. what if the process is completed, check for completion, for updation
    // condition for while loop
    if (remaining_time[idx] == 0) {
      completed++;
    }

    time++; // time needs to be incremented if that "continue" isn't hit
  }

  // print the Gantt chart
  printf("Gantt Chart: ");
  for (int i = 0; i < gantt_index; i++) {
    printf("%c", gantt_char[i]);
  }
  printf("\n");
}

int main() {
  int pid[3] = {1, 2, 3};
  int burst[3] = {8, 4, 9};
  int arrival[3] = {0, 1, 2};

  sjf(pid, burst, arrival, 3);
  return 0;
}
