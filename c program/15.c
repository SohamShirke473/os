// Write C Program to implement the following SCAN Disk Scheduling Policy.
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

int main() {
  int n, head, total = 0, direction;
  int size = 200; // 0–199

  printf("Enter number of requests: ");
  scanf("%d", &n);

  int req[n];
  printf("Enter request sequence:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &req[i]);

  printf("Enter initial head position: ");
  scanf("%d", &head);

  printf("Enter direction (0 = LEFT, 1 = RIGHT): ");
  scanf("%d", &direction);

  sort(req, n);

  printf("\nSeek Sequence: %d ", head);

  if (direction == 1) {
    // RIGHT first
    for (int i = 0; i < n; i++) {
      if (req[i] >= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // go to end
    total += abs((size - 1) - head);
    head = size - 1;

    // then LEFT
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] < head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }
  } else {
    // LEFT first
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] <= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // go to start
    total += abs(head - 0);
    head = 0;

    // then RIGHT
    for (int i = 0; i < n; i++) {
      if (req[i] > head) {
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