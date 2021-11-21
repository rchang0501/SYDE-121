// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
// cd r28chang/SYDE-121/assignment01

#include <iostream>
#include <string>
#include <cmath>

auto main() -> int
{
    std::string curr;
    double lines = 0;
    double maxInt = 0;
    double minInt = 0;
    double totalInt = 0.0;
    double avgInt = 0.0;
    double totalSquared = 0.0;
    double stdev = 0.0;
    double currInt = 0;

    while (getline(std::cin, curr))
    {
        lines++;
        currInt = stoi(curr);
        totalInt += currInt;
        
        // determine the sum of squares
        totalSquared += currInt * currInt;

        // initialize min and max ints
        if (lines == 1)
        {
            maxInt = currInt;
            minInt = currInt;
        }

        // determine the biggest int
        else if (currInt > maxInt)
        {
            maxInt = currInt;
        }

        // determine the smallest int
        else if (currInt < minInt)
        {
            minInt = currInt;
        }
    }

    if (lines <= 1)
    {
        std::cout << "ERROR" << std::endl;
    }

    else
    {
        // calculate the average of integers
        avgInt = totalInt / lines;

        // calculate standard deviation
        stdev = sqrt(1 / (lines - 1) * (totalSquared - lines * avgInt * avgInt));

        // print statements
        std::cout << "number of integers: " + std::to_string(lines) << std::endl;
        std::cout << "max integer read: " + std::to_string(maxInt) << std::endl;
        std::cout << "min integer read: " + std::to_string(minInt) << std::endl;
        std::cout << "average of integers read: " + std::to_string(avgInt) << std::endl;
        std::cout << "standard deviation: " + std::to_string(stdev) << std::endl;
    }

    return 0;
}