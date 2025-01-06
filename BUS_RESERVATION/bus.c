#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 50

typedef struct Bus {
    int id;
    char name[100];
    int availableSeats;
    int reservedSeats;
}Bus;

Bus busses[MAX_BUSES];

void clearBuffer();
void menu();
int userChoice();
void addBus(int *);
void displayBus(int);
void reserveSeats(int);
void cancelReservation(int);

int main(){
    int choice, busCount = 0;
    while(choice != 5){
    menu();
    choice =  userChoice();
    switch(choice){
        case 1:
        addBus(&busCount);
        break;
        case 2:
        displayBus(busCount);
        break;
        case 3:
        reserveSeats(busCount);
        break;
        case 4:
        cancelReservation(busCount);
        break;
        case 5:
        printf("Program exitted successfully");
        break;
        default:
        printf("Kindly select from the options ");
    }
    }
    return 0;
}

void clearBuffer(){
    while(getchar() != '\n');
}

void menu(){
    printf("\n\nBus Reservation System");
    printf("\n1. Add Bus");
    printf("\n2. display Buses");
    printf("\n3. Reserve Seat");
    printf("\n4. Cancel Reservation");
    printf("\n5. Exit");
}

int userChoice(){
    int choice, isValid;
    do{
    printf("\nEnter your choice:-  ");
    isValid = scanf("%d", &choice);
    clearBuffer();
    if(isValid != 1 || choice < 1 || choice > 5){
        printf("Enter the number between (1-5)");
    }
    }while(isValid != 1 || choice < 1 || choice > 5);
    return choice;
}

void addBus(int *busCount){
    char busSize;
    printf("Enter Bus id ");
    scanf("%d", &busses[*busCount]);
    clearBuffer();
    printf("Enter the bus name ");
    fgets(busses[*busCount].name, sizeof(busses[*busCount].name), stdin);
    busses[*busCount].name[strcspn(busses[*busCount].name, "\n")] = '\0';
    do{
    printf("Enter the bus size  s for (0-20) b for (0-40) d for (0-60)");
    busSize = getchar();
    if(busSize != 's' && busSize != 'b' && busSize != 'd'){
        printf("Kindly input from following sizes\n ");
    }
    }while(busSize != 's' && busSize != 'b' && busSize != 'd');
    busses[*busCount].availableSeats = busSize == 's' ? 20 : busSize == 'b' ? 40 : 60;
    (*busCount)++;
    busses[*busCount].reservedSeats = 0;
    printf("Bus added successfully ");    
}

void displayBus(int busCount){
    int i;
    printf("\nID\t\tName\t\tAvailable Seats");
    printf("\n--------------------------------------------------------");
    for(i = 0; i < busCount; i++){
        printf("\n%d\t\t%s\t\t%d", busses[i].id, busses[i].name, busses[i].availableSeats);
    }
}

int getBusId(int *i, int busCount, int *isFound, char *prompt ){
    int id;
printf("%s", prompt);
    scanf("%d", &id);
    for(*i = 0; *i < busCount; i++){
        if(id == busses[*i].id){
            *isFound = 1;
            break;
        }
    }
    return id;
}

void reserveSeats(int busCount){
    int id, i, isFound = 0, reserveSeats;
   id = getBusId(&i, busCount, &isFound, "Enter Bus Id you want to reserve your seats in ");
    if(!isFound){
        printf("Bus not Found!!");
        return;
    }
    do{
    printf("How many seats you want to  reserve ");
    scanf("%d", &reserveSeats);
    if(busses[i].availableSeats < reserveSeats){
        printf("Too many seats ");
    }else if(reserveSeats < 0){
        printf("Invalid input!!!");
    }
    }while(busses[i].availableSeats < reserveSeats || reserveSeats < 0);
    busses[i].reservedSeats = reserveSeats;
    busses[i].availableSeats -= reserveSeats;
    printf("Seats reserved Successfully ");
}

void cancelReservation(int busCount){
    int i, id, isFound = 0;
    id = getBusId(&i, busCount, &isFound, "Enter Bus Id ");
    if(!isFound){
        printf("Bus not Found!!!");
        return;
    }
    if(busses[i].reservedSeats <= 0){
        printf("You have no reservation in the bus ");
        return;
    }
    busses[i].availableSeats += busses[i].reservedSeats;
    busses[i].reservedSeats = 0;
    printf("Reservation cancelled successfully");
}