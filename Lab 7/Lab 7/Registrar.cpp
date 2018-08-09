//
//  Registrar.cpp
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#include "Registrar.h"
#include "Course.h"
#include "Student.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace BrooklynPoly {
    Registrar::Registrar () {};
    
    void Registrar::printReport() const {
        cout << "STUDENTS:" << endl;
        if (students.size () == 0){
            cout << "\tNONE" <<endl;
        }
        else{
            for (size_t index = 0; index < students.size (); ++index){
                //if (students[index] != nullptr) {
                cout << "\t";
                students [index] -> print_Student();
                //}
            }
        }
        cout << "COURSES:" << endl;
        if (courses.size () == 0){
            cout << "\tNONE" <<endl;
        }
    
        else {
            for (size_t index = 0; index < courses.size (); ++index){
                //if (courses[index] != nullptr ){
                cout << "\t";
                courses [index] -> print_Course ();
                //}
            }
        }
            
    }
    
    
    size_t Registrar::findStudent (const string& studentName) const {
        for (size_t index = 0; index < students.size(); ++ index){
            if (students[index] -> getName () == studentName) {
                return index;
            }
        }
        return students.size ();
        
    }
    
    size_t Registrar::findCourse (const string& courseName) const {
        for (size_t index = 0; index < courses.size(); ++ index){
            if (courses[index] -> getName () == courseName) {
                return index;
            }
        }
        return courses.size ();
        
    }
    
    bool Registrar::addCourse(const string& name){
        if (findCourse (name) != courses.size ()) {
            cout << "ERROR: Course " << name <<
            " already exists" << endl;
            return false;
        }
        courses.push_back (new Course (name));
        return true;
    }
    
    bool Registrar::addStudent(const string& name){
        if (findStudent (name) != students.size ()) {
            cout << "ERROR: Student " << name <<
            " already exists" << endl;
            return false;
        }
        students.push_back (new Student (name));
        return true;
    }
    
    bool Registrar::enrollStudentInCourse (const string& studentName,
                                const string& courseName) {
        size_t indexCourse = findCourse (courseName);
        size_t indexStudent = findStudent (studentName);
        if (indexCourse == courses.size() ||
            indexStudent == students.size ()) {
            if (indexCourse == courses.size()) {
                cout << "ERROR: Course " << courseName <<
                " doesn't exist" << endl;
            }
            if (indexStudent == students.size()) {
                cout << "ERROR: Student " << studentName <<
                " doesn't exist" << endl;
            }
            return false;
        }
        courses [indexCourse] ->
        enrollStudent ( * (students[indexStudent]) );
        students [indexStudent] ->
        enrollCourse ( * (courses[indexCourse]) );
        return true;
    }
    
    bool Registrar::cancelCourse (const string& courseName){
        size_t indexCourse = findCourse (courseName);
        if (indexCourse == courses.size()) {
            cout << "ERROR: Course " << courseName <<
            " doesn't exist" << endl;
            return false;
        }
        courses [indexCourse] -> cancelCourse ();
        delete courses [indexCourse];
        courses[indexCourse] = nullptr;
        courses [indexCourse] = courses [courses.size () - 1];
        courses.pop_back();
        return true;
    }
    
    bool Registrar::changeStudentName(const string& studentName,
                                      const string& newName) {
        size_t indexStudent = findStudent (studentName);
        if (studentName == newName) {
            cout << "ERROR: Why are you renaming" <<
            " yourself to your own name again?" << endl;
            return false;
        }
        if (indexStudent == students.size () ||
            findStudent(newName) != students.size ()) {
            if (indexStudent == students.size ()) {
                cout << "ERROR: Student " << studentName <<
                " doesn't exist" << endl;
            }
            if (findStudent(newName) != students.size ()) {
                cout << "ERROR: Student " << newName <<
                " already exists" << endl;
            }
            return false;
        }
        students [indexStudent] -> changeName (newName);
        return true;
    }
    
    bool Registrar::dropStudentFromCourse (const string& studentName,
                                const string& courseName) {
        size_t indexCourse = findCourse (courseName);
        size_t indexStudent = findStudent (studentName);
        if (indexCourse == courses.size() ||
            indexStudent == students.size ()) {
            if (indexCourse == courses.size()) {
                cout << "ERROR: Course " << courseName <<
                " doesn't exist" << endl;
            }
            if (indexStudent == students.size ()) {
                cout << "ERROR: Student " << studentName <<
                " doesn't exist" << endl;
            }
            return false;
        }
        courses [indexCourse] ->
        dropOrRemoveStudent (* students [indexStudent]);
        students [indexStudent] ->
        cancelOrDropCourse ( * courses [indexCourse] );
        return true;
    }
    
    bool Registrar::removeStudent (const string& name){
        size_t indexStudent = findStudent (name);
        if (indexStudent == students.size () ) {
            cout << "ERROR: Student " << name <<
            " doesn't exist" << endl;
            return false;
        }
        students[indexStudent] -> remove ();
        delete students [indexStudent];
        students [indexStudent] = nullptr;
        students [indexStudent] = students [students.size () -1 ];
        students.pop_back ();
        return true;
    }
    
    void Registrar::purge () {
        for (size_t index = 0; index < students.size() ; ++ index) {
            //if (students [index] != nullptr) {
                removeStudent (students[index] -> getName ());
            //}
        }
        
        students.clear ();
        for (size_t index2 = 0; index2 < courses.size (); ++index2) {
            delete courses[index2];
        }
        courses.clear ();
    }
}
