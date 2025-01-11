#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PARTICIPANTS 50
#define RECORDS_FILE "records.txt"

typedef struct Participant {
    char name[50];
    int id;
    char organization[50];
    int registrationFee;
    bool paymentStatus;
} Participant;
 
Participant participant[MAX_PARTICIPANTS];


void clearBuffer(){
    while(getchar() != '\n');
}

void loadParticipants(short int *count){
    FILE *fptr = fopen(RECORDS_FILE , "r");
    while(fscanf(fptr , "Name:- %99[^,], ID:- %d, Organization:- %99[^,], Fee:- %d, Status:- %d\n" , participant[*count].name , &participant[*count].id , participant[*count].organization , &participant[*count].registrationFee , &participant[*count].paymentStatus) == 5){
        (*count)++;
    }
    fclose(fptr);
}

void menu(){
    printf("\n1. Enter the participants details ");
    printf("\n2. Pay the Payment");
    printf("\n3. Display the participant");
    printf("\n4. Exit");
}

void userChoice(short int *choice){
    int isValid;
    do{
    printf("\nEnter the choice ");
    isValid = scanf("%d", choice);
    if( isValid != 1 || *choice < 1 || *choice > 4 ){
        printf("Kindly input the number between 1 and 4. ");
    }
    }while( isValid != 1 || *choice < 1 || *choice > 4 );
    clearBuffer();
}

void updatePaymentStatus(Participant * participant){
    if(participant->paymentStatus){
        printf("Fees is already paid\n");
        return;
    }
    int option;
    printf("Do you want to pay the fee, now? (1-Yes , 0 - No) ");
    scanf("%d", &option );
    clearBuffer();
    if(option){
        printf("fees paid successfully\n ");
        participant->paymentStatus = true;
        return;
    }
    participant->paymentStatus = false;
}


int isParticipantThere( int count ){
    int i, id;
    printf("Enter the participant id:- ");
    scanf("%d", &id);
    for(i = 0; i < count ; i++){
        if(participant[i].id == id){
           return i;
        }
    }
    return -1;
}

void userChoiceUpdatePaymentStatus(short int count){
    int i;
    int number = isParticipantThere(count);
    if(number >= 0){
        FILE *fptr = fopen(RECORDS_FILE , "w");
        updatePaymentStatus(&participant[number]);
        for(i = 0; i < count; i++){
            fprintf(fptr , "Name:- %s, ID:- %d, Organization:- %s, Fee:- %d, Status:- %d\n", participant[i].name , participant[i].id , participant[i].organization , participant[i].registrationFee , participant[i].paymentStatus);
            fclose(fptr);
        }
        return;
    }
    printf("There is no one by that id.\n");
    return;
}

int recursivelyAdjustFee(unsigned int fee){
    if(fee < 1000){
        return recursivelyAdjustFee(fee + 1);
    } else if (fee > 10000){
        return recursivelyAdjustFee(fee - 1);
    }
    return fee;
}

void enterRegistrationFee(Participant * participant){
    int i ;
     unsigned int feeSelected;
    printf("Select Registration Fee (1000 to 10000) ");
    scanf("%d", &feeSelected );
    clearBuffer();
    if(feeSelected < 1000 || feeSelected > 10000){
      participant->registrationFee =  recursivelyAdjustFee(feeSelected);
      printf("Fees adjusted.\n");
      return;
    }
    participant->registrationFee = feeSelected;
}

void inputParticipantData(short int* count){
    if(*count >= MAX_PARTICIPANTS){
        printf("The limit has been reached. \n");
        return;
    }
    FILE *fptr = fopen(RECORDS_FILE, "a");
    if(fptr == NULL){
        perror("Error in opening the file ");
        return;
    }

    printf("Enter the participant name ");
    fgets(participant[*count].name , sizeof(participant[*count].name), stdin);
    participant[*count].name[strcspn(participant[*count].name , "\n")] = '\0';
    fprintf(fptr , "Name:- %s,",participant[*count].name);

    printf("Enter the id ");
    scanf("%d", &participant[*count].id);
    fprintf(fptr , " ID:- %d,", participant[*count].id);
    clearBuffer();

    printf("Enter the organization name ");
    fgets(participant[*count].organization , sizeof(participant[*count].organization), stdin);
    participant[*count].organization[strcspn(participant[*count].organization , "\n")] = '\0';
    fprintf(fptr , " Organization:- %s,", participant[*count].organization);

    enterRegistrationFee(&participant[*count]);
    fprintf(fptr , " Fee:- %d,", participant[*count].registrationFee);

    updatePaymentStatus(&participant[*count]);
    fprintf(fptr , " Status:- %d\n", participant[*count].paymentStatus );
    (*count)++;
    fclose(fptr);

}

void centerNumber(int number , int width){
    int numLength = snprintf( NULL , 0 , "%d" , number );

    int leftPadding = (width - numLength) / 2;
    int rightPadding = width - numLength - leftPadding;
    printf("%*s%d%*s",leftPadding , "", number , rightPadding , "" );
}

void centerText(char *text , int width){
    int length = strlen(text);
    int leftPadding = (width - length) / 2;
    int rightPadding = width - length - leftPadding;
    printf("%*s%s%*s", leftPadding, "", text , rightPadding , "");
}

void displayParticipants(short int count){
    if(count <= 0){
        printf("Nothing in the records\n");
        return;
    }
    int i;
    printf("\n");
    centerText("Name", 30);
    centerText("Id", 10);
    centerText("Organization", 20);
    centerText("Fee", 10);
    centerText("Status", 20);
    printf("\n");
    for(i = 0 ; i  < count; i++){
    centerText(participant[i].name , 30);
    centerNumber(participant[i].id , 10);
    centerText(participant[i].organization , 20);
    centerNumber(participant[i].registrationFee, 10 );
    centerText(participant[i].paymentStatus == 1 ? "Paid" : "Unpaid", 20);
    printf("\n");
    }
}


int main(){
    short int choice, count = 0;
    loadParticipants(&count);
    while ( 1 )
    {
    menu();
    userChoice(&choice);
    switch( choice )
    {
        case 1:
            inputParticipantData(&count);
            break;
        case 2:
            userChoiceUpdatePaymentStatus(count);
            break;
        case 3:
            displayParticipants(count);
            break;
        case 4:
            printf("Exit successfully ");
            exit(0);
            break;
        default:
            printf("Kindly select from the options ");
    }
    }

}