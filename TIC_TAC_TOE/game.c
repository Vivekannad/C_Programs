#include <stdio.h>
#include <string.h>

void showBoard(char[]);
int checkForWin(char[]);

void main()
{
    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, isFound;
    int player = 1;
    char choice , mark; // X or O
    do
    {
        showBoard(arr);
        player = (player % 2) ? 1 : 2;
        // if (player % 2 == 1) player = 1 else player = 2;
        printf("Player %d turn  " , player);
        mark = (player == 1) ? 'X' : 'O';
        scanf("%c", &choice);
        while(getchar() != '\n');
        printf("The choice you entered is %c", choice);

        for(i = 1; i < strlen(arr); i++){
            if(arr[i] == choice){
                arr[i] = mark;
                isFound = 1;
                break;
            } 
        }

        // if (choice == 1 && arr[1] == '1')
        // {
        //     arr[1] = mark;
        // }
        // else if (choice == 2 && arr[2] == '2')
        // {
        //     arr[2] = mark;
        // }
        // else if (choice == 3 && arr[3] == '3')
        // {
        //     arr[3] = mark;
        // }
        // else if (choice == 4 && arr[4] == '4')
        // {
        //     arr[4] = mark;
        // }
        // else if (choice == 5 && arr[5] == '5')
        // {
        //     arr[5] = mark;
        // }
        // else if (choice == 6 && arr[6] == '6')
        // {
        //     arr[6] = mark;
        // }
        // else if (choice == 7 && arr[7] == '7')
        // {
        //     arr[7] = mark;
        // }
        // else if (choice == 8 && arr[8] == '8')
        // {
        //     arr[8] = mark;
        // }
        // else if (choice == 9 && arr[9] == '9')
        // {
        //     arr[9] = mark;
        // }
        if(!isFound)
        {
            printf("Invalid input ");
            player--;
            while(getchar() != '\n');   //Buffer clearing.
        }
        i = checkForWin(arr);
        if(i == -1) player++;
    } while (i == -1);
    showBoard(arr);
    if(i == 1){
        printf("player %d won", player);
    }else {
        printf("Game drawn");
    }
}

// void showBoard(char nums[]){
//   int i;
//   for (i = 0; i < strlen(nums); i++){
//     printf("|    |    |\n");
//     printf("| %c  ", nums[i]);
//     if(nums[i] % 3 == 0) printf("\n");
//     printf("-----|----|-------\n");
//   }
// }


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
    printf("-------|-------|-------\n");
}

int checkForWin(char charac[])
{
    int i;
    for(i = 0; i < 3; i++){
        if(charac[i] == charac[i+1] && charac[i+1] == charac[i+2]){
            return 1;
        }
    }
    for(i = 0; i < 3; i++){
        if(charac[i] == charac[i+3] && charac[i+3] == charac[i+6]){
            return 1;
        }
    }

    // if (charac[1] == charac[2] && charac[2] == charac[3])
    //     return 1;
    // else if (charac[1] == charac[4] && charac[4] == charac[7])
    //     return 1;
    if (charac[1] == charac[5] && charac[5] == charac[9])
        return 1;
    // else if (charac[2] == charac[5] && charac[5] == charac[8])
    //     return 1;
    // else if (charac[3] == charac[6] && charac[6] == charac[9])
    //     return 1;
    // else if (charac[4] == charac[5] && charac[5] == charac[6])
    //     return 1;
    // else if (charac[7] == charac[8] && charac[8] == charac[9])
        // return 1;
    else if (charac[3] == charac[5] && charac[5] == charac[7])
        return 1;
        //for game draw
    else if(charac[1] != '1' && charac[2] != '2' && charac[3] != '3' && charac[4] != '4' && charac[5] != '5' && charac[6] != '6' && charac[7] != '7' && charac[8] != '8' && charac[9] != '9')
    return 0;
    else return -1;
}