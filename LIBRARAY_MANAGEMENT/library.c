#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 200
#define FILE_NAME "library_data.txt"


struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Book books[MAX_BOOKS];   

void menu();
void userChoice(int *);
void addBook(int);
void displayAvailableBooks(int);
void clearBuffer();
void checkOutBook(int);
void loadBooks(int *);

int main(){
    int choice, exitFlag = 0, bookCount = 0;
    loadBooks(&bookCount);
    while(!exitFlag){
        menu();
        userChoice(&choice);
        switch(choice){
            case 1:
                addBook(bookCount);
                bookCount++;
                printf("---------------------------------------\n");
                break;
            case 2:
                checkOutBook(bookCount);
                printf("---------------------------------------\n");
                break;
            case 3:
                displayAvailableBooks(bookCount);
                printf("---------------------------------------\n");
                break;
            case 4:
                printf("Program exited successfully\n");
                exitFlag = 1;
                break;
            default:
                printf("Choose between the options\n");
                printf("---------------------------------------\n");
        }
    }
    return 0;
}

void clearBuffer(){
    while(getchar() != '\n'); // Clear the input buffer
}

void menu(){
    printf("\nPress 1 to add a book");
    printf("\nPress 2 to check out a book");
    printf("\nPress 3 to display available books");
    printf("\nPress 4 to exit\n");
}

void userChoice(int *choice){   
    int isValid;
    do{
        printf("Enter your choice: ");
        isValid = scanf("%d", choice); // Pass the address of choice
        clearBuffer();
        if(isValid != 1 || *choice < 1 || *choice > 4){
            printf("Enter a number between 1 and 4\n");
        }
    }while(isValid != 1 || *choice < 1 || *choice > 4);
}

void addBook(int i){
    if(i >= MAX_BOOKS) {
        printf("You can add max %d books\n", MAX_BOOKS);
        return;
    }
    FILE *fp1;
    printf("Enter the book id: ");
    scanf("%d", &books[i].id); 
    clearBuffer(); // Clear the input buffer after reading an integer

    printf("Enter the book name: ");
    fgets(books[i].title, sizeof(books[i].title), stdin);
    books[i].title[strcspn(books[i].title, "\n")] = '\0'; // Remove newline character

    printf("Enter the author of the book: ");
    fgets(books[i].author, sizeof(books[i].author), stdin);
    books[i].author[strcspn(books[i].author, "\n")] = '\0'; // Remove newline character

    books[i].available = 1;

    fp1 = fopen(FILE_NAME, "a"); // Open file in append mode fopen(filename, mode);
    if (fp1 == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp1, "ID: %d, Title: %s, Author: %s, Available: %d\n", books[i].id, books[i].title, books[i].author, books[i].available); // Write book details to file
    printf("Book added successfully\n");
    fclose(fp1); // Close the file
}

void checkOutBook(int n){
    char bookName[100];
    int i, isFound = 0;
    printf("Enter the book name you want to checkout: ");
    fgets(bookName, sizeof(bookName), stdin);
    bookName[strcspn(bookName, "\n")] = '\0'; // Remove newline character

    for(i = 0; i < n; i++){
        if(strcmp(books[i].title, bookName) == 0 && books[i].available == 1){   //if found strsmp returns 0;
            books[i].available = 0;
            isFound = 1;
            printf("Book '%s' checked out successfully.\n", bookName);
            break;
        }
    }
    if(!isFound){
        printf("No available book with the name '%s' found in the record.\n", bookName);
    } else {
        FILE *fp1 = fopen(FILE_NAME, "w"); // Open file in write mode
        if (fp1 == NULL) {
            printf("Error opening file\n");
            return;
        }
        for(i = 0; i < n; i++){
            fprintf(fp1, "ID: %d, Title: %s, Author: %s, Available: %d\n", books[i].id, books[i].title, books[i].author, books[i].available); // Write updated book details to file
        }
        fclose(fp1); // Close the file
    }
}

void displayAvailableBooks(int bookCount){
    if(bookCount <= 0 ){
        printf("\nThere are no books in the library\n");
        return;
    } 
    FILE *fp;
    char s[256];
    fp = fopen(FILE_NAME, "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    int found = 0;
    while (fgets(s, sizeof(s), fp) != NULL) { // Read each line from the file
        int id, available;
        char title[100], author[100];
        // Parse the line to extract book details
        sscanf(s, "ID: %d, Title: %99[^,], Author: %99[^,], Available: %d", &id, title, author, &available);
        if (available == 1) { // Check if the book is available
            if (!found) {
                printf("These are available books:\n");
                found = 1;
            }
            printf("%s", s); // Print the book details
        }
    }
    if (!found) {
        printf("\nThere are no available books\n");
    }
    fclose(fp); // Close the file
}

void loadBooks(int *bookCount) {
    FILE *fp = fopen(FILE_NAME, "r"); // Open file in read mode
    // if (fp == NULL) {
    //     printf("Could not open file %s for reading.\n", FILE_NAME);
    //     return;
    // }

    while (fscanf(fp, "ID: %d, Title: %99[^,], Author: %99[^,], Available: %d\n", &books[*bookCount].id, books[*bookCount].title, books[*bookCount].author, &books[*bookCount].available) != EOF) {
        (*bookCount)++;
    }

    fclose(fp); // Close the file
}