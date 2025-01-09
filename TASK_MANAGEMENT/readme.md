# Task Manager Application

This **Task Manager Application** in C provides a robust framework for managing tasks, including functionalities to add, update, and display tasks, all while leveraging file handling to persist data. The program is structured with key features like centered formatting for display and clear modular functions for ease of use and maintenance.

---

## **Features**

1. **Add Tasks**:
   - Input task details: title, description, priority, and status.
   - Save tasks to a file (`tasks.txt`) for persistence.

2. **Update Task Status**:
   - Toggle the status of a task between "Pending" and "Done."
   - Update changes in both memory and the file.

3. **Display Tasks**:
   - Neatly display all tasks in a tabular format with centered text and numbers for improved readability.

4. **File Handling**:
   - Read tasks from the file at startup to ensure no data is lost between sessions.
   - Write tasks back to the file after updates.

5. **Validation**:
   - Prevent invalid choices for task operations.
   - Validate task indices when updating status.

6. **Modular Design**:
   - Clear separation of concerns with functions for each task (e.g., `loadTasks`, `inputTaskDetails`, `updateTaskStatus`).

7. **Centered Formatting**:
   - Custom functions (`centerText` and `centerNumber`) to display content in a visually appealing manner.

---

## **File Format**

Tasks are stored in a file named `tasks.txt` in the following format:
```
Title:- Task Title, Description:- Task Description, Priority:- Task Priority, Status:- Task Status
```


---

## **Code Structure**

- **Global Definitions**:
  - `Task` structure to define the attributes of a task.
  - `tasks` array to store up to 50 tasks.

- **Key Functions**:
  - `clearBuffer`: Clears the input buffer to handle newlines correctly.
  - `menu`: Displays the menu to the user.
  - `userChoice`: Validates and retrieves the user's choice.
  - `loadTasks`: Loads tasks from the `tasks.txt` file.
  - `inputTaskDetails`: Allows users to input task details and save them.
  - `updateTaskStatusValidation`: Validates and updates task status.
  - `updateTaskStatus`: Toggles a task's status.
  - `centerText` & `centerNumber`: Centers text and numbers for display.
  - `displayTaskDetails`: Displays all tasks in a well-formatted table.

---

## **Sample Run**

### **Menu**
```
1. To input a task
2. To change the status of a task
3. To display the tasks
4. Exit
Enter your choice: 1
```

### **Input a Task**
```
Enter the title of the task:-  Buy groceries
Enter the task description:-  Purchase fruits and vegetables.
Enter the priority:-  3
Status has been set to pending.
Task added successfully.
```

### **Display Tasks**
```
------------------------------------------------------------------------------------------
  No    Title      Description                          Priority         Status
------------------------------------------------------------------------------------------
   1    Buy       Purchase fruits and vegetables.         3            Pending
------------------------------------------------------------------------------------------
```

### **Update Task Status**
```
Enter the number of the task (1-50): 1
Status Updated to Done.
```

---

## **Improvements and Extensions**

- Add functionality to delete a task.
- Enable sorting tasks by priority or status.
- Enhance the display table to include more details like deadlines or categories.

This application is a great starting point for managing tasks effectively and demonstrates efficient use of C programming concepts like structures, file handling, and modular design.
