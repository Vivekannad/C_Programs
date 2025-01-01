# Tic Tac Toe Game

This is a simple Tic Tac Toe game implemented in C. The game allows two players to play against each other on the same computer.

## How to Play

1. The game board is represented by a 3x3 grid.
2. Players take turns to place their mark (X or O) on the board.
3. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the game.
4. If all nine squares are filled and no player has three marks in a row, the game is a draw.


## Code Structure

- `main()`: The main function that initializes the game and controls the game loop.
- `showBoard(char[])`: A function to display the current state of the game board.
- `checkForWin(char[])`: A function to check if there is a winner or if the game is a draw.

## Example

```
Player 1 turn
Enter your choice: 1

       |       |
   X   |   2   |   3
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

Player 2 turn
Enter your choice: 5

       |       |
   X   |   2   |   3
       |       |
-------|-------|-------
       |       |
   4   |   O   |   6
       |       |
-------|-------|-------
       |       |
   7   |   8   |   9
       |       |
-------|-------|-------
```

