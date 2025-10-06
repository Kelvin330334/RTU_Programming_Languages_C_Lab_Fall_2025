/*
 * week4_2_struct_student.c
 * Author: [Kelvin Thuruthiyil BIJU ]
 * Student ID: [241ADB039]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and
 * grade. Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student s1, s2;

  // Assign values manually
  strcpy(s1.name, "Alice");
  s1.id = 101;
  s1.grade = 4.5f;

  strcpy(s2.name, "Bob");
  s2.id = 102;
  s2.grade = 3.8f;

  // Print struct contents
  printf("Student 1: Name: %s, ID: %d, Grade: %.2f\n", s1.name, s1.id,
         s1.grade);
  printf("Student 2: Name: %s, ID: %d, Grade: %.2f\n", s2.name, s2.id,
         s2.grade);

  return 0;
}