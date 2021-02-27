//
//  hw01.cpp
//  homework1
//
//  Created by Cindy Lee on 9/6/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: The program decrypts a text file that was encoded using Caesar cypher.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decryptCharacter(char encryptedChar, int stepRotation) {
    /*
     Decrypts a lowercase character given the inputted step
     rotation used to perform encryption.
     */
    
    // return the character if it is not between 'a' and 'z'
    if (!('a' <= encryptedChar && encryptedChar <= 'z')) {
        return encryptedChar;
    }
    
    // decrypt depending on positive or negative rotation
    char decryptedChar;
    if (stepRotation >= 0) {
        decryptedChar = encryptedChar - (stepRotation % 26);
    }
    else {
        decryptedChar = encryptedChar - ((stepRotation % 26) + 26);
    }

    // if invalid character, loop around to obtain decrypted character
    if (decryptedChar < 'a') {
        decryptedChar = 'z' - ('a' - decryptedChar) + 1;
    }
    return decryptedChar;
}

void decrypt(string& encrypted, int stepRotation) {
    /*
     Modifies an encryped string into its decrypted form.
     */
    for (size_t indexS = 0; indexS < encrypted.size(); ++indexS) {
        encrypted[indexS] = decryptCharacter(encrypted[indexS], stepRotation);
    }
}

int main() {
    // Receive file name from input
    ifstream encryptedFile("encrypted.txt");
    if (!encryptedFile) {
        cerr << "Failed to open… \n";
        exit(1);
    }
    vector<string> fileLines;
    int step = 0;
    string line;
    
    // First line in the file will be rotation step.
    // Then it will be the encrypted lines.
    encryptedFile >> step;
    while (getline(encryptedFile, line)) {
        fileLines.push_back(line);
    }
    encryptedFile.close();
    
    // Lines in the file are encrypted in reverse order.
    // Decrypt and display in reverse order.
    for (size_t index = fileLines.size() - 1; index > 0; --index) {
        decrypt(fileLines[index], step);
        cout << fileLines[index] << endl;
    }
}
