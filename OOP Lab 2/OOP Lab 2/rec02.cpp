//
//  rec02.cpp
//  OOP Lab 2
//
//  Created by Cindy Lee on 9/15/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
// Purpose: Store and output sorted hydrocarbons with given name entries for each one

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct hydroCarbon {
    vector <string> names;
    int carbon;
    int hydrogen;
};

//ask the user to input correct file name and return file name
string retrievingFile () {
    cout << "File Name? ";
    string fileName;
    cin >> fileName;
    ifstream sciFile (fileName);
    if (!sciFile){
        cerr << "Could not find file. Try again \n";
        fileName = retrievingFile ();
    }
   
    sciFile.close ();
    return fileName;
}

void display (const vector <hydroCarbon>& hc, int largest) {
    
//    int counter = 0;
//    int carbonNum = 1;
//    while (counter < hc.size ()) {
//        for (size_t index = 0; index < hc.size (); ++index) {
//            if (hc [index].carbon == carbonNum){
//                cout << 'C' << hc [index].carbon << 'H' << hc [index].hydrogen;
//                for (size_t nameIndex = 0; nameIndex < hc [index].names.size(); ++nameIndex ) {
//                    cout << ' ' << hc [index].names [ nameIndex ];
//                }
//                cout << '\n';
//                counter += 1;
//            }
//        }
//        carbonNum += 1;
//    }
    
    for (int carb = 1; carb <= largest; ++carb) {
        for (size_t index = 0; index < hc.size (); ++index) {
            if (hc[index].carbon == carb) {
                cout << 'C' << carb << 'H' << hc[index].hydrogen;
                for (size_t name = 0; name < hc[index].names.size (); ++name) {
                    cout << ' ' << hc [index].names [name];
                }
                cout << '\n';
            }
        }
    }
}

//find whether the hydrocarbon exists in vector
//if so, return index; else, return size of vector
size_t findHC (const vector <hydroCarbon>& hc, int carbonNum, int hydrogenNum) {
    for (size_t index = 0; index < hc.size(); ++index) {
        if ( (hc [index].carbon == carbonNum) &&
            (hc [index].hydrogen == hydrogenNum) ) {
            return index;
        }
    }
    return hc.size ();
}



int main() {
    vector <hydroCarbon> hydroCarbons;
    
    //ifstream sciFile ("hydrocarbon.txt");
    //instead ask user for input
    
    string fileName = retrievingFile();
    ifstream sciFile (fileName);
    
    //streaming file
    string hcName;
    char carbon;
    char hydrogen;
    int carbonNum = 0;
    int hydrogenNum = 0;
    int largestCarbonNum = 0;
    
    while (sciFile >> hcName >> carbon >>
           carbonNum >> hydrogen >> hydrogenNum){
        size_t index = findHC (hydroCarbons, carbonNum, hydrogenNum);
        if (index < hydroCarbons.size ()) {
            //add hydrocarbon name to existing hydrocarbon
            hydroCarbons [index].names.push_back (hcName);
        }
        else {
            //add new hydrocarbon to vector
            //if new hydrocarbon has larger carbon number, make that largest
            hydroCarbon newChemical;
            newChemical.names.push_back (hcName);
            newChemical.carbon = carbonNum;
            newChemical.hydrogen = hydrogenNum;
            hydroCarbons.push_back (newChemical);
            if (carbonNum > largestCarbonNum){
                largestCarbonNum = carbonNum;
            }
        }
    }
    
    sciFile.close ();
    display (hydroCarbons, largestCarbonNum);
    
}
