// Write a C program to implement solution of Producer consumer problem through
// Semaphore.
#include <stdio.h>
#include <stdlib.h>

int buffer[10];
int size;
int in = 0, out = 0;
int mutex = 1;
int empty;
int full = 0;

void sem_wait(int *sem) { (*sem)--; }
void sem_signal(int *sem) { (*sem)++; }

void producer(int n) {
  if (empty == 0) {
    printf("\nBuffer FULL! Producer BLOCKED\n");
    return;
  }

  sem_wait(&empty);
  sem_wait(&mutex);

  buffer[in] = n;
  printf("\nProduced: %d at position %d", n, in);
  in = (in + 1) % size;

  sem_signal(&mutex);
  sem_signal(&full);

  printf("\nBuffer status -> full=%d, empty=%d\n", full, empty);
}

void consumer() {
  if (full == 0) {
    printf("\nBuffer EMPTY! Consumer BLOCKED\n");
    return;
  }

  sem_wait(&full);
  sem_wait(&mutex);

  int item = buffer[out];
  printf("\nConsumed: %d from position %d", item, out);
  out = (out + 1) % size;

  sem_signal(&mutex);
  sem_signal(&empty);

  printf("\nBuffer status -> full=%d, empty=%d\n", full, empty);
}

int main() {
  int choice;

  printf("Enter the size of the buffer: ");
  scanf("%d", &size);

  empty = size;

  while (1) {
    printf("\n1. Produce\n2. Consume\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int x;
      printf("Enter item to produce: ");
      scanf("%d", &x);
      producer(x);
      break;
    }
    case 2:
      consumer();
      break;

    case 3:
      exit(0);

    default:
      printf("Invalid input\n");
    }
  }
}