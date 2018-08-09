//
//  Student.h
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Course;
    
    class Student {
    private:
        std::string name;
        std::vector <Course*> courses;
    public:
        Student (const std::string& name);
        std::string getName () const;
        void print_Student () const;
        size_t findCourse (const Course& course) const;
        bool enrollCourse (Course& course);
        bool cancelOrDropCourse (const Course& course);
        
        void changeName (const std::string& newName);
        
        //bool dropCourse (const Course& course);
        
        bool remove ();
    };
}

#endif /* STUDENT_H */
