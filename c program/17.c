// Write C Program to implement the following LOOK Disk Scheduling Policy.
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
    // move right
    for (int i = 0; i < n; i++) {
      if (req[i] >= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // reverse left
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] < head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

  } else { // LEFT
    // move left
    for (int i = n - 1; i >= 0; i--) {
      if (req[i] <= head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }

    // reverse right
    for (int i = 0; i < n; i++) {
      if (req[i] > head) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
      }
    }
  }

  printf("\nTotal Seek Time = %d", total);
  printf("\nAverage = %.2f\n", (float)total / n);

  return 0;
}