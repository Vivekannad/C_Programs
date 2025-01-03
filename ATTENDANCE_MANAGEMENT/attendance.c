#include <stdio.h>
#define MAX_STUDENTS 100

struct Attendance { //structure declaration
    char name[100];
    int rollNo;
    char attendance;
};

 struct Attendance student[MAX_STUDENTS];

 void clearBuffer(){
    while(getchar() != '\n');
 }
void menu(){
    printf("\n Press 1) to add a student");
    printf("\n Press 2) to mark the attendance ");
    printf("\n Press 3) to view the attendance ");
    printf("\n Press 4) to exit ");
}   //decleration
void addStudent(int n, int *studentCount){
    int i;
    for(i = 0; i < n; i++){
    printf("Enter the student name ");
    fgets(student[*studentCount].name, sizeof(student[*studentCount].name), stdin );
    printf("Enter the roll no ");
    scanf("%d", &student[*studentCount].rollNo);
    clearBuffer();
    (*studentCount)++;
    }

}

void markAttendance(int studentCount){
    int rollNoEntered , i , isFound = 0;
    printf("ENter the roll No of the student ");
    scanf("%d", &rollNoEntered);        //111
    clearBuffer();
    for(i = 0; i < studentCount; i++){
        if(rollNoEntered == student[i].rollNo){
            printf("Enter the attendance of the student (P for present) and (A for absent)");
            scanf("%c", &student[i].attendance);
            isFound = 1;    //true
        }
    }
    if(!isFound){
        printf("There is no student by that roll no ");
    }
}
void displayAllStudents(int studentCount){
    int i;
    for(i =0; i < studentCount; i++){
        printf("The student name is %s", student[i].name);
        printf("\nThe student roll no is %d", student[i].rollNo);
        printf("\nThe student attendance is %c", student[i].attendance);
    }
}

void exitLoop(int *exitFlag){
    *exitFlag = 1;
}

int main(){
    int n, choice, studentCount = 0, exitFlag = 0;  // false
    printf("Enter the number of students you want to add ");
    scanf("%d", &n);
    struct Attendance student[n];
    while(1){
        if(choice == 4) break;
        menu(); //calling
        printf("Enter the choice ");
        scanf("%d", &choice);  
        clearBuffer();
        switch(choice){
            case 1:
                addStudent(n, &studentCount);
                break;
            case 2:
                markAttendance(studentCount);
                break;
            case 3:
                displayAllStudents(studentCount);
                break;
            case 4:
                printf("Program exitted successfully");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    printf("Exiting the program.\n");
    return 0;
}