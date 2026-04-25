// Write a program to implement Round Robin. Calculate waiting time, turnaround
// time for each process. Calculate avg. waiting time, avg turnaround time.
#include <stdio.h>

struct Process {
  int pid, at, bt, rt;
  int wt, tat, ct;
};

int main() {
  int n, tq;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];

  for (int i = 0; i < n; i++) {
    printf("Enter AT and BT of P%d: ", i + 1);
    scanf("%d %d", &p[i].at, &p[i].bt);
    p[i].pid = i + 1;
    p[i].rt = p[i].bt;
  }

  printf("Enter Time Quantum: ");
  scanf("%d", &tq);

  int current_time = 0, completed = 0;
  int total_wt = 0, total_tat = 0;

  // Gantt Chart arrays
  int gantt_pid[1000];
  int gantt_time[1000];
  int g = 0;

  while (completed < n) {
    int found = 0;

    for (int i = 0; i < n; i++) {
      if (p[i].at <= current_time && p[i].rt > 0) {
        found = 1;

        gantt_pid[g] = p[i].pid;

        if (p[i].rt > tq) {
          current_time += tq;
          p[i].rt -= tq;
        } else {
          current_time += p[i].rt;
          p[i].rt = 0;

          p[i].ct = current_time;
          p[i].tat = p[i].ct - p[i].at;
          p[i].wt = p[i].tat - p[i].bt;

          total_wt += p[i].wt;
          total_tat += p[i].tat;

          completed++;
        }

        gantt_time[g] = current_time;
        g++;
      }
    }

    if (!found) {
      current_time++; // CPU idle
    }
  }

  // -------- GANTT CHART --------
  printf("\nGantt Chart:\n");

  for (int i = 0; i < g; i++) {
    printf("| P%d ", gantt_pid[i]);
  }
  printf("|\n");

  printf("0 ");
  for (int i = 0; i < g; i++) {
    printf("%d ", gantt_time[i]);
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