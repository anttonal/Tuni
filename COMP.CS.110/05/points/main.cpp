#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string filename;
    cout << "Input file: ";
    cin >> filename;
    ifstream file(filename);

    if (!file)
    {
        cout << "Error! The file " << filename << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    map<string, int> scores;
    string line;

    while (getline(file, line))
    {
        istringstream lineStream(line);
        string name;
        int points;

        if (getline(lineStream, name, ':'))
        {
            lineStream >> points;
            scores[name] += points;
        }
    }
    file.close();

    cout << "Final scores:" << endl;
    for (auto it = scores.begin(); it != scores.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return EXIT_SUCCESS;
}
