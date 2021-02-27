//
//  rec02.cpp
//  lab2
//
//  Created by Cindy Lee on 9/15/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Store and output sorted hydrocarbons with given name entries for each one

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct Hydrocarbon {
    vector<string> names;
    int carbonNum;
    int hydrogenNum;
};

string retrieveFileName() {
    /*
     Asks the user to input a file name and returns that file name.
     If user inputs invalid file name, asks the user again until valid.
     */
    cout << "File Name? ";
    string fileName;
    cin >> fileName;
    ifstream hydrocarbonFile(fileName);
    if (!hydrocarbonFile){
        cerr << "Could not find file. Try again \n";
        fileName = retrieveFileName();
    }
   
    hydrocarbonFile.close();
    return fileName;
}

size_t findHCIndex(const vector<Hydrocarbon>& hcs, int carbonNum, int hydrogenNum) {
    /*
     Returns index in a vector of hydrocarbons that matches the specified
     carbon and hydrogen numbers.
     
     If hydrocarbon is not in the vector, return the size of vector.
     */
    for (size_t index = 0; index < hcs.size(); ++index) {
        if ((hcs[index].carbonNum == carbonNum) &&
            (hcs[index].hydrogenNum == hydrogenNum)) {
            return index;
        }
    }
    return hcs.size();
}

int readHydrocarbonFile(ifstream& hydrocarbonFile, vector<Hydrocarbon>& hydrocarbons) {
    /*
     Reads a file of hydrocarbon informations and stores information in
     the given vector.
     
     Returns the largest carbon number among all the hydrocarbons.
     */
    string hcName;
    char carbon;
    char hydrogen;
    int carbonNum = 0;
    int hydrogenNum = 0;
    int largestCarbonNum = 0;
    
    while (hydrocarbonFile >> hcName >> carbon >>
           carbonNum >> hydrogen >> hydrogenNum) {
        size_t index = findHCIndex(hydrocarbons, carbonNum, hydrogenNum);
        if (index < hydrocarbons.size()) {
            //add name to existing hydrocarbon
            hydrocarbons[index].names.push_back(hcName);
        }
        else {
            //add new hydrocarbon entry to vector
            //if new hydrocarbon has larger carbon number, make that largest
            Hydrocarbon newEntry;
            newEntry.names.push_back(hcName);
            newEntry.carbonNum = carbonNum;
            newEntry.hydrogenNum = hydrogenNum;
            hydrocarbons.push_back(newEntry);
            if (carbonNum > largestCarbonNum){
                largestCarbonNum = carbonNum;
            }
        }
    }
    
    return largestCarbonNum;
}

void display(const vector<Hydrocarbon>& hcs, int largestCNum) {
    /*
     Outputs hydrocarbons in order of sorted carbon numbers.
     */
    for (int cNum = 1; cNum <= largestCNum; ++cNum) {
        for (const Hydrocarbon& hc : hcs) {
            if (hc.carbonNum == cNum) {
                cout << 'C' << cNum << 'H' << hc.hydrogenNum;
                for (const string& name : hc.names) {
                    cout << ' ' << name;
                }
                cout << '\n';
            }
        }
    }
}


int main() {
    vector<Hydrocarbon> hydroCarbons;
    string fileName = retrieveFileName();
    ifstream hydrocarbonFile(fileName);
    
    int largestCarbonNum = readHydrocarbonFile(hydrocarbonFile, hydroCarbons);
    
    hydrocarbonFile.close ();
    display(hydroCarbons, largestCarbonNum);
}
