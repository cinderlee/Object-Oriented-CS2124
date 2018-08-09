//
//  Warrior.hpp
//  Homework 7
//
//  Created by Cindy Lee on 11/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Header file for Protector

#ifndef PROTECTOR_H
#define PROTECTOR_H

#include <stdio.h>
#include <string>

namespace WarriorCraft {
    class Lord;
    
    class Protector {
    public:
        // initializing a Protector
        Protector (const std::string& name, double strength);
        
        // return whether hired
        bool isHired () const;
        
        // return whether dead
        bool isDead () const;
        
        // change to hired
        void changeToHired (Lord* noble);
        
        // return strength
        double getStrength () const;
        
        // pure virtual changing strength
        virtual void changeStrength (double ratio) = 0;
        
        // change to dead
        void changeToDead ();
        
        // changing attributes to quit
        void changeToRunaway();
        
        // quitting a Noble
        bool runaway ();
    protected:
        
        // return Lord's name
        std::string lordName () const;
        
        // return name
        std::string getName () const;
        
    private:
        std::string name;
        double strength;
        bool hired = false;
        bool dead = false;
        Lord* master = nullptr;
    };
    
    class Wizard: public Protector {
    public:
        using Protector::Protector;
        //Wizard (const std::string& name, double strength);
        void changeStrength(double ratio);
    };
    
    class Warrior: public Protector {
    public:
        // using Protector's constructor
        using Protector::Protector;
        
        // pure virtual, changing strength 
        virtual void changeStrength (double ratio) = 0;
        
    };
    
    class Archer: public Warrior {
    public:
        // using warrior's constructor
        using Warrior::Warrior;
        
        // changing strength
        void changeStrength(double ratio);
    };
    
    class Swordsman: public Warrior {
    public:
        // using warrior's constructor
        using Warrior::Warrior;
        
        // changing strength
        void changeStrength(double ratio);
    };
}


#endif /* PROTECTOR_H */
