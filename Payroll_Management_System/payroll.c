#include <stdio.h>
#include <string.h>
#define MAX_EMP 50

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float allowances;
    float deductions;
    float bonus;
    float netSalary;
};
struct Employee employee[MAX_EMP];  //globally declaring structure variable.

void salaryCalc(int i){
    employee[i].netSalary = employee[i].basicSalary + employee[i].allowances + employee[i].bonus - employee[i].deductions;
}
void clearBuffer(){
        while(getchar() != '\n');   //clears the buffer
}

void detailInput(int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Enter the id of emlpoyee ");
        scanf("%d", &employee[i].id);
        clearBuffer();
        printf("Enter the name of employee ");
        fgets(employee[i].name, sizeof(employee[i].name), stdin);   //using fgets for string input
        employee[i].name[strcspn(employee[i].name, "\n")] = '\0';
        printf("Enter basic salary of the employee ");
        scanf("%f", &employee[i].basicSalary);
        printf("ENter allowances of the employee ");
        scanf("%f", &employee[i].allowances);
        clearBuffer();
        do{
        printf("Enter deductions of the employee ");
        scanf("%f", &employee[i].deductions);
        clearBuffer();
        if(employee[i].deductions > employee[i].basicSalary){
            printf("deduction cannot be higher than the salary\n");
        }
        }while(employee[i].deductions > employee[i].basicSalary);
        printf("ENter the bonus for the employee ");
        scanf("%f", &employee[i].bonus);
        clearBuffer();
        salaryCalc(i);
    }
}

void sortByNetSalary(int n){
    int i,j;
    for(i = 0; i < n - 1; i++){
        for(j = i+1; j < n; j++){
            if (employee[i].netSalary < employee[j].netSalary) {
                struct Employee temp = employee[i];
                employee[i] = employee[j];
                employee[j] = temp;
            }
        }
    }
}
void displayEmpDetail(int n){
    int i;
    for(i = 0; i < n; i++){
        printf("\nEmp Id: %d", employee[i].id);
        printf("\nEmp Name: %s", employee[i].name);
        printf("\nEmp Basic Salary: %.2f", employee[i].basicSalary);
        printf("\nEmp Allowances: %.2f", employee[i].allowances);
        printf("\nEmp Deductions: %.2f", employee[i].deductions);
        printf("\nEmp Bonus: %.2f", employee[i].bonus);
        printf("\nEmp Net Salary: %.2f\n", employee[i].netSalary);
    }
}

int main(){
    int n;
    do{
    printf("Enter the number of employees (1-50)");
    scanf("%d", &n);
    if(n > MAX_EMP) printf("number should be between 1-50");
    } while(n > MAX_EMP);
    struct Employee employee[n];
    detailInput(n);
    sortByNetSalary(n);
    displayEmpDetail(n);
    return 0;
}