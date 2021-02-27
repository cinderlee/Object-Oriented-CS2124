//
//  hw02.cpp
//  homework2
//
//  Created by Cindy Lee on 9/16/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: To simulate a medieval world where warriors battle
//  by reading in commands from a file

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Warrior {
    string name;
    int strength;
};

// Prototypes
void addWarrior(vector<Warrior>& warriors, const string& name, int strength);
void battle(vector<Warrior>& fight, const string& warOne, const string& warTwo);
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
        if (command == "Warrior"){
            string name = "";
            int strength = 0;
            medievalFile >> name >> strength;
            addWarrior(warriors, name, strength);
        }
        
        // Battle command: commence battle
        else if (command == "Battle"){
            string warriorOne;
            string warriorTwo;
            medievalFile >> warriorOne >> warriorTwo;
            battle(warriors, warriorOne, warriorTwo);
        }
        
        // status command: output status of all warriors
        else {
            status(warriors);
        }
    }
    
    medievalFile.close();
}

void addWarrior(vector<Warrior>& warriors, const string& name, int strength) {
    /*
     Creates and adds a warrior to the given vector of warriors
     */
    Warrior newWarrior;
    newWarrior.name = name;
    newWarrior.strength = strength;
    warriors.push_back(newWarrior);
}

void battle (vector <Warrior>& warriors, const string& warriorOne, const string& warriorTwo) {
    /*
     Commences battle between two warriors if possible
     */
    
    // find indices of the warriors in battle
    size_t indexWarriorOne = 0;
    size_t indexWarriorTwo = 0;
    for (size_t index = 0; index < warriors.size(); ++index) {
        if (warriors[index].name == warriorOne) {
            indexWarriorOne = index;
        }
        else if (warriors[index].name == warriorTwo ) {
            indexWarriorTwo = index;
        }
    }
    
    cout << warriorOne << " battles " << warriorTwo << endl;
    
    // both warriors are already dead
    if (warriors[indexWarriorOne].strength == 0 && warriors[indexWarriorTwo].strength == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    
    // both warriors have equal strength
    else if (warriors[indexWarriorOne].strength == warriors[indexWarriorTwo].strength) {
        warriors[indexWarriorOne].strength = warriors[indexWarriorTwo].strength = 0;
        cout << "Mutual Annihilation: " << warriorOne << " and " <<
            warriorTwo << " die at each other's hands" << endl;
    }
    
    // both warriors are alive and different strengths
    else if (warriors[indexWarriorOne].strength > 0 && warriors[indexWarriorTwo].strength > 0) {
        // determine who is weaker, who is stronger
        size_t strongerWarriorIndex = 0;
        size_t weakerWarriorIndex = 0;
        if (warriors[indexWarriorOne].strength > warriors[indexWarriorTwo].strength) {
            strongerWarriorIndex = indexWarriorOne;
            weakerWarriorIndex = indexWarriorTwo;
        }
        else {
            strongerWarriorIndex = indexWarriorTwo;
            weakerWarriorIndex = indexWarriorOne;
        }
        
        // battle
        warriors[strongerWarriorIndex].strength -= warriors[weakerWarriorIndex].strength;
        warriors[weakerWarriorIndex].strength = 0;
        cout << warriors[strongerWarriorIndex].name << " defeats " <<
            warriors[weakerWarriorIndex].name << endl;
    }
    
    // only one warrior is alive, ouput who is alive
    else if (warriors[indexWarriorOne].strength > 0) {
        cout << "He's dead, " << warriors[indexWarriorOne].name << endl;
    }

    else {
        cout << "He's dead, " << warriors[indexWarriorTwo].name << endl;
    }
}

void status(const vector<Warrior>& warriors) {
    /*
     Outputs the status of all warriors
     */
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for (const Warrior& warrior : warriors) {
        cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
    }
}

