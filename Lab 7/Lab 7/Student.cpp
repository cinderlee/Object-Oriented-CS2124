//
//  Student.cpp
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly{
    
    Student::Student (const string& name): name(name) {}
    
    string Student::getName () const {
        return name;
    }
    
    void Student::print_Student () const {
        cout << name << ": ";
        if (courses.size () == 0){
            cout << "NONE" << endl;
        }
        else {
            //bool inCourse = false;
            for (size_t index = 0; index < courses.size(); ++index) {
                //if (courses [index] != nullptr) {
                    //inCourse = true;
                cout << courses [index] -> getName();
                cout << " ";
            }
            //if (!inCourse) {
            //    cout << "NONE";
            //}
            cout << "\n";
        }
    }
    
    size_t Student::findCourse (const Course& course) const {
        for (size_t index = 0; index < courses.size(); ++ index){
            if (courses[index] == &course) {
                return index;
            }
        }
        return courses.size ();
    }
    
    bool Student::enrollCourse (Course& course) {
        if (findCourse (course) != courses.size()) {
            cout << "ERROR: Student " << name <<
            " already exists in Course " <<
            course.getName() << endl;
            return false;
        }
        courses.push_back (&course);
        return true;
    }
    
    bool Student::cancelOrDropCourse ( const Course& course ) {
        size_t indexCourse = findCourse ( course );
        if (indexCourse == courses.size ()){
            return false;
        }
        //delete courses[indexCourse];
        //courses[indexCourse] = nullptr;
        courses[indexCourse] = courses[ courses.size () - 1];
        courses.pop_back ();
        return true;
        
    }
    
    void Student::changeName (const string& newName) {
        name = newName;
    }
    
//    bool Student::dropCourse (const Course& course) {
//        size_t index = findCourse (course);
//        if (index == courses.size ()) {
//            return false;
//        }
//        courses [index] = courses[ courses.size () - 1];
//        courses.pop_back ();
//        return true;
//    }
    
    bool Student::remove () {
        for (size_t index = 0; index < courses.size (); ++index) {
            //if (courses[index] != nullptr) {

            courses[index] -> dropOrRemoveStudent (*this);
            //}
        }
        return true;
    }
    
}
