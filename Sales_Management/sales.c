#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCK 50
#define RECORDS_FILE "records.txt"

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
void inputSalesData(Product[] , int, int);
void calculateSalesValue(Product*, int);
void recursiveAdjustStock(Product *, int);
void displayProducts(Product[],int);
void loadSalesData(Product [], int *);

int main()
{
    int n = 0, count = 0;
    Product products[n];
    loadSalesData(products , &count);
    printf("Enter the number of products ");
    scanf("%d", &n);
    clearBuffer();
    inputSalesData(products, n, count);
    displayProducts(products, n+count);
    return 0;
}

void clearBuffer()
{
    while (getchar() != '\n');
}

void inputSalesData(Product product[], int count, int n)
{
    int i;
        FILE *fp = fopen(RECORDS_FILE , "a");
    if(fp == NULL){
        perror("Eror opening the file");
        return;
    }
    for (i = 0; i < count; i++)
    {
        int place = i + n;
        printf("Enter the name of the product ");
        fgets(product[place].name, sizeof(product[place].name), stdin); // also adds \n if length less than given size
        product[place].name[strcspn(product[place].name, "\n")] = '\0'; // removes extra \n
        fprintf(fp, " %s,", product[place].name );
        printf("Enter the code of the product ");
        scanf("%d", &product[place].code);
        fprintf(fp , " %d,", product[place].code);
        clearBuffer();
        printf("Enter the price of the product ");
        scanf("%f", &product[place].price);
        fprintf(fp, " %.2f,", product[place].price);
        clearBuffer();
        printf("Enter the quantity in stock for this product (0-50) ");
        scanf("%d", &product[place].stockQuantity);
        clearBuffer();
        if (product[place].stockQuantity > MAX_STOCK) {
            recursiveAdjustStock(&product[place], product[place].stockQuantity - MAX_STOCK);
            printf("Stock adjusted !!\n");
        }
        fprintf(fp, " %d,", product[place].stockQuantity);
        calculateSalesValue(&product[place], place);
        fprintf(fp, " %.2f \n", product[place].salesValue);
    }
    fclose(fp);

}

void calculateSalesValue(Product *product, int n){
    (*product).salesValue = (*product).price * (*product).stockQuantity;
}

void recursiveAdjustStock(Product *product, int limit) {
    if (limit > 0) {
        product->stockQuantity--;
        recursiveAdjustStock(product, --limit);
    }
}


void displayProducts(Product product[], int n){
    int i;
    printf("\nName\t\tcode\tprice\tstock\tsalesValue");
    for(i = 0; i < n; i++){
        printf("\n%s\t\t%d\t%.1f\t%d\t%.2f", product[i].name, product[i].code , product[i].price, product[i].stockQuantity, product[i].salesValue);
    }
}

void loadSalesData(Product product[], int *count){
    FILE *file = fopen(RECORDS_FILE, "r");
    while(fscanf(file, " %99[^,], %d, %f, %d, %f", product[*count].name, &product[*count].code, &product[*count].price, &product[*count].stockQuantity, &product[*count].salesValue) == 5){
        printf("Data loaded successfully\n");
        (*count)++;
    }
    fclose(file);
}