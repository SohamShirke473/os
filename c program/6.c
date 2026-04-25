// Write a C program to simulate the Best Fit Memory Allocation Technique
// with Internal Fragmentation calculation.

#include <stdio.h>

int main() {
  int np, nb;

  printf("Enter the number of processes: ");
  scanf("%d", &np);

  printf("Enter the number of blocks: ");
  scanf("%d", &nb);

  int p[np], b[nb], alloc[np], frag[np];
  int original_b[nb]; // to store original block sizes

  // Input process sizes
  for (int i = 0; i < np; i++) {
    printf("Enter the size of process %d: ", i + 1);
    scanf("%d", &p[i]);
    alloc[i] = -1;
    frag[i] = 0;
  }

  // Input block sizes
  for (int i = 0; i < nb; i++) {
    printf("Enter the size of block %d: ", i + 1);
    scanf("%d", &b[i]);
    original_b[i] = b[i]; // save original size
  }

  // Best Fit Allocation
  for (int i = 0; i < np; i++) {
    int bestIdx = -1;

    for (int j = 0; j < nb; j++) {
      if (b[j] >= p[i]) {
        if (bestIdx == -1 || b[j] < b[bestIdx]) {
          bestIdx = j;
        }
      }
    }

    if (bestIdx != -1) {
      alloc[i] = bestIdx;
      frag[i] = b[bestIdx] - p[i]; // internal fragmentation
      b[bestIdx] -= p[i];          // remaining block size
    }
  }

  // Output
  printf("\nProcess No\tProcess Size\tBlock No\tFragmentation\n");

  int total_frag = 0;

  for (int i = 0; i < np; i++) {
    printf("%d\t\t%d\t\t", i + 1, p[i]);

    if (alloc[i] != -1) {
      printf("%d\t\t%d\n", alloc[i] + 1, frag[i]);
      total_frag += frag[i];
    } else {
      printf("Not Allocated\t0\n");
    }
  }

  printf("\nTotal Internal Fragmentation = %d\n", total_frag);

  return 0;
}