#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <vector>
#include <string>

using namespace std;
using Matrix_row = vector< unsigned int >;
using Symbol_matrix = vector< Matrix_row >;

// Type of the symbols in the gameboard.
enum symbol_type {ZERO, ONE, EMPTY};

// Constants for the size of the gameboard.
const unsigned int NUMBER_OF_SYMBOLS = 3;
const unsigned int SIZE = 2 * NUMBER_OF_SYMBOLS;

// Constant for the upper bound of probability distribution.
// Zeros and ones have the same probability, say x, and the estimated
// probability of empties is 6x, whereupon their sum is 8x, and thus,
// the interval must have eigth points, as [0..7].
const unsigned int DISTR_UPPER_BOUND = 7;

// Width of the left-most column, needed in printing the gameboard.
const unsigned int LEFT_COLUMN_WIDTH = 5;


class GameBoard
{
public:
    // Constructor.
    GameBoard();

    // Returns a boolean value corresponding to the validity of the seed.
    bool is_bad_seed( unsigned int seed );

    // Prints the gameboard.
    void print() const;

    // Assings a matrix containing symbols created by the user to the board.
    void assign_symbols( Symbol_matrix board_symbols );

    // Adds a symbol into the board.
    void add_symbol( unsigned int x, unsigned int y, unsigned int symbol );

    // Checks if the symbol is possible to be added to the coordinates entered
    // by the user and returns a corresponding boolean value.
    bool can_add_symbol( const unsigned int x, const unsigned int y, const unsigned int symbol ) const;

    // Checks if the board contains empty slots.
    bool is_game_over() const;

private:
    // The board's symbols in a matrix
    Symbol_matrix board_symbols_;

    // Prints a line with the given length and the given character.
    void print_line( unsigned int length, char fill_character ) const;

    // Checks if the board would have too many adjacent symbols in the event that
    // the symbol is placed in the desired location.
    bool too_many_adjacent_symbols( const unsigned int x, const unsigned int y, const unsigned int symbol ) const;


    // Checks if the board would have too many equal symbols in the event that
    // the symbol is placed in the desired location.
    bool too_many_equal_symbols( const unsigned int x, const unsigned int y, const unsigned int symbol ) const;

    // Seed values, from [1..50], producing non-solvable gameboard.
    const vector<unsigned int> BAD_SEEDS = { 2, 8, 12, 13, 16, 20, 21, 23,
                                                  26, 29, 31, 32, 34, 41, 42,
                                                  43, 44, 46 };


};

#endif // GAMEBOARD_HH
