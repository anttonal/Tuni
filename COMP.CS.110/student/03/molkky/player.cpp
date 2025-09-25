#include "player.hh"

Player::Player(std::string const player_name):
player_name_(player_name), points_(0)
{
}

std::string Player::get_name()
{
    return player_name_;
}

int Player::get_points()
{
    return points_;
}

void Player::add_points(int pts)
{
    points_ += pts;

    if ( points_ > 50)
    {
        std::cout << get_name() << " gets penalty points!" << std::endl;
        points_ = 25;
    }

}

bool Player::has_won()
{
    return points_ == 50;
}
