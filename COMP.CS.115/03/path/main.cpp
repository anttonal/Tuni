/* Path
 *
 * Description:
 * This program implements a Path puzzle. The board is a 5x4 grid (ROWS x COLUMNS),
 * and in each round, the player selects a source and a destination point
 * (four numbers total), attempting to move a button from the source to the destination
 * (if the move is valid). The game checks whether the move is allowed.
 * Initially, all green buttons are placed on the top row, and all red buttons are
 * placed on the bottom row. The game ends when all green buttons have been moved
 * to the bottom row and all red buttons to the top row. Buttons cannot move
 * through or over other buttons.
 * The game board displays green buttons as 'G', red buttons as 'R',
 * empty holes as 'o', and unused spaces as blank.
 *
 * Program author(s):
 *
 * Name: Antton Alivuotila
 * Student number: 151259218
 * UserID: bvanal
 * E-Mail: antton.alivuotila@tuni.fi
 * Feedback language (fi/en): fi
 *
 * Name: Elina Junttila
 * Student number: 152731793
 * UserID: mqf772
 * E-Mail: elina.junttila@tuni.fi
 * Feedback language (fi/en): fi
 *
 * Notes about the program and its implementation:
 *
 * We added a `Button` class to keep things clean and organized. The gameboard is stored
 * as a `map<Location, unique_ptr<Button>>`, which made tracking buttons
 * and swapping their places very low-effort.
 *
 * To avoid stuffing too much into the move logic, we added a helper method:
 * `isPathClear`, which checks if a path is free either horizontally or vertically.
 * It made the code way easier to read and manage.
 *
 * Overall, we tried to keep things modular and readable but still simple.
 * */

#include "gameboard.hh"
#include <iostream>

// Constant outputs
const string INPUT_TEXT = "Enter start point (x, y) and destination point (x, y), or q to quit: ";
const string INVALID_POINT = "Invalid start/destination point.";
const string IDENTICAL_POINTS = "Given points are the same.";   // Actually useless
const string CANNOT_MOVE = "There is no path between start point and destination point.";
const string GAME_OVER = "Game over. Congratulations!";
const string MOVES_MADE = " move(s) made.";


// Enable the user to play the game.
// Until the game is over, read user commands and move the given buttons,
// if possible.
// After each move, print the game board again.
// As the game is over or the user gives the quit command,
// print the number of moves made.
void playGame(GameBoard& gb)
{
    Location p1 = {0, 0};
    Location p2 = {0, 0};
    string command = "";
    unsigned int total_moves = 0;
    gb.print();

    // Loop until game is over
    while(not gb.isGameOver())
    {
        cout << INPUT_TEXT;
        cin >> command;
        // If user quits
        if(command == "q" or command == "Q")
        {
            cout << total_moves << MOVES_MADE << endl;
            return;
        }
        // Checks if the input is valid
        try
        {
            p1.x = stoi(command);
            cin >> command;
            p1.y = stoi(command);
            cin >> command;
            p2.x = stoi(command);
            cin >> command;
            p2.y = stoi(command);
        }
        catch (invalid_argument const& ex)
        {
            cout << "Invalid argument: " << ex.what() << endl;
            return;
        }

        // Check validity of the locations
        if(not gb.isValidLocations(p1, p2))
        {
            cout << INVALID_POINT << endl;
            continue;
        }

        // Try to move
        if(gb.move(p1, p2))
        {
            ++total_moves;
            gb.print();
        }
        else
        {
            cout << CANNOT_MOVE << endl;
        }
    }
    cout << GAME_OVER << endl;
    cout << total_moves << MOVES_MADE << endl;
}


int main()
{
    GameBoard board;
    board.initialFill(); // Fill the gameboard initially
    playGame(board); // Start and end the game
    return 0;
}
