#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 50

//question no 1 by Vivek anand

struct Student {
	int rollNo;
	char name[50];
	int totalClasses;
	int attendedClasses;
	float attendancePercentage;
	char status[50];
};

struct Student students[MAX_STUDENTS];

void clearBuffer(){
	while(getchar() != '\n');
}

void attendedClasses(int i){
	do{
	printf("Enter the total number of classes the student attended ");
	scanf("%d", &students[i].attendedClasses);
	if(students[i].attendedClasses > students[i].totalClasses ){
		printf("Student can not attend more classes than there are \n");
	}else if( students[i].attendedClasses < 0){
		printf("Invalid Input\n");
	}
	}while(students[i].attendedClasses > students[i].totalClasses || students[i].attendedClasses < 0);
}

void calculateAttendancePercentageAndStatus(int i){
	students[i].attendancePercentage =	(students[i].attendedClasses * 100)/students[i].totalClasses;
	if(students[i].attendancePercentage < 75) {
		strcpy(students[i].status, "Defaulter");
	}else strcpy(students[i].status, "Regular");
}
void studentInputDetails(int n ){
	int i;
	for(i = 0; i < n; i++){
	printf("\n\nEnter details for Student %d\n", i + 1);
	printf("ENter the roll No of the student ");
	scanf("%d", &students[i].rollNo);
	clearBuffer();
	printf("Enter the name of the student ");
	fgets(students[i].name, sizeof(students[i].name), stdin);
	students[i].name[strcspn(students[i].name, "\n")] = '\0';
	printf("Enter the total number of classes ");
	scanf("%d", &students[i].totalClasses);	
	attendedClasses(i);	
	calculateAttendancePercentageAndStatus(i);
	}
}



void displayAllStudents(int n){
	int i;
	printf("\nRoll no\t\tName\t\tAttendance %\t\tStatus");
	for(i = 0; i < n; i++){
		printf("\n%d\t\t%s\t\t%f\t\t%s", students[i].rollNo, students[i].name, students[i].attendancePercentage, students[i].status);
	}
}

int main() {
	int n, studentCount;
	do{
	printf("Enter the number of students ");
	scanf("%d", &n );
	if(n > MAX_STUDENTS) {
		printf("You can input Max %d students", MAX_STUDENTS);
	}else if(n < 0){
		printf("Invalid input ");
	}	
	} while(n > MAX_STUDENTS || n < 0);
	struct Student students[n];
	studentInputDetails(n);
	displayAllStudents(n);
	return 0;
}