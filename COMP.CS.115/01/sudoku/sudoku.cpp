#include "sudoku.hh"
#include <iostream>

Sudoku::Sudoku() : grid(9, vector<char>(9, ' ')) {}

void Sudoku::set(int i, int j, char c)
{
    if (!is_valid_cell(i, j)){
        cout << "Trying to access illegal cell (" << i << ", " << j << ")!" << endl;
    }
    else if (!is_valid_char (c)){
        cout << "Trying to set illegal character " << c << " to (" << i << ", " << j << ")!" << endl;
    }
    else {
        grid[i][j] = c;
    }
}

void Sudoku::print()
{

    int i = 0;
    int j = 0;
    cout << "#####################################" << endl;
    for (vector<char> row : grid){
        cout << "# ";
        for (char c : row){
            cout << c;
            if (j % 3 == 2 && j < 8)
                cout << " # ";
            else if (j < 8)
                cout << " | ";
            j++;
        }
        cout << " #" << endl;
        j = 0;
        i++;
        if (i % BLOCK_SIZE == 0)
            cout << "#####################################" << endl;
        else
            cout << "#---+---+---#---+---+---#---+---+---#" << endl;
    }
}

bool Sudoku::check()
{
    if (check_rows()){
        if (check_columns()){
            if (check_block())
                return true;
        }
    }
    return false;
}



bool Sudoku::is_valid_char(char c)
{
    return VALID_CHAR.count(c) > 0;
}

bool Sudoku::is_valid_cell(int i, int j)
{
    return (i >= 0 && i <= 8) && (j >= 0 && j <= 8);
}

bool Sudoku::check_rows()
{
    for (int i = 0; i < 9; i++) {
        std::map<char, int> count;
        for (int j = 0; j < 9; j++) {
            char c = grid.at(i).at(j);
            if (c != ' ') count[c]++;
        }
        for (char num = '1'; num <= '9'; num++) {
            if (count[num] > 1) {
                std::cout << "Row " << i << " has multiple " << num << "'s!" << std::endl;
                return false;
            }
        }
    }


    return true;
}

bool Sudoku::check_columns()
{
    ::set<char> seen;
    for (int j = 0; j <= 8; ++j){
        for (int i = 0; i <= 8; ++i) {
            if (grid[i][j] != ' '){
                if (seen.count(grid[i][j])) {
                    cout << "Column " << j <<  " has multiple " << grid[i][j] <<  "'s!" << endl;
                    return false;
                }
                seen.insert(grid[i][j]);
            }
        }
        seen.clear();
    }
    return true;
}


bool Sudoku::check_block()
{   for(int x = 0; x < 9; x += 3){
        for(int y = 0; y < 9; y += 3){
            std::set<char> seen;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    char c = grid.at(x+i).at(y+j);
                    if (c != ' ' && seen.find(c) != seen.end()) {
                        cout << "Block at (" << x << ", " << y << ") has multiple " << c << "'s!" << endl;
                        return false;
                    }
                    seen.insert(c);
                }
            }
        }
    }

    return true;
}
