// Write C Program to simulate Paging technique.
#include <stdio.h>

// Computes floor(log2(n)) for n >= 1 using repeated division.
int log2int(int n) {
  int count = 0;
  while (n > 1) {
    n = n / 2;
    count++;
  }
  return count;
}
int main() {
  int processKB, pageBytes, memoryMB;
  int processBytes, memoryBytes;
  int totalFrames, totalPages;
  int physicalBits, logicalBits;
  int offsetBits, pageBits;

  printf("Enter Size of Process (in KB): ");
  scanf("%d", &processKB);
  printf("Enter Page Size (in Bytes): ");
  scanf("%d", &pageBytes);
  printf("Enter Size of Main Memory (in MB): ");
  scanf("%d", &memoryMB);

  // Convert all user inputs to bytes for uniform calculations.
  processBytes = processKB * 1024;
  memoryBytes = memoryMB * 1024 * 1024;

  // Frame/page count depends on page size.
  totalFrames = memoryBytes / pageBytes;
  totalPages = processBytes / pageBytes;

  // Address bits = log2(total addressable bytes).
  physicalBits = log2int(memoryBytes);
  logicalBits = log2int(processBytes);

  // Offset bits are decided by page size; remaining bits are page/frame bits.
  offsetBits = log2int(pageBytes);
  pageBits = logicalBits - offsetBits;
  printf("\nOUTPUT:\n");
  printf("1. Total number of frames in memory = %d\n", totalFrames);
  printf("2. Number of entries in page table = %d\n", totalPages);
  printf("3. Physical Address Bits = %d bits\n", physicalBits);
  printf(" Distribution: Frame bits = %d , Offset bits = %d\n",
         physicalBits - offsetBits, offsetBits);
  printf("4. Logical Address Bits = %d bits\n", logicalBits);
  printf(" Distribution: Page bits = %d , Offset bits = %d\n", pageBits,
         offsetBits);

  // page table entries
  int entries;
  printf("\nEnter number of page table entries to input: ");
  scanf("%d", &entries);

  int pageNo[entries], frameNo[entries], validBit[entries];
  for (int i = 0; i < entries; i++) {
    printf("Enter Page No, Frame No, Valid Bit: ");
    scanf("%d %d %d", &pageNo[i], &frameNo[i], &validBit[i]);
  }
  printf("\nPAGE TABLE\n");
  printf(" %-10s %-10s %-10s\n", "Page No", "Frame No", "Valid");
  for (int i = 0; i < entries; i++) {
    printf(" %-10d %-10d %-10d\n", pageNo[i], frameNo[i], validBit[i]);
  }
  while (1) {
    int choice;
    printf("\n1. Enter Logical Address\n2. Exit\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 2)
      break;

    // Logical address is entered as binary string of logicalBits length.
    char logicalAddr[100];
    printf("Enter Logical Address in binary (%d bits): ", logicalBits);
    scanf("%s", logicalAddr);

    // Extract page number from leftmost pageBits bits.
    int pageNumber = 0;
    for (int i = 0; i < pageBits; i++) {
      pageNumber = pageNumber * 2 + (logicalAddr[i] - '0');
    }

    // Search page table and check validity bit.
    int found = 0;
    for (int i = 0; i < entries; i++) {
      // Case-1: Page in memory → Hit
      if (pageNo[i] == pageNumber && validBit[i] == 1) {
        found = 1;
        printf("Page Hit\n");
        break;
      }
    }
    // Case-2: Page not in memory → Page Fault
    if (found == 0)
      printf("Page Fault\n");
  }
  return 0;
}