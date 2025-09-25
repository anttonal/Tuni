#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

using namespace std;

bool palindrome_recursive(string word)
{
    RECURSIVE_FUNC

    unsigned int letters = word.length();

    if ( letters < 3 )
    {
        if (letters == 1)
        {
            return true;
        }
        else
        {
            return word.at(0) == word.at(1);
        }
    }

    else if ( word.at(0) == word.at(letters-1) )
    {
        return palindrome_recursive(word.substr(1, letters-2));
    }

    else
    {
        return false;
    }
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    cout << "Enter a word: ";
    string word;
    cin >> word;

    if(palindrome_recursive(word)){
        cout << word << " is a palindrome" << endl;
    } else {
        cout << word << " is not a palindrome" << endl;
    }
}
#endif
