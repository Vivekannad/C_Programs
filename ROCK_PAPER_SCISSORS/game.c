    //Made By Mr.Vivekanand Chimrani.

#include <stdio.h>  //required
#include <stdlib.h> //required
#include <time.h>   //required
#include <string.h> //requires
#include <windows.h> //required

void menu();
void userChoice(char *, int *);
void clearBuffer();
void checkResult(char, char[], int *, int *);
void computerMoveHandler(char []);
void displayScores(int , int);

int main()
{

    int exitFlag = 0 , computerScore = 0 , userScore = 0;
    char computerMove[10];
    char userMove;
        printf("\n\t\t\t\t---------ROCK----PAPER----SCISSOR-----GAME");
    while(!exitFlag){
    menu();
    userChoice(&userMove, &exitFlag);
    if(exitFlag){
        printf("Exiting the program bye bye ");
        break;
    }
    printf("You chose %s and the computer chose ...", userMove == 'R' ? "Rock" : userMove == 'P' ? "Paper" : "Scissor");
    computerMoveHandler(computerMove);
    Sleep(700);
    checkResult(userMove, computerMove, &computerScore, &userScore);
    displayScores(computerScore, userScore);
    }
    return 0;
}

void clearBuffer()
{
    while (getchar() != '\n'); // clearing the buffer
}

void menu()
{
    printf("\nEnter R for rock");
    printf("\nEnter P for paper");
    printf("\nEnter S for scissors");
    printf("\nPress X to Exit");
}
void userChoice(char *move, int *exitFlag)
{
    int isValid;
    do
    {
        printf("\nEnter your move ");
        isValid = scanf("%c", move);
        clearBuffer();  //clearing buffer
        if (isValid != 1 || (*move != 'R' && *move != 'P' && *move != 'S' && *move != 'X')) //checking input
        {
            printf("\nKindly enter the move from the menu\n");
        }
        if(*move == 'X'){
            *exitFlag = 1;
        }
    } while (isValid != 1 || (*move != 'R' && *move != 'P' && *move != 'S'&& *move != 'X'));
}
void computerMoveHandler(char computerMove[])
{
    int random;
    srand(time(NULL));  // makes rand() to return different values
    random = rand() % 3;    // generating random number between 0,1,2.
    strcpy(computerMove, random == 0 ? "Rock" : random == 1 ? "Paper": "Scissor");  // initializing computerMove.
    Sleep(1000);
    printf(" %s\n", computerMove);
}
void checkResult(char userMove, char computerMove[], int *computerScore , int * userScore)
{
    switch (userMove)
    {
    case 'R':
        if (strcmp(computerMove, "Rock") == 0)  // we compare strings through strcmp() function
            printf("It is a Draw");
        if (strcmp(computerMove, "Paper") == 0){
            printf("Paper wraps up the rock, computer wins");
            (*computerScore)++;
        }
        if (strcmp(computerMove, "Scissor") == 0){
            printf("Rock breaks the scissor, You Win");
            (*userScore)++;
        }
        break;
    case 'P':
        if (strcmp(computerMove, "Rock") == 0){
            printf("Paper wraps up the rock, You win");
            (*userScore)++;
        }
        if (strcmp(computerMove, "Paper") == 0)
            printf("It is a Draw");
        if (strcmp(computerMove, "Scissor") == 0){
            printf("Scissor tears the paper, Computer Wins ");
                (*computerScore)++;
        }
        break;
    case 'S':
        if (strcmp(computerMove, "Rock") == 0){
            printf("Rock breaks the scissor, Computer Wins");
            (*computerScore)++;
        }
        if (strcmp(computerMove, "Paper") == 0){
            printf("Scissor tears the paper, You Win");
            (*userScore)++;
        }
        if (strcmp(computerMove, "Scissor") == 0)
            printf("It is a Draw");
        break;
    default:
        printf("Nothing between the options ");
    }
}
void displayScores(int computerScore , int userScore){
    printf("\nComputer\t\tYou\t\t");
    printf("\n%d%25d",computerScore, userScore);
 }

