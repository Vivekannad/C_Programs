#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30

int x,y,fruitX, fruitY;

void draw();
void setUp();

int main() {
    setUp();
    draw();
    return 0;
}

void draw () {
int i, j;
for(i = 0 ; i <= HEIGHT ; i++){
    for(j  = 0; j <= WIDTH ; j++){

        if(i == 0 || i == HEIGHT || j == 0 || j == WIDTH ){
            printf("*");
        } else {
            if(i == x && j == y) {
                printf("0");
            } else if (i == fruitX && j == fruitY){
                printf("@");
            }else
            printf(" ");
        }
    }
        printf("\n");
    }
}

void setUp(){
    x = HEIGHT / 2;
    y = WIDTH / 2;

    label1:
    fruitX = rand() % 20;
    if(fruitX == 0)
    goto label1;


    label2:
    fruitY = rand() % 20;
    if(fruitY == 0)
    goto label2;

}
