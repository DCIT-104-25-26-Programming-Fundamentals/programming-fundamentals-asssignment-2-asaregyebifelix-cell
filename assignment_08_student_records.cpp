// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Define the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};
void showMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverageScore(const vector<Student>& students);

int main() {
    vector<Student> students; 
    int choice;
    
    cout << "WELCOME TO THE STUDENT RECORD SYSTEM!" << endl;
    cout << "=====================================" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            cout << endl;
            continue;
        }
        
        switch(choice) {
            case 1:
                addStudent(students);
                break;
                
            case 2:
                displayAllStudents(students);
                break;
                
            case 3:
                calculateAverageScore(students);
                break;
                
            case 4:
                cout << "\nThank you for using the Student Record System! Goodbye!" << endl;
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
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    int numScores;
    double score;
    
    cout << "Student name: ";
    cin.ignore();  
    getline(cin, newStudent.name);
    
    if (newStudent.name.empty()) {
        cout << "Error: Student name cannot be empty!" << endl;
        return;
    }
    
    cout << "Student ID: ";
    cin >> newStudent.id;

    for (const auto& student : students) {
        if (student.id == newStudent.id) {
            cout << "Error: Student ID " << newStudent.id << " already exists!" << endl;
            return;
        }
    }
    
    cout << "How many scores? ";
    cin >> numScores;
    
    if (numScores <= 0) {
        cout << "Error: Number of scores must be positive!" << endl;
        return;
    }
    
    for (int i = 0; i < numScores; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        
        if (score < 0 || score > 100) {
            cout << "Warning: Score " << score << " is outside the range 0-100." << endl;
        }
        
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    cout << "\n=================================================================================" << endl;
    cout << setw(20) << left << "Name" 
         << setw(15) << left << "ID" 
         << setw(30) << left << "Scores" 
         << setw(15) << left << "Average" << endl;
    cout << "=================================================================================" << endl;
    
    for (const auto& student : students) {
        cout << setw(20) << left << student.name;
        cout << setw(15) << left << student.id;
        
        string scoresStr = "";
        if (student.scores.empty()) {
            scoresStr = "No scores";
        } else {
            for (size_t i = 0; i < student.scores.size(); i++) {
                scoresStr += to_string(static_cast<int>(student.scores[i]));
                if (i < student.scores.size() - 1) {
                    scoresStr += ", ";
                }
            }
        }
        cout << setw(30) << left << scoresStr;
        
        if (student.scores.empty()) {
            cout << setw(15) << left << "N/A" << endl;
        } else {
            double sum = 0;
            for (double score : student.scores) {
                sum += score;
            }
            double average = sum / student.scores.size();
            cout << setw(15) << left << fixed << setprecision(2) << average << endl;
        }
    }
    cout << "=================================================================================" << endl;
}

void calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the system. Please add students first!" << endl;
        return;
    }
    
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;
    
    bool found = false;
    for (const auto& student : students) {
        if (student.id == searchId) {
            found = true;
            
            if (student.scores.empty()) {
                cout << student.name << " has no scores recorded." << endl;
            } else {
                double sum = 0;
                for (double score : student.scores) {
                    sum += score;
                }
                double average = sum / student.scores.size();
                cout << student.name << "'s average score: " << fixed << setprecision(2) << average << endl;
            }
            break;
        }
    }
    
    if (!found) {
        cout << "Error: Student with ID " << searchId << " not found!" << endl;
    }
}

