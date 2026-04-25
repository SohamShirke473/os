// Write a C program to simulate the Worst Fit Memory Allocation Technique.
#include <stdio.h>

int main() {
  int n, m;

  printf("Enter number of memory blocks: ");
  scanf("%d", &n);

  int blocks[n];

  printf("Enter the size of each block:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &blocks[i]);
  }

  printf("Enter number of processes: ");
  scanf("%d", &m);

  int processes[m], allocation[m];

  printf("Enter the size of each process:\n");
  for (int i = 0; i < m; i++) {
    scanf("%d", &processes[i]);
    allocation[i] = -1;
  }

  // Worst Fit Algorithm
  for (int i = 0; i < m; i++) {
    int worstIdx = -1;

    for (int j = 0; j < n; j++) {
      if (blocks[j] >= processes[i]) {
        if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
          worstIdx = j;
        }
      }
    }

    if (worstIdx != -1) {
      allocation[i] = worstIdx;
      blocks[worstIdx] -= processes[i];
    }
  }

  // Output
  printf("\nProcess No.\tProcess Size\tBlock No.\n");

  for (int i = 0; i < m; i++) {
    printf("%d\t\t%d\t\t", i + 1, processes[i]);

    if (allocation[i] != -1)
      printf("%d\n", allocation[i] + 1);
    else
      printf("Not Allocated\n");
  }

  printf("\nRemaining Memory (Fragmentation):\n");
  for (int i = 0; i < n; i++) {
    printf("Block %d: %d\n", i + 1, blocks[i]);
  }

  return 0;
}