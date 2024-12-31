# Tic Tac Toe Game

This is a simple console-based Tic Tac Toe game implemented in C.

## How to Play

1. The game is played on a 3x3 grid.
2. Player 1 is 'X' and Player 2 is 'O'.
3. Players take turns to enter the number corresponding to the cell where they want to place their mark.
4. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.
5. If all 9 cells are filled and no player has three marks in a row, the game is a draw.


## Code Overview

The main functions in the code are:

- `void showBoard(char[])`: Displays the current state of the game board.
- `int checkForWin(char[])`: Checks if there is a winner or if the game is a draw.
- `void main()`: The main function that controls the game flow.

## Example

```
       |       |
   1   |   2   |   3 
       |       |
-------|-------|-------
       |       |
   4   |   5   |   6 
       |       |
-------|-------|-------
       |       |
   7   |   8   |   9 
       |       |
-------|-------|-------

Player 1 turn
```

Players will input the number corresponding to the cell where they want to place their mark.
