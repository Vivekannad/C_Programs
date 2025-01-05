# File Management System

This is a simple file management system written in C. It allows users to create, read, write, rename, and delete files through a console-based interface.

## Features

- **Create a file**: Create a new file with specified content.
- **Read a file**: Display the content of an existing file.
- **Write to a file**: Append content to an existing file.
- **Rename a file**: Rename an existing file.
- **Delete a file**: Remove an existing file.

2. **Follow the on-screen menu** to perform file operations:
    - Press `1` to create a file.
    - Press `2` to read a file.
    - Press `3` to write to a file.
    - Press `4` to rename a file.
    - Press `5` to delete a file.
    - Press `6` to exit the program.

## Helper Functions
- `const *getFileNameAndExt()`: Prompts the user for a file name and validates the extension (e.g., .txt).
- `const *getContent` : Accepts multi-line input from the user to write to a file.
- `void clearBuffer()` : Clears the input buffer to handle user input more effectively.

## Functions

- `void clearBuffer()`: Clears the input buffer to prevent unwanted characters from being read.
- `void clearScreen()`: Clears the console screen for better readability.
- `void menu()`: Displays the menu options to the user.
- `void createFile()`: Creates a new file with user-specified content.
- `void readFile()`: Reads and displays the content of a file.
- `void writeToFile()`: Appends content to an existing file.
- `void renameFile()`: Renames an existing file.
- `void removeFile()`: Deletes an existing file.

## Example

Here's an example of how to use the program:

1. **Create a file**:
    - Select option `1` from the menu.
    - Enter the file name and extension (e.g., `example.txt`).
    - Enter the content for the file.
    - The file will be created with the specified content.

2. **Read a file**:
    - Select option `2` from the menu.
    - Enter the file name and extension (e.g., `example.txt`).
    - The content of the file will be displayed.

3. **Write to a file**:
    - Select option `3` from the menu.
    - Enter the file name and extension (e.g., `example.txt`).
    - Enter the content to append to the file.
    - The content will be added to the file.

4. **Rename a file**:
    - Select option `4` from the menu.
    - Enter the old file name and extension (e.g., `example.txt`).
    - Enter the new file name and extension (e.g., `new_example.txt`).
    - The file will be renamed.

5. **Delete a file**:
    - Select option `5` from the menu.
    - Enter the file name and extension (e.g., `example.txt`).
    - The file will be deleted.

## Notes

- The program uses `system("cls")` for Windows and `system("clear")` for Linux/MacOS to clear the console screen.
- File names and extensions are validated to ensure proper input.

## Coder
Developed By **Vivek Anand**.