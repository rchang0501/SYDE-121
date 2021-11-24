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
    int rows = 0;
    int cols = 0;
    float currInt = 0.0;

    std::vector<float> values;

    while (getline(std::cin, curr))
    {
        lines++;
        currInt = stof(curr);

        if (lines == 1)
        {
            rows = stoi(curr);
        }
        else if (lines == 2)
        {
            cols = stoi(curr);
        }
        else
        {
            values.push_back(currInt);
        }
    }

    int counter = 0;
    vector<vector<float>> list(rows, vector<float>(cols, 0.0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            list[i][j] = values[counter];
            counter++;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::to_string(list[i][j]) << std::endl;
        }
    }

    return 0;
}