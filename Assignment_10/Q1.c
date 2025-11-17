// First Fit Memory Allocation Strategy in C

#include <stdio.h>

void firstFit(int blockSize[], int processSize[], int processNum, int blockNum) {
  int i, j;
  int allocation[processNum];

  // ALLOCATION INITIALIZATION AS -1
  for (i = 0; i < processNum; i++) {
    allocation[i] = -1;
  }

  // FIRST FIT
  for (i = 0; i < processNum; i++) {
    for (j = 0; j < blockNum; j++) {
      if (blockSize[j] >= processSize[i]) {
        // allocating block j to the i'th process
        allocation[i] = j;

        // Reduce available memory in this block.
        blockSize[j] -= processSize[i];

        break;  // go to the next process in the queue
      }
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (int i = 0; i < processNum; i++) {
    printf("%d\t\t%d\t\t", i + 1, processSize[i]);
    if (allocation[i] != -1) {
      printf("%d - Remaining Size (%d)\n", allocation[i] + 1, blockSize[allocation[i]]);
    } else {
      printf("Not Allocated\n");
    }
  }
  printf("\n");
}

int main() {
  int blockNum, processNum;
  int blockSize[] = {100, 500, 200, 300, 600};
  int processSize[] = {212, 417, 112, 426};
  blockNum = sizeof(blockSize) / sizeof(blockSize[0]);
  processNum = sizeof(processSize) / sizeof(processSize[0]);

  printf("\n--- FIRST FIT MEMORY ALLOCATION ---\n");
  firstFit(blockSize, processSize, processNum, blockNum);

  return 0;
}
