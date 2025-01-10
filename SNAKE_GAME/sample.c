#include <stdio.h>
#include <stdlib.h> // For system()

void setCursorPosition(int row, int col) {
    printf("\033[%d;%dH", row, col); // Move cursor to (row, col)
}

void clearScreen() {
    system("cls");
    // printf("\033[2J"); // Clear the screen
    // printf("\033[H");  // Move cursor to top-left
}

void drawBorder(int rows, int cols) {
    // Top border
    for (int i = 1; i <= cols; i++) {
        setCursorPosition(1, i);
        printf("-");
    }

    // Bottom border
    for (int i = 1; i <= cols; i++) {
        setCursorPosition(rows, i);
        printf("-");
    }

    // Left and right borders
    for (int i = 1; i <= rows; i++) {
        setCursorPosition(i, 1);     // Left border
        printf("%c", 179);
        // printf("|");
        setCursorPosition(i, cols); // Right border
        printf("%c", 179);
    }
}

int main() {
    int rows = 20; // Number of rows
    int cols = 50; // Number of columns

    clearScreen(); // Clear the terminal

    drawBorder(rows, cols); // Draw the border

    // Move the cursor to a safe location below the border
    setCursorPosition(rows + 1, 1);

    // Wait for the user to exit
    printf("\nPress Enter to exit...");
    getchar();

    // Restore cursor position for normal terminal usage
    setCursorPosition(rows + 2, 1);
    printf("\033[0m"); // Reset terminal styles if modified

    return 0;
}
