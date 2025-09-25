#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    int num;
    cin >> num;
    int factor_1 = num;

    if (num <= 0)
    {

        cout << "Only positive numbers accepted" << endl;
        return 0;
    }

    for ( int factor = num/2; factor > 0; --factor )
    {
        if ( not (num % factor) )
        {
            if (factor_1 * factor == num)
            {
                cout << num << " = " << factor << " * " << factor_1 << endl;
                break;
            }
            if ( factor * factor == num)
            {
                cout << num << " = " << factor << " * " << factor << endl;
                break;
            }

            factor_1 = factor;
        }
    }

    return 0;
}
