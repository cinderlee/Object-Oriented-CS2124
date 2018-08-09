//
//  Warrior.cpp
//  Homework 6
//
//  Created by Cindy Lee on 10/21/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Warrior cpp file

#include "Warrior.h"
#include "Noble.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
    
    //output operator for warrior
    std::ostream& operator<<
    (std::ostream& os, const Warrior& warrior) {
        os << warrior.name << ": " <<
        warrior.strength;
        return os;
    }
    
    //initializing a warrior
    Warrior::Warrior (const string& name, double strength) :
    name (name), strength (strength), hired (false), boss (nullptr),
    dead (false) {}
    
    //return whether the warrior is hired
    bool Warrior::isHired () const {
        return hired;
    }
    
    // change attribute if hired
    void Warrior::changeToHired (Noble& noble) {
        boss = &noble;
        hired = true;
    }
    
    // change attribute if fired
    void Warrior::changeToFired () {
        boss = nullptr;
        hired = false;
    }
    
    //change attributes if running away
    void Warrior::changeToRunaway() {
        boss = nullptr;
        hired = false;
    }
    
    // change attribute if dead
    void Warrior::changeToDead () {
        dead = true;
    }
    
    // return warrior's name
    string Warrior::getName () const {
        return name;
    }
    
    // return warrior's strength
    double Warrior::getStrength () const {
        return strength;
    }
    
    // change the warrior's strength
    void Warrior::changeStrength (double ratio) {
        strength = strength * ratio;
    }
    
    // warrior running away from noble
    bool Warrior::runaway () {
        
        // if a noble exists
        if (boss != nullptr) {
            
            // call on noble's remove method
            bool running = boss -> running (*this);
            cout << name << " flees in terror, abandoning his lord, ";
            cout << boss -> getName () << endl;
            
            // call changeToRunaway to modify attributes if
            // running away is successful
            if (running) {
                changeToRunaway ();
            }
            return running;
        }
        return false;
    }
    
}
