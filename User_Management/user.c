#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#define MAX_USERS 10
#define CREDENTIALS 30

typedef struct
{
    char username[30];
    char password[CREDENTIALS];
} User;

//Global variables
User user[MAX_USERS];
int userCount = 0;

void clearBuffer();
void menu();
void userChoice(int *);
void registerUser();
int userLogin();
void fix_fgets_input(char *);
void inputCredentials(char *, char *);
void maskPassword(char *);
void getLogInTime();

int main()
{
    int choice;
    // while (1)
    // {
    //     menu();
    //     userChoice(&choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         registerUser(&choice);
    //         break;
    //     case 2:
    //         int user_index = userLogin();
    //         if (user_index >= 0)
    //         {
    //             printf("Welcome back! %s ", user[user_index].username); 
    //         }
    //         else
    //         {
    //             printf("\nLogin Failed! Incorrect username or password. \n");
    //         }
    //         break;
    //     case 3:
    //         printf("\nExiting program");
    //         exit(0);
    //         break;
    //     default:
    //         printf("Enter between the choices ");
    //     }
    // }

        getLogInTime();

        return 0;
}



void clearBuffer(){
    while(getchar() != '\n');
}

void menu()
{
    printf("\n\nUser Management System");
    printf("\n1. Register");
    printf("\n2. Login");
    printf("\n3. Exit");
}

void getLogInTime(){
    char timeString[30];
    //time_t: A type used to store the time in seconds since the Unix epoch (January 1, 1970)
    time_t currentTime;            // Variable to store time in seconds since epoch
    // A structure that holds detailed components of time (e.g., hours, minutes, seconds, year, month, day).
    struct tm *localTime;          // Structure to hold local time information

    // Get the current time in seconds
    currentTime = time(NULL);   // seconds passed since 1st Jan 1970.
    if (currentTime == -1) {
        printf("Error getting the current time.\n");
        return ;
    }

    // Convert to local time
    localTime = localtime(&currentTime);
    if (localTime == NULL) {
        printf("Error converting to local time.\n");
        return ;
    }


    // Display the time in a readable format
    sprintf(timeString , "%02d:%02d:%02d" , localTime->tm_hour,
           localTime->tm_min,
           localTime->tm_sec );
        printf("The time is %s", timeString);
}


void userChoice(int *choice)
{
    printf("\nEnter your choice ");
    scanf("%d", choice);
    clearBuffer();
}

void registerUser()
{
    if (userCount >= MAX_USERS)
    {
        printf("Maximum numbers reached \n.");
        return;
    }
    printf("Enter new User \n");
    inputCredentials(user[userCount].username, user[userCount].password);

    userCount++;
    printf("\nRegistration Successful ");
}

int userLogin()
{
    int i;
    char username[CREDENTIALS];
    char password[CREDENTIALS];
    inputCredentials(username, password);
    for (i = 0; i < userCount; i++)
    {
        if (strcmp(username, user[i].username) == 0 && strcmp(password, user[i].password) == 0)
        {
            return i;
        }
    }

    return -1;
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void inputCredentials(char *username, char *password){
    int wantMasked = 0, isValid;
    printf("Enter the name ");
    fgets(username, CREDENTIALS, stdin);
    fix_fgets_input(username);
    printf("Enter the password ");
    do{
        printf("\nDo you want it hidden or not? 1-hide 0-shown ");
        isValid = scanf("%d", &wantMasked);
        clearBuffer();  //clears the buffer to remove unnecessary characters
        if(isValid != 1 || (wantMasked != 1 && wantMasked != 0)){
            printf("Invalid Input! ");
        }
    }while(isValid != 1 || (wantMasked != 1 && wantMasked != 0));
    
    if(wantMasked){
        maskPassword(password);
    }else{
        printf("Password:- ");
        fgets(password, CREDENTIALS, stdin);
        fix_fgets_input(password);
    }
}

void maskPassword(char *password){
    printf("Password:- ");
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch(); // gets the input without putting it in output buffer
        if (ch == '\r')
        {
            break;
        }
        else if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
                //First \b: Moves the cursor one position back, so it is now on the last printed asterisk.
                //Space (' '): Overwrites the asterisk (*) with a blank space.
                //Second \b: Moves the cursor back again to the position where the asterisk was, so that further input will overwrite the correct position
            }
        }
        else
        {
            password[i++] = ch;

            printf("*");
        }
    }
    password[i] = '\0'; // null character to end the string when i index is end of string

    printf("\n the password is %s", password);
}