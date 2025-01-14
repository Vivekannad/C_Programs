#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <

#define MAX_USERS 10
#define CREDENTIALS 30

typedef struct {
    char username[30];
    char password[CREDENTIALS];
}User;

User user[MAX_USERS];
int userCount = 0;

void menu();
void userChoice(int *);
void registerUser();
int userLogin();
void fix_fgets_input(char*);
void inputCredentials(char* , char*);

int main(){
    int choice;
while( 1 ){
        menu();
        userChoice(&choice);
        switch(choice){
            case 1:
            registerUser(&choice);
            break;
            case 2:
            int user_index = userLogin();
            if(user_index >= 0){
                printf("Welcome back! %s ", user[user_index].username );
            }else{
                printf("\nLogin Failed! Incorrect username or password. \n");
            }
            break;
            case 3:
            printf("\nExiting program");
            exit(0);
            break;
            default:
            printf("Enter between the choices ");
        }
    }
}

void menu(){
    printf("\nUser-Management-System");
    printf("\n1. Register");
    printf("\n2. Login");
    printf("\n3. Exit");
}
void userChoice(int *choice){
    printf("\nEnter your choice ");
    scanf("%d", choice );
    getchar();
}

void registerUser(){
    if(userCount >= MAX_USERS){
        printf("Maximum numbers reached \n.");
        return;
    }
    printf("\nEnter new User ");
    inputCredentials(user[userCount].username,user[userCount].password);

    userCount++;
    printf("Registration Successful ");
}

int userLogin(){
    int i;
    char username [CREDENTIALS];
    char password [CREDENTIALS];
    inputCredentials(username , password);

    for(i = 0; i < userCount; i++){
    if(strcmp(username , user[i].username) == 0 && strcmp(password , user[i].password) == 0){
        return i;
    }
    }

    return -1;
}

void fix_fgets_input(char *string){
    int index = strcspn(string , "\n");
    string[index] = '\0';
}

void inputCredentials(char* username , char *password){
      printf("Enter the name ");
    fgets(username, CREDENTIALS , stdin  );
    fix_fgets_input(username);
    printf("Enter the password ");
    fgets(password , CREDENTIALS , stdin);
    fix_fgets_input(password);
}