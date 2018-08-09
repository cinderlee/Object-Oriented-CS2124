//
//  Noble.cpp
//  Homework 6
//
//  Created by Cindy Lee on 10/21/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Noble cpp file

#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace WarriorCraft {
    
    // overloading output operator to cout Noble
    ostream& operator<<
    (ostream& os, const Noble& noble){
        os << noble.name << " has an army of " << noble.army.size ();
        //loop through vector to output each warrior
        for (size_t index = 0; index < noble.army.size (); ++index) {
            os << "\n\t" << * (noble.army [index]);
        }
        return os;
    }
    
    // initialize Noble
    Noble::Noble (const string& name) : name (name)  {}
    
    // return name of Noble
    string Noble::getName () const {
        return name;
    }
    
    // return whether Noble is dead
    bool Noble::isDead () const {
        return dead;
    }
    
    //hire a warrior
    bool Noble::hire (Warrior& warrior) {
        //cannot hire if dead
        if (dead){
            cout << "Cannot hire! " << name << " is dead" << endl;
            return false;
        }
        
        //cannot hire if warrior has already been hired
        if (warrior.isHired()){
            cout << "Cannot hire employed " <<
            warrior.getName() << endl;
            return false;
        }
        
        //add warrior to army, set warrior to be hired
        army.push_back (&warrior);
        warrior.changeToHired (*this);
        armyStrength += warrior.getStrength();
        return true;
    }
    
    //locating a warrior in army vector
    size_t Noble::findWarrior (const Warrior& warrior) const{
        
        // return warrior's index in vector
        for (size_t index = 0; index < army.size (); ++index) {
            if (army [index] == &warrior) {
                return index;
            }
        }
        
        // return size of vector if warrior does not exist
        return army.size();
    }
    
    // removing a warrior from army if exists
    // return pointer of warrior that was removed
    Warrior* Noble::remove (const Warrior& warrior) {
        //locate warrior if it exists
        size_t counter = findWarrior (warrior);
        
        //cannot fire if warrior does not exist
        if (counter == army.size ()) {
            cout << warrior.getName () << " does not exist in " <<
            name << "'s army!" << endl;
            return nullptr;
        }
        
        Warrior* removeWar = army [counter];
        
        //shift over warriors in army to maintain order
        for (size_t index = counter; index < army.size () - 1; ++index) {
            army[index] = army [index + 1];
        }
        
        //remove last replica of warrior
        army.pop_back();
        armyStrength -= removeWar -> getStrength ();
        return removeWar;
    }
    
    //firing a warrior
    bool Noble::fire (Warrior& warrior){
        //cannot fire if dead
        if (dead) {
            cout << "Dead " << name << " cannot fire" << endl;
            return false;
        }
        
        // call on remove method to remove from army
        Warrior* fired = remove (warrior);
        
        // if warrior exists in army
        // call on warrior's changeToFired method
        if (fired) {
            cout << "You don't work for me anymore " << warrior.getName() <<
            "! -- " << name << endl;
            fired -> changeToFired ();
        }

        return fired != nullptr;
    }
    
    //removing a runaway
    bool Noble::running (const Warrior& warrior){
        //cannot runaway if noble is dead
        if (dead) {
            cout << "Cannot " << name <<
            " run away from a dead noble" << endl;
            return false;
        }
        
        // call on remove method to remove from army
        Warrior* running = remove (warrior);
        return running != nullptr;
    }
        
    //noble and warriors lose strength
    void Noble::loseStrength (double ratio) {
        armyStrength = 0;
        //for each warrior, adjust strength to the ratio
        for (size_t index = 0; index < army.size (); ++index) {
            army [index] -> changeStrength ( ratio );
            armyStrength += army [index] -> getStrength();
        }
    }
    
    //battling another Noble
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
        else if (armyStrength == other.armyStrength) {
            cout << "Mutual Annihalation: " << name << " and " <<
            other.name << " die at each other's hands" << endl;
            dead = true;
            other.dead = true;
            loseStrength (0);
            other.loseStrength (0);
        }
        
        //if army is stronger, other and his army dies
        //army loses strength
        else if (armyStrength > other.armyStrength) {
            double ratio = 1 - (other.armyStrength/armyStrength);
            loseStrength (ratio);
            other.loseStrength(0);
            cout << name << " defeats " << other.name << endl;
            other.dead = true;
        }
        
        //if other army is stronger, army dies
        //other army loses strength
        else {
            double ratio = 1 - (armyStrength/other.armyStrength);
            loseStrength (0);
            other.loseStrength(ratio);
            cout << other.name << " defeats " << name << endl;
            dead = true;
        }
    }
    
}
