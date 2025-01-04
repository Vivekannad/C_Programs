# Student Attendance Management System

## Overview
This project is a **Student Attendance Management System** implemented in C. It allows users to input and manage attendance records for a list of students. The system calculates attendance percentages and categorizes students as "Regular" or "Defaulter" based on their attendance percentage. It provides functionalities to input student details, calculate attendance, and display the data.

## Features
- Input and store details for up to 50 students.
- Calculate attendance percentage for each student.
- Automatically assign "Regular" or "Defaulter" status based on attendance.
- Display a summary of all students, including roll number, name, attendance percentage, and status.

## Code Structure
The project is structured as follows:

### Struct Definition
- **`struct Student`**: Represents a student with the following fields:
  - `rollNo`: The roll number of the student.
  - `name`: The name of the student.
  - `totalClasses`: The total number of classes conducted.
  - `attendedClasses`: The number of classes the student attended.
  - `attendancePercentage`: The percentage of attendance.
  - `status`: The attendance status ("Regular" or "Defaulter").

### Functions
1. **`clearBuffer`**: Clears the input buffer to prevent input issues.
2. **`attendedClasses`**: Validates and inputs the number of classes attended by a student.
3. **`calculateAttendancePercentageAndStatus`**: Calculates the attendance percentage and assigns the attendance status.
4. **`studentInputDetails`**: Inputs the details for all students.
5. **`displayAllStudents`**: Displays the attendance summary for all students.

### Main Function
- Prompts the user to input the number of students.
- Collects details for each student.
- Displays the attendance summary.


## Sample Input and Output
### Input
```
Enter the number of students: 2

Enter details for Student 1
Enter the roll No of the student: 1
Enter the name of the student: Alice
Enter the total number of classes: 50
Enter the total number of classes the student attended: 40

Enter details for Student 2
Enter the roll No of the student: 2
Enter the name of the student: Bob
Enter the total number of classes: 50
Enter the total number of classes the student attended: 30
```

### Output
```
Roll no		Name		Attendance %		Status
1		Alice		80.000000		Regular
2		Bob		60.000000		Defaulter
```

## Validation
- Ensures the number of students does not exceed the maximum limit (50).
- Prevents invalid inputs for attended classes (e.g., negative values or values exceeding total classes).

## Limitations
- Fixed maximum number of students (50).
- Attendance percentage and status displayed with limited formatting.

## Future Improvements
- Add functionality to update student records.
- Improve the formatting of displayed output.
- Implement file handling to save and load student data.

## Coder
Developed by **Vivek Anand**.

