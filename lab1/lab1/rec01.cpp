//
//  rec01.cpp
//  lab1
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

int countAliveNeighbors(const vector<string>& board, int i, int j) {
    /*
     Returns the number of alive neighbors given a position on the board.
     */
    int counter = 0;
    for (int row = i - 1; row <= i + 1; ++row){
        for (int col = j - 1; col <= j + 1; ++col){
            if (row == i && col == j){
                continue;
            }
            if (board[row][col] == '*'){
                counter += 1;
            }
        }
    }
    return counter;
}

vector<string> getInitialState(const string& filenm) {
    /*
     Returns a vector of strings representing the initial state of the board read
     in from a file.
     
     Board details:
        * = alive
        - = dead (converted to a space to match output text file)
     
     Note: Each row has a length of 20. The board is padded with a border of dead cells
     to remove the need for boundary checking.
     */
    ifstream boardFile(filenm);
    vector<string> board;
    string rowBorder(22, ' ');
    board.push_back(rowBorder);
    string line;
    
    while (getline(boardFile, line)){
        for (size_t index = 0; index < line.size(); ++index){
            if (line[index] == '-'){
                line[index] = ' ';
            }
        }
        board.push_back(" " + line + " ");
    }
    boardFile.close();
    board.push_back(rowBorder);
    return board;
}

void printBoard(const vector<string>& board, int generationNum = 0) {
    /*
     Outputs the board and its associated generation number
     */
    if (generationNum == 0) {
        cout << "Initial State:" << endl;
    }
    else {
        cout << "Generation " << generationNum << endl;
    }
    
    for (size_t row = 1; row < board.size() - 1; ++row){
        for (int col = 1; col < board[row].size () - 1; ++col){
            cout << board[row][col];
        }
        cout << "\n";
    }
    cout << string(40, '-') << endl;
}

void simulateConway(vector<string>& board, int numSimulations) {
    /*
     Simulates Conway's Game of Life for n generations.
     
     Rules:
        A living cell needs two or three living neighbors to remain alive in the next
        generation, otherwise the cell dies loneliness or overcrowding.
     
       A dead cell with exactly three living neighbors becomes alive in the next generation.
     */
    
    // print initial state
    printBoard(board);
    
    for (int counter = 1; counter <= numSimulations; ++counter) {
        // record which position to flip state
        vector<vector<int>> flipStates;
        
        for (int row = 1; row < board.size() - 1; ++row) {
            for (int col = 1; col < board[row].size() - 1; ++col) {
                int aliveNeighborsCount = countAliveNeighbors(board, row, col);
                if (board[row][col] == ' ' && aliveNeighborsCount == 3) {
                    flipStates.push_back({row, col});
                }
                else if (board[row][col] == '*' && !(aliveNeighborsCount == 2 || aliveNeighborsCount == 3)) {
                    flipStates.push_back({row, col});
                }
            }
        }
        
        for (const vector<int>& pos : flipStates) {
            int row = pos[0];
            int col = pos[1];
            if (board[row][col] == '*') {
                board[row][col] = ' ';
            }
            else {
                board[row][col] = '*';
            }
        }
        
        printBoard(board, counter);
    }
}

int main() {
    vector<string> board = getInitialState("life.txt");
    simulateConway(board, 10);
}
