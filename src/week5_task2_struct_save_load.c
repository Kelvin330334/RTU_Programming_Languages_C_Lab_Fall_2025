// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
  Student s1;
  strcpy(s1.name, "Kelvin");
  s1.age = 21;
  s1.gpa = 3.75f;

  const char *filename = "student.txt";

  // Call save_student() to save student data to file
  save_student(s1, filename);

  // Call load_student() to read data back into a new struct
  Student s2 = load_student(filename);

  // Print loaded data to confirm correctness
  printf("Loaded student: Name: %s, Age: %d, GPA: %.2f\n", s2.name, s2.age,
         s2.gpa);

  return 0;
}

// Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error: could not open file for writing.\n");
    return;
  }
  fprintf(fp, "%s\n%d\n%.2f\n", s.name, s.age, s.gpa);
  fclose(fp);
}

// Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
  Student s;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: could not open file for reading.\n");
    // Return a default/empty student
    s.name[0] = '\0';
    s.age = 0;
    s.gpa = 0.0f;
    return s;
  }
  fgets(s.name, MAX_NAME_LEN, fp);
  // Remove trailing newline from name
  size_t len = strlen(s.name);
  if (len > 0 && s.name[len - 1] == '\n') s.name[len - 1] = '\0';
  fscanf(fp, "%d", &s.age);
  fscanf(fp, "%f", &s.gpa);
  fclose(fp);
  return s;
}