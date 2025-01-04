#include <stdio.h>
#include <string.h>

void showBoard(char[]);
int checkForWin(char[]);

void main()
{
    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, isFound;
    int player = 1;
    char choice, mark; // X or O
    do
    {
        showBoard(arr);
        player = (player % 2) ? 1 : 2;
        printf("Player %d turn  ", player);
        mark = (player == 1) ? 'X' : 'O';
        scanf(" %c", &choice); // Added space before %c to consume any whitespace
        isFound = 0; // Initialize isFound to 0
        if (choice < '1' || choice > '9' || getchar() != '\n') { // Validate input range and ensure single character input
            printf("Invalid input\n");
            while(getchar() != '\n'); // Clear the buffer
        } else {
            for(i = 1; i < 10; i++){ // Corrected loop condition
                if(arr[i] == choice){
                    arr[i] = mark;
                    isFound = 1;
                    break;
                } 
            }

            if(!isFound)
            {
                printf("Invalid input\n");
                player--;
            }
        }
        i = checkForWin(arr);
        if(i == -1) player++;
    } while (i == -1);
    showBoard(arr);
    if(i == 1){
        printf("Player %d won\n", player);
    }else {
        printf("Game drawn\n");
    }
}

void showBoard(char charac[])
{
    printf("       |       |\n");
    printf("   %c   |   %c   |   %c \n", charac[1], charac[2], charac[3]);
    printf("       |       |\n");
    printf("-------|-------|-------\n");
    printf("       |       |\n");
    printf("   %c   |   %c   |   %c \n", charac[4], charac[5], charac[6]);
    printf("       |       |\n");
    printf("-------|-------|-------\n");
    printf("       |       |\n");
    printf("   %c   |   %c   |   %c \n", charac[7], charac[8], charac[9]);
    printf("       |       |\n");
}

int checkForWin(char charac[])
{
    // Check rows
    for(int i = 1; i <= 7; i += 3){
        if(charac[i] == charac[i+1] && charac[i+1] == charac[i+2]){
            return 1;
        }
    }
    // Check columns
    for(int i = 1; i <= 3; i++){ // Corrected loop increment
        if(charac[i] == charac[i+3] && charac[i+3] == charac[i+6]){
            return 1;
        }
    }
    // Check diagonals
    if (charac[1] == charac[5] && charac[5] == charac[9])
        return 1;
    if (charac[3] == charac[5] && charac[5] == charac[7])
        return 1;
    // Check for draw
    if(charac[1] != '1' && charac[2] != '2' && charac[3] != '3' && charac[4] != '4' && charac[5] != '5' && charac[6] != '6' && charac[7] != '7' && charac[8] != '8' && charac[9] != '9')
        return 0;
    return -1;
}