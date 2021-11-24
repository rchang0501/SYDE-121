// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
// cd r28chang/SYDE-121/assignment01

#include <iostream>
#include <string>
#include <cmath>
#include <vector> 

using namespace std; 

auto main() -> int
{
    std::string curr;
    double lines = 0;
    double totalInt = 0.0;
    double avgInt = 0.0;
    double totalSquared = 0.0;
    double stdev = 0.0;
    double currInt = 0;
    int valueSize = 0; 

    std::vector <int> values; // list to hold all input values 

    while (getline(std::cin, curr))
    {
        lines++; // count the number of lines 

        currInt = stoi(curr); // convert the current line to an integer  
        totalInt += currInt; // add all the number in the file 

        values.push_back(currInt); // add the number to the value array 
    }

    // making sure there are enough valuesto compute standard deviation
    if (lines <= 1)
    {
        std::cout << "ERROR" << std::endl; // ouput error line 
    }

    else
    {
        // calculate the average of integers
        avgInt = totalInt / lines;

        valueSize = values.size(); // determine number of values 

        // iterate through list 
        for (int i = 0 ; i < valueSize ; i++){
            totalSquared += (values[i] - avgInt)*(values[i] - avgInt); // compute the numberator of the expression 
        }

        // calculate standard deviation
        stdev = sqrt(1 / (lines - 1) * (totalSquared));

        // print statements
        std::cout << "standard deviation: " + std::to_string(stdev) << std::endl;
    }

    return 0;
}