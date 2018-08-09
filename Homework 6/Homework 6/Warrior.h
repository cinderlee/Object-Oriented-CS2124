//
//  Warrior.h
//  Homework 6
//
//  Created by Cindy Lee on 10/21/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Warrior header file

#ifndef WARRIOR_H
#define WARRIOR_H

#include <stdio.h>
#include <string>
#include <iostream>

namespace WarriorCraft {
    class Noble;
    
    class Warrior {
        //output operator for warrior
        friend std::ostream& operator<<
        (std::ostream& os, const Warrior& warrior);
        
    private:
        std::string name;
        double strength;
        bool hired;
        Noble* boss;
        bool dead;
        
    public:
        //initializing a warrior
        Warrior (const std::string& name, double strength);
        
        //return whether the warrior is hired
        bool isHired () const;
        
        // change attribute if hired
        void changeToHired (Noble& noble);
        
        // change attribute if fired
        void changeToFired ();
        
        // change attribute if running away
        void changeToRunaway ();
        
        // change attribute if dead
        void changeToDead ();
        
        //return warrior's name
        std::string getName () const;
        
        //return warrior's strength
        double getStrength () const;
        
        //// change the warrior's strength
        void changeStrength (double ratio);
        
        //warrior is running away from noble
        bool runaway ();
    };
}


#endif /* WARRIOR_H */
