#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
  char name[50];
  int id;
  char address[100];
} Student;

int main() {
  Student students[MAX_STUDENTS];
  int numStudents = 0;

  printf("Student Database\n");
  printf("================\n");

  // Adding students to the database
  char choice;
  do {
    Student newStudent;
    printf("\nEnter student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);

    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    getchar(); // Clearing the newline character from the input buffer

    printf("Enter student address: ");
    fgets(newStudent.address, sizeof(newStudent.address), stdin);

    students[numStudents++] = newStudent;

    printf("\nDo you want to add another student? (y/n): ");
    scanf("%c", &choice);
    getchar(); // Clearing the newline character from the input buffer

  } while (choice == 'y' || choice == 'Y');

  // Retrieving student information based on ID
  int searchID;
  printf("\nEnter student ID to search: ");
  scanf("%d", &searchID);

  int i;
  int found = 0;
  for (i = 0; i < numStudents; i++) {
    if (students[i].id == searchID) {
      printf("\nStudent Found:\n");
      printf("Name: %s", students[i].name);
      printf("ID: %d\n", students[i].id);
      printf("Address: %s", students[i].address);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("\nStudent with ID %d not found.\n", searchID);
  }

  return 0;
}
