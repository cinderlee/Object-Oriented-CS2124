//
//  hw03.cpp
//  Homework 3
//
//  Created by Cindy Lee on 9/23/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, id: cl3616
//  Purpose: Create battles between warriors after taking in
//  warrior's name, weapon, and strength from a file

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Warrior{
public:
    Warrior (const string& nameWar, const string& weapon, int strength):
    warName (nameWar), weapon (weapon, strength) {
    }
    
    string getName (){
        return warName;
    }
    
    void battle (Warrior& other){
        //if both warriors have strength 0
        if (other.weapon.getStrength () == 0 &&
            weapon.getStrength () == 0) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        //if both warriors have equal strength
        else if (weapon.getStrength () ==
                 other.weapon.getStrength()){
            other.weapon.changeStrength(0);
            weapon.changeStrength (0);
            cout << "Mutual Annihilation: " << warName << " and " <<
            other.warName << " die at each other's hands" << endl;
        }
        
        //if both warriors are alive and different strengths
        else if (weapon.getStrength () > 0 &&
                 other.weapon.getStrength () > 0) {
            if (weapon.getStrength ()>
                other.weapon.getStrength ()) {
                weapon.changeStrength (weapon.getStrength () -
                                       other.weapon.getStrength());
                other.weapon.changeStrength(0);
                cout << warName << " defeats " <<
                other.warName << endl;
            }
            else {
                other.weapon.changeStrength(other.weapon.getStrength() -
                                            weapon.getStrength());
                weapon.changeStrength(0);
                cout << other.warName << " defeats " <<
                warName << endl;
            }
        }
        
        //if only first warrior is alive
        else if (weapon.getStrength () > 0) {
            cout << "He's dead, " << warName << endl;
        }
        
        //if only second warrior is alive
        else {
            cout << "He's dead, " << other.warName << endl;
        }
    }
    
    //output warrior's name, weapon, and strength
    void display () const {
        cout << "Warrior: " << warName <<
        ", weapon: " << weapon.getName() <<
        ", " << weapon.getStrength() << endl;
    }
    
private:
    class Weapon {
    public:
        Weapon (const string& weaponName, int weaponStrength):
        name (weaponName), strength (weaponStrength) {
        }
        
        string getName () const {
            return name;
        }
        
        int getStrength () const {
            return strength;
        }
        
        void changeStrength (int newStrength){
            strength = newStrength;
        }
    private:
        string name;
        int strength;
    };
    string warName;
    Weapon weapon;
};

//Prototypes
//add Warrior to a vector of Warriors
void addWarrior (vector <Warrior>& fighter,
                 const string& name, const string& weaponName, int strength);

//commence battle between two warriors
void battle (vector <Warrior>& fight,
             const string& warOne, const string& warTwo);

//output status of each warrior
void status (const vector <Warrior>& wars);

int main() {
    vector <Warrior> wars;
    
    //open warrior file
    ifstream medieval ("warriors.txt");
    if (!medieval) {
        cerr << "Could not open file \n";
        exit (1);
    }
    string command;
    
    //stream the command
    while (medieval >> command){
        
        //if Warrior command, stream name and strength
        //call addWarrior
        if (command == "Warrior"){
            string name;
            string weaponName;
            int strength = 0;
            medieval >> name >> weaponName >> strength;
            addWarrior (wars, name, weaponName, strength);
        }
        
        //if Battle command, stream warriors
        //call battle
        else if (command == "Battle"){
            string warriorOne;
            string warriorTwo;
            medieval >> warriorOne >> warriorTwo;
            battle (wars, warriorOne, warriorTwo);
        }
        
        //if status command, call status
        else {
            status (wars);
        }
    }
    medieval.close ();
}

//add Warrior to vector of Warriors
void addWarrior (vector <Warrior>& fighter,
                 const string& name, const string& weaponName,
                 int strength){
    Warrior newWarrior (name, weaponName, strength);
    fighter.push_back (newWarrior);
}



//commence battle between two warriors
void battle (vector <Warrior>& fight,
             const string& warOne, const string& warTwo) {
    //denote indexWarOne for first warrior
    //denote indexWarTwo for second warrior
    size_t indexWarOne = 0;
    size_t indexWarTwo = 0;
    
    //loop through vector to find indices for warriors
    for (size_t index = 0; index < fight.size(); ++index){
        if (fight [index].getName() == warOne) {
            indexWarOne = index;
        }
        else if (fight [index].getName() == warTwo ) {
            indexWarTwo = index;
        }
    }
    
    cout << fight [indexWarOne].getName() << " battles "
    << fight [indexWarTwo].getName() << endl;
    
    //warriors battle
    fight[indexWarOne].battle (fight[indexWarTwo]);
}

//output status of warriors' name and strengths
void status (const vector<Warrior>& wars){
    cout << "There are: " << wars.size () << " warriors" << endl;
    //loop through vector to output name and strength of each warrior
    for (size_t index = 0; index < wars.size (); ++index) {
        wars [index].display ();
    }
}
