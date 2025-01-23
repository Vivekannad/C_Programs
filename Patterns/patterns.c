#include <stdio.h>


void pattern1();
void pattern2();
void pattern3();
void pattern4();
void pattern5();
void pattern6();
void pattern7();
void pattern8();
void pattern9();
void pattern10();
void pattern11();
void pattern12();
void pattern13();


int main () {
    // pattern1();
    // pattern2();
    // pattern3();
    // pattern4();
    // pattern5();
    // pattern6();
    // pattern7();
    // pattern8();
    // pattern9();
    // pattern10();
    // pattern11();
    // pattern12();
    pattern13();
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

void pattern6 () {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int k = n - i; k > 0 ; k--){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void pattern7 () {
    int n = 5;

    for(int i = 0; i < n; i++){
        for(int k = 0; k < i; k++){
            printf(" ");
        }
        for(int j = n; j > i; j--){
            printf("*");
        }
        printf("\n");
    }
}

void pattern8 () {
    int n = 5;
    for(int i = 1; i <= n; i++){
        for(int k = n; k > i; k--){
            printf(" ");
        }
        for(int j = 0; j < (2 * i) - 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void pattern9 () {
        int n = 5;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k < i; k++){
            printf(" ");
        }
        for(int j = (2 * n) - 1; j >= (2 * i) - 1 ; j--){
            printf("*");
        }
        printf("\n");
    }

}

void pattern10 () {
    int n = 5; 
    for(int i = 0; i < n; i++) {
        for(int k = n; k > i; k--){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void pattern11 () { 
    int n = 5;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < i; k++) {
            printf(" ");
        }
        for(int j = n; j > i; j--) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern12 () {
    //optimized way you can also choose to make two separate loops.
    
    int n = 5;
    for(int i = 0; i < 2 * n; i++) {
        int spaceInit = i < n ? n - i : (i-n)+1 ;
        for(int k = spaceInit; k < n; k++) {
            printf(" ");
        }
    
        for(int j = spaceInit; j > 0; j--) {
            printf("* ");
        }
        printf("\n");
    }
}

void pattern13 () {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int k = n; k > i; k--) {
            printf(" ");
        }
        for(int j = 1; j <= (2 * i) - 1; j++) {
            if(j == 1 || j == 2 * i - 1 || i == n     ){
                printf("*");
            }else printf(" ");
        }
        printf("\n");
    }
}