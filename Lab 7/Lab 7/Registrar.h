//
//  Registrar.hpp
//  Lab 7
//
//  Created by Cindy Lee on 10/20/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Course.h"
#include "Student.h"
#include <stdio.h>
#include <string>
#include <vector>

namespace BrooklynPoly {
    
    class Registrar {
    private:
        std::vector <Student*> students;
        std::vector <Course*> courses;
    public:
        Registrar ();
        void printReport () const;
        size_t findStudent (const std::string& studentName) const;
        size_t findCourse (const std::string& courseName) const;
        bool addCourse (const std::string& name);
        bool addStudent (const std::string& name);
        bool enrollStudentInCourse (const std::string& studentName,
                                    const std::string& courseName);
        
        bool cancelCourse (const std::string& courseName);
        
        bool changeStudentName (const std::string& studentName,
                                const std::string& newName);
        
        bool dropStudentFromCourse (const std::string& studentName,
                                    const std::string& courseName);
        
        bool removeStudent (const std::string& studentName);
        
        void purge ();
    };
}


#endif /* REGISTRAR_H */
