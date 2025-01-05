#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer();
void menu();
void  createFile();
void readFile();
// char* getFileNameAndExt();

int main(){
    int choice;
    menu();
    while(choice != 6){
    printf("\n\nEnter you Choice:-  ");
    scanf("%d", &choice);
    clearBuffer();
    switch(choice){
        case 1:
        createFile();
        break;
        case 2:
        readFile();
        break;
        case 6:
        printf("Program exitted successfully");
        break;
        default:
        printf("Kindly select from the options ");
    }
    }

    return 0;
}

void menu(){
    printf("Press 1) to create a file");
    printf("\nPress 2) to read the file");
    printf("\nPress 3) to write to a file");
    printf("\nPress 4) to rename a file");
    printf("\nPress 5) to delete a file");
    printf("\nPress 6) to exit");
}

void clearBuffer(){
    while(getchar() != '\n');
}

const char* getFileNameAndExt(){
    int length;
    static char fileName[100];  //static enables the variable to be stored for the lifetime of code. // not in function's lifetime but the code.
    char extension[10];
    printf("Enter the file name ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName , "\n")] = '\0';
    length = strlen(fileName);
    do{
    printf("Enter the file extension ");
    fgets(extension, sizeof(extension), stdin);
    extension[strcspn(extension , "\n")] = '\0';
    if(extension[0] != '.'){
        printf("Invalid extension input .");
    }
    }while(extension[0] != '.');
    strcat(fileName, extension);
    return fileName;
}

char* getContent(){
    static char content[100];
    printf("Enter the content ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content , "\n")] = '\0';
    return content;
}

void createFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    // fileName =  getFileNameAndExt();
    strcpy(fileName, getFileNameAndExt());
    fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Error opening the file ");
        return;
    }
    strcpy(content, getContent());
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File created successfully");
}

void readFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt());
    fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Error opening the file ");
        return;
    }
    printf("Here is the content \n");
    while(fgets(content, sizeof(content), fp)){
        printf("%s", content);
    }
    fclose(fp);
}

void writetoFile(){
    char fileName[100];
    char content[100];
    FILE *fp;
    strcpy(fileName, getFileNameAndExt());
    fp = fopen(fileName, "a");
    if(fp == NULL){
        printf("Error opening the file ");
        return;
    }
    strcpy(content, getContent());
    fprintf(fp,  "%s", content);
    fclose(fp);
}