//
//  Noble.hpp
//  Homework 7
//
//  Created by Cindy Lee on 11/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  header file of Noble

#ifndef NOBLE_H
#define NOBLE_H

#include <stdio.h>
#include <string>
#include <vector>

namespace WarriorCraft {
    class Protector;
    
    class Noble {
    public:
        // initializing Noble
        Noble (const std::string& name, double strength);
        
        //return name of Noble
        std::string getName () const;
        
        //Noble battling
        void battle (Noble& other);
        
        // return whether Noble is dead
        bool isDead () const ;
        
        //pure virtual, Noble changing strength
        virtual void changeStrength (double newStrength) = 0;
        
    protected:
        // returning strenght of Noble
        double getStrength () const;
        
    private:
        std::string name;
        double strength;
        bool dead = false;
    };
    
    class Lord : public Noble {
    public:
        // Lord constructor
        Lord (const std::string& name);
        
        // hiring a Protector
        bool hires (Protector& war);
        
        // a Protector running away
        bool running (const Protector* war);
        
    private:
        std::vector <Protector*> army;
        
        // changing strength
        void changeStrength (double newStrength);
        
        // locating Protector in army
        size_t findProtector (const Protector* warrior) const;
    };
    
    class PersonWithStrengthToFight : public Noble {
    public:
        // use Noble's constructor
        using Noble::Noble;
    private:
        
        // changing strenght
        void changeStrength (double newStrength);
    };
}

#endif /* NOBLE_H */
