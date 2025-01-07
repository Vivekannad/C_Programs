#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 50
#define SMALL_BUS 20
#define BIG_BUS 40
#define DOUBLE_DECKER 60

typedef struct Bus {
    int id;
    char name[100];
    int availableSeats;
    int seats[DOUBLE_DECKER];
    int reservedSeats;
} Bus;

Bus busses[MAX_BUSES];

void clearBuffer();
void menu();
int userChoice();
void addBus(int *);
void displayBus(int);
void reserveSeats(int);
void cancelReservation(int);
void loadData();

int main() {
    int choice = 0, busCount = 0;
    loadData();
    while (choice != 5) {
        menu();
        choice = userChoice();
        switch (choice) {
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
                printf("Program exited successfully\n");
                exit(0);
            default:
                printf("Kindly select from the options\n");
        }
    }
    return 0;
}

void clearBuffer() {
    while (getchar() != '\n');
}

void loadData() {
    FILE *fptr = fopen("records.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int busCount = 0;
    while (fscanf(fptr, "ID: %d, Name: %99[^,], Available Seats: %d, Reserved Seats: %d\n", 
                  &busses[busCount].id, busses[busCount].name, 
                  &busses[busCount].availableSeats, &busses[busCount].reservedSeats) == 4) {
        busCount++;
    }
    fclose(fptr);
}

void menu() {
    printf("\n\nBus Reservation System");
    printf("\n1. Add Bus");
    printf("\n2. Display Buses");
    printf("\n3. Reserve Seat");
    printf("\n4. Cancel Reservation");
    printf("\n5. Exit\n");
}

int userChoice() {
    int choice, isValid;
    do {
        printf("Enter your choice: ");
        isValid = scanf("%d", &choice);
        clearBuffer();
        if (isValid != 1 || choice < 1 || choice > 5) {
            printf("Enter a number between 1 and 5\n");
        }
    } while (isValid != 1 || choice < 1 || choice > 5);
    return choice;
}

void addBus(int *busCount) {
    int size, i;
    FILE *fptr;
    fptr = fopen("records.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    if (*busCount >= MAX_BUSES) {
        printf("Maximum number of buses reached!\n");
        fclose(fptr);
        return;
    }
    char busSize;
    printf("Enter Bus ID: ");
    scanf("%d", &busses[*busCount].id);
    clearBuffer();
    printf("Enter the bus name: ");
    fgets(busses[*busCount].name, sizeof(busses[*busCount].name), stdin);
    busses[*busCount].name[strcspn(busses[*busCount].name, "\n")] = '\0';
    do {
        printf("Enter the bus size (s for 0-20, b for 0-40, d for 0-60): ");
        busSize = getchar();
        clearBuffer();
        if (busSize != 's' && busSize != 'b' && busSize != 'd') {
            printf("Kindly input from the following sizes\n");
        }
    } while (busSize != 's' && busSize != 'b' && busSize != 'd');
    size = busSize == 's' ? SMALL_BUS : busSize == 'b' ? BIG_BUS : DOUBLE_DECKER;
    busses[*busCount].availableSeats = size;
    busses[*busCount].reservedSeats = 0;
    fprintf(fptr, "ID: %d, Name: %s, Available Seats: %d, Reserved Seats: %d\n", busses[*busCount].id, busses[*busCount].name, busses[*busCount].availableSeats, busses[*busCount].reservedSeats);
    for (i = 0; i < size; i++) {
        busses[*busCount].seats[i] = 0;
    }
    fclose(fptr);
    (*busCount)++;
    printf("Bus added successfully\n");
}

void displayBus(int busCount) {
    int id, availableSeats;
    char name[100], s[256];
    FILE *fptr;
    fptr = fopen("records.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    if (busCount == 0) {
        printf("No Buses to display\n");
        fclose(fptr);
        return;
    }
    printf("\nID\t\tName\t\tAvailable Seats");
    printf("\n--------------------------------------------------------");
    while (fgets(s, sizeof(s), fptr) != NULL) {
        sscanf(s, "ID: %d, Name: %99[^,], Available Seats: %d", &id, name, &availableSeats);
        printf("\n%d\t\t%s\t\t%d", id, name, availableSeats);
    }
    fclose(fptr);
    printf("\n");
}

int getBusId(int *i, int busCount, int *isFound, char *prompt) {
    int id;
    printf("%s", prompt);
    scanf("%d", &id);
    for (*i = 0; *i < busCount; (*i)++) {
        if (id == busses[*i].id) {
            *isFound = 1;
            break;
        }
    }
    return id;
}

void getReservedSeatNo(int reserveSeats, int i) {
    int j, seatNo;
    printf("Enter your seat numbers:\n");
    for (j = 0; j < reserveSeats; j++) {
        do {
            printf("Seat %d at: ", j + 1);
            scanf("%d", &seatNo);
            clearBuffer();
            if (seatNo > busses[i].availableSeats || busses[i].seats[seatNo] != 0) {
                printf("Seat number not available\n");
            }
        } while (seatNo > busses[i].availableSeats || busses[i].seats[seatNo] != 0);
        busses[i].seats[seatNo] = 1;
    }
}

void reserveSeats(int busCount) {
    int id, i, isFound = 0, reserveSeats,j;
    id = getBusId(&i, busCount, &isFound, "Enter Bus ID you want to reserve your seats in: ");
    if (!isFound) {
        printf("Bus not found!\n");
        return;
    }
    do {
        printf("How many seats do you want to reserve? ");
        scanf("%d", &reserveSeats);
        if (busses[i].availableSeats < reserveSeats) {
            printf("Too many seats\n");
        } else if (reserveSeats < 0) {
            printf("Invalid input!\n");
        }
    } while (busses[i].availableSeats < reserveSeats || reserveSeats < 0);
    getReservedSeatNo(reserveSeats, i);
    busses[i].reservedSeats += reserveSeats;
    busses[i].availableSeats -= reserveSeats;
    printf("Seats reserved successfully\n");

    // Update the file with the new reservation details
    FILE *fptr = fopen("records.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int j = 0; j < busCount; j++) {
        fprintf(fptr, "ID: %d, Name: %s, Available Seats: %d, Reserved Seats: %d\n", busses[j].id, busses[j].name, busses[j].availableSeats, busses[i].reservedSeats);
    }
    fclose(fptr);
}

void cancelReservation(int busCount) {
    int i, id, isFound = 0;
    id = getBusId(&i, busCount, &isFound, "Enter Bus ID: ");
    if (!isFound) {
        printf("Bus not found!\n");
        return;
    }
    if (busses[i].reservedSeats <= 0) {
        printf("You have no reservation in the bus\n");
        return;
    }
    busses[i].availableSeats += busses[i].reservedSeats;
    busses[i].reservedSeats = 0;
    // Update the file with the new reservation details
    FILE *fptr = fopen("records.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int j = 0; j < busCount; j++) {
        fprintf(fptr, "ID: %d, Name: %s, Available Seats: %d, Reserved Seats: %d\n", busses[j].id, busses[j].name, busses[j].availableSeats);
    }
    fclose(fptr);
    printf("Reservation cancelled successfully\n");
}