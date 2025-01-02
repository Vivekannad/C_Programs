# Payroll Management System

This is a simple Payroll Management System written in C. It allows you to input employee details, calculate their net salary, sort employees by their net salary, and display the details.

## Features

- Input employee details including ID, name, basic salary, allowances, deductions, and bonus.
- Calculate net salary for each employee.
- Sort employees by their net salary in descending order.
- Display employee details.

## Usage

1. Clone the repository or download the source code.
2. Compile the `payroll.c` file using a C compiler.
3. Run the compiled executable.

### Input

- Enter the number of employees (between 1 and 50).
- For each employee, enter the following details:
  - ID
  - Name
  - Basic Salary
  - Allowances
  - Deductions (must be less than or equal to the basic salary)
  - Bonus

### Output

The program will display the details of each employee, sorted by their net salary in descending order.

## Example

```
Enter the number of employees (1-50): 2
Enter the id of employee: 1
Enter the name of employee: John Doe
Enter basic salary of the employee: 5000
Enter allowances of the employee: 1000
Enter deductions of the employee: 500
Enter the bonus for the employee: 200

Enter the id of employee: 2
Enter the name of employee: Jane Smith
Enter basic salary of the employee: 6000
Enter allowances of the employee: 1200
Enter deductions of the employee: 600
Enter the bonus for the employee: 300

Emp Id: 2
Emp Name: Jane Smith
Emp Basic Salary: 6000.00
Emp Allowances: 1200.00
Emp Deductions: 600.00
Emp Bonus: 300.00
Emp Net Salary: 6900.00

Emp Id: 1
Emp Name: John Doe
Emp Basic Salary: 5000.00
Emp Allowances: 1000.00
Emp Deductions: 500.00
Emp Bonus: 200.00
Emp Net Salary: 5700.00
```
