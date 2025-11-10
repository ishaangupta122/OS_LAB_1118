// Write a program in C/C++/Java to simulate the Banker’s algorithm for
// deadlock avoidance. Consider at least 3 processes in the system, with 4
// resource  classes  having  at  least  one  resource  instance  for  each  class.
// Assume the values for Available, Allocation, MAX, and request from
// a  particular  process  from  your  side.  Program  must  reflect  two  cases,
// where a safe sequence exists for one and safe sequence does not exist
// for another.

// Banker's Algorithm for Deadlock Avoidance
#include <stdio.h>

int main() {
  // Number of processes (n) and resource types (m)
  int n = 5, m = 3;

  // -------------------------------
  // Step 1: Initialize matrices
  // -------------------------------

  // Allocation Matrix: resources currently allocated to each process
  int alloc[5][3] = {
      {0, 1, 0},  // P0
      {2, 0, 0},  // P1
      {3, 0, 2},  // P2
      {2, 1, 1},  // P3
      {0, 0, 2}   // P4
  };

  // Max Matrix: maximum demand of each process
  int max[5][3] = {
      {7, 5, 3},  // P0
      {3, 2, 2},  // P1
      {9, 0, 2},  // P2
      {2, 2, 2},  // P3
      {4, 3, 3}   // P4
  };

  // Available resources in the system
  int avail[3] = {3, 3, 2};

  // -------------------------------
  // Step 2: Initialize helper arrays
  // -------------------------------

  int f[n], ans[n], ind = 0;  // f[] tracks finished processes; ans[] stores safe sequence

  // Mark all processes as unfinished (0)
  for (int k = 0; k < n; k++) {
    f[k] = 0;
  }

  // -------------------------------
  // Step 3: Calculate Need matrix
  // -------------------------------
  // Need = Max - Allocation

  int need[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  // -------------------------------
  // Step 4: Apply Safety Algorithm
  // -------------------------------

  int y = 0;
  for (int k = 0; k < n; k++) {  // repeat n times to find safe sequence
    for (int i = 0; i < n; i++) {
      if (f[i] == 0) {  // process not yet finished
        int flag = 0;

        // Check if Need <= Available for all resources
        for (int j = 0; j < m; j++) {
          if (need[i][j] > avail[j]) {
            flag = 1;  // process can't be executed now
            break;
          }
        }

        // If all needs of process i can be satisfied
        if (flag == 0) {
          ans[ind++] = i;  // add process to safe sequence

          // Release allocated resources after process finishes
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];

          f[i] = 1;  // mark process as finished
        }
      }
    }
  }

  // -------------------------------
  // Step 5: Check if system is safe
  // -------------------------------

  int flag = 1;
  for (int i = 0; i < n; i++) {
    if (f[i] == 0) {  // any process still unfinished → unsafe
      flag = 0;
      printf("\nThe following system is NOT in a safe state.\n");
      break;
    }
  }

  // -------------------------------
  // Step 6: Display result
  // -------------------------------

  if (flag == 1) {
    printf("\nThe system is in a SAFE state.\n");
    printf("Safe Sequence is: ");

    // print the safe sequence
    for (int i = 0; i < n - 1; i++)
      printf("P%d -> ", ans[i]);
    printf("P%d\n", ans[n - 1]);
  }

  return 0;
}
