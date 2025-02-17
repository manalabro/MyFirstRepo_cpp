#include <iostream>
#include <iomanip>

using namespace std;

// Function to convert letter grades to grade points
double getGradePoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "D" || grade == "d") return 1.0;
    if (grade == "F" || grade == "f") return 0.0;
    return -1; // Invalid grade
}

int main() {
    int numCourses;
    double totalGradePoints = 0.0, totalCredits = 0.0;

    // Welcome message
    cout << "******************************\n";
    cout << "      CGPA CALCULATOR         \n";
    cout << "******************************\n";

    // Ask user for number of courses
    cout << "Enter the total number of courses you took: ";
    cin >> numCourses;

    // Validate input
    while (numCourses <= 0) {
        cout << "Invalid input! Please enter a positive number: ";
        cin >> numCourses;
    }

    // Loop to get grade and credit hours for each course
    for (int i = 1; i <= numCourses; i++) {
        string grade;
        double creditHours;

        cout << "\nEnter details for Course " << i << ":\n";
        cout << "Grade (A, B, C, D, F): ";
        cin >> grade;

        // Convert grade to grade points
        double gradePoint = getGradePoint(grade);

        // Validate grade input
        while (gradePoint == -1) {
            cout << "Invalid grade! Please enter a valid grade (A, B, C, D, F): ";
            cin >> grade;
            gradePoint = getGradePoint(grade);
        }

        cout << "Credit hours: ";
        cin >> creditHours;

        // Validate credit hours input
        while (creditHours <= 0) {
            cout << "Invalid credit hours! Enter a positive number: ";
            cin >> creditHours;
        }

        // Compute total grade points
        totalGradePoints += gradePoint * creditHours;
        totalCredits += creditHours;
    }

    // Check if credits are valid before calculating CGPA
    if (totalCredits == 0) {
        cout << "\nError: No valid courses entered. CGPA calculation failed.\n";
        return 1;
    }

    // Calculate CGPA
    double CGPA = totalGradePoints / totalCredits;

    // Display result
    cout << "\n*****************************\n";
    cout << "         RESULT               \n";
    cout << "******************************\n";
    cout << "Your CGPA is: " << fixed << setprecision(2) << CGPA << endl;
    cout << "******************************\n";

    return 0;
}


