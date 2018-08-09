//
//  hw05.cpp
//  Homework 5
//
//  Created by Cindy Lee on 10/7/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//
//  Purpose: Simulate nobles hiring and firing warriors and
//  nobles battling each other from a given list of commands
//  in a text file

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
        cout << name << ": " <<
        strength << endl;
    }
    
private:
    string name;
    double strength;
    bool hired = false;
};

class Noble {
public:
    Noble (const string& name) : name (name) {}
    
    // return name of Noble
    string getName () const {
        return name;
    }
    
    // return whether Noble is dead
    bool isDead () const {
        return dead;
    }
    
    //hire a warrior
    bool hire (Warrior& warrior) {
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
        warrior.changeToHired ();
        armyStrength += warrior.getStrength();
        return true;
    }
    
    //firing a warrior, return warrior pointer
    Warrior* fire (const string& warriorName){
        //cannot fire if dead
        if (dead) {
            cout << "Dead " << name << " cannot fire" << endl;
            return nullptr;
        }
        
        //locate warrior if it exists
        size_t counter = 0;
        for (size_t index = 0; index < army.size (); ++index) {
            if (army [index] -> getName () == warriorName) {
                counter = index;
            }
        }
        
        //cannot fire if warrior does not exist
        if (army [counter] -> getName () != warriorName ) {
            cout << warriorName << " does not exist in " <<
            name << "'s army!" << endl;
            return nullptr;
        }
        
        Warrior* fired = army [counter];
        
        //shift over warriors in army to maintain order
        for (size_t index = counter; index < army.size () - 1; ++index) {
            army[index] = army [index + 1];
        }
        
        //remove last replica of warrior
        army.pop_back();
        armyStrength -= fired -> getStrength ();
        fired -> changeToFired ();
        cout << "You don't work for me anymore " << fired -> getName() <<
        "! -- " << name << endl;
        return fired;
    }
    
    //noble and warriors lose strength
    void loseStrength (double ratio) {
        armyStrength = 0;
        //for each warrior, adjust strength to the ratio
        for (size_t index = 0; index < army.size (); ++index) {
            army [index] -> changeStrength ( ratio );
            armyStrength += army [index] -> getStrength();
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
            cout << "\t";
            army [index] -> display ();
        }
    }
    
    // clearing out the hired warriors from army
    void clear () {
        // delete each hired warrior
        for (size_t index = 0; index < army.size () ; ++index){
            delete army [index];
        }
        army.clear ();
    }
    
private:
    string name;
    double armyStrength = 0;
    vector <Warrior*> army;
    bool dead = false;
};

// Prototypes

//creating a noble
bool createNoble (const string& name, vector <Noble*>& nobles);

//creating a warrior
bool createWarrior (const string& name, int strength,
                    vector <Warrior*>& warriors);

//finding index of noble
size_t findNoble (const string& name, const vector <Noble*>& nobles);

//finding index of warrior
size_t findWarrior (const string& name, const vector <Warrior*>& warriors);

//a noble hiring a warrior
bool hire (const string& nobleName, const string& warriorName,
           vector <Noble*>& nobles, vector <Warrior*>& warriors);

//a noble firing a warrior
bool fire (const string& nobleName, const string& warriorName,
           vector <Noble*>& nobles, vector <Warrior*>& warriors);

//a noble battling another noble
bool battle (const string& nobleOne, const string& nobleTwo,
             vector <Noble*>& nobles);

// show status of nobles, nobles' armies, and unemployed warriors
void status (const vector <Noble*>& nobles,
             const vector <Warrior*>& warriors);

// clearing out nobles and warriors
void clear (vector <Noble*>& nobles, vector <Warrior*>& warriors);



int main() {
    ifstream nobleFile ("nobleWarriors.txt");
    
    // if file not found
    if (!nobleFile) {
        cerr << "Invalid file name.";
        exit (1);
    }
    
    string command;
    
    vector <Noble*> nobles;
    vector <Warrior*> warriors;
    
    //stream commands from file
    while (nobleFile >> command) {
        
        // if noble command
        // stream noble's name
        // create noble
        if (command == "Noble"){
            string name;
            nobleFile >> name;
            createNoble (name, nobles);
        }
        
        // if warrior command,
        // stream warrior's name
        // create warrior
        else if (command == "Warrior"){
            string name;
            int strength = 0;
            nobleFile >> name >> strength;
            createWarrior (name, strength, warriors);
        }
        
        // if hire command
        // stream noble's name and warrior's name
        // call hire
        else if (command == "Hire"){
            string nobleName;
            string warriorName;
            nobleFile >> nobleName >> warriorName;
            hire (nobleName, warriorName, nobles, warriors);
        }
        
        // if fire command
        // stream noble's name and warrior's name
        // call fire
        else if (command == "Fire"){
            string nobleName;
            string warriorName;
            nobleFile >> nobleName >> warriorName;
            fire (nobleName, warriorName, nobles, warriors);
        }
        
        // if battle command
        // stream the two nobles' names
        // call battle
        else if (command == "Battle") {
            string nobleOne;
            string nobleTwo;
            nobleFile >> nobleOne >> nobleTwo;
            battle (nobleOne, nobleTwo, nobles);
        }
        
        // if status command, call status
        else if (command == "Status") {
            status (nobles, warriors);
        }
        
        // if clear command, call clear
        else {
            clear (nobles, warriors);
        }
    }
    
    nobleFile.close();
    
}

// creating a noble
bool createNoble (const string& name, vector <Noble*>& nobles) {
    
    // check for if a noble with name exists
    for (size_t index = 0; index < nobles.size(); ++index){
        if ( nobles [index] -> getName() == name ){
            cout << "Noble " << name <<
            " already exists!" << endl;
            return false;
        }
    }
    
    // create new noble and add to vector
    nobles.push_back (new Noble(name));
    return true;
}

//create a new warrior
bool createWarrior (const string& name, int strength,
                    vector <Warrior*>& warriors) {
    
    //check if a warrior with name exists
    for (size_t index = 0; index < warriors.size(); ++index){
        if ( warriors [index] -> getName() == name ){
            cout << "Warrior " << name <<
            " already exists!" << endl;
            return false;
        }
    }
    
    // create new warrior and add to vector
    warriors.push_back (new Warrior (name, strength));
    return true;
}

// return noble's index in vector if exists
size_t findNoble (const string& name, const vector <Noble*>& nobles){
    
    // return the index in vector
    for (size_t index = 0; index <nobles.size (); ++index){
        if (nobles[index] -> getName () == name){
            return index;
        }
    }
    
    // return size of vector if not found
    return nobles.size ();
}

// return warrior's index in vector if exists
size_t findWarrior (const string& name, const vector <Warrior*>& warriors){
    
    // return the index in vector
    for (size_t index = 0; index <warriors.size (); ++index){
        if (warriors [index] -> getName () == name){
            return index;
        }
    }
    
    // return size of vector if not found
    return warriors.size ();
}

bool hire (const string& nobleName, const string& warriorName,
           vector <Noble*>& nobles, vector <Warrior*>& warriors){
    
    // find index of both noble and
    // warrior in their corresponding vectors
    size_t nobleIndex = findNoble (nobleName, nobles);
    size_t warIndex = findWarrior (warriorName, warriors);
    
    // if noble and warrior do not exist
    if (nobleIndex == nobles.size ()  &&
        warIndex == warriors.size ()){
        cout << "Cannot hire! " << nobleName <<
        " does not exist and " << warriorName <<
        " is not unemployed!" << endl;
        return false;
    }
    
    // if only noble doesn't exist
    else if ( nobleIndex == nobles.size () ) {
        cout << "Cannot hire! " << nobleName <<
        " does not exist" << endl;
        return false;
    }
    
    // if only warrior doesn't exist
    else if ( warIndex == warriors.size () ) {
        cout << "Cannot hire! " << warriorName <<
        " is not unemployed " << endl;
        return false;
    }
    
    // if both exist, call noble's hire
    else {
        nobles [nobleIndex] -> hire (*(warriors [warIndex]));
        
        //shift over unemployed warriors to maintain order
        //and to pop out hired warrior
        for (size_t index = warIndex;
             index < warriors.size () - 1; ++index) {
            warriors [index] = warriors [index + 1];
        }
        
        //remove last replica of warrior
        warriors.pop_back();
        return true;
    }
}


// firing a warrior
bool fire (const string& nobleName, const string& warriorName,
           vector <Noble*>& nobles, vector <Warrior*>& warriors ){
    
    // find index of noble
    size_t nobleIndex = findNoble (nobleName, nobles);
    
    // if noble does not exist
    if (nobleIndex == nobles.size () ){
        cout << "Cannot fire! " << nobleName <<
        " doesn't exist!!" << endl;
        return false;
    }

    // if noble exist, call noble's fire
    // add warrior back to vector if warrior exists
    else {
        Warrior* fired = nobles [nobleIndex] -> fire (warriorName);
        
        // if return value is nullptr
        if (fired == nullptr) {
            return false;
        }
        
        //if warrior does exist
        warriors.push_back (fired);
        return true;
    }
}

// battle
bool battle (const string& nobleOne, const string& nobleTwo,
             vector <Noble*>& nobles){
    
    //retrieve index of nobleOne and nobleTwo
    size_t nobleOneIndex = findNoble (nobleOne, nobles);
    size_t nobleTwoIndex = findNoble (nobleTwo, nobles);
    
    // if neither exist
    if (nobleOneIndex == nobles.size () &&
        nobleTwoIndex == nobles.size ()){
        cout << nobleOne << " and " << nobleTwo <<
        " don't exist! Can't battle!" << endl;
        return false;
    }
    
    //if only nobleOne doesn't exist
    else if (nobleOneIndex == nobles.size ()){
        cout << nobleOne << "doesn't exist! Can't battle!" << endl;
        return false;
    }
    
    // if only nobleTwo doesn't exist
    else if (nobleTwoIndex == nobles.size ()){
        cout << nobleTwo << "doesn't exist! Can't battle!" << endl;
        return false;
    }
    
    // else, nobleOne declares battle!
    else {
        nobles [nobleOneIndex] -> battle (*(nobles [nobleTwoIndex]));
        return true;
    }
}

// outputting status
void status (const vector <Noble*>& nobles,
             const vector <Warrior*>& warriors){
    cout << "Status" << "\n" << "=====" << endl;
    
    //outputting Nobles
    cout << "Nobles:" << endl;
    
    // if no nobles exist
    if (nobles.size () == 0){
        cout << "NONE" << endl;
    }
    
    // output nobles if exist using noble's display
    else {
        for (size_t index = 0; index < nobles.size (); ++index){
            nobles [index] -> display();
        }
    }

    //outputting Warriors
    cout << "Unemployed Warriors:" << endl;
    
    //if no warriors exist
    if (warriors.size () == 0) {
        cout << "NONE" << endl;
    }
    
    //if warriors do exist
    else {
        
        //output warriors who are not hired
        for (size_t index = 0; index < warriors.size (); ++index){
            warriors [index] -> display();
        }
    }
}

//clearing out nobles and warriors
void clear (vector <Noble*>& nobles, vector <Warrior*>& warriors){
    // delete each noble's army
    // delete each noble
    for (size_t index = 0; index < nobles.size(); ++ index) {
        nobles [index] -> clear ();
        delete nobles [index];
    }
    
    //clear nobles vector
    nobles.clear ();
    
    // deleting each warrior
    for (size_t index = 0; index < warriors.size(); ++ index) {
        delete warriors [index];
    }
    
    // clear warriors vector
    warriors.clear ();
}

