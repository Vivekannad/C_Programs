# Bus Reservation System

This project is a simple Bus Reservation System implemented in C. It allows users to add buses, display available buses, reserve seats, and cancel reservations. The data is stored in a file named `records.txt`.

## Features

- Add a new bus with a unique ID, name, and size.
- Display all available buses with their details.
- Reserve seats in a specific bus.
- Cancel reservations in a specific bus.
- Load bus data from a file on startup.

## Files

- `bus.c`: The main source code file containing the implementation of the Bus Reservation System.
- `records.txt`: The file used to store bus data.

## Functions

- `void clearBuffer()`: Clears the input buffer.
- `void menu()`: Displays the main menu.
- `int userChoice()`: Gets the user's choice from the menu.
- `void addBus(int *busCount)`: Adds a new bus to the system.
- `void displayBus(int busCount)`: Displays all available buses.
- `void reserveSeats(int busCount)`: Reserves seats in a specific bus.
- `void cancelReservation(int busCount)`: Cancels reservations in a specific bus.
- `void loadData(int *busCount)`: Loads bus data from the file.

## Usage

1. Compile the `bus.c` file using a C compiler:
    ```sh
    gcc bus.c -o bus_reservation
    ```

2. Run the compiled program:
    ```sh
    ./bus_reservation
    ```

3. Follow the on-screen instructions to interact with the Bus Reservation System.

## Example

Here is an example of how to use the system:

1. Add a new bus:
    ```
    Enter Bus ID: 1
    Enter the bus name: Bus A
    Enter the bus size (s for 0-20, b for 0-40, d for 0-60): s
    Bus added successfully
    ```

2. Display available buses:
    ```
    ID      Name            Available Seats
    ----------------------------------------
    1       Bus A           20
    ```

3. Reserve seats:
    ```
    Enter Bus ID you want to reserve your seats in: 1
    How many seats do you want to reserve? 5
    Enter your seat numbers:
    Seat 1 at: 1
    Seat 2 at: 2
    Seat 3 at: 3
    Seat 4 at: 4
    Seat 5 at: 5
    Seats reserved successfully
    ```

4. Cancel reservations:
    ```
    Enter Bus ID: 1
    Reservation cancelled successfully
    ```

## Notes

- Ensure that the `records.txt` file is in the same directory as the executable.
- The system supports a maximum of 50 buses.
- The bus sizes are defined as follows:
  - Small Bus: 20 seats
  - Big Bus: 40 seats
  - Double Decker: 60 seats
