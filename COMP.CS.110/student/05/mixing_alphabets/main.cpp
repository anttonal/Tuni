#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    minstd_rand generator;

    cout << "Enter some text. Quit by entering the word \"END\"." << endl;
    string word;

    while (cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }
        if ( word.size() != 1 )
        {
            shuffle(++word.begin(), --word.end(), generator);
        }

        cout << word << endl;
    }

    return EXIT_SUCCESS;
}
