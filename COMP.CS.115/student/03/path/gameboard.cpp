#include "gameboard.hh"
#include <iostream>
#include <algorithm>

const vector<Location> VALID_LOCS = {
    {1,1}, {2,1}, {3,1}, {4,1},
           {2,2},
           {2,3}, {3,3},
           {2,4},
    {1,5}, {2,5}, {3,5}, {4,5}
};

const map<int, Location> CROSSING_POINTS = {
    {1, {2,1}},
    {3, {2,3}},
    {5, {2,5}},
};

GameBoard::GameBoard() {}

GameBoard::~GameBoard() {}

void GameBoard::initialFill()
{
    for (const auto& loc : VALID_LOCS)
    {
        // If top row
        if (loc.y == 1 ) {
            gameboard_[loc] = make_unique<Button>('G');
        // If bottom row
        } else if (loc.y == 5) {
            gameboard_[loc] = make_unique<Button>('R');
        // The rest of valid locations
        } else {
            gameboard_[loc] = nullptr;
        }
    }
}

void GameBoard::print() const
{
    // Gameboard size
    const int width = COLUMNS;
    const int height = ROWS;

    // Print top border with column numbers
    cout << "===============" << endl;
    cout << "|   |";

    for (int x = 1; x <= width; ++x)
    {
        cout << " " << x;
    }

    cout << " |" << endl;
    cout << "---------------" << endl;

    for (int y = 1; y <= height; ++y)
    {
        // Print row number and contents
        cout << "| " << y << " |";

        for (int x = 1; x <= width; ++x)
        {
            Location loc{static_cast<unsigned>(x), static_cast<unsigned>(y)};
            auto it = gameboard_.find(loc);

            if (it != gameboard_.end() && it->second) {
                // Print button (G or R)
                cout << " " << it->second->GetColor();
            }
            else if (it != gameboard_.end()) {
                // Empty location
                cout << " " << 'o';
            }
            else {
                // Unusable space
                cout << "  ";
            }
        }
        cout << " |" << endl;
    }

    // Bottom border
    cout << "===============" << endl;
}

bool GameBoard::isGameOver() const
{
    int width = COLUMNS;
    int top_row = 1;
    int bot_row = 5;

    // Check that all buttons in the top row are red
    for (int x = 1; x <= width; ++x)
    {
        Location loc{static_cast<unsigned>(x), static_cast<unsigned>(top_row)};
        if (!gameboard_.at(loc) || !gameboard_.at(loc)->IsRed()) {
            return false;
        }
    }

    // Check that all buttons in the bottom row are green
    for (int x = 1; x <= width; ++x)
    {
        Location loc{static_cast<unsigned>(x), static_cast<unsigned>(bot_row)};
        if (!gameboard_.at(loc) || !gameboard_.at(loc)->IsGreen()) {
            return false;
        }
    }

    return true;
}

bool GameBoard::isValidLocations(const Location &start,
                                 const Location &destination) const
{
    // Parameters valid
    if (gameboard_.find(start) != gameboard_.end()
        && gameboard_.find(destination) != gameboard_.end()) {
        // Start has button
        if (gameboard_.at(start)) {
            // Destination doesn't
            if (!gameboard_.at(destination)) {
                // p1 and p2 are not the same points (trivial)
                if (start != destination) {
                    return true;
                }
                else {
                    cout << "Given points are the same." << endl;
                }
            }
        }
    }

    return false;

}

bool GameBoard::move(const Location &start, const Location &destination)
{
    // Differences in coordinates
    int dx = destination.x - start.x;
    int dy = destination.y - start.y;

    // Case 1: Move in the same row (horizontal only)
    if (dy == 0) {
        if (isPathClear(start, destination, true)) {
            swap(gameboard_.at(start), gameboard_.at(destination));
            return true;
        }
        else {
            return false;
        }
    }

    // Case 2: Vertical move starts from crossing column (x == 2)
    else if (start.x == 2) {
        if (isPathClear(start, destination, false)) {
            // Only vertical move
            if (dx == 0) {
                swap(gameboard_.at(start), gameboard_.at(destination));
                return true;
            }
            // Vertical + horizontal move
            else {
                if (isPathClear(start, destination, true)) {
                    swap(gameboard_.at(start), gameboard_.at(destination));
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        else {
            return false;
        }
    }

    // Case 3: Move across rows using a crossing point (go horizontal first)
    else if (isPathClear(start, CROSSING_POINTS.at(start.y), true)) {
        if (isPathClear(CROSSING_POINTS.at(start.y), destination, false)) {
            // If destination.y doesn't have a crossing point, move directly
            if (!CROSSING_POINTS.count(destination.y)) {
                swap(gameboard_.at(start), gameboard_.at(destination));
                return true;
            }
            // If destination.y has a crossing point, add horizontal move
            else if (isPathClear(CROSSING_POINTS.at(destination.y),
                                 destination, true)) {
                swap(gameboard_.at(start), gameboard_.at(destination));
                return true;
            }
        }
    }

    return false;
}

bool GameBoard::isPathClear(const Location& start,
                            const Location& destination,
                            bool check_horizontal) const
{
    if (check_horizontal) { // Horizontal check
        unsigned int lower_x = min(start.x, destination.x);
        unsigned int higher_x = max(start.x, destination.x);

        // Check each cell between start and destination in the same row
        for (unsigned int x = lower_x; x <= higher_x; ++x)
        {
            Location loc{x, destination.y};
            // If there's a button here (and this isn't the starting cell)
            if (gameboard_.at(loc) && loc != start) {
                return false; // Path blocked
            }
        }
    }

    else { // Vertical check
        unsigned int lower_y = min(start.y, destination.y);
        unsigned int higher_y = max(start.y, destination.y);

        // Check each cell between start and destination in the same column
        for (unsigned int y = lower_y; y <= higher_y; ++y)
        {
            Location loc{start.x, y};
            // If there's a button here (and this isn't the starting cell)
            if (gameboard_.at(loc) && loc != start) {
                return false; // Path blocked
            }
        }
    }

    return true;
}
