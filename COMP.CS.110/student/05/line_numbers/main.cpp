#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input_file_name;
    string output_file_name;

    cout << "Input file: ";
    getline(cin, input_file_name);

    cout << "Output file: ";
    getline(cin, output_file_name);

    ifstream input_file(input_file_name);
    if ( not input_file )
    {
        cout << "Error! The file " << input_file_name << " cannot be opened." << endl;
        return 1;
    }
    else
    {
        ofstream output_file(output_file_name);
        string row;
        unsigned int row_index = 0;
        while ( getline(input_file, row) )
        {
            ++row_index;
            output_file << row_index << " " << row << endl;
        }
        input_file.close();
    }
}
