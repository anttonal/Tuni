#include <iostream>
#include <string>

using namespace std;

// 97 to 122

string encrypt(string encry_key, string to_encry)
{
    int lenght = to_encry.length();

    for (int i = 0; i < lenght; ++i)
        int ascii = static_cast< int >( to_encry[i] );
        to_encry.replace(0, 1, e)
    return to_encry;
}


int main()
{
    cout << "Enter the encryption key: ";

    string encry_key;
    getline(cin, encry_key);

    cout << "Enter the text to be encrypted: ";

    string to_encry;
    getline(cin, to_encry);



    return 0;
}
