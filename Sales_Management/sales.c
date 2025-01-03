#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product {
    char name[100];
    int code;
    float price;
    int quantity;
    float salesValue;
} Product;

//Stock cannot be greater than 50.

void clearBuffer();
void menu();
void inputSalesData(Product* , int);

void main(){
int productCount = 0;
Product products[25];
 menu();
 inputSalesData(&products[productCount], productCount);

}

void clearBuffer(){
    while(getchar() != '\n');
}
void menu(){
    printf("\nPress 1 ")
}

void inputSalesData(Product *product, int count){
    char c;
    printf("Enter the name of the product ");
    fgets(product->name, sizeof(product->name), stdin); // also adds \n if length less than given size
    product->name[strcspn(product->name, "\n")] = '\0'; // removes extra \n
    printf("Enter the code of the product ");
    scanf("%d", &product->code);
    // scanf("%d", &product->code);
    // c = getchar();
    // printf("\n The character returned is %c and its ASCII code is %d", c , c);
    clearBuffer(); 
    printf("Enter the price of the product ");
    scanf("%f", &product->price);
    clearBuffer();
    printf("Enter the quantity in stock for this product ");
    scanf("%d", &product->quantity);
    clearBuffer();
    printf("Enter the total Sales Value for this product ");
    scanf("%f", &product->salesValue);
    clearBuffer();
}