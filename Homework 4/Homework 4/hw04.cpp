//
//  hw04.cpp
//  Homework 4
//
//  Created by Cindy Lee on 10/3/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//
//  Purpose: Simulate medieval battles between nobles, who can hire/fire
//  warriors. An army of warriors battle for the nobles.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Warrior{
public:
    Warrior (const string& name, double strength) : name (name), strength (strength) {}
    
    //return whether the warrior is hired
    bool isHired () const {
        return hired;
    }
    
    // change attribute if hired
    void changeToHired () {
        hired = true;
    }
    
    // change attribute if fired
    void changeToFired () {
        hired = false;
    }
    
    // return warrior's name
    string getName () const {
        return name;
    }
    
    // return warrior's strength
    double getStrength () const {
        return strength;
    }
    
    // change the warrior's strength
    void changeStrength (double ratio) {
        strength = strength * ratio;
    }
    
    //displaying warrior
    void display () const {
        cout << "\t" << name << ": " <<
        strength << endl;
    }
    
private:
    string name;
    double strength;
    bool hired = false;
};

class Noble {
public:
    Noble (const string &name) : name (name) {}
    
    //hire a warrior
    bool hire (Warrior& warrior) {
        //cannot hire if dead
        if (dead){
            return false;
        }
        
        //cannot hire if warrior has already been hired
        if (warrior.isHired()){
            return false;
        }
        
        //add warrior to army, set warrior to be hired
        army.push_back (&warrior);
        warrior.changeToHired ();
        armyStrength += warrior.getStrength();
        return true;
    }
    
    //firing a warrior
    bool fire (Warrior& warrior) {
        //cannot fire if dead
        if (dead) {
            return false;
        }
        
        //locate warrior if it exists
        size_t counter = 0;
        for (size_t index = 0; index < army.size (); ++index) {
            if (army [index] == &warrior) {
                counter = index;
            }
        }
        
        //cannot fire if warrior does not exist
        if (army [counter] != &warrior) {
            return false;
        }
        
        //shift over warriors in army to maintain order
        for (size_t index = counter; index < army.size () - 1; ++index) {
            army[index] = army [index + 1];
        }
        
        //remove last replica of warrior
        army.pop_back();
        armyStrength -= warrior.getStrength();
        warrior.changeToFired ();
        cout << warrior.getName() <<
        ", you're fired! -- " << name << endl;
        return true;
    }
    
    //noble and warriors lose strength
    void loseStrength (double ratio) {
        armyStrength = 0;
        //for each warrior, adjust strength to the ratio
        for (size_t index = 0; index < army.size (); ++index) {
            (* (army [index]) ).changeStrength ( ratio );
            armyStrength += (*(army [index])).getStrength();
        }
    }
    
    //battling another Noble
    void battle (Noble& other) {
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
    
    //displaying Noble and his army
    void display () const {
        cout << name << " has an army of " << army.size () << endl;
        //loop through vector to display each warrior
        for (size_t index = 0; index < army.size (); ++index) {
            (* (army [index])).display ();
        }
    }
    
private:
    string name;
    double armyStrength = 0;
    vector <Warrior*> army;
    bool dead = false;
};

// test code
int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    //Test to see if fire works
    //art.hire(cheetah);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}
