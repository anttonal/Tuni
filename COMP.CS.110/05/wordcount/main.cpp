#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int main()
{
    string file_name = "";
    cout << "Input file: ";
    getline(cin, file_name);
    ifstream file_object(file_name);

    if (!file_object)
    {
        cout << "Error! The file " << file_name << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    map<string, set<int>> words;
    string row = "";
    unsigned int row_number = 1;

    while (getline(file_object, row))
    {
        istringstream rowstream(row);
        string word = "";

        while (rowstream >> word)
        {
            words[word].insert(row_number);
        }

        ++row_number;
    }

    for (map<string, set<int>>::iterator word_iter = words.begin(); word_iter != words.end(); ++word_iter)
    {
        cout << word_iter->first << " " << word_iter->second.size() << ": ";

        for (set<int>::iterator row_num_iter = word_iter->second.begin(); row_num_iter != word_iter->second.end(); ++row_num_iter)
        {
            if (row_num_iter != word_iter->second.begin())
            {
                cout << ", ";
            }
            cout << *row_num_iter;
        }
        cout << endl;
    }

    file_object.close();
    return EXIT_SUCCESS;
}
