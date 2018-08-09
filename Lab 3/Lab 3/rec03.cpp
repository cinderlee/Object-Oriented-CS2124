//
//  rec03.cpp
//  Lab 3
//
//  Created by Cindy Lee on 9/22/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, id: cl3616
//  Purpose: Simulate a minesweeper game for the user to interact with

#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

struct Cell {
    int numberBomb = 0;
    bool bomb = false;
    bool visible = false;
};

class Minesweeper {
public:
    //Minesweeper (vector <vector <Cell>>& boarder, int row, int col) :
    //board (boarder), rows (row), cols (col){
    Minesweeper (){
        rows = 16;
        cols = 30;
        for (int row = 0; row < rows+2; ++row) {
            vector <Cell> aRow;
            for (int column = 0; column < cols+2; ++column){
                Cell cell;
                aRow.push_back (cell);
            }
            board.push_back(aRow);
        }
        srand(time (NULL));
        for (size_t indexRow = 1; indexRow < rows+1; ++indexRow){
            for (size_t indexCol = 1; indexCol < board [indexRow].size()-1; ++indexCol){
                if (rand () % 100 < 10) {
                    board [indexRow] [indexCol].bomb = true;
                    //size_t surround = indexRow - 1;
                    //size_t surrC = indexCol - 1;
                    board [indexRow + 1] [indexCol-1].numberBomb += 1;
                    board [indexRow + 1] [indexCol].numberBomb += 1;
                    board [indexRow + 1] [indexCol+1].numberBomb += 1;
                    board [indexRow - 1] [indexCol+1].numberBomb += 1;
                    board [indexRow - 1] [indexCol].numberBomb += 1;
                    board [indexRow - 1] [indexCol-1].numberBomb += 1;
                    board [indexRow] [indexCol - 1].numberBomb += 1;
                    board [indexRow] [indexCol + 1].numberBomb += 1;
                    //for (size_t count = indexRow - 1; count < indexRow + 2; ++count){
                    //  for (size_t counter = indexCol - 1; counter< indexCol + 2; ++ count) {
                    //        if ((count > 0) && (count < rows - 1)) {
                    //            if ((counter > 0) && (counter < cols - 1)){
                    //                if (board [surround] [surrC].bomb == true){
                    //                    board[indexRow][indexCol].bomb += 1;
                    //                }
                    //            }
                    //        }
                }
            }
        }
    }
    
    void display (bool x) {
        if (x) {
            for (size_t indexRow = 1; indexRow < rows+1; ++indexRow){
                for (size_t indexCol = 1; indexCol < board [indexRow].size()-1; ++indexCol){
                    if (board [indexRow][indexCol].bomb == true) {
                        board[indexRow][indexCol].visible = true;
                        cout << 'X';
                    }
                    else if (board [indexRow][indexCol].visible == true) {
                        if (board [indexRow][indexCol].numberBomb == 0){
                            cout << ' ';
                        }
                        else{
                            cout << board[indexRow][indexCol].numberBomb;
                        }
                    }
                    else{
                        cout << '-';
                    }
                }
                cout << '\n';
            }
        }
        else {
            for (size_t indexRow = 1; indexRow < rows+1; ++indexRow){
                for (size_t indexCol = 1; indexCol < board [indexRow].size()-1; ++indexCol){
                    if (board[indexRow][indexCol].visible == true) {
                        if (board [indexRow][indexCol].numberBomb == 0){
                            cout << ' ';
                        }
                        else{
                            cout << board[indexRow][indexCol].numberBomb;
                        }
                    }
                    else{
                        cout << '-';
                    }
                }
                cout << '\n';
            }
        }
    }
    
    bool validRow (int inputRow) const {
        if ((inputRow > 0) && (inputRow < rows+1)){
            return true;
        }
        return false;
    }
    
    bool validCol (int inputCol) const {
        if ((inputCol > 0) && (inputCol < cols + 1)){
            return true;
        }
        return false;
    }
    
    bool isVisible (int row, int col) const {
        if (board [row][col].visible == true) {
            return true;
        }
        return false;
    }
    
    bool done () const {
        if (donester == true){
            return true;
        }
        for (size_t indexRow = 1; indexRow < rows+1; ++indexRow){
            for (size_t indexCol = 1; indexCol < board [indexRow].size()-1; ++indexCol){
                if ((board [indexRow] [indexCol].visible == false) &&
                    (board[indexRow][indexCol].bomb == false)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool play (int row, int col){
        //cout << row << col<< endl;
        if (board [row][col].bomb == true) {
            donester = true;
            board[row][col].visible = true;
            return false;
        }
        
        else if (board [row] [col].numberBomb > 0 ){
            board[row][col].visible = true;
        }
        else {
            board[row][col].visible = true;
            if (row + 1 < rows + 1){
                if (!isVisible (row + 1, col)){
                    play (row + 1, col);
                }
                if (col - 1 > 0) {
                    if (!isVisible (row + 1, col-1)){
                        play (row + 1, col - 1);
                    }
                }
                if (col + 1 < cols + 1){
                    if (!isVisible (row + 1, col+1)){
                        play (row + 1, col + 1);
                    }
                }
            }
            if (row - 1 > 0){
                if (!isVisible (row - 1, col)){
                    play (row - 1, col);
                }
                if (col - 1 > 0) {
                    if (!isVisible (row - 1, col-1)){
                        play (row - 1, col - 1);
                    }
                }
                if (col + 1 < cols + 1){
                    if (!isVisible (row - 1, col+1)){
                        play (row - 1, col +1);
                    }
                }
            }
            if (col - 1 > 0) {
                if (!isVisible (row, col-1)){
                    play (row, col -1);
                }
            }
            if (col + 1 < cols + 1) {
                if (!isVisible (row, col+1)){
                    play (row, col + 1);
                }
            }
        }
        return true;
    }
    
private:
    int rows;
    int cols;
    bool donester;
    vector <vector <Cell>> board;
};

int main() {
    Minesweeper sweeper;
    // Continue until the only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display the board without bombs
        
        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r,c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        // Set selected square to be visible. May effect other cells.
        if (!sweeper.play(row_sel,col_sel)) {
            cout << "BOOM!!!\n";
            sweeper.display(true);
            // We're done! Should consider ending more "cleanly",
            // eg. Ask user to play another game.
            exit(0);
        }
    }
    // Ah! All invisible cells are bombs, so you won!
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown
}
