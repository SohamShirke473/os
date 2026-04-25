// Write a C program to simulate FIFO Page replacement.
#include <stdio.h>

int main() {
  int n, m;

  printf("Enter the number of pages: ");
  scanf("%d", &n);

  int pages[n];
  printf("Enter the pages (reference string): ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &pages[i]);
  }

  printf("Enter the number of frames: ");
  scanf("%d", &m);

  int frames[m];

  // Initialize frames with -1 (empty)
  for (int i = 0; i < m; i++) {
    frames[i] = -1;
  }

  int pageFaults = 0;
  int index = 0; // Points to next frame to replace (FIFO pointer)

  printf("\nPage\tFrames\n");

  for (int i = 0; i < n; i++) {
    int found = 0;

    // Check if page already exists (HIT)
    for (int j = 0; j < m; j++) {
      if (frames[j] == pages[i]) {
        found = 1;
        break;
      }
    }

    // If not found → PAGE FAULT
    if (!found) {
      frames[index] = pages[i];
      index = (index + 1) % m; // Circular queue
      pageFaults++;
    }

    // Print frames
    printf("%d\t", pages[i]);
    for (int j = 0; j < m; j++) {
      if (frames[j] != -1)
        printf("%d ", frames[j]);
      else
        printf("- ");
    }
    printf("\n");
  }

  printf("\nTotal Page Faults = %d\n", pageFaults);

  return 0;
}