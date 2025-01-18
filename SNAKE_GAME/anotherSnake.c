#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define HEIGHT 20
#define WIDTH 30

int x,y,fruitX, fruitY , flag , gameEnd , score = 0;

void draw();
void setUp();
void input();
void makeLogic();

int main () { 

    // getchar();
    setUp();
    while(gameEnd != 1) {
    input();
    if (flag != 0) { // Only draw and make logic if a key is pressed
        draw();
        makeLogic();
        flag = 0;
    }
    }
    return 0;

}

void draw () {
    system("cls");
int i, j , k;
for(i = 0 ; i <= HEIGHT ; i++){
    for(j  = 0; j <= WIDTH ; j++){

        if(i == 0 || i == HEIGHT || j == 0 || j == WIDTH ){
            printf("*");
        } else {
            if(i == x && j == y) {
                printf("0");
                for( k = 0; k < score ; k++){
                    printf("0");
                }
            } else if (i == fruitX && j == fruitY){
                printf("&");
            }else
            printf(" ");
        }
    }
        printf("\n");
    }
}

void setUp(){
    srand(time(NULL));
    if(score == 0){
    x = HEIGHT / 2;
    y = WIDTH / 2;

    }


    label1:
    fruitX = rand() % 20;
    if(fruitX == 0)
    goto label1;


    label2:
    fruitY = rand() % 20;
    if(fruitY == 0)
    goto label2;
    gameEnd = 0;
    score = 0;

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
            default:
                flag = 0;
        }
    }
}

void makeLogic () {
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

    if (x < 0 || x == HEIGHT || y < 0 || y == WIDTH) {
        printf("Game Ended \n");
        gameEnd = 1;
    }
        if(x == fruitX && y == fruitY) {
        score+=1;
        setUp();
    }
}
