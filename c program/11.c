// Write C Program to simulate Optimal Page Replacement.
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

  // Initialize frames
  for (int i = 0; i < m; i++) {
    frames[i] = -1;
  }

  int pageFaults = 0;

  printf("\nPage\tFrames\n");

  for (int i = 0; i < n; i++) {
    int found = 0;

    // Check HIT
    for (int j = 0; j < m; j++) {
      if (frames[j] == pages[i]) {
        found = 1;
        break;
      }
    }

    // If PAGE FAULT
    if (!found) {
      int replaceIndex = -1;
      int farthest = i + 1;

      for (int j = 0; j < m; j++) {
        int k;

        // Find next use of frames[j]
        for (k = i + 1; k < n; k++) {
          if (frames[j] == pages[k]) {
            if (k > farthest) {
              farthest = k;
              replaceIndex = j;
            }
            break;
          }
        }

        // If page not used again → best to replace
        if (k == n) {
          replaceIndex = j;
          break;
        }
      }

      // If empty frame exists
      if (replaceIndex == -1) {
        for (int j = 0; j < m; j++) {
          if (frames[j] == -1) {
            replaceIndex = j;
            break;
          }
        }
      }

      frames[replaceIndex] = pages[i];
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
