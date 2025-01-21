#include <stdio.h>


void pattern1();
void pattern2();
void pattern3();
void pattern4();
void pattern5();

int main () {
    // pattern1();
    // pattern2();
    // pattern3();
    // pattern4();
    pattern5();
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

void pattern3 () {
    int n = 5;
    for(int i = 0; i < n; i++){
        for(int j = n-i; j >= 1; j--){
            printf("*");
        }
        printf("\n");
    }
}

void pattern4 () {
    int n = 5;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= i; j++ ) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void pattern5 () {
    int n = 5;
    /* One way is this which is for beginners easy to understand
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1; i < n; i++){
        for(int j = n - i; j >= 1; j--){
            printf("*");
        }
        printf("\n");
    }
    */
   // 2nd way which is optimized as there is only one outer loop and one inner loop.
   int rowN = (2 * n) - 1;
   for(int i = 1; i <= rowN; i++){
    int colN = i <= n ? i : rowN - (i-1);
        for(int j = 0; j < colN; j++){
            printf("*");
        } 
        printf("\n");
   }
}