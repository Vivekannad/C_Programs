# Kaun Banega Crorepati

This is a C implementation of the popular quiz game "Kaun Banega Crorepati". The game loads questions from a file and allows the player to answer them within a specified time limit. The player can also use lifelines to assist with difficult questions.

## Features

- Loads questions from a text file
- Displays questions with multiple-choice options
- Allows the player to use lifelines (50/50 and Skip the question)
- Enforces a time limit for each question
- Displays the total prize money won by the player

## Requirements

- A C compiler (e.g., GCC)
- A terminal that supports ANSI escape codes for colored output (e.g., most Unix-based terminals)

## Setup

1. Clone the repository or download the source code.
2. Ensure you have a C compiler installed on your system.
3. Place the `questions.txt` file in the same directory as the source code. The file should be formatted as follows:
    ```
    Question 1
    Option A
    Option B
    Option C
    Option D
    Correct Option (A, B, C, or D)
    Time limit in seconds
    Prize money
    ```

## Compilation

To compile the program, use the following command:

```sh
gcc -o kbc quiz.c -lconio -lwindows
```

## Usage

Run the compiled executable:

```sh
./kbc
```

Follow the on-screen instructions to play the game. Answer the questions by typing the corresponding option letter (A, B, C, or D) or use 'L' to access lifelines.

## Lifelines

- **50/50**: Removes two incorrect options.
- **Skip the question**: Skips the current question without penalty.

## Example

```
        let's play Kaun Banega Crorepati 
Question: Who is known as the father of computer?
A. Charles Babbage
B. Nicholas Henry
C. Ada Lovalace
D. Alan Turing

Hurry up you have only 30 seconds to answer 
Enter your answer (A , B , C or D) or L for Lifeline 
```

## License

This project is licensed under the MIT License.