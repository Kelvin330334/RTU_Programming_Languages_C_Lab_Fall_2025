// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100];
  char line[256];
  int line_count = 0;

  // BONUS: ask user for filename instead of using default "data.txt"
  printf("Enter filename to use: ");
  if (scanf("%99s", filename) != 1) {
    printf("Invalid filename.\n");
    return 1;
  }

  // 1. Open file for writing (mode = "w")
  fp = fopen(filename, "w");
  // 2. Check if file opened successfully
  if (fp == NULL) {
    printf("Failed to open file for writing.\n");
    return 1;
  }
  // 3. Write 2–3 lines of text to the file using fprintf()
  fprintf(fp, "This is line 1.\n");
  fprintf(fp, "This is line 2.\n");
  fprintf(fp, "This is line 3.\n");
  // 4. Close the file
  fclose(fp);

  // 5. Open file again for reading (mode = "r")
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Failed to open file for reading.\n");
    return 1;
  }
  // 6. Use fgets() in a loop to read and print each line to the console
  printf("\nContents of %s:\n", filename);
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }
  // 7. Close the file
  fclose(fp);

  // BONUS: count number of lines read
  printf("\nNumber of lines read: %d\n", line_count);

  return 0;
}