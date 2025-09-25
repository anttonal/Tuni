#include <iostream>
#include <string>
#include <vector>


std::vector< std::string > split(std::string line, char separator, bool ignore=false)
{
    std::string addable;
    std::vector< std::string > parts_list;

    for ( size_t i = 0; i < line.size(); ++i)
    {
        if ( line[i] == separator)
        {
            if ( addable == "" and ignore)
                continue;
            else
            {
                parts_list.push_back(addable);
                addable = "";
            }
        }

        else
        {
            addable += line[i];
        }
    }

    parts_list.push_back(addable);

    return parts_list;
}


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
