//
//  Noble.h
//  Homework 6
//
//  Created by Cindy Lee on 10/21/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Noble header file

#ifndef NOBLE_H
#define NOBLE_H

#include <stdio.h>
#include <string>
#include <vector>

namespace WarriorCraft {
    class Warrior;
    
    class Noble {
        
        // output operator of Noble
        friend std::ostream& operator<<
        (std::ostream& os, const Noble& noble);
        
    private:
        std::string name;
        std::vector <Warrior*> army;
        double armyStrength = 0;
        bool dead = false;
        
        //noble and warriors lose strength
        void loseStrength (double ratio);
        
        //finding warrior in army
        size_t findWarrior (const Warrior& warrior) const;
        
    public:
        
        //initializing noble
        Noble (const std::string& name);
        
        // returns name of noble
        std::string getName () const;
        
        //returns whether noble is dead
        bool isDead () const;
        
        // hiring a warrior
        bool hire (Warrior& warrior);
        
        // removing a warrior from army
        Warrior* remove (const Warrior& warrior);
        
        //firing a warrior
        bool fire (Warrior& warrior);
        
        //a warrior is running away
        bool running (const Warrior& warrior);
        
        //battling another Noble
        void battle (Noble& other);
    };
}
#endif /* NOBLE_H */
