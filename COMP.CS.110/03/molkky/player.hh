#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>
#include <iostream>

class Player
{
public:
    Player(std::string const player_name);

    std::string get_name();
    int get_points();
    void add_points(int pts);
    bool has_won();

private:

    std::string player_name_;
    int points_;
};

#endif // PLAYER_HH
