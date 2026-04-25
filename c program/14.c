// Write C Program to implement the SSTF Disk Scheduling Policy.
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, head, total = 0;

  printf("Enter number of requests: ");
  scanf("%d", &n);

  int req[n], visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = 0;

  printf("Enter request sequence:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &req[i]);

  printf("Enter initial head position: ");
  scanf("%d", &head);

  printf("\nSeek Sequence: %d ", head);

  for (int i = 0; i < n; i++) {
    int min = 9999, index = -1;

    for (int j = 0; j < n; j++) {
      if (!visited[j]) {
        int dist = abs(req[j] - head);
        if (dist < min) {
          min = dist;
          index = j;
        }
      }
    }

    visited[index] = 1;
    total += min;
    head = req[index];
    printf("-> %d ", head);
  }

  printf("\nTotal Seek Time = %d\n", total);
  return 0;
}
