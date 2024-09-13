#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function declarations
    string calculateGrade(int marks);
    double calculateGradePoint(string grade);
    string determineClass(double sgpa);

// Main function to calculate student results
    void calculateStudentResults() {
        string student_id;
        const int num_courses = 4;
        string course_titles[num_courses] = {"Programming", "Hardware", "Academic Writing", "French"};
        int credit_hours[num_courses] = {3, 3, 3, 3};
        int marks[num_courses];
        string grades[num_courses];
        double grade_points[num_courses], weighted_grade_points[num_courses], total_wgp = 0.0, sgpa;
        int total_credit_hours = 0;

        cout << "Enter your Student ID: ";
        cin >> student_id;

        for (int i = 0; i < num_courses; i++) {
            cout << "Enter marks for " << course_titles[i] << ": ";
            cin >> marks[i];
            grades[i] = calculateGrade(marks[i]);
            grade_points[i] = calculateGradePoint(grades[i]);
            weighted_grade_points[i] = grade_points[i] * credit_hours[i];
            total_wgp += weighted_grade_points[i];
            total_credit_hours += credit_hours[i];
        }

        sgpa = total_wgp / total_credit_hours;

        // Display the results
        cout << "\nFIRST SEMESTER RESULTS" << endl;
        cout << "**********************" << endl;
        cout << "Student ID: " << student_id << endl;
        cout << "Course Title \tMarks\tGrade\tCHrs\tGP\tWGP" << endl;
        cout << "**************************************************************************************" << endl;

        for (int i = 0; i < num_courses; i++) {
            cout << course_titles[i] << "\t" << marks[i] << "\t" << grades[i] << "\t"
                 << credit_hours[i] << "\t" << fixed << setprecision(1) << grade_points[i] << "\t"
                 << weighted_grade_points[i] << endl;
        }

        cout << "**************************************************************************************" << endl;
        cout << "\t\t\t" << "∑CHrs = " << total_credit_hours << "\t" << "∑WGP = " << total_wgp << endl;
        cout << "SGPA: " << sgpa << endl;
        cout << "Semester Class: " << determineClass(sgpa) << endl;
        cout << "--------------------------------------END OF RESULTS-------------------------------------------\n" << endl;
    }

// Function to calculate grade based on marks
    string calculateGrade(int marks) {
        if (marks >= 80) return "A";
        else if (marks >= 75) return "B+";
        else if (marks >= 70) return "B";
        else if (marks >= 65) return "C+";
        else if (marks >= 60) return "C";
        else if (marks >= 55) return "D+";
        else if (marks >= 50) return "D";
        else return "F";
    }

// Function to calculate grade point based on grade
    double calculateGradePoint(string grade) {
        if(grade == "A") return 4.0;
        else if (grade == "B+") return 3.5;
        else if (grade == "B") return 3.0;
        else if (grade == "C+") return 2.5;
        else if (grade == "C") return 2.0;
        else if (grade == "D+") return 1.5;
        else if (grade == "D") return 1.0;
        else return 0.0;
    }

// Function to determine semester class based on SGPA
    string determineClass(double sgpa) {
        if (sgpa >= 3.6) return "FIRST CLASS";
        else if (sgpa >= 3.0) return "SECOND CLASS UPPER";
        else if (sgpa >= 2.0) return "SECOND CLASS LOWER";
        else return "PASS";
    }

    int main() {
        char moreStudents = 'Y';

        do {
            calculateStudentResults();
            cout << "Are there more students? (Y/N): ";
            cin >> moreStudents;
        } while (moreStudents == 'Y' || moreStudents == 'y');

        return 0;
    }