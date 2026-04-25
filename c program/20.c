// Write a program to demonstrate the concept of deadlock avoidance through
// Banker’s Algorithm.
#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int numProcesses, numResources;

int totalResources[MAX_RESOURCES];
int maxDemand[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

// Calculate Available = Total - Allocated
void calculateAvailable() {
  for (int r = 0; r < numResources; r++) {
    int allocatedSum = 0;
    for (int p = 0; p < numProcesses; p++) {
      allocatedSum += allocation[p][r];
    }
    available[r] = totalResources[r] - allocatedSum;
  }
}

// Calculate Need = Max - Allocation
void calculateNeed() {
  for (int p = 0; p < numProcesses; p++) {
    for (int r = 0; r < numResources; r++) {
      need[p][r] = maxDemand[p][r] - allocation[p][r];
    }
  }
}

// Safety Algorithm
int checkSafety() {
  int work[MAX_RESOURCES];
  int finished[MAX_PROCESSES] = {0};
  int safeSequence[MAX_PROCESSES];

  int count = 0;

  // Work = Available
  for (int r = 0; r < numResources; r++) {
    work[r] = available[r];
  }

  while (count < numProcesses) {
    int foundProcess = 0;

    for (int p = 0; p < numProcesses; p++) {
      if (!finished[p]) {
        int canExecute = 1;

        for (int r = 0; r < numResources; r++) {
          if (need[p][r] > work[r]) {
            canExecute = 0;
            break;
          }
        }

        if (canExecute) {
          // Release resources
          for (int r = 0; r < numResources; r++) {
            work[r] += allocation[p][r];
          }

          safeSequence[count++] = p;
          finished[p] = 1;
          foundProcess = 1;
        }
      }
    }

    if (!foundProcess)
      break;
  }

  if (count == numProcesses) {
    printf("\nSystem is in SAFE state\nSafe Sequence: ");
    for (int i = 0; i < numProcesses; i++) {
      printf("P%d", safeSequence[i]);
      if (i != numProcesses - 1)
        printf(" -> ");
    }
    printf("\n");
    return 1;
  } else {
    printf("\nSystem is NOT SAFE (Deadlock possible)\n");
    return 0;
  }
}

// Resource Request Algorithm
void requestResources() {
  int processId;
  int request[MAX_RESOURCES];

  printf("\nEnter process number: ");
  scanf("%d", &processId);

  printf("Enter request vector:\n");
  for (int r = 0; r < numResources; r++) {
    scanf("%d", &request[r]);
  }

  // Check request <= need
  for (int r = 0; r < numResources; r++) {
    if (request[r] > need[processId][r]) {
      printf("Error: Request exceeds maximum need.\n");
      return;
    }
  }

  // Check request <= available
  for (int r = 0; r < numResources; r++) {
    if (request[r] > available[r]) {
      printf("Resources not available. Process must wait.\n");
      return;
    }
  }

  // Try allocation
  for (int r = 0; r < numResources; r++) {
    available[r] -= request[r];
    allocation[processId][r] += request[r];
    need[processId][r] -= request[r];
  }

  printf("\nChecking system safety after allocation...\n");

  if (checkSafety()) {
    printf("Request GRANTED.\n");
  } else {
    // Rollback
    for (int r = 0; r < numResources; r++) {
      available[r] += request[r];
      allocation[processId][r] -= request[r];
      need[processId][r] += request[r];
    }
    printf("Request DENIED. System would become unsafe.\n");
  }
}

int main() {
  printf("Enter number of processes: ");
  scanf("%d", &numProcesses);

  printf("Enter number of resource types: ");
  scanf("%d", &numResources);

  printf("\nEnter total resources:\n");
  for (int r = 0; r < numResources; r++) {
    scanf("%d", &totalResources[r]);
  }

  printf("\nEnter Max Demand Matrix:\n");
  for (int p = 0; p < numProcesses; p++) {
    printf("Process P%d:\n", p);
    for (int r = 0; r < numResources; r++) {
      scanf("%d", &maxDemand[p][r]);
    }
  }

  printf("\nEnter Allocation Matrix:\n");
  for (int p = 0; p < numProcesses; p++) {
    printf("Process P%d:\n", p);
    for (int r = 0; r < numResources; r++) {
      scanf("%d", &allocation[p][r]);
    }
  }

  calculateAvailable();
  calculateNeed();

  printf("\nNeed Matrix:\n");
  for (int p = 0; p < numProcesses; p++) {
    for (int r = 0; r < numResources; r++) {
      printf("%d ", need[p][r]);
    }
    printf("\n");
  }

  printf("\nAvailable Resources:\n");
  for (int r = 0; r < numResources; r++) {
    printf("%d ", available[r]);
  }
  printf("\n");

  checkSafety();

  char choice;
  printf("\nTest resource request? (y/n): ");
  scanf(" %c", &choice);

  if (choice == 'y' || choice == 'Y') {
    requestResources();
  }

  return 0;
}