#ifndef ROCKPAPERSCISSORS_HH
#define ROCKPAPERSCISSORS_HH
#include "basegame.hh"

class RockPaperScissors : public BaseGame
{
public:
    RockPaperScissors(unsigned int rounds);
    virtual ~RockPaperScissors();

private:
    void printGameName() const;
    unsigned int roundWinner(const std::string& word1, const std::string& word2) const;
};

#endif // ROCKPAPERSCISSORS_HH
