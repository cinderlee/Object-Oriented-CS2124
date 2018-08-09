//
//  hw01.cpp
//  OOPHomework1
//
//  Created by Cindy Lee on 9/6/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Purpose: The program decrypts a text file that was encoded using Caesar cypher.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//decrypts a character given the inputted step rotation used to encrypt
char decryptCharacter (char character, int stepRotation) {
    //return character if not between 'a' and 'z'
    if ( ! ('a' <= character && character <= 'z') ) {
        return character;
    }
    
    //decrypt depending on positive or negative rotation
    char decrypted;
    if (stepRotation >= 0){
        decrypted = character - (stepRotation % 26);
    }
    else {
        decrypted = character - ((stepRotation % 26) + 26);
    }
    char newDecrypted;
    
    //if valid character, return character
    //else loop around to obtain decrypted character
    if (decrypted < 'a') {
        newDecrypted = 'z' - ('a' - decrypted) + 1;
        return newDecrypted;
    }
    return decrypted;
}

//modifies the string to its decrypted forms
void decrypt (string& crypted, int stepRotation) {
    for (size_t indexS = 0; indexS < crypted.size(); ++indexS) {
        //call function to decrypt each character
        crypted [indexS] =
        decryptCharacter (crypted [indexS], stepRotation);
    }
}

int main() {
    //open file to read
    ifstream encryptedFile ("encrypted.txt");
    if (!encryptedFile) {
        cerr << "Failed to open… \n" ;
        exit (1);
    }
    vector <string> fileLines;
    int step;
    
    //retrieve the step rotation from file
    encryptedFile >> step;
    string line;
    
    //append each line to vector fileLines
    while (getline (encryptedFile, line)) {
        fileLines.push_back (line);
    }
    encryptedFile.close ();
    
    //decrypt text and output to screen in correct order
    for (size_t index = fileLines.size () - 1; index > 0; --index){
        decrypt (fileLines[index], step);
        cout << fileLines [index] << endl;
    }
}
