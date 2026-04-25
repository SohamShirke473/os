// Write a C program to implement solution of Producer consumer problem through
// Semaphore.
#include <stdio.h>
#include <stdlib.h>

int *buffer;
int size;

int in = 0, out = 0;

// Semaphores
int buffer_access = 1; // binary semaphore
int empty;             // counting semaphore
int full = 0;          // counting semaphore

// wait operation
void down(int *s) { (*s)--; }

// signal operation
void up(int *s) { (*s)++; }

// display semaphore values
void display() {
  printf("Empty = %d, Full = %d, Buffer_Access = %d\n", empty, full,
         buffer_access);
}

// Producer
void producer() {
  int item;

  if (empty == 0) {
    printf("Producer BLOCKED (Buffer Full)\n");
    display();
    return;
  }

  item = rand() % 100;

  down(&empty);
  down(&buffer_access);

  buffer[in] = item;
  printf("Produced: %d at position %d\n", item, in);
  in = (in + 1) % size;

  up(&buffer_access);
  up(&full);

  display();
}

// Consumer
void consumer() {
  int item;

  if (full == 0) {
    printf("Consumer BLOCKED (Buffer Empty)\n");
    display();
    return;
  }

  down(&full);
  down(&buffer_access);

  item = buffer[out];
  printf("Consumed: %d from position %d\n", item, out);
  out = (out + 1) % size;

  up(&buffer_access);
  up(&empty);

  display();
}

int main() {
  int choice;

  printf("Enter buffer size: ");
  scanf("%d", &size);

  buffer = (int *)malloc(size * sizeof(int));
  empty = size;

  while (1) {
    printf("\n--- MENU ---\n");
    printf("1. Schedule Producer\n");
    printf("2. Schedule Consumer\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      producer();
      break;
    case 2:
      consumer();
      break;
    case 3:
      free(buffer);
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}