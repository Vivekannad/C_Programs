# Conference Management System

This is a simple console-based application for managing conference participants. The application allows you to add participants, update their payment status, and display the list of participants.

## Features

- **Add Participant Details:** Enter the name, ID, organization, registration fee, and payment status of a participant.
- **Update Payment Status:** Update the payment status of an existing participant.
- **Display Participants:** Display the list of all participants with their details.

## Files

- `conference.c`: The main source code file containing the implementation of the conference management system.

## Prerequisites

- GCC (GNU Compiler Collection) or any C compiler installed on your system.

## How to Compile and Run

1. **Compile the program:**

   Open a terminal or command prompt and navigate to the directory containing `conference.c`. Run the following command to compile the program:

   ```sh
   gcc conference.c -o conference
   ```

2. **Run the program:**

   After compiling, run the executable:

   ```sh
   ./conference
   ```

   On Windows, you may need to use:

   ```sh
   conference.exe
   ```

## Usage

1. **Menu Options:**

   - `1. Enter the participants details`: Add a new participant to the system.
   - `2. Pay the Payment`: Update the payment status of an existing participant.
   - `3. Display the participant`: Display the list of all participants with their details.
   - `4. Exit`: Exit the application.

2. **Adding a Participant:**

   When you select option 1, you will be prompted to enter the participant's name, ID, organization, and registration fee. The payment status will also be updated.

   Example:
   ```
   Enter the participant name: John Doe
   Enter the id: 101
   Enter the organization name: ABC Corp
   Select Registration Fee (1000 to 10000): 1200
   Do you want to pay the fee, now? (1-Yes , 0 - No): 1
   ```

3. **Updating Payment Status:**

   When you select option 2, you will be prompted to enter the participant's ID. If the participant is found, you can update their payment status.

   Example:
   ```
   Enter the participant id: 101
   Do you want to pay the fee, now? (1-Yes , 0 - No): 1
   ```

4. **Displaying Participants:**

   When you select option 3, the list of all participants will be displayed with their details.

   Example:
   ```
   Name                          Id        Organization         Fee       Status              
   John Doe                      101       ABC Corp             1200      Paid                
   ```

## Function Descriptions

- **clearBuffer:** Clears the input buffer to avoid any unwanted characters.
- **loadParticipants:** Loads participant data from the `records.txt` file into the `participant` array.
- **menu:** Displays the main menu options.
- **userChoice:** Prompts the user to enter a choice from the menu and validates the input.
- **updatePaymentStatus:** Updates the payment status of a given participant.
- **isParticipantThere:** Checks if a participant with a given ID exists in the `participant` array.
- **userChoiceUpdatePaymentStatus:** Prompts the user to enter a participant ID and updates the payment status if the participant exists.
- **recursivelyAdjustFee:** Recursively adjusts the registration fee to ensure it is within the range of 1000 to 10000.
- **enterRegistrationFee:** Prompts the user to enter a registration fee and adjusts it if necessary.
- **inputParticipantData:** Prompts the user to enter participant details and saves them to the `records.txt` file.
- **centerNumber:** Centers a number within a given width for display purposes.
- **centerText:** Centers a text string within a given width for display purposes.
- **displayParticipants:** Displays the list of all participants with their details.

## Notes

- The participant details are stored in a file named `records.txt`.
- The maximum number of participants is limited to 50.

