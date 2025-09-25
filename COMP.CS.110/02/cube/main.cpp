#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a number: ";

    int cubed;
    cin >> cubed;

    if ( cubed > 46340)
    {
        cout << "Error! The cube of " << cubed << " is not " << cubed*cubed*cubed << "." << endl;
    }
    else
    {
        cout << "The cube of " << cubed << " is " << cubed*cubed*cubed << "." << endl;
    }
}
