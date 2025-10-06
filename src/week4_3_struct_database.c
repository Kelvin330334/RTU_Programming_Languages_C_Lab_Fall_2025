/*
 * week4_3_struct_database.c
 * Author: [kelvin Thuruthiyil BIJU ]
 * Student ID: [241ADB039]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student *students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter name for student %d: ", i + 1);
    scanf("%49s", students[i].name);
    printf("Enter id for student %d: ", i + 1);
    scanf("%d", &students[i].id);
    printf("Enter grade for student %d: ", i + 1);
    scanf("%f", &students[i].grade);
  }

  printf("\nStudent Records:\n");
  printf("%-20s %-10s %-10s\n", "Name", "ID", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id,
           students[i].grade);
  }

  // Optional: Compute average grade
  float sum = 0.0f;
  for (int i = 0; i < n; i++) {
    sum += students[i].grade;
  }
  printf("\nAverage grade: %.2f\n", sum / n);

  free(students);

  return 0;
}