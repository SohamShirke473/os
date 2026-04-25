// Write a program to implement the FCFS Disk Scheduling Policy.
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, head, total = 0;

  printf("Enter number of requests: ");
  scanf("%d", &n);

  int req[n];
  printf("Enter request sequence (0-199):\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &req[i]);

  printf("Enter initial head position: ");
  scanf("%d", &head);

  printf("\nSeek Sequence: %d ", head);

  for (int i = 0; i < n; i++) {
    total += abs(req[i] - head);
    head = req[i];
    printf("-> %d ", head);
  }

  printf("\nTotal Seek Time = %d", total);
  printf("\nAverage Seek Time = %.2f\n", (float)total / n);

  return 0;
}