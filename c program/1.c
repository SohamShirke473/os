// Write a C program to implement FCFS (with arrival time=0 for all). Calculate
// waiting time, turnaround time for each process. Calculate avg. waiting time,
// avg turnaround time for process.

#include <stdio.h>

struct Process {
  int pid;
  int burst_time;
  int waiting_time;
  int turnaround_time;
  int completion_time;
};

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];

  // Input
  for (int i = 0; i < n; i++) {
    printf("Enter burst time of process %d: ", i + 1);
    scanf("%d", &p[i].burst_time);
    p[i].pid = i + 1;
  }

  int current_time = 0;

  // FCFS logic
  for (int i = 0; i < n; i++) {
    p[i].completion_time = current_time + p[i].burst_time;
    current_time = p[i].completion_time;

    p[i].turnaround_time = p[i].completion_time; // AT = 0
    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
  }

  int total_wt = 0, total_tat = 0;

  // Table output
  printf("\nPID\tBT\tWT\tTAT\tCT\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time,
           p[i].turnaround_time, p[i].completion_time);

    total_wt += p[i].waiting_time;
    total_tat += p[i].turnaround_time;
  }

  printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

  // -------- SIMPLE GANTT CHART --------
  printf("\nGantt Chart:\n");

  // Process sequence
  for (int i = 0; i < n; i++) {
    printf("P%d ", p[i].pid);
    if (i != n - 1)
      printf("| ");
  }

  printf("\n0 ");
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i].completion_time);
  }

  printf("\n");

  return 0;
}