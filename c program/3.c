// Write a C program to simulate the Preemptive SJF scheduling policy.
#include <stdio.h>

struct Process {
  int pid, at, bt, rt;
  int wt, tat, ct;
};

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];

  // Input
  for (int i = 0; i < n; i++) {
    printf("Enter AT and BT of P%d: ", i + 1);
    scanf("%d %d", &p[i].at, &p[i].bt);
    p[i].pid = i + 1;
    p[i].rt = p[i].bt; // remaining time
  }

  int completed = 0, current_time = 0;
  int total_wt = 0, total_tat = 0;

  // For Gantt chart
  int gantt[1000];
  int g = 0;

  while (completed < n) {
    int idx = -1;
    int min_rt = 999999;

    // Find process with shortest remaining time
    for (int i = 0; i < n; i++) {
      if (p[i].at <= current_time && p[i].rt > 0) {
        if (p[i].rt < min_rt) {
          min_rt = p[i].rt;
          idx = i;
        }
      }
    }

    if (idx != -1) {
      gantt[g++] = p[idx].pid;

      p[idx].rt--;
      current_time++;

      if (p[idx].rt == 0) {
        completed++;
        p[idx].ct = current_time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        total_wt += p[idx].wt;
        total_tat += p[idx].tat;
      }
    } else {
      gantt[g++] = -1; // idle
      current_time++;
    }
  }

  // -------- GANTT CHART --------
  printf("\nGantt Chart:\n");

  for (int i = 0; i < g; i++) {
    if (gantt[i] == -1)
      printf("IDLE ");
    else
      printf("P%d ", gantt[i]);

    if (i != g - 1)
      printf("| ");
  }

  printf("\n0 ");
  for (int i = 1; i <= g; i++) {
    printf("%d ", i);
  }

  // -------- TABLE --------
  printf("\n\nPID\tAT\tBT\tWT\tTAT\tCT\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt,
           p[i].tat, p[i].ct);
  }

  printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

  return 0;
}
