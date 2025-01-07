# Library Management System

This is a simple Library Management System written in C. It allows users to add books, check out books, and display available books. The book data is stored in a text file (`library_data.txt`).

## Features

- Add a new book to the library
- Check out a book from the library
- Display all available books in the library

## Files

- `library.c`: The main source code file containing all the functions and logic for the Library Management System.
- `library_data.txt`: The file where book data is stored.

## Functions

### `void menu()`
Displays the menu options to the user.

### `void userChoice(int *choice)`
Prompts the user to enter a choice and validates the input.

### `void addBook(int i)`
Adds a new book to the library and appends the book details to `library_data.txt`.

### `void checkOutBook(int n)`
Allows the user to check out a book by marking it as unavailable in the system and updating `library_data.txt`.

### `void displayAvailableBooks(int bookCount)`
Displays all available books in the library by reading from `library_data.txt`.

### `void loadBooks(int *bookCount)`
Loads the book data from `library_data.txt` into the `books` array.

### `void clearBuffer()`
Clears the input buffer to handle input correctly.

## Usage

1. **Add a Book**:
    - Select option `1` from the menu.
    - Enter the book ID, title, and author.

2. **Check Out a Book**:
    - Select option `2` from the menu.
    - Enter the name of the book you want to check out.

3. **Display Available Books**:
    - Select option `3` from the menu.

4. **Exit**:
    - Select option `4` from the menu to exit the program.

## Notes

- The maximum number of books that can be added is defined by `MAX_BOOKS` (200 by default).
- The book data is stored in `library_data.txt` in the format:
    ```
    ID: <id>, Title: <title>, Author: <author>, Available: <1 or 0>
    ```

