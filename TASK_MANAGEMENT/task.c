#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 50
#define RECORDS_FILE "tasks.txt"

typedef struct Task
{
    char title[50];
    char description[100];
    int priority;
    bool status;
} Task;

Task tasks[MAX_TASKS];

// Function declarations
void clearBuffer();
void menu();
void loadTasks(int *);
void userChoice(int *);
void inputTaskDetails(int *);
void updateTaskStatusValidation(int);
void updateTaskStatus(Task *);
void displayTaskDetails(int);
void centerText(const char *, int);
void centerNumber(int, int);

int main()
{
    int choice, taskCount = 0;
    loadTasks(&taskCount);
    printf("\n----------------------------TASK MANAGER-----------------------\n");
    while (choice != 4)
    {
        menu();              // prints the menu to user
        userChoice(&choice); // inputs from the user and validates
        switch (choice)
        {
        case 1:
            inputTaskDetails(&taskCount); // take all input details from user
            break;
        case 2:
            updateTaskStatusValidation(taskCount);
            break;
        case 3:
            displayTaskDetails(taskCount); // displays the tasks
            break;
        case 4:
            printf("Program exitted successfully "); // exits the program
            break;
        default:
            printf("Kindly select from the options "); // default code
        }
    }
    return 0;
}

void clearBuffer()
{
    while (getchar() != '\n'); // clears the buffer
}

void loadTasks(int *taskCount)
{
    FILE *file = fopen(RECORDS_FILE, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "Title:-%[^,], Description:- %[^,], Priority:- %d, Status:- %d\n", tasks[*taskCount].title, tasks[*taskCount].description, &tasks[*taskCount].priority, &tasks[*taskCount].status) == 4)
    {
        (*taskCount)++;
    }

    fclose(file);
}

void menu()
{
    printf("\n1. To input a task ");
    printf("\n2. To change the status of a task ");
    printf("\n3. To display the tasks");
    printf("\n4. Exit");
}

void userChoice(int *choice)
{
    int isValid;
    do
    {
        printf("\nEnter your choice:- ");
        isValid = scanf("%d", choice);
        clearBuffer();
        if (isValid != 1 || *choice < 1 || *choice > 4)
        { // validates if it is a number between 1 and 4.
            printf("\nEnter the number between 1 to 4\n");
        }
    } while (isValid != 1 || *choice < 1 || *choice > 4);
}

void inputTaskDetails(int *taskCount)
{
     FILE *fptr = fopen(RECORDS_FILE , "a");
    if (*taskCount > MAX_TASKS)
    {
        printf("Task input limit reached ");
        fclose(fptr);
        return;
    }
    printf("Enter the title of the task:-  ");
    scanf("%[^\n]", &tasks[*taskCount].title); // using bitwise operators to get string as input
    fprintf(fptr , "Title:-  %s,", tasks[*taskCount].title);
    clearBuffer();
    printf("Enter the task description:-  ");
    scanf("%[^\n]", &tasks[*taskCount].description);
       fprintf(fptr , " Description:- %s,", tasks[*taskCount].description);
    clearBuffer();
    printf("Enter the priority:-  ");
    scanf("%d", &tasks[*taskCount].priority);
       fprintf(fptr , " Priority:- %d,", tasks[*taskCount].priority);
    tasks[*taskCount].status = false;
       fprintf(fptr , " Status:- %d\n", tasks[*taskCount].status);
    printf("Status has been set to pending \n");
    clearBuffer(); // clearing newline character
    (*taskCount)++;
    fclose(fptr);
    printf("Task added successfully");
}

void updateTaskStatusValidation(int taskCount){
           if(taskCount > 0){
            int taskNumber;
            printf("Enter the number of the task (1-50) ");
            scanf("%d", &taskNumber);
            clearBuffer();
            if(taskNumber > taskCount || taskNumber <= 0){
                printf("Task not found ");
            }else{
            updateTaskStatus(&tasks[taskNumber - 1]); // updates the status
            }
        } else{
            printf("No, tasks are there to update ");
        }
}

void updateTaskStatus(Task *task)
{
    task->status = (!task->status) ? true : false;
    printf("Status Updated to %s\n", task->status ? "Done" : "Pending");

    // Update the file
    FILE *file = fopen(RECORDS_FILE, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < MAX_TASKS; i++)
    {
        if (strlen(tasks[i].title) > 0) // Check if the task is valid
        {
            fprintf(file, "Title:-%s, Description:- %s, Priority:-  %d, Status:-  %d\n", tasks[i].title, tasks[i].description, tasks[i].priority, tasks[i].status);
        }
    }

    fclose(file);
}

void centerText(const char *text, int width)
{ 
    int len = strlen(text);     // centers the text
    if (len >= width)
    {
        printf("%s", text);
        return;
    }
    int leftPadding = (width - len) / 2;
    int rightPadding = width - len - leftPadding;
    printf("%*s%s%*s", leftPadding, "", text, rightPadding, "");
}

void centerNumber(int number, int width)
{ 
    int numLength = snprintf(NULL, 0, "%d", number);    // centers the number

    if (numLength >= width)
    {
        printf("%d", number);
        return;
    }

    int leftPadding = (width - numLength) / 2;
    int rightPadding = width - numLength - leftPadding;
    printf("%*s%d%*s", leftPadding, "", number, rightPadding, "");
}

void displayTaskDetails(int taskCount)
{
    int i;
    if (taskCount <= 0)
    {
        printf("No tasks to display");
        return;
    }
    printf("\nHere are the tasks ");
    printf("\n------------------------------------------------------------------------------------------\n");
    centerText("No", 5);
    centerText("Title", 10); // text centering function
    centerText("Description", 40);
    centerText("Priority", 15);
    centerText("Status", 15);
    printf("\n------------------------------------------------------------------------------------------");
    for (i = 0; i < taskCount; i++)
    {
        printf("\n");
        centerNumber(i+1, 5);
        centerText(tasks[i].title, 10);
        centerText(tasks[i].description, 40);
        centerNumber(tasks[i].priority, 15); // number centering function
        centerText(tasks[i].status ? "Done" : "Pending", 15);
    }
    printf("\n------------------------------------------------------------------------------------------\n");
}