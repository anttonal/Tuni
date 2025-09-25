#include "mostvowels.hh"
#include <iostream>

MostVowels::MostVowels(unsigned int rounds) : BaseGame(rounds)
{}

MostVowels::~MostVowels()
{}

void MostVowels::printGameName() const
{
    std::cout << "Most Vowels Game" << std::endl;
}

int MostVowels::countVowels(const std::string& word) const {
    int count = 0;
    for (char ch : word) {
        ch = std::tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'y') {
            ++count;
        }
    }
    return count;
}

unsigned int MostVowels::roundWinner(const std::string &word1, const std::string &word2) const
{
    if(countVowels(word1) > countVowels(word2))
    {
        return 1;
    }
    else if(countVowels(word1) < countVowels(word2))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
