//
//  rec06.cpp
//  Lab 6
//
//  Created by Cindy Lee on 10/13/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.

//  Cindy Lee, ID: cl3616
//  Purpose: Dynamic arrays and copy control

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
    void display(ostream& os = cout) const {
        os << '[' << title << ',' << salary << ']';
    }
private:
    string title;
    double salary;
}; // class Position

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone,
          Position& aPosition)
    : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    void display(ostream& os = cout) const {
        os << name << ' ' << room << ' ' << phone << ", ";
        pos->display(os);
    }
    const string& getName() const { return name; }
    const unsigned& getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
public:
    
    Directory () : size (0), capacity (1), entries (new Entry* [1]) {
//        size = 0;
//        capacity = 0;
//        entries = new Entry* [capacity];
        for (size_t index =0; index < capacity; ++index){
            entries [index] = nullptr;
        }
    }
    
    Directory ( const Directory& dr ) {
        cout << "YO, I'm copy" << endl;
        size = dr.size;
        capacity = dr.capacity;
        entries = new Entry* [capacity];
        for (size_t index = 0; index < size; ++index) {
            entries [index] = new Entry (*(dr.entries [index]));
        }
        
        for (size_t index = size; index < capacity; ++index) {
            entries [index] = nullptr;
        }
    }
    
    ~Directory () {
        cout << "Bye, I'm destructing" << endl;
        for (size_t index = 0; index << size ; ++index) {
            delete entries [index];
        }
        delete [] entries;
    }
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)    {
            // something is missing!!!  Add it!
            Entry** old = entries;
            capacity = capacity * 2 + 1;
            entries = new Entry* [capacity];
            //entries = new Entry* [capacity*2 + 1];
            //capacity = capacity * 2 + 1;
            for (size_t index = 0; index < size ; ++ index) {
                entries [index] = old [index];
            }
            
            for (size_t index = size; index < capacity; ++ index) {
                entries [index] = nullptr;
            }
            
            delete [] old;
            
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
        
    } // add
    
    int operator[] (const string& name) const {
        for (size_t index = 0; index < size; ++index) {
            if (entries[index] -> getName() == name){
                return entries [index] -> getPhone ();
            }
        }
        return 0;
    }
    
    Directory& operator= (const Directory& dr)  {
        if (this != &dr ) {
            for (size_t index = 0; index < size; ++index) {
                delete entries [index];
            }
            delete [] entries;
            capacity = dr.capacity;
            size = dr.size;
            entries = new Entry* [capacity];
            for (size_t index = 0; index < size; ++index) {
                entries [index] = new Entry (*(dr.entries [index]));
            }
            for (size_t index = size; index < capacity; ++ index) {
                entries [index] = nullptr;
            }
        }
        return *this;
    }
    
    void display(ostream& os = cout) const {
        for (size_t i = 0; i < size; ++i) {
            entries[i]->display(os);
            os << endl;
        }
    }
    
private:
    Entry** entries = nullptr;
    size_t size = 0;
    size_t capacity = 0;
}; // class Directory

void doNothing(Directory dir) { dir.display(); }

int main() {
    
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    d.display();
    
    Directory d2 = d;    // What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    d2.display();
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    
    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main

