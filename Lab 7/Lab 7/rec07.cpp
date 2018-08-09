//
//  rec07.cpp
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Purpose: To simulate registering for classes using separate compilation

#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace BrooklynPoly;
using namespace std;

int main() {
    
    Registrar registrar;
    cout << "Test 1"<< endl;
    cout << "No courses or students added yet\n";
    registrar.printReport();  // or registrar.printReport()
    cout << "\n";
    
    cout << "Test 2"<< endl;
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    registrar.printReport ();
    cout << "\n";
    
    cout << "Test 3"<< endl;
    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    registrar.printReport();
    cout << "\n";
    
    cout << "Test 4"<< endl;
    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    registrar.printReport();
    cout << "\n";
    
    cout << "Test 5"<< endl;
    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    registrar.printReport();
    cout << "\n";
    
    cout << "Test 6"<< endl;
    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    registrar.printReport();
    cout << "\n";
    
    cout << "Test 7"<< endl;
    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    registrar.printReport();
    cout << "\n";
    
    cout << "Test 8"<< endl;
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    registrar.printReport ();
    cout << "\n";
    
    cout << "Test 9" << endl;
    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    registrar.printReport ();
    cout << "\n";
    
    cout << "Test 10" << endl;
    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    registrar.printReport();
    cout << "\n";
    
//    cout << "Test 11" << endl;
//    cout << "RemoveStudent MightyMouse\n";
//    registrar.removeStudent("MightyMouse");
//    registrar.printReport();
    
    cout << "Test 11" << endl;
    cout << "Purge for start of next semester\n";
    registrar.purge();
    registrar.printReport();
    cout << "\n";
    //Reading in a file
    
    cout << "Test 12" << endl;
    ifstream fileName ("transactions.txt");
    if (!fileName) {
        cerr << "No file";
        exit (1);
    }

    Registrar registrarTwo;
    string line;
    //while (fileName >> command) {
    while (getline (fileName, line)){
        string command;
        string studentName;
        string courseName;
        stringstream commandLine;
        commandLine << line;
        commandLine >> command;
        if (command == "PrintReport") {
            cout << "Printing Report" << endl;
            registrarTwo.printReport();
            cout << "\n";
        }
        else if (command == "AddCourse") {
            commandLine >> courseName;
            if (courseName == "" ) {
                cout << "ERROR: Missing course name to add" << endl;
            }
            else {
                cout << "Adding " << courseName << endl;
                registrarTwo.addCourse(courseName);
            }
            cout << "\n";
        }
        else if (command == "AddStudent") {
            commandLine >> studentName;
            if (studentName == "") {
                cout << "ERROR: Missing student name to add" << endl;
            }
            else {
                cout << "Adding " << studentName << endl;
                registrarTwo.addStudent(studentName);
            }
            cout << "\n";
        }
        else if (command == "EnrollStudentInCourse") {
            commandLine >> studentName >> courseName;
            if (studentName == "") {
                cout << "ERROR: Missing student to enroll course" << endl;
            }
            else if (courseName == "") {
                cout << "ERROR: Missing course name to add " <<
                studentName << " to" << endl;
            }
            else {
                cout << "Enrolling " << studentName <<
                " to " << courseName << endl;
                registrarTwo.enrollStudentInCourse
                (studentName, courseName);
            }
            cout << "\n";
        }
        else if (command == "CancelCourse" ) {
            commandLine >> courseName;
            if (courseName == "") {
                cout << "ERROR: Missing course name to cancel" << endl;
            }
            else {
                cout << "Canceling " << courseName << endl;
                registrarTwo.cancelCourse(courseName);
            }
            cout << "\n";
        }
        else if (command == "ChangeStudentName" ) {
            string secondName;
            commandLine >> studentName >> secondName ;
            if (studentName == "") {
                cout << "ERROR: Missing student to change name" << endl;
            }
            else if (secondName == "") {
                cout << "ERROR: Missing name to change " <<
                studentName << " to" << endl;
            }
            else {
                cout << "Changing " << studentName <<
                " to " << secondName << endl;
                registrarTwo.changeStudentName
                (studentName, secondName);
            }
            cout << "\n";
        }
        else if (command == "DropStudentFromCourse") {
            commandLine >> studentName >> courseName;
            if (studentName == "") {
                cout << "ERROR: Missing student name to drop" << endl;
            }
            else if (courseName == "") {
                cout << "ERROR: Missing course name to drop " <<
                studentName << " from" << endl;
            }
            else {
                cout << "Dropping " << studentName <<
                " from " << courseName << endl;
                registrarTwo.dropStudentFromCourse
                (studentName, courseName);
            }
            cout << "\n";
        }
        else if (command == "RemoveStudent"){
            commandLine >> studentName;
            if (studentName == "" ) {
                cout << "ERROR: Missing student name to remove" << endl;
            }
            else {
                cout << "Removing " << studentName <<endl;
                registrarTwo.removeStudent(studentName);
            }
            cout << "\n";
        }
        else {
            cout << "Purging" << endl;
            registrarTwo.purge ();
            cout << "\n";
            registrarTwo.printReport();
        }
    }
    fileName.close();
}

