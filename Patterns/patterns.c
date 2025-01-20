#include <stdio.h>


void pattern1();
void pattern2();

int main () {
    // pattern1();
    pattern2();
    return 0;
}

void pattern1() {
    int n = 5;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

void pattern2 () {
    int n = 5;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}