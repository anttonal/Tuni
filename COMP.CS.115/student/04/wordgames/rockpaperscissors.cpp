#include "rockpaperscissors.hh"
#include <iostream>
#include <vector>
#include <algorithm>

RockPaperScissors::RockPaperScissors(unsigned int rounds) : BaseGame(rounds)
{}

RockPaperScissors::~RockPaperScissors()
{}

void RockPaperScissors::printGameName() const
{
    std::cout << "Rock-Paper-Scissors Game" << std::endl;
}

unsigned int RockPaperScissors::roundWinner(const std::string &word1, const std::string &word2) const
{
    const std::vector<std::string> valid = {"rock", "paper", "scissors"};

    bool valid1 = std::find(valid.begin(), valid.end(), word1) != valid.end();
    bool valid2 = std::find(valid.begin(), valid.end(), word2) != valid.end();

    if (!valid1 && valid2) {
        return 2;  // Player 1 misspelled
    }
    if (valid1 && !valid2) {
        return 1;  // Player 2 misspelled
    }
    if (!valid1 && !valid2) {
        return 0;  // Both misspelled — tie
    }

    std::string p1 = word1;
    std::string p2 = word2;

    if (p1 == p2) {
        return 0;
    }

    if ((p1 == "rock"     && p2 == "scissors") ||
        (p1 == "scissors" && p2 == "paper")    ||
        (p1 == "paper"    && p2 == "rock")) {
        return 1;
    }

    if ((p2 == "rock"     && p1 == "scissors") ||
        (p2 == "scissors" && p1 == "paper")    ||
        (p2 == "paper"    && p1 == "rock")) {
        return 2;
    }

    return 0;
}
