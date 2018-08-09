//
//  rec01.cpp
//  Lab_1
//
//  Created by Cindy Lee on 9/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee
//  Lab 1: Implementing Conway's Game of Life and generating 10 generations after given initial state


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int countneighbor (vector <string> v, int i, int j){
    //counts the number of neighbors who are alive
    int counting = 0;
    for (int start = i - 1; start <= (i + 1); ++start){
        for (int startrow = j - 1; startrow <= (j + 1); ++startrow ){
            if (v[start][startrow] == '*'){
                counting += 1;
            }
        }
    }
    if (v[i][j] == '*') {
        counting -= 1;
    }
    return counting;
}

//    if (v [i-1][j-1] == '*'){
//        counting += 1;
//    }
//    if (v [i-1][j] == '*'){
//        counting += 1;
//    }
//    if (v [i-1] [j + 1] == '*'){
//        counting += 1;
//    }
//    if (v [i][j-1] == '*'){
//        counting += 1;
//    }
//    if (v [i][j+1] == '*'){
//        counting += 1;
//    }
//    if (v [i+1][j-1] == '*'){
//        counting += 1;
//    }
//    if (v [i+1][j] == '*'){
//        counting += 1;
//    }
//    if (v [i+1][j+1] == '*'){
//        counting += 1;
//    }


int main() {
    //read initial state
    ifstream someStream ("life.txt");
    vector<string> vs;
    string s (22, ' ');
    vs.push_back (s);
    string line;
    while (getline (someStream, line)){
        for (size_t indexstring = 0; indexstring < line.size(); ++indexstring){
            if (line [indexstring] == '-'){
                line [indexstring] = ' ';
            }
        }
        line = " " + line + " ";
        vs.push_back (line);
    }
    someStream.close();
    vs.push_back (s);
    
    //print initial state
    cout << "Initial State:" << endl;
    for (size_t index = 1; index < vs.size ()-1; ++index){
        for (int initialline = 1; initialline < vs[index].size () - 1; ++initialline){
            cout << vs [index] [initialline];
        }
        cout << "\n";
    }
    string marker (40, '-');
    cout << marker << endl;
    
    int counter = 1;
    while (counter < 11){
        //generate a second board
        vector <string> vs2;
        for (size_t lines = 0; lines < vs.size (); ++lines) {
            vs2.push_back (s);
        }
        
        //count number of neighbors to determine next generation
        for (int index2 = 1; index2 < vs.size () - 1; ++index2){
            for (int index3 = 1; index3 < vs[index2].size () - 1; ++index3){
                int count = countneighbor (vs, index2, index3);
                if (vs [index2] [index3] == ' ' && count == 3) {
                    vs2 [index2] [index3] = '*';
                }
                else if (vs [index2] [index3] == '*' && (count == 2 || count == 3)) {
                    vs2 [index2] [index3] = '*';
                }
            }
        }
        
        //output generation
        cout << "Generation ";
        cout << counter << endl;
        for (size_t indexforv2 = 1; indexforv2 < vs2.size ()-1; ++indexforv2){
            for (int charindex = 1; charindex < vs2[indexforv2].size () - 1; ++charindex){
                cout << vs2 [indexforv2][charindex];
            }
            cout << "\n";
        }
        cout << marker << endl;
        
        vs = vs2;
        counter += 1;
    }
}
