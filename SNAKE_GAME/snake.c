#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 30
#define MAX_TAIL 100

// Movement directions
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

// Global variables
int x, y, fruitX, fruitY, flag, gameEnd, score = 0;
int tailX[MAX_TAIL], tailY[MAX_TAIL], tailLength;

// Function declarations
void draw();
void setUp();
void input();
void makeLogic();
void gotoxy(int x, int y);
void clearScreen();
void instructions();
void hideCursor();

int main() {
    clearScreen();
    instructions();
    getch();
    clearScreen();
    setUp();
    hideCursor();
    while (!gameEnd) {
        input();
        makeLogic();
        draw();
        printf("The score is %d\n", score);
        Sleep(500 - score); // Dynamic speed increase
    }

    printf("\nGame Ended!!\n");
    Sleep(1000);
    return 0;
}

// Clears the console screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

//instructions of the game
void instructions() {
    printf("\nWELCOME TO THE SNAKE GAME\n");
    printf("Press w for upward direction\n");
    printf("Press s for downward direction\n");
    printf("Press a for left direction\n");
    printf("Press d for right direction\n");
    printf("The game would be over if snake hits the boundary or hits its own tail\n");
    printf("Press any key to continue");
}

// Moves the cursor to a specific position
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Initializes game variables
void setUp() {
    srand(time(NULL));
    y = HEIGHT / 2;  // y represents vertical axis
    x = WIDTH / 2;   // x represents horizontal axis

    fruitY = (rand() % (HEIGHT - 2)) + 1;
    fruitX = (rand() % (WIDTH - 2)) + 1;

    gameEnd = 0;
    tailLength = 0;
    score = 0;
    flag = RIGHT;
}

// Handles user input for movement
void input() {
    if (kbhit()) { // If a key is pressed
        switch (getch()) {
            case 'w': flag = UP; break;
            case 's': flag = DOWN; break;
            case 'd': flag = RIGHT; break;
            case 'a': flag = LEFT; break;
        }
    }
}

// Updates game logic
void makeLogic() {
    // Update tail position
    for (int i = tailLength - 1; i > 0; i--) {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }

        tailX[0] = x;
        tailY[0] = y;


    // Move snake
    switch (flag) {
        case UP:    y--; break;
        case DOWN:  y++; break;
        case RIGHT: x++; break;
        case LEFT:  x--; break;
    }

    // Check boundary collision
    if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH) {
        gameEnd = 1;
        return;
    }

    // Check self-collision
    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameEnd = 1;
            return;
        }
    }

    // Check if snake eats the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        tailLength++;

        // Generate new fruit location
        int fruitOnTail;
        do {
            fruitOnTail = 0;
            fruitX = (rand() % (WIDTH - 2)) + 1;
            fruitY = (rand() % (HEIGHT - 2)) + 1;

            for (int i = 0; i < tailLength; i++) {
                if (fruitX == tailX[i] && fruitY == tailY[i]) {
                    fruitOnTail = 1;
                    break;
                }
            }
        } while (fruitOnTail || (fruitX == x && fruitY == y));
    }
}

// Renders the game board
void draw() {
    gotoxy(0, 0);
    
    for (int i = 0; i <= HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            if (i == 0 || i == HEIGHT || j == 0 || j == WIDTH) {
                printf("*"); // Walls
            } else if (i == y && j == x) {
                printf("O"); // Snake head
            } else if (i == fruitY && j == fruitX) {
                printf("&"); // Fruit
            } else {
                int tailFound = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (i == tailY[k] && j == tailX[k]) {
                        printf("o"); // Snake tail
                        tailFound = 1;
                        break;
                    }
                }
                if (!tailFound) printf(" ");
            }
        }
        printf("\n");
    }
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}