//
//  Course.h
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#ifndef COURSE_H
#define COURSE_H

#include <stdio.h>
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Student;
    
    class Course {
    private:
        std::string name;
        std::vector <Student*> students;
    public:
        
        std::string getName () const;
        Course (const std::string& name);
        void print_Course () const;
        size_t findStudent (const Student& student) const;
        bool enrollStudent (Student& student);
        void cancelCourse ();
        bool dropOrRemoveStudent (const Student& student);
        //bool removeStudent (const Student& student);
    };
}

#endif /* COURSE_H */
