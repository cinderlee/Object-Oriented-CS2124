//
//  rec05.cpp
//  Lab 5
//
//  Created by Cindy Lee on 10/6/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: To simulate CS lab administration

//  resubmitted on Sunday because caught a mistake
//  used TimeSlot's retrieved variable information to make a copy
//  of the TimeSlot object instead of using TimeSlot's default copy constructor
//  changed the line of code to use TimeSlot's default copy constructor

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Section{
public:
    Section (const string& name, const string& day, int time) : sectionName (name), day ( day, time ){}
    
    Section (const Section& sec){
        sectionName = sec.sectionName;
        //day = TimeSlot (sec.day.getDay(), sec.day.getTime());
        day = TimeSlot (sec.day);
        for (size_t index= 0 ; index < sec.student.size (); ++index){
            Student* stud = new Student (*sec.student[index]);
//            int counter = 1;
//            for (size_t newI = 0; newI < (*(sec.student [index])).returnRecord().size(); ++newI ){
//                (*stud).changeGrade((*(sec.student [index])).returnRecord()[newI], counter);
//                counter += 1;
//            }
            student.push_back (stud);
        }
    }
    
    ~Section () {
        cout << "Section " << sectionName << " is being deleted." << endl;
        for (size_t index= 0 ; index < student.size (); ++index){
            cout << "Deleting " << (*student[index]).getName () << endl;
            delete student[index];
        }
        student.clear();
//            cout << "Deleting " << (*(student[index])).getName() << endl;
//            delete student [index];
        
        cout << "\n";
    }

    
    void display () const {
        cout << "Section: " << sectionName << ", ";
        day.display();
//        "Time Slot: [Day: " << day.getDay()
//        << ", Start time: ";
//        if (day.getTime () > 12 ) {
//            cout << day.getTime() - 12 << "pm";
//        }
//        else if (day.getTime () == 12 ){
//            cout << 12 << "pm";
//        }
//        else {
//            cout << day.getTime () << "am";
//        }
        cout << ", Students: ";
        if (student.size () == 0){
            cout << "None" << endl;
        }
        else {
            cout << "\n";
            for (size_t index = 0; index < student.size (); ++index) {
                (*student[index]).display();
            }
        }
    }
    
    void addNewGrade (const string& name, int grade, int week){
        for (size_t index = 0; index < student.size (); ++index) {
            if ((*student[index]).getName () == name ){
                (*student[index]).changeGrade(grade, week);
            }
        }
    }
    
    void addStudent (const string& name ) {
        Student* stuff = new Student (name);
        student.push_back (stuff);
    }
    
private:
    
    class Student {
    public:
        Student (const string& name) : name (name) {}
        
        string getName () const {
            return name;
        }
        
        void changeGrade (int grade, int week) {
            record [week - 1] = grade;
        }
        
        void display () const {
            cout << "Name: " << name << ", Grades:";
            for (size_t index = 0; index < record.size(); ++index ){
                cout << " " << record [index];
            }
            cout << "\n";
        }
        
//        const vector <int>& returnRecord () const{
//            return record;
//        }
//
    private:
        string name;
        vector <int> record = vector <int> (14, -1);
    };
    
    class TimeSlot {
    public:
        TimeSlot (const string& day, int time) : day (day), time (time) {}
        
        TimeSlot () {}
        
        string getDay () const {
            return day;
        }
        
        int getTime () const {
            return time;
        }
        
        void display () const {
            cout << "Time Slot: [Day: " << getDay()
            << ", Start time: ";
            if (getTime () > 12 ) {
                cout << getTime() - 12 << "pm";
            }
            else if (getTime () == 12 ){
                cout << 12 << "pm";
            }
            else {
                cout << getTime () << "am";
            }
        }

    private:
        string day;
        int time;
    };
    
    string sectionName;
    TimeSlot day;
    vector <Student*> student;
    
};

class LabWorker {
public:
    LabWorker (const string& name) : name ( name ), sec (nullptr){}
    
    void display () const {
        cout << name ;
        if (sec == nullptr) {
            cout << " does not have a section." << endl;
        }
        else {
            cout << "has ";
            sec -> display();
        }
    }
    
    bool addSection (Section& section) {
        if (sec != nullptr ) {
            return false;
        }
        sec = &section;
        return true;
    }
    
    void addGrade (const string& name, int grade, int week) {
        //for (size_t index = 0 ; index < (*sec); ++index) {
        sec -> addNewGrade (name, grade, week);
    }
private:
    string name;
    Section* sec;
};

// Test code
void doNothing(Section sec) { sec.display(); }

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    secA2.display();
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    secA2.display();
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    moe.display();

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    moe.display();

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    jane.display();

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    moe.display();

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    moe.display();

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main
