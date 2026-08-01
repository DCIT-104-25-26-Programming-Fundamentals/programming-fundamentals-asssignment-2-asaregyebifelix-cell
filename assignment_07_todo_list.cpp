// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Function prototypes
void showMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;  // Dynamic list to store tasks
    int choice;
    
    cout << "WELCOME TO THE TO-DO LIST APPLICATION!" << endl;
    cout << "======================================" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        // Clear input buffer to handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        
        switch(choice) {
            case 1:
                addTask(tasks);
                break;
                
            case 2:
                viewTasks(tasks);
                break;
                
            case 3:
                deleteTask(tasks);
                break;
                
            case 4:
                cout << "\nGoodbye! Have a productive day!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
        
        cout << endl;
        
    } while (choice != 4);
    
    return 0;
}

// Function to display the menu
void showMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    
    cout << "Enter task: ";
    cin.ignore();  // Clear the newline character from previous input
    getline(cin, task);
    
    // Trim leading/trailing spaces (optional)
    if (!task.empty()) {
        tasks.push_back(task);
        cout << "Task added: \"" << task << "\"" << endl;
    } else {
        cout << "Error: Task description cannot be empty!" << endl;
    }
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty. Add some tasks!" << endl;
        return;
    }
    
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete. Your list is empty!" << endl;
        return;
    }
    
    // Display current tasks with numbers
    viewTasks(tasks);
    
    cout << "Enter task number to delete: ";
    int taskNumber;
    cin >> taskNumber;
    
    // Check if input is valid
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number." << endl;
        return;
    }
    
    // Check if task number is within range
    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number! Please enter a number between 1 and " 
             << tasks.size() << "." << endl;
        return;
    }
    
    // Save the task description for confirmation message
    string removedTask = tasks[taskNumber - 1];
    
    // Remove the task
    tasks.erase(tasks.begin() + (taskNumber - 1));
    
    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}

