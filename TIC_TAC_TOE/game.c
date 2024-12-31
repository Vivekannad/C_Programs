#include <stdio.h>
#include <conio.h>

void showBoard(char[]);
int checkForWin(char[]);

void main()
{
    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int choice, i;
    int player = 1;
    char mark; // X or O
    do
    {
        showBoard(arr);
        player = (player % 2) ? 1 : 2;
        printf("Player %d turn  " , player);
        mark = (player == 1) ? 'X' : 'O';
        scanf("%d", &choice);

        if (choice == 1 && arr[1] == '1')
        {
            arr[1] = mark;
        }
        else if (choice == 2 && arr[2] == '2')
        {
            arr[2] = mark;
        }
        else if (choice == 3 && arr[3] == '3')
        {
            arr[3] = mark;
        }
        else if (choice == 4 && arr[4] == '4')
        {
            arr[4] = mark;
        }
        else if (choice == 5 && arr[5] == '5')
        {
            arr[5] = mark;
        }
        else if (choice == 6 && arr[6] == '6')
        {
            arr[6] = mark;
        }
        else if (choice == 7 && arr[7] == '7')
        {
            arr[7] = mark;
        }
        else if (choice == 8 && arr[8] == '8')
        {
            arr[8] = mark;
        }
        else if (choice == 9 && arr[9] == '9')
        {
            arr[9] = mark;
        }
        else
        {
            printf("Invalid input ");
            player--;
            while(getchar() != '\n');
            // getch();
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
    if (charac[1] == charac[2] && charac[2] == charac[3])
        return 1;
    else if (charac[1] == charac[4] && charac[4] == charac[7])
        return 1;
    else if (charac[1] == charac[5] && charac[5] == charac[9])
        return 1;
    else if (charac[2] == charac[5] && charac[5] == charac[8])
        return 1;
    else if (charac[3] == charac[6] && charac[6] == charac[9])
        return 1;
    else if (charac[4] == charac[5] && charac[5] == charac[6])
        return 1;
    else if (charac[7] == charac[8] && charac[8] == charac[9])
        return 1;
    else if (charac[3] == charac[5] && charac[5] == charac[7])
        return 1;
        //for game draw
    else if(charac[1] != '1' && charac[2] != '2' && charac[3] != '3' && charac[4] != '4' && charac[5] != '5' && charac[6] != '6' && charac[7] != '7' && charac[8] != '8' && charac[9] != '9')
    return 0;
    else return -1;
}