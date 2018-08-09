//
//  Noble.cpp
//  Homework 7
//
//  Created by Cindy Lee on 11/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  CPP file of Noble


#include "Noble.h"
#include "Protector.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
    
    // initializing a noble
    Noble::Noble (const string& name, double strength):
    name (name), strength (strength) {}
    
    // returns name of noble
    string Noble::getName () const {
        return name;
    }
    
    // returns whether noble is dead
    bool Noble::isDead () const {
        return dead;
    }
    
    // returns strength of noble
    double Noble::getStrength() const {
        return strength;
    }
    
    // changes strength of a Noble
    void Noble::changeStrength (double newStrength) {
        strength = newStrength;
    }
    
    // battling a noble
    void Noble::battle (Noble& other) {
        
        cout << name << " battles " << other.name << endl;
        
        //if both are dead
        if (dead and other.dead){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        //if one Noble is dead
        else if (dead) {
            cout << "He's dead, " << other.name << endl;
        }
        else if (other.dead){
            cout << "He's dead, " << name << endl;
        }
        
        //if Nobles have equal strength, both die, armies strength = 0
        else if (strength == other.strength) {
            cout << "Mutual Annihalation: " << name << " and " <<
            other.name << " die at each other's hands" << endl;
            dead = true;
            other.dead = true;
            changeStrength (0);
            other.changeStrength (0);
        }
        
        //if army is stronger, other and his army dies
        //army loses strength
        else if (strength > other.strength) {
            double ratio = other.strength/strength;
            changeStrength (1 - ratio);
            other.changeStrength(0);
            cout << name << " defeats " << other.name << endl;
            other.dead = true;
        }
        
        //if other army is stronger, army dies
        //other army loses strength
        else {
            double ratio = strength/other.strength;
            changeStrength (0);
            other.changeStrength(1 - ratio);
            cout << other.name << " defeats " << name << endl;
            dead = true;
        }
        
    }
    
    //Lord's constructor
    Lord::Lord (const string& name) : Noble (name, 0) {}
    
    // Lord hiring a Protector
    bool Lord::hires (Protector& war) {
        // if Lord is dead
        if (isDead()) {
            return false;
        }
        
        // if Protector is already hired or
        // if Protected is dead
        if (war.isHired () || war.isDead ()) {
            return false;
        }
        
        // else hire Protector
        // adjust strength to add Protector's strength
        army.push_back (&war);
        war.changeToHired(this);
        Noble::changeStrength ( getStrength() + war.getStrength());
        return true;
    }
    
    // Lord changing strength
    void Lord::changeStrength (double ratio) {
        double armyStrength = 0;
        //for each warrior, adjust strength to the ratio
        for (size_t index = 0; index < army.size (); ++index) {
            army [index] -> changeStrength ( ratio );
            armyStrength += army [index] -> getStrength();
        }
        Noble::changeStrength(armyStrength);
    }
    
    // finding Protector in army
    size_t Lord::findProtector (const Protector* warrior) const{
        
        // return protector's index in vector
        for (size_t index = 0; index < army.size (); ++index) {
            if (army [index] == warrior) {
                return index;
            }
        }
        
        // return size of vector if protector does not exist
        return army.size();
    }
    
    // A warrior quitting a noble
    bool Lord::running (const Protector* war) {
        // if Noble is dead
        if (isDead () ) {
            cout << "Cannot " << 
            " run away from a dead noble" << endl;
            return false;
        }
        
        // locate Protector
        size_t counter = findProtector (war);
        if (counter == army.size() ) {
            return false;
        }
        
        // shift Protectors to maintain order
        for (size_t index = counter; index < army.size () - 1; ++index) {
            army[index] = army [index + 1];
        }
        
        // remove last replica of warrior
        // adjust strength
        army.pop_back();
        Noble::changeStrength ( getStrength() - war -> getStrength());
        return true;
    }
    

    // Noble with strength changing his 
    void PersonWithStrengthToFight::changeStrength(double ratio) {
        Noble::changeStrength( ratio * getStrength());
    }
    
}
