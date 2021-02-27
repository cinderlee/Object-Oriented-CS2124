//
//  hw03.cpp
//  homework3
//
//  Created by Cindy Lee on 9/23/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Create battles between warriors after taking in
//  warrior's name, weapon, and strength from a file

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Warrior{
public:
    Warrior(const string& name, const string& weapon, int strength): name(name), weapon(weapon, strength) { }
    
    string getName() const {
        return name;
    }
    
    void battle(Warrior& other) {
        // both warriors have strength 0
        if (other.weapon.getStrength() == 0 && weapon.getStrength() == 0) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        // both warriors have equal strength
        else if (weapon.getStrength() == other.weapon.getStrength()) {
            other.weapon.setStrength(0);
            weapon.setStrength (0);
            cout << "Mutual Annihilation: " << name << " and " << other.name << " die at each other's hands" << endl;
        }
        
        // both warriors are alive and have different strengths
        else if (weapon.getStrength() > 0 && other.weapon.getStrength() > 0) {
            if (weapon.getStrength() > other.weapon.getStrength()) {
                weapon.setStrength(weapon.getStrength() - other.weapon.getStrength());
                other.weapon.setStrength(0);
                cout << name << " defeats " << other.name << endl;
            }
            else {
                other.weapon.setStrength(other.weapon.getStrength() - weapon.getStrength());
                weapon.setStrength(0);
                cout << other.name << " defeats " << name << endl;
            }
        }
        
        // only one warrior is alive, ouput who is alive
        else if (weapon.getStrength() > 0) {
            cout << "He's dead, " << name << endl;
        }
        else {
            cout << "He's dead, " << other.name << endl;
        }
    }
    
    void display() const {
        cout << "Warrior: " << name << ", weapon: " << weapon.getName() << ", " << weapon.getStrength() << endl;
    }
    
private:
    class Weapon {
    public:
        Weapon(const string& weaponName, int weaponStrength): name(weaponName), strength(weaponStrength) { }
        
        string getName() const {
            return name;
        }
        
        int getStrength() const {
            return strength;
        }
        
        void setStrength(int newStrength) {
            strength = newStrength;
        }
    private:
        string name;
        int strength;
    };

    string name;
    Weapon weapon;
};

//Prototypes
void addWarrior(vector<Warrior>& warriors, const string& name, const string& weaponName, int strength);
void battle(vector <Warrior>& warriors, const string& warriorOne, const string& warriorTwo);
void status(const vector<Warrior>& warriors);

int main() {
    vector<Warrior> warriors;
        
    // open warrior file
    ifstream medievalFile("warriors.txt");
    if (!medievalFile) {
        cerr << "Could not open file \n";
        exit(1);
    }
    string command;
    
    while (medievalFile >> command) {

        // Warrior command: add Warrior to warriors vector
        if (command == "Warrior") {
            string name = "";
            string weaponName = "";
            int strength = 0;
            medievalFile >> name >> weaponName >> strength;
            addWarrior(warriors, name, weaponName, strength);
        }
        
        // Battle command: commence battle
        else if (command == "Battle") {
            string warriorOne;
            string warriorTwo;
            medievalFile >> warriorOne >> warriorTwo;
            battle(warriors, warriorOne, warriorTwo);
        }
        
        //if status command, call status
        else {
            status(warriors);
        }
    }

    medievalFile.close ();
}

void addWarrior(vector<Warrior>& warriors, const string& name, const string& weaponName, int strength) {
    /*
     Creates and adds a warrior to the given vector of warriors
     */
    Warrior newWarrior(name, weaponName, strength);
    warriors.push_back(newWarrior);
}

//commence battle between two warriors
void battle(vector <Warrior>& warriors, const string& warriorOne, const string& warriorTwo) {
    /*
     Commences battle between two warriors if possible
     */
    
    // find indices of the warriors in battle
    size_t indexWarriorOne = 0;
    size_t indexWarriorTwo = 0;
    for (size_t index = 0; index < warriors.size(); ++index) {
        if (warriors[index].getName() == warriorOne) {
            indexWarriorOne = index;
        }
        else if (warriors[index].getName() == warriorTwo) {
            indexWarriorTwo = index;
        }
    }
    
    cout << warriors[indexWarriorOne].getName() << " battles " << warriors[indexWarriorTwo].getName() << endl;
    
    // battle!
    warriors[indexWarriorOne].battle(warriors[indexWarriorTwo]);
}

void status(const vector<Warrior>& warriors) {
    /*
     Outputs the status of all warriors
     */
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (const Warrior& warrior : warriors) {
        warrior.display();
    }
}
