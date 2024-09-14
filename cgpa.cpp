#include <iostream>
using namespace std;

struct Course {
    float gradePoint;   // Grade point for the course (e.g., 9.0, 8.5)
    float credit;       // Credit for the course (e.g., 3, 4,5)
};

int main() {
    int courses;
    cout << "Enter the number of courses you have taken: ";
    cin >> courses;

    Course* courseList = new Course[courses];  // Dynamically allocate memory for courses

    float totalGradePoints = 0;  
    float totalCredits = 0;      

    
    for (int i = 0; i < courses; i++) {
        cout << "Enter the credit for course " << i + 1 << ": ";
        cin >> courseList[i].credit;

        cout << "Enter the grade point for course " << i + 1 << ": ";
        cin >> courseList[i].gradePoint;

        // Accumulate total grade points and credits
        totalGradePoints += courseList[i].gradePoint * courseList[i].credit;
        totalCredits += courseList[i].credit;
    }

    // Calculate GPA (for the semester)
    float GPA = totalGradePoints / totalCredits;

    // Display each course's grade point and credit
    cout << "\nCourse details: \n";
    for (int i = 0; i < courses; i++) {
        cout << "Course " << i + 1 << ": Credit = " << courseList[i].credit 
             << ", Grade Point = " << courseList[i].gradePoint << endl;
    }

    // Display total credits, total grade points, and GPA
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your GPA for this semester is: " << GPA << endl;

    
    int semesters;
    cout << "\nDo you want to calculate CGPA for multiple semesters? (1 for Yes, 0 for No): ";
    cin >> semesters;

    if (semesters == 1) {
        int totalSemesters;
        cout << "Enter the number of semesters: ";
        cin >> totalSemesters;

        float* semesterGPAs = new float[totalSemesters];  // Store GPAs for each semester
        float totalCGPA = 0;

        for (int i = 0; i < totalSemesters; i++) {
            cout << "Enter GPA for semester " << i + 1 << ": ";
            cin >> semesterGPAs[i];
            totalCGPA += semesterGPAs[i];
        }

        // Calculate CGPA over all semesters
        cout << "Your CGPA over " << totalSemesters << " semesters is: " << totalCGPA / totalSemesters << endl;

        delete[] semesterGPAs;  
    }

    delete[] courseList;  

    return 0;
}

