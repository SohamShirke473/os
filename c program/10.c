// Write C Program to simulate LRU Page Replacement.
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
  int time[m]; // stores last used time

  // Initialize
  for (int i = 0; i < m; i++) {
    frames[i] = -1;
    time[i] = -1;
  }

  int pageFaults = 0;
  int counter = 0; // acts like time

  printf("\nPage\tFrames\n");

  for (int i = 0; i < n; i++) {
    int found = 0;

    // Check if page is already in frames (HIT)
    for (int j = 0; j < m; j++) {
      if (frames[j] == pages[i]) {
        found = 1;
        time[j] = counter++; // update usage time
        break;
      }
    }

    // If page not found → PAGE FAULT
    if (!found) {
      int lruIndex = 0;

      // Find least recently used page
      for (int j = 1; j < m; j++) {
        if (time[j] < time[lruIndex]) {
          lruIndex = j;
        }
      }

      frames[lruIndex] = pages[i];
      time[lruIndex] = counter++;
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