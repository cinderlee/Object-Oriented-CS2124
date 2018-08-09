//
//  Course.cpp
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>

using namespace std;

namespace BrooklynPoly {
    Course::Course (const string& name) : name (name) {}
    
    string Course::getName () const {
        return name;
    }
    
    void Course::print_Course() const {
        cout << name << ":";
        if (students.size () == 0){
            cout << " NONE" << endl;
        }
        else {
            //bool hasStudents = false;
            for (size_t index = 0; index < students.size(); ++index) {
                //if (students [index] != nullptr) {
                    //hasStudents = true;
                    cout << " ";
                    cout << students [index] -> getName();
                //}
            }
            //if (!hasStudents) {
              //  cout << "NONE";
            //}
            cout << "\n";
        }
    }
    
    
    
    size_t Course::findStudent (const Student& student) const {
        for (size_t index = 0; index < students.size(); ++ index){
            if (students[index] == &student) {
                return index;
            }
        }
        return students.size ();
    }
    
    bool Course::enrollStudent (Student& student) {
        if (findStudent (student) != students.size()) {
            cout << "ERROR: Student " << student.getName() <<
            " already is enrolled in this course" << endl;
            return false;
        }
        students.push_back (&student);
        return true;
    }
    
    void Course::cancelCourse () {
        for (size_t index = 0; index < students.size (); ++index) {
            students [index] -> cancelOrDropCourse (*this);
        }
    }
    
    bool Course::dropOrRemoveStudent(const Student& student) {
        size_t index = findStudent (student);
        if (index != students.size ()) {
            students [index] = students [students.size() - 1];
            students.pop_back ();
            return true;
        }
        cout << "ERROR: Student " << student.getName() <<
        " was never enrolled in this course" << endl;
        return false;
    }
    
//    bool Course::removeStudent(const Student& student) {
//        size_t index = findStudent (student);
//        if (index == students.size ()) {
//            return false;
//        }
//        //delete students [index];
//        //students[index] = nullptr;
//        students [index] = students [students.size() - 1];
//        students.pop_back ();
//        return true;
//    }
}
