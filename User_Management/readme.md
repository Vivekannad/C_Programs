# User Management System

This project is a simple user management system implemented in C. It allows users to register, log in, view registration history, and retrieve forgotten passwords. The system stores user credentials and registration times.

## Functions

### `void clearBuffer()`
Clears the input buffer to remove any leftover characters.

### `void menu()`
Displays the main menu with options to register, log in, view history, retrieve forgotten passwords, and exit.

### `void userChoice(int *choice)`
Prompts the user to enter their choice from the menu.

### `bool isUserAlreadyRegistered(char *username)`
Checks if a user with the given username is already registered.

### `void registerUser()`
Registers a new user by prompting for a username and password. It also stores the registration time.

### `int userLogin()`
Prompts the user to enter their username and password to log in. 

### `void modifyFgetsInput(char *string)`
Removes the newline character from the input string obtained using `fgets`.

### `bool inputCredentials(char *username, char *password)`
Prompts the user to enter their username and password. Allows the user to choose whether to mask the password.

### `void maskPassword(char *password)`
Masks the password input by displaying asterisks instead of the actual characters.

### `const char* getRegistrationTime()`
Returns the current time as a string in the format `HH:MM:SS`.

### `void displayRegisteredUsersHistory()`
Displays the registration history of all registered users, including their usernames and registration times.

### `int forgetPassword()`
Prompts the user to enter their username and retrieves the password if the user is found. 

## Libraries Used

### `<stdio.h>`
Provides functions for input and output operations, such as `printf`, `scanf`, and `fgets`.

### `<stdlib.h>`
Includes functions for memory allocation, process control, conversions, and others. Used here for `exit`.

### `<string.h>`
Contains functions for manipulating C strings and arrays, such as `strcmp`, `strcpy`, and `strcspn`.

### `<conio.h>`
Provides console input/output functions, such as `getch`, which is used to read a character from the console without echoing it.

### `<ctype.h>`
Includes functions for testing and mapping characters, such as `isdigit` and `isalpha`.

### `<time.h>`
Contains functions for manipulating date and time information, such as `time` and `localtime`.

### `<stdbool.h>`
Defines the boolean type and values `true` and `false`.

## Sample Code Output

```
User Management System
1. Register
2. Login
3. History
4. Forget Password
5. Exit

Enter your choice 1
Enter new User 
Enter the name JohnDoe
Enter the password 
Do you want it hidden or not? 1-hide 0-shown 1
Password:- ****
Registration Successful 

User Management System
1. Register
2. Login
3. History
4. Forget Password
5. Exit

Enter your choice 2
Enter the name JohnDoe
Enter the password 
Do you want it hidden or not? 1-hide 0-shown 1
Password:- ****
Welcome back! JohnDoe 

User Management System
1. Register
2. Login
3. History
4. Forget Password
5. Exit

Enter your choice 5

Exiting program
```

## How to Compile and Run

1. Save the code in a file named `user.c`.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `user.c`.
4. Compile the code using a C compiler, for example:
   ```
   gcc user.c -o user_management
   ```
5. Run the compiled program:
   ```
   ./user_management
   ```

