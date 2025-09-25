#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

using Network = map<string, vector<string>>;

const string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";

vector<string> split(const string& s,
                     const char delimiter,
                     bool ignore_empty = false)
{
    vector<string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void print_network(const Network& network, const string& marketer, int dots)

{
    cout << string(dots, '.') << marketer << endl;

    if ( network.find(marketer) != network.end() )
    {
        for ( const string& referral : network.at(marketer) )
        {
            print_network( network, referral, dots+2 );
        }
    }
}

int count_network(const Network& network, const string& marketer, int count)
{
    if ( network.find(marketer) != network.end() )
    {
        for ( const string& referral : network.at(marketer) )
        {
            count += count_network( network, referral, 1);
        }
    }
    return count;
}

void network_depth(const Network& network, const string& marketer, int depth, int& record)
{
    if ( depth > record )
    {
        record = depth;
    }

    if ( network.find(marketer) != network.end() )
    {
        for ( const string& referral : network.at(marketer) )
        {
            network_depth(network, referral, depth+1, record);
        }
    }

}


int main()
{
    Network network;

    while(true)
    {
        string line;
        cout << "> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }

            string id1 = parts.at(1);
            string id2 = parts.at(2);

            if ( network.find(id1) != network.end() )
            {
                network.at(id1).push_back(id2);
            }
            else
            {
                vector<string> new_vector;
                new_vector.push_back(id2);
                network.insert( {id1, new_vector} );
            }

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            print_network(network, id, 0);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            cout << count_network(network, id, 0) << endl;;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);
            int record = 1;
            network_depth(network, id, 1, record);

            cout << record << endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            cout << "Erroneous command!" << endl << HELP_TEXT;
        }
    }
}
