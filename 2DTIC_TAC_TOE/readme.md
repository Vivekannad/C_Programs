# 2D Tic Tac Toe Game

This is a simple console-based 2D Tic Tac Toe game implemented in C.

## How to Play

1. The game is played on a 3x3 grid.
2. Player 1 is 'X' and Player 2 is 'O'.
3. Players take turns to enter the row and column number where they want to place their mark.
4. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.
5. If all 9 cells are filled and no player has three marks in a row, the game is a draw.


## Code Overview

The main functions in the code are:

- `void showBoard(char[][MAX_COLS], int)`: Displays the current state of the game board.
- `int checkSquareEmpty(char[][MAX_COLS], int, int, int, char)`: Checks if a square is empty and places the mark if it is.
- `int checkForWin(char[][MAX_COLS], int)`: Checks if there is a winner or if the game is a draw.

## Example

```
|    |    |
| 1  | 2  | 3  
-----|----|-------
|    |    |
| 4  | 5  | 6  
-----|----|-------
|    |    |
| 7  | 8  | 9  
-----|----|-------
```

Players will input the row and column number corresponding to the cell where they want to place their mark.

