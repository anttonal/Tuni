#include <iostream>

using namespace std;

long int exclamation(long int x)
{
    if ( x == 0 )
        return 1;

    long int ans = x;

    for (long int index = 1; index < x; ++index)
    {
        ans = ans * index;
    }

    return ans;
}

int main()
{
    cout << "Enter the total number of lottery balls: ";
    long int tot_balls;
    cin >> tot_balls;

    cout << "Enter the number of drawn balls: ";
    long int drawn_balls;
    cin >> drawn_balls;

    if ( tot_balls < 0 or drawn_balls < 0 )
    {
        cout << "The number of balls must be a positive number." << endl;
        return 0;
    }

    if ( drawn_balls > tot_balls )
    {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        return 0;
    }

    cout << "The probability of guessing all " << drawn_balls << " balls correctly is 1/" <<
            exclamation(tot_balls)/(exclamation(tot_balls-drawn_balls)*exclamation(drawn_balls)) << endl;

    return 0;
}
