//
//  Warrior.cpp
//  Homework 7
//
//  Created by Cindy Lee on 11/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  CPP file for Protector

#include "Protector.h"
#include "Noble.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
    
    //initializing Protector
    Protector::Protector (const string& name, double strength):
    name (name), strength (strength){}
    
    // return Protector's name
    string Protector::getName () const {
        return name;
    }
    // return Lord's name
    string Protector::lordName () const {
        if (master) {
            return master -> getName();
        }
        return "";
    }
    
    // return true if hired
    bool Protector::isHired() const {
        return hired;
    }
    
    // return true if dead
    bool Protector::isDead() const {
        return dead;
    }
    
    // change attributes if hired
    void Protector::changeToHired(Lord* noble) {
        master = noble;
        hired = true;
    }
    
    // return strength
    double Protector::getStrength() const {
        return strength;
    }
    
    // change strength of Protector
    void Protector::changeStrength(double ratio) {
        strength *= ratio;
        if (master -> isDead()) {
            dead = true;
        }
    }
    
    // change attribute if dead
    void Protector::changeToDead() {
        dead = true;
    }
    
    // change attributes if quitting
    void Protector::changeToRunaway() {
        hired = false;
        master = nullptr;
    }
    
    // Protector is quitting
    bool Protector::runaway () {
        if (dead) {
            return false;
        }
        if (master != nullptr) {
            
            // call on noble's running away method
            bool running = master -> running (this);
            cout << name << " flees in terror, abandoning his lord, ";
            cout << master -> getName () << endl;
            
            // call changeToRunaway to modify attributes if
            // quitting is successful
            if (running) {
                changeToRunaway ();
            }
            return running;
        }
        return false;
    }
    
    // a Wizard fighting, thus changing strength
    void Wizard::changeStrength(double ratio) {
        Protector::changeStrength(ratio);
        cout << "POOF" << endl;
    }
    
    // Warrior fighting, thus changing strength
    void Warrior::changeStrength(double ratio) {
        Protector::changeStrength(ratio);
        cout << getName () <<  " says: Take that in the name of my lord, "
        << lordName () << endl;
    }
    
    // Archer fighting, thus changing strength
    void Archer::changeStrength(double ratio) {
        cout << "TWANG! ";
        Warrior::changeStrength(ratio);
    }
    
    // Swordsman fighting, thus changing strength
    void Swordsman::changeStrength(double ratio) {
        cout << "CLANG! ";
        Warrior::changeStrength(ratio);
    }
    
}
