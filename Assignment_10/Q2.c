// Worst Fit Memory Allocation Strategy in C

#include <stdio.h>

void bestFit(int blockSize[], int processSize[], int processNum, int blockNum) {
  int i, j, allocation[processNum];

  // ALLOCATION INITIALIZATION AS -1
  for (int i = 0; i < processNum; i++)
    allocation[i] = -1;

  // WORST FIT
  for (int i = 0; i < processNum; i++) {
    int worstIdx = -1;
    for (int j = 0; j < blockNum; j++) {
      if (blockSize[j] >= processSize[i]) {
        if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
          worstIdx = j;
      }
    }
    if (worstIdx != -1) {
      allocation[i] = worstIdx;
      blockSize[worstIdx] -= processSize[i];
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
  int blockSize[10], processSize[10], blockNum, processNum;
  int allocation[10];

  printf("Enter number of memory blocks: ");
  scanf("%d", &blockNum);

  printf("Enter block sizes:\n");
  for (int i = 0; i < blockNum; i++)
    scanf("%d", &blockSize[i]);

  printf("Enter number of processes: ");
  scanf("%d", &processNum);

  printf("Enter process sizes:\n");
  for (int i = 0; i < processNum; i++)
    scanf("%d", &processSize[i]);

  bestFit(blockSize, processSize, processNum, blockNum);

  return 0;
}
