#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 256
#define CONTENT_SIZE 1024

void clearBuffer();
void clearScreen();
void menu();
void createFile();
void readFile();
void writeToFile();
void renameFile();
void removeFile();

int main(){
    int choice = 0;
    while(choice != 6){
        printf("\n-----------------------------------------------FILE-MANAGEMENT-SYSTEM---------------------------------------------\n\n");
        menu();
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        switch(choice){
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                writeToFile();
                break;
            case 4:
                renameFile();
                break;
            case 5:
                removeFile();
                break;
            case 6:
                printf("Program exited successfully.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

void menu(){
    printf("Press 1) to create a file");
    printf("\nPress 2) to read a file");
    printf("\nPress 3) to write to a file");
    printf("\nPress 4) to rename a file");
    printf("\nPress 5) to delete a file");
    printf("\nPress 6) to exit");
}

void clearBuffer(){
    while(getchar() != '\n');
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux/MacOS
    #endif
}


const char* getFileNameAndExt(const char* prompt){
    static char fileName[FILENAME_SIZE];  //static enables the variable to be stored for the lifetime of code. // not in function's lifetime but the code.
    char extension[10];
    printf("%s", prompt);
    scanf("%s", fileName);  // as there is no space in file names. 
    clearBuffer();
    do{
        printf("Enter the file extension (e.g., .txt): ");
        scanf("%s", extension);     //as there is no space in extension
        clearBuffer();
        if(extension[0] != '.'){
            printf("Invalid extension input. Please start with a dot (.).\n");
        }
    }while(extension[0] != '.');
    strcat(fileName, extension);
    return fileName;
}

const char* getContent(){
    static char content[CONTENT_SIZE];
    printf("Enter the content: ");
    if (fgets(content, sizeof(content), stdin) == NULL) {
        printf("Error reading content.\n");
        content[0] = '\0';  // Ensure content is empty on error
    }
    return content;
}

void createFile(){
    char fileName[FILENAME_SIZE];
    char content[CONTENT_SIZE];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "w");
    if(fp == NULL){
        perror("Error opening the file.\n");    // prints the error
        return;
    }
    strcpy(content, getContent());
    fprintf(fp, "%s", content);
    fclose(fp);
    clearScreen();
    printf("File '%s' created successfully.\n", fileName);
}

void readFile(){
    char fileName[FILENAME_SIZE];
    char content[CONTENT_SIZE];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "r");
    if(fp == NULL){
        clearScreen();
        perror("Error opening the file.\n");
        return;
    }
    clearScreen();
    printf("Content of '%s':\n", fileName);
    while(fgets(content, sizeof(content), fp)){
        printf("%s", content);
    }
    fclose(fp);
}

void writeToFile(){
    char fileName[FILENAME_SIZE];
    char content[CONTENT_SIZE];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "a");
    if(fp == NULL){
        clearScreen();
        perror("Error opening the file.\n");
        return;
    }
    strcpy(content, getContent());
    fprintf(fp, "%s", content);
    fclose(fp);
    clearScreen();
    printf("Content added to '%s' successfully.\n", fileName);
}

void renameFile(){
    char oldFileName[FILENAME_SIZE];
    char newFileName[FILENAME_SIZE];
    strcpy(oldFileName, getFileNameAndExt("Enter your old file name: "));
    strcpy(newFileName, getFileNameAndExt("Enter your new file name: "));
    if (rename(oldFileName, newFileName) == 0) {
        clearScreen();
        printf("File renamed from '%s' to '%s' successfully.\n", oldFileName, newFileName);
    } else {
        clearScreen();
        perror("Error renaming the file.\n");
    }
}

void removeFile(){
    char fileName[FILENAME_SIZE];
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    if(remove(fileName) == 0){
        clearScreen();
        printf("File '%s' deleted successfully.\n", fileName);
    }else{
        clearScreen();
        perror("Error deleting the file.\n");
    }
}