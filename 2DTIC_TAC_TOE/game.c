#include <stdio.h>

#define MAX_COLS 3

void showBoard(char[][MAX_COLS], int);
int checkSquareEmpty(char[][MAX_COLS], int, int, int, char);
int checkForWin(char[][MAX_COLS], int);

void main(){
  char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  int player = 1, i, rowChoice, colChoice, isValid;
  char mark; // X or O
  for (i = -1; i == -1;){
    player = (player % 2) ? 1 : 2;
    mark = (player == 1) ? 'X' : 'O';
    showBoard(arr, 3);
    printf("player %d turn (%c) ", player, mark);
    do{
      printf(" Enter the row number (1-3)");
      isValid = scanf("%d", &rowChoice);
      if (isValid != 1 || rowChoice < 0 || rowChoice > 3){
        printf("Invalid input! put a number between (1-3) ");
      };
    } while (isValid != 1 || rowChoice < 1 || rowChoice > 3);
    do{
      printf("Enter the column number(1-3)");
      isValid = scanf("%d", &colChoice);
      if (isValid != 1 || colChoice < 0 || colChoice > 3)
      {
        printf("Invalid input! put a number between (1-3) ");
      };
    }
    while (isValid != 1 || colChoice < 1 || colChoice > 3);
    if (checkSquareEmpty(arr, 3, rowChoice - 1, colChoice - 1, mark))
    {
      i = checkForWin(arr, 3);
      if (i == 1)
      {
        showBoard(arr, 3);
        printf("Player %d wins", player);
      }
      else if (i == 0)
      {
        showBoard(arr, 3);
        printf("The game is a draw ");
      }
      else
      {
        player++;
      }
    }
  }
}

void showBoard(char nums[][MAX_COLS], int row)
{
  int i, j;
  for (i = 0; i < row; i++)
  {
    printf("|    |    |\n");
    for (j = 0; j < MAX_COLS; j++)
    {
      printf("| %c  ", nums[i][j]);
    }
    printf("\n");
    printf("-----|----|-------\n");
  }
}

int checkSquareEmpty(char nums[][MAX_COLS], int row, int rowChoice, int colChoice, char mark)
{
  if (nums[rowChoice][colChoice] != 'X' && nums[rowChoice][colChoice] != 'O')
  {
    nums[rowChoice][colChoice] = mark;
    return 1;
  }
  else{
    printf("Square already taken! Choose another one.\n");
    return 0;
  }
}

int checkForWin(char nums[][MAX_COLS], int row)
{
  if (nums[0][0] == nums[0][1] && nums[0][1] == nums[0][2])
    return 1;
  else if (nums[1][0] == nums[1][1] && nums[1][1] == nums[1][2])
    return 1;
  else if (nums[2][0] == nums[2][1] && nums[2][1] == nums[2][2])
    return 1;
  else if (nums[0][0] == nums[1][0] && nums[1][0] == nums[2][0])
    return 1;
  else if (nums[0][1] == nums[1][1] && nums[1][1] == nums[2][1])
    return 1;
  else if (nums[0][2] == nums[1][2] && nums[1][2] == nums[2][2])
    return 1;
  else if (nums[0][0] == nums[1][1] && nums[1][1] == nums[2][2])
    return 1;
  else if (nums[0][2] == nums[1][1] && nums[1][1] == nums[2][0])
    return 1;
  else if (nums[0][0] != '1' && nums[0][1] != '2' && nums[0][2] != '3' && nums[1][0] != '4' && nums[1][1] != '5' && nums[1][2] != '6' && nums[2][0] != '7' && nums[2][1] != '8' && nums[2][2] != '9')
  {
    return 0;
  }
  else
    return -1;
}
