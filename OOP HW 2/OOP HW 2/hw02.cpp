//
//  hw02.cpp
//  OOP HW 2
//
//  Created by Cindy Lee on 9/16/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Purpose: To simulate a medieval world where warriors battle,
//  by reading commands from a file

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Warrior has a name and strength
struct Warrior {
    string name;
    int strength;
};

//Prototypes
//add Warrior to a vector of Warriors
void addWarrior (vector <Warrior>& fighter,
                 const string& name, int strength);

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
            int strength = 0;
            medieval >> name >> strength;
            addWarrior (wars, name, strength);
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
}

//add Warrior to vector of Warriors
void addWarrior (vector <Warrior>& fighter,
                    const string& name, int strength){
    Warrior newWarrior;
    newWarrior.name = name;
    newWarrior.strength = strength;
    fighter.push_back (newWarrior);
}



//commence battle between two warriors if possible
void battle (vector <Warrior>& fight,
             const string& warOne, const string& warTwo) {
    //denote indexWarOne for first warrior
    //denote indexWarTwo for second warrior
    size_t indexWarOne = 0;
    size_t indexWarTwo = 0;
    
    //loop through vector to find indices for warriors
    for (size_t index = 0; index < fight.size(); ++index){
        if (fight [index].name == warOne) {
            indexWarOne = index;
        }
        else if (fight [index].name == warTwo ) {
            indexWarTwo = index;
        }
    }
    
    cout << fight [indexWarOne].name << " battles "
    << fight [indexWarTwo].name << endl;
    
    //if both warriors are already dead
    if (fight [indexWarOne].strength == 0 &&
        fight [indexWarTwo].strength == 0) {
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    
    //if both warriors have equal strength
    else if (fight [indexWarOne].strength ==
             fight [indexWarTwo].strength){
        fight [indexWarOne].strength =
        fight [indexWarTwo].strength = 0;
        cout << "Mutual Annihilation: " <<
        fight [indexWarOne].name << " and " <<
        fight [indexWarTwo].name <<
        " die at each other's hands" << endl;
    }
    
    //if both warriors are alive and different strengths
    else if (fight [indexWarOne].strength > 0 &&
             fight [indexWarTwo].strength > 0) {
        //stronger is index of stronger warrior
        //weaker is index of weaker warrior
        size_t stronger = 0;
        size_t weaker = 0;
        //determine who is weaker, who is stronger
        if (fight [indexWarOne].strength >
            fight [indexWarTwo].strength) {
            stronger = indexWarOne;
            weaker = indexWarTwo;
        }
        else {
            stronger = indexWarTwo;
            weaker = indexWarOne;
        }
        //battle
        fight [stronger].strength -= fight [weaker].strength;
        fight [weaker].strength = 0;
        cout << fight [stronger].name << " defeats " <<
        fight [weaker].name << endl;
    }
    
    //if only first warrior is alive
    else if (fight [indexWarOne].strength > 0) {
        cout << "He's dead, " << fight [indexWarOne].name << endl;
    }
    
    //if only second warrior is alive
    else {
        cout << "He's dead, " << fight [indexWarTwo].name << endl;
    }
}

//output status of warriors' name and strengths
void status (const vector<Warrior>& wars){
    cout << "There are: " << wars.size () << " warriors" << endl;
    //loop through vector to output name and strength of each warrior
    for (size_t index = 0; index < wars.size (); ++index) {
        cout << "Warrior: " << wars [index].name <<
        ", strength: " << wars [index].strength << endl;
    }
}

