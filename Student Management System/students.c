#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char gender;
}Student;

void inputStudentsData(Student*);
void displayStudents(Student*);
void clearBuffer();

int main () {
    Student *student;
    int n;
    printf("Enter the number of students ");
    scanf("%d", &n);
    clearBuffer();
    student = (Student*) malloc (2 * sizeof(int));
    for(int i = 0; i < n; i++) {
    inputStudentsData((student + i));
    
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        displayStudents(student+ i);
        free(student[i].name);
    }

    free(student);
}

void inputStudentsData (Student *student) {
    char tempName[100];     //temporary name
    printf("Enter the name of the student ");
    scanf("%[^\n]", tempName);
    student->name = (char *) malloc (strlen(tempName) + 1); // one space for null character
    strcpy(student->name , tempName);
    printf("Enter the age of the student ");
    scanf("%d", &student->age);
    clearBuffer();
    printf("Enter the gender of the student ");
    student->gender =  getchar();
    clearBuffer();
}

void displayStudents (Student *student) {
    printf("\nName:- %s, Age:- %d, Gender:- %c", student->name , student->age , student->gender);
}

void clearBuffer() {
    while(getchar() != '\n');
}