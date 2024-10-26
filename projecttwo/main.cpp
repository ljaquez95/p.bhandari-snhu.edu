//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Leslie Jaquez
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU //CS-300-15308-M01:Analysis and Design
// Description : Project Two
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

//This is the structure for the course
using namespace std;
struct Course {
    string title;
    vector<string> prerequisites;
};

// This is the function to load data structure (courses)
void loadStructure(map<string, Course>& courses) {

    // This will read the code course data and populate in the code with the course map

    courses["CSCI100"] = {"Introduction to Computer Science", {}};
    courses["CSCI101"] = {"Introduction to Programming in C++", {}};
    courses["CSCI200"] = {"Data Structures", {"CSCI101"}};
    courses["CSCI301"] = {"Advanced Programming in C++", {"CSCI101"}};
    courses["CSCI300"] = {"Introduction to Algorithms", {"CSCI200"}};
    courses["CSCI350"] = {"Operating Systems", {"CSCI200"}};
    courses["CSCI400"] = {"Large Software Development", {"CSCI301", "CSCI350"}};
    courses["MATH201"] = {"Discrete Mathematics", {}};
    cout << "The data structure loaded successfully." << endl;

}


// This is the function to print course deatails
void printCourseDetails(const map<string, Course>& courses) {
    cout << "Here is a sample schedule:\n\n";
    for (const auto& pair : courses) {
        cout << pair.first << ", " << pair.second.title << endl;
    }
}


// This is the function to print course information
void printCourse(const map<string, Course>& courses) {
    string cCode;
    cout << "What course do you want to know about? ";
    cin >> cCode;

    auto it = courses.find(cCode);
    if (it != courses.end()) {
        cout << it->first << ", " << it->second.title << endl;
        cout << "Prerequisites: ";
        for (const auto& prereq : it->second.prerequisites) {
            cout << prereq << ", ";
        }
        cout << endl;
    } else {
        cout << "Course could not be found!" << endl;
    }
}


int main() {
    // This is the map to store courses
    map<string, Course> courses;

    // This will load data structure
    loadStructure(courses);

    // This is the menu loop
    int choice;
    do {
        cout << "\nWelcome to the course planner.\n\n";
        cout << "1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n\n";
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                loadStructure(courses);
                break;
            case 2:
                printCourseDetails(courses);
                break;
            case 3:
                printCourse(courses);
                break;
            case 9:
                cout << "Thank you for using the course planner!\n";
                break;
            default:
                cout << choice << " is not a valid option.\n";
        }
    } while (choice != 9);

    return 0;
}













