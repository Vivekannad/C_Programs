#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void boarder();
void gotoxy(int , int);
void clearScreen();

int main(){
    clearScreen();
    boarder();

    gotoxy(2,2);
    printf("---------------------------------SNAKE_GAME--------------------------------");
    printf("\n%c Use Arrow keys to move the snake", 179);
    printf("\n%c Backward movement is not allowed", 179);
    printf("\n%c Press Enter key, anytime to end the game ", 179);
    printf("\n%c Don't maximize the window ", 179);
    printf("\n%c Press any key to continue ",179);

    getch();
    clearScreen();
    boarder();
    return 0;
}

void gotoxy(int x, int y){
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void clearScreen() {
    system("cls");
    // printf("\033[2J"); // Clear the screen
    // printf("\033[H");  // Move cursor to top-left
}

void boarder(){
    int width = 50;
    int height = 25;
    int i;

    // Top border
    // printf("%c", 218);
    for(i = 1; i <= width; i++){
        gotoxy(i,1);
        printf("%c", 196);
        gotoxy(i,height);
        printf("%c", 196);
    }
    // printf("%c", 191);

    // Side borders
    for(i = 1; i <= height; i++){
        gotoxy(1 , i);
        printf("%c", 179);
        gotoxy(width , i);
        printf("%c", 179);
    }

    gotoxy(width, height);
}