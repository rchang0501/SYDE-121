// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
// cd r28chang/SYDE-121/assignment01

#include <iostream>
#include <string>

auto main() -> int
{
    std::string curr;
    bool a = false; // let a be the first pair value
    bool b = false; // let b be the second pair value
    int lines = 0;  // line counter for file reader
    int pair = 0;   // pair counter for output

    while (getline(std::cin, curr))
    {
        lines++;

        // assinging proper boolean based on input
        if (lines % 2 == 1)
        {
            if (curr == "" || curr == "\n")
            {
                a = false;
            }
            else
            {
                a = true;
            }
        }

        else if (lines % 2 == 0)
        {
            if (curr == "" || curr == "\n")
            {
                b = false;
            }
            else
            {
                b = true;
            }
        }

        // output only for pairs
        if (lines % 2 == 0)
        {
            pair++;                                        // icnrement the pair number
            std::string pairString = std::to_string(pair); // convert to string

            // header
            std::cout << "Pair number: " + pairString << std::endl;
            std::cout << "----------------------------" << std::endl;

            // first case of De Morgan's Law
            std::cout << "not (a and b)" << std::endl;
            if (!(a && b))
            {
                std::cout << "true\n"
                          << std::endl;
            }
            else
            {
                std::cout << "false\n"
                          << std::endl;
            }

            // second case of De Morgan's Law
            std::cout << "not(a) or not(b)" << std::endl;
            if (!a || !b)
            {
                std::cout << "true\n"
                          << std::endl;
            }
            else
            {
                std::cout << "false\n"
                          << std::endl;
            }

            // third  case of De Morgan's Law
            std::cout << "not (a or b)" << std::endl;
            if (!(a || b))
            {
                std::cout << "true\n"
                          << std::endl;
            }
            else
            {
                std::cout << "false\n"
                          << std::endl;
            }

            // fourth case of De Morgan's Law
            std::cout << "not(a) and not(b)" << std::endl;
            if (!a && !b)
            {
                std::cout << "true\n"
                          << std::endl;
            }
            else
            {
                std::cout << "false\n"
                          << std::endl;
            }
        }
    }
    return 0;
}
