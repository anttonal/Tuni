#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";

    int amount;
    std::cin >> amount;

    for ( int reps = 1; reps <= amount; ++reps )
    {
        if ( reps % 3 == 0 )
        {
            if ( reps % 7 == 0 )
            {
                std::cout << "zip boing" << std::endl;
                continue;
            }
            std::cout << "zip" << std::endl;
            continue;
        }

        if ( reps % 7 == 0 )
        {
            std::cout << "boing" << std::endl;
            continue;
        }

        std::cout << reps << std::endl;
    }

    return 0;
}
