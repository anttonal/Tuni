#ifndef SUDOKU_HH
#define SUDOKU_HH
#include <set>
#include <vector>
#include <map>

using namespace std;

// Sizes of a block and the whole sudoku
const unsigned int BLOCK_SIZE = 3;
const unsigned int SIZE = 3 * BLOCK_SIZE;
const set<char> VALID_CHAR = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

class Sudoku
{
public:
    Sudoku();
    void set(int i, int j, char c);
    void print();
    bool check();

private:
    vector<vector<char>> grid;
    bool is_valid_char(char c);
    bool is_valid_cell(int i, int j);
    bool check_rows();
    bool check_columns();
    bool check_block();
};

#endif // SUDOKU_HH
