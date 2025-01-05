#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer();
void menu();
void createFile();
void readFile();
void writeToFile();
void renameFile();
void removeFile();
// char* getFileNameAndExt();

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

const char* getFileNameAndExt(const char* prompt){
    static char fileName[100];  //static enables the variable to be stored for the lifetime of code. // not in function's lifetime but the code.
    char extension[10];
    printf("%s", prompt);
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName , "\n")] = '\0';
    do{
        printf("Enter the file extension (e.g., .txt): ");
        fgets(extension, sizeof(extension), stdin);
        extension[strcspn(extension , "\n")] = '\0';
        if(extension[0] != '.'){
            printf("Invalid extension input. Please start with a dot (.).\n");
        }
    }while(extension[0] != '.');
    strcat(fileName, extension);
    return fileName;
}

const char* getContent(){
    static char content[100];
    printf("Enter the content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content , "\n")] = '\0';
    return content;
}

void createFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Error opening the file.\n");
        return;
    }
    strcpy(content, getContent());
    fprintf(fp, "%s", content);
    fclose(fp);
    system("cls");
    printf("File '%s' created successfully.\n", fileName);
}

void readFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Error opening the file.\n");
        return;
    }
    system("cls");
    printf("Content of '%s':\n", fileName);
    while(fgets(content, sizeof(content), fp)){
        printf("%s", content);
    }
    fclose(fp);
}

void writeToFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    fp = fopen(fileName, "a");
    if(fp == NULL){
        printf("Error opening the file.\n");
        return;
    }
    strcpy(content, getContent());
    fprintf(fp, "%s", content);
    fclose(fp);
    system("cls");
    printf("Content added to '%s' successfully.\n", fileName);
}

void renameFile(){
    char oldFileName[100];
    char newFileName[100];
    strcpy(oldFileName, getFileNameAndExt("Enter your old file name: "));
    strcpy(newFileName, getFileNameAndExt("Enter your new file name: "));
    if (rename(oldFileName, newFileName) == 0) {
        system("cls");
        printf("File renamed from '%s' to '%s' successfully.\n", oldFileName, newFileName);
    } else {
        system("cls");
        printf("Error renaming the file.\n");
    }
}

void removeFile(){
    char fileName[100];
    strcpy(fileName, getFileNameAndExt("Enter the file name: "));
    if(remove(fileName) == 0){
        system("cls");
        printf("File '%s' deleted successfully.\n", fileName);
    }else{
        system("cls");
        printf("Error deleting the file.\n");
    }
}