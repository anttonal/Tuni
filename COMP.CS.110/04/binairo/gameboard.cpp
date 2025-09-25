#include "gameboard.hh"
#include <iostream>
#include <random>

// Constructor.
GameBoard::GameBoard()
{}

// Prints the game board.
void GameBoard::print() const
{
    // Printing upper border
    print_line( LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=' );

    // Printing title row
    cout << "|   | ";
    for( unsigned int i = 0; i < SIZE; ++i )
    {
        cout << i + 1 << " ";
    }
    cout << "|" << endl;

    // Printing line after the title row
    print_line( LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '-' );

    unsigned int row_index = 0;
    // Printing the actual content of the gameboard
    for( const Matrix_row& row : board_symbols_ )
    {
        cout << "| " <<  ++row_index << " | ";
        for(unsigned int symbol : row)
        {
            if ( symbol == EMPTY )
            {
                cout << "  ";
            }
            else
            {
                cout << symbol << " ";
            }

        }
        cout << "|" << endl;
    }

    // Printing lower border
    print_line( LEFT_COLUMN_WIDTH + 1 + 2 * SIZE + 1, '=' );
}

// Prints a line with the given length and the given character.
void GameBoard::print_line( unsigned int length, char fill_character ) const
{
    for(unsigned int i = 0; i < length; ++i)
    {
        cout << fill_character;
    }
    cout << endl;
}

// Assings a matrix containing symbols created by the user to the board.
void GameBoard::assign_symbols(Symbol_matrix board_symbols )
{
    board_symbols_ = board_symbols;
}

// Adds a symbol into the board.
void GameBoard::add_symbol( const unsigned int y, const unsigned int x, const unsigned int symbol )
{
    board_symbols_.at(x-1).at(y-1) = symbol;
}

// Checks if the board would have too many adjacent symbols in the event that
// the symbol is placed in the desired location
bool GameBoard::too_many_adjacent_symbols( const unsigned int y, const unsigned int x, const unsigned int symbol ) const
{
    unsigned int adjacent_zero_count = 0;
    unsigned int adjacent_one_count = 0;

    for ( unsigned int i = 0; i < SIZE; ++i)
    {
        unsigned int board_symbol = board_symbols_.at(i).at(y-1);

        if ( i == x-1 )
        {
            board_symbol = symbol;
        }
        if ( board_symbol == ZERO )
        {
            adjacent_zero_count += 1;
            adjacent_one_count = 0;
        }
        else if ( board_symbol == ONE )
        {
            adjacent_one_count += 1;
            adjacent_zero_count = 0;
        }
        else
        {
            adjacent_one_count = 0;
            adjacent_zero_count = 0;
        }
        if ( adjacent_zero_count == NUMBER_OF_SYMBOLS or adjacent_one_count == NUMBER_OF_SYMBOLS)
        {
            return true;
        }
    }

    adjacent_zero_count = 0;
    adjacent_one_count = 0;

    for ( unsigned int j = 0; j < SIZE; ++j)
    {
        unsigned int board_symbol = board_symbols_.at(x-1).at(j);

        if ( j == y-1 )
        {
            board_symbol = symbol;
        }
        if ( board_symbol == ZERO )
        {
            adjacent_zero_count += 1;
            adjacent_one_count = 0;
        }
        else if ( board_symbol == ONE )
        {
            adjacent_one_count += 1;
            adjacent_zero_count = 0;
        }
        else
        {
            adjacent_one_count = 0;
            adjacent_zero_count = 0;
        }
        if ( adjacent_zero_count == NUMBER_OF_SYMBOLS or adjacent_one_count == NUMBER_OF_SYMBOLS)
        {
            return true;
        }
    }
    return false;
}

// Checks if the board would have too many equal symbols in the event that
// the symbol is placed in the desired location.
bool GameBoard::too_many_equal_symbols( const unsigned int y, const unsigned int x, const unsigned int symbol ) const
{
    unsigned int total_zero_count = 0;
    unsigned int total_one_count = 0;

    // Goes through each symbol in the column entered by the user and counts the amount of symbols.
    for ( unsigned int i = 0; i < SIZE; ++i)
    {
        unsigned int board_symbol = board_symbols_.at(i).at(y-1);

        // The symbol to be entered.
        if ( i == x-1 )
        {
            board_symbol = symbol;
        }

        if ( board_symbol == ZERO )
        {
            total_zero_count += 1;
        }

        else if ( board_symbol == ONE )
        {
            total_one_count += 1;
        }

        if ( total_zero_count > NUMBER_OF_SYMBOLS or total_one_count > NUMBER_OF_SYMBOLS )
        {
            return true;
        }
    }

    total_zero_count = 0;
    total_one_count = 0;

    // Goes through each symbol in the row entered by the user and counts the amount of symbols.
    for ( unsigned int j = 0; j < SIZE; ++j )
    {
        unsigned int board_symbol = board_symbols_.at(x-1).at(j);

        // The symbol to be entered.
        if ( j == y-1 )
        {
            board_symbol = symbol;
        }

        if ( board_symbol == ZERO )
        {
            total_zero_count += 1;
        }

        else if ( board_symbol == ONE )
        {
            total_one_count += 1;
        }

        if ( total_zero_count > NUMBER_OF_SYMBOLS or total_one_count > NUMBER_OF_SYMBOLS )
        {
            return true;
        }
    }
    return false;
}

// Checks if the symbol is possible to be added to the coordinates entered
// by the user and returns a corresponding boolean value.
bool GameBoard::can_add_symbol( const unsigned int x, const unsigned int y, const unsigned int symbol ) const
{
    if ( board_symbols_.at(y-1).at(x-1) != EMPTY)
    {
        return false;
    }

    else if ( too_many_adjacent_symbols(x, y, symbol) )
    {
        return false;
    }

    else if ( too_many_equal_symbols(x, y, symbol) )
    {
        return false;
    }

    else
    {
        return true;
    }
}

// Returns a boolean value corresponding to the validity of the seed.
bool GameBoard::is_bad_seed( unsigned int seed )
{
    for ( unsigned int bad_seed : BAD_SEEDS)
    {
        if ( seed == bad_seed )
        {
            return true;
        }
    }
    return false;
}

// Checks if the board contains empty slots.
bool GameBoard::is_game_over() const
{
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        for (unsigned int j = 0; j < SIZE; ++j)
        {
            if ( board_symbols_.at(i).at(j) == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}
