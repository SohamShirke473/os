// Write a C program to simulate Non Pre-emptive Priority Scheduling policy with
// arrival time.

#include <stdio.h>

struct Process {
  int pid, at, bt, pr;
  int wt, tat, ct;
  int done;
};

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];

  // Input
  for (int i = 0; i < n; i++) {
    printf("Enter AT, BT, Priority of P%d: ", i + 1);
    scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
    p[i].pid = i + 1;
    p[i].done = 0;
  }

  int current_time = 0, completed = 0;
  int total_wt = 0, total_tat = 0;

  // For Gantt chart
  int order[n];
  int time[n + 1];
  int k = 0;

  time[0] = 0;

  // Scheduling
  while (completed < n) {
    int idx = -1;
    int best_pr = 999999;

    for (int i = 0; i < n; i++) {
      if (p[i].at <= current_time && p[i].done == 0) {
        if (p[i].pr < best_pr) {
          best_pr = p[i].pr;
          idx = i;
        }
      }
    }

    if (idx != -1) {
      order[k] = p[idx].pid;

      current_time += p[idx].bt;

      p[idx].ct = current_time;
      p[idx].tat = p[idx].ct - p[idx].at;
      p[idx].wt = p[idx].tat - p[idx].bt;

      time[k + 1] = current_time;

      total_wt += p[idx].wt;
      total_tat += p[idx].tat;

      p[idx].done = 1;
      completed++;
      k++;
    } else {
      current_time++; // CPU idle
    }
  }

  // -------- GANTT CHART --------
  printf("\nGantt Chart:\n");

  for (int i = 0; i < k; i++) {
    printf("P%d ", order[i]);
    if (i != k - 1)
      printf("| ");
  }

  printf("\n%d ", time[0]);
  for (int i = 1; i <= k; i++) {
    printf("%d ", time[i]);
  }

  // -------- TABLE --------
  printf("\n\nPID\tAT\tBT\tPR\tWT\tTAT\tCT\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr,
           p[i].wt, p[i].tat, p[i].ct);
  }

  printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

  return 0;
}