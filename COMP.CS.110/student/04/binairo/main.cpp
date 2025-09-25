/* Binairo
 *
 * Desc:
 *   This program implements a Binairo game with the gameboard of size 6 x 6.
 * Each square in the gameboard has zero, one, or empty. The aim is to add
 * zeros and ones in the empty squares by following the rules:
 * - each horizontal and vertical line can have at most three identical numbers
 * - each horizontal and vertical line can have at most two identical number
 *   sequentially.
 *   At first, the user is asked, if the gameboard will be filled with
 * randomly drawn characters, or with user-given 36 characters. In the first
 * option, a seed value for the random number generator will be asked next.
 * In the latter option, the user is asked to input 36 characters, the
 * validity of which is checked.
 *   On each round, the user is asked for the coordinates and the identity
 * of the character to be added, i.e. three characters. The player wins if
 * the gameboard has been filled following the rules above. The program does
 * not allow additions violating the above rules, but it is possible to end up
 * to a situation where no addition is possible any more.
 *   The program checks the user-given inputs. The character to be added must
 * be zero or one. The coordinates must be inside the gameboard, and the
 * square indicated by them must be empty.
 *
 * Program author
 * Name: Antton Alivuotila
 * Student number: 151259218
 * UserID: bvanal
 * E-Mail: antton.alivuotila@tuni.fi
 * */

#include "gameboard.hh"
#include <iostream>
#include <random>

// Output messages
const string QUIT = "Quitting ...";
const string BAD_SEED = "Bad seed";
const string OUT_OF_BOARD = "Out of board";
const string INVALID_INPUT = "Invalid input";
const string WRONG_SIZED_INPUT = "Wrong size of input";
const string WRONG_CHARACTER = "Wrong character";
const string CANT_ADD = "Can't add";
const string WIN = "You won!";


// Converts the given numeric string to the corresponding integer
// (by calling stoi) and returns the integer.
// If the given string is not numeric, returns zero.
unsigned int stoi_with_check( const string& str )
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if ( not isdigit(str.at(i)) )
        {
            is_numeric = false;
            break;
        }
    }
    if ( is_numeric )
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// Modifies the input given by the user into a more suitable format
// if the input is valid. If it is not, returns the input as a string
// calling it invalid.
void modify_input_if_valid( string& input )
{
    if ( input.length() != 38 )
    {
        cout << WRONG_SIZED_INPUT << endl;
        input = "invalid";
        return;
    }

    else
    {
        input = input.substr(1, 36);

        for ( unsigned int i = 0; i < input.length(); ++i )
        {
            if ( input.at(i) == '0' )
            {
                input.at(i) = ZERO;
            }

            else if ( input.at(i) == '1' )
            {
                input.at(i) = ONE;
            }

            else if ( input.at(i) == ' ' )
            {
                input.at(i) = EMPTY;
            }

            else
            {
                cout << WRONG_CHARACTER << endl;
                input = "invalid";
                return;
            }
        }
    }
}


// Removes empty characters (such as ' ' etc.) from the given string.
// Returns true if the given string has exactly one non-empty character,
// which is either '0' or '1', otherwise returns false.
bool find_fill_symbol( string& str )
{
    string fill_str = "";
    for ( unsigned int i = 0; i < str.size(); ++i )
    {
        if ( not isspace(str.at(i)) )
        {
            fill_str += str.at(i);
        }
    }

    str = fill_str;
    return ( fill_str.size() == 1 and
           (fill_str.at(0) == '0' or fill_str.at(0) == '1') );
}


// Enables the user to play the game, i.e. by repeatedly asking an symbol
// to be added and its position, until the game is over.
void play_game( GameBoard& board )
{
    board.print();
    while ( not board.is_game_over() )
    {
        string x_str = "";
        string y_str = "";
        string rest_input = "";
        cout << "Enter two coordinates and a fill symbol, or q to quit: ";


        // Reading x coordinate as a string and checking if it was quit command
        cin >> x_str;
        if ( x_str.at(0) == 'q' or x_str.at(0) == 'Q' )
        {
            cout << QUIT << endl;
            return;
        }

        // Reading y coordinate
        cin >> y_str;

        // Changing coordinates from string to int and checking if they are
        // inside the board
        unsigned int x = stoi_with_check(x_str);
        unsigned int y = stoi_with_check(y_str);

        if ( not (1 <= x and x <= SIZE and 1 <= y and y <= SIZE) )
        {
            cout << OUT_OF_BOARD << endl;
            getline(cin, rest_input);
            continue;
        }

        // Reading the rest of the input line including fill symbol and
        // checking if the rest input consists exactly of one '0' or '1'
        getline(cin, rest_input);
        if ( not find_fill_symbol(rest_input) )
        {
            cout << INVALID_INPUT << endl;
            continue;
        }

        // Seeing if it is possible to add the given symbol on the given position
        // and adding it if it is.
        unsigned int symbol = stoi(rest_input);
        if ( board.can_add_symbol( x, y, symbol ) )
        {
            board.add_symbol( x, y, symbol );
        }

        // If it wasn't, prints an error message.
        else
        {
            cout << CANT_ADD << endl;
            continue;
        }

        // If the given symbol was possible to add, print the changed gameboard
        board.print();
    }
    // If the game ends up to a totally filled gameboard, the player won
    cout << WIN << endl;
}

// Gives the user a possibility to select a filling way.
// Returns true if filling succeeded, otherwise returns false.
// Creates a vector containing a vector containing unsigned integers,
// (a matrix), of symbols in the selected filling way and assigns
// it into the board object.
bool select_start( GameBoard& board )
{
    // Initializing the matrix.
    Symbol_matrix board_symbols;
    string choice = "";
    cout << "Select start (R for random, I for input): ";
    getline(cin, choice);

    // If no valid character was inputted.
    if(choice != "R" and choice != "r" and choice != "I" and choice != "i")
    {
        return false;
    }

    // If user selected randomized board filling.
    else if(choice == "R" or choice == "r")
    {
        string seed_string = "";
        cout << "Enter a seed value: ";
        getline(cin, seed_string);

        // Seeing if the seed results in an unsolvable situation
        if ( board.is_bad_seed(stoi_with_check(seed_string)) )
        {
            cout << BAD_SEED << endl;
            return false;
        }

        // Initializing the random number generator.
        default_random_engine rand_gen;
        rand_gen.seed(stoi_with_check(seed_string));
        uniform_int_distribution<unsigned int> distribution(0, DISTR_UPPER_BOUND);

        // Randomizes a symbol for each row and column in the
        // intended size (6x6).
        for ( unsigned int i = 0; i < SIZE; ++i )
        {
            Matrix_row row;
            for ( unsigned int j = 0; j < SIZE; ++j )
            {
                unsigned int new_symbol = distribution(rand_gen);

                // If the symbol is between 2-7 registers it as an empty symbol.
                if ( new_symbol > 1 )
                {
                    row.push_back( EMPTY );
                }

                else if ( new_symbol == 1)
                {
                    row.push_back( ONE );
                }

                else
                {
                    row.push_back( ZERO );
                }
            }

            // Creates the matrix one row at a time.
            board_symbols.push_back( row );
        }

    }

    else // if(choice == "I" or choice == "i")
    {
        // Asks for an input and -
        string input = "";
        cout << "Input: ";
        getline(cin, input);

        // - checks if it is in the correct format.
        modify_input_if_valid(input);
        if ( input == "invalid" )
        {
            return false;
        }


        else
        {
            // Creates matrix by going through each symbol one at a time and splitting them
            // into groups of six.
            Matrix_row row;
            for( size_t i = 0; i < input.length(); ++i )
            {
                unsigned int new_symbol = input.at(i);

                // If the symbol is between 2-7 registers it as an empty symbol.
                if ( new_symbol > 1 )
                {
                    row.push_back( EMPTY );
                }

                else if ( new_symbol == 1 )
                {
                    row.push_back( ONE );
                }

                else
                {
                    row.push_back( ZERO );
                }

                // Creates rows by pushing only six symbols at a time.
                if ( i % 6 == 5 )
                {
                    board_symbols.push_back( row );
                    row = Matrix_row();
                }
            }
        }
    }

    // Assigns the symbol matrix into the board
    board.assign_symbols(board_symbols);
    return true;
}

// Short and simple main function.
int main()
{
    GameBoard board;
    while ( not select_start(board) ); // no code to be repeated

    play_game(board); // Runs the game until the board is full or the user quits.
    return 0;
}
