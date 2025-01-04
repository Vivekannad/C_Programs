#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STOCK 50

typedef struct Product
{
    char name[100];
    int code;
    float price;
    int stockQuantity;
    float salesValue;
} Product;

// Stock cannot be greater than 50.

void clearBuffer();
void inputSalesData(Product *, int);
void calculateSalesValue(Product*, int);
// void adjustStock(Product*,int);
void displayProducts(Product*,int);

int main()
{
    int n;
    printf("Enter the number of products ");
    scanf("%d", &n);
    clearBuffer();
    Product products[n];
    inputSalesData(&products[n], n);
    calculateSalesValue(&products[n],n);
    // adjustStock(&products[n]);
    displayProducts(&products[n],n);
    return 0;
}

void clearBuffer()
{
    while (getchar() != '\n');
}

void inputSalesData(Product *product, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Enter the name of the product ");
        fgets(product->name, sizeof(product->name), stdin); // also adds \n if length less than given size
        product->name[strcspn(product->name, "\n")] = '\0'; // removes extra \n
        printf("Enter the code of the product ");
        scanf("%d", &product->code);
        clearBuffer();
        printf("Enter the price of the product ");
        scanf("%f", &product->price);
        clearBuffer();
        printf("Enter the quantity in stock for this product ");
        scanf("%d", &product->stockQuantity);
        clearBuffer();
    }
}

void calculateSalesValue(Product * product, int n){
    int i;
    for(i = 0; i < n; i++){
        (product)[i].salesValue = product[i].price * product[i].stockQuantity;
    }
}
// void adjustStock(Product * product, int n){
//     int i;
//     for(i = 0; i < n; i++){
//         if(product->stockQuantity > MAX_STOCK ){
//             adjustStock(&product, n);

//         }
//     }
// }

void displayProducts(Product * product, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("The sales value  is %f ", product[i].salesValue);
    }
}