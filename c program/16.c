// Write C Program to implement the following C-SCAN Disk Scheduling Policy.
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
}

int main() {
  int n, head, total = 0, direction;
  int size = 200;

  printf("Enter number of requests: ");
  scanf("%d", &n);

  int req[n];
  printf("Enter requests:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &req[i]);

  printf("Enter head: ");
  scanf("%d", &head);

  printf("Direction (0=LEFT,1=RIGHT): ");
  scanf("%d", &direction);

  sort(req, n);

  printf("\nSeek Sequence: %d ", head);

  if (direction == 1) { // RIGHT
    // Move right
    for (int i = 0; i < n; i++) {
      if (req[i] >= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // Go to end
    total += abs((size - 1) - head);
    head = size - 1;

    // Jump to start (no service)
    total += size - 1;
    head = 0;

    // Service remaining
    for (int i = 0; i < n; i++) {
      if (req[i] < head)
        continue; // skip none actually, just clean logic
      if (req[i] < (size - 1)) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

  } else { // LEFT
    // Move left
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] <= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // Go to start
    total += abs(head - 0);
    head = 0;

    // Jump to end
    total += size - 1;
    head = size - 1;

    // Service remaining
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] > head)
        continue;
      if (req[i] > 0) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }
  }

  printf("\nTotal Seek Time = %d", total);
  printf("\nAverage Seek Time = %.2f\n", (float)total / n);

  return 0;
}