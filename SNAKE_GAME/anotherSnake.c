#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h> // Include for Sleep function

#define HEIGHT 20
#define WIDTH 30

int x,y,fruitX, fruitY , flag , gameEnd , score = 0;
int tailX[100] , tailY[100];
int piece;

void draw();
void setUp();
void input();
void makeLogic();
void gotoxy(int x, int y);
void hideCursor();

int main () { 

    hideCursor();
    setUp();
    while(gameEnd != 1) {
        gotoxy(0,0);
        input();
        makeLogic();
        draw();
        Sleep(200); // Add a small delay to control the speed of the game
    }
    return 0;

}

void draw () {
    system("cls");
int i, j , k , ch;
for(i = 0 ; i <= HEIGHT ; i++){
    for(j  = 0; j <= WIDTH ; j++){

        if(i == 0 || i == HEIGHT || j == 0 || j == WIDTH ){
            printf("*");
        } else {
            if(i == x && j == y) {
                printf("0");
            } else if (i == fruitX && j == fruitY){
                printf("&");
            }else{
                ch = 0;
                for(k = 0; k < piece; k++){
                    if(i == tailX[k] && j == tailY[k]){
                        printf("o");
                        ch = 1;
                    }
                }
                if(ch == 0) printf(" ");
            }
        }
    }
        printf("\n");
    }
}

void setUp(){
    srand(time(NULL));
    x = HEIGHT / 2;
    y = WIDTH / 2;

    label1:
    fruitX = rand() % HEIGHT;
    if(fruitX == 0)
        goto label1;

    label2:
    fruitY = rand() % WIDTH;
    if(fruitY == 0)
        goto label2;

    gameEnd = 0;
    piece = 0;
    score = 0;
    flag = 3;
}

void input () {
    if(kbhit()) { // Call kbhit as a function
        switch(getch()) {
            case 'a' :
                flag = 1;
                break;
            case 's' :
                flag = 2;
                break;
            case 'd' :
                flag = 3;
                break;
            case 'f' :
                flag = 4;
                break;
         
        }
    }
}

void makeLogic () {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < piece; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(flag) {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
    }

    if (x >= HEIGHT || y >= WIDTH) {
        printf("Game Ended \n");
        gameEnd = 1;
    }

    for(int i = 0; i < piece; i++) {
        if(tailX[i] == x && tailY[i] == y) {
            printf("Game Ended \n");
            gameEnd = 1;
        }
    }

    if(x == fruitX && y == fruitY) {
        score += 10;
        piece++;
        
        label1:
        fruitX = rand() % HEIGHT;
        if(fruitX == 0)
            goto label1;

        label2:
        fruitY = rand() % WIDTH;
        if(fruitY == 0)
            goto label2;
    }
}


// Function to move cursor to top-left without clearing the screen
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   // getting the handle of output buffer
}

// Function to hide cursor
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}