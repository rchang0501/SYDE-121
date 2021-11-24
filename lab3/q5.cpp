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
    std::vector<int> targets;

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
        else if (lines > 2 && lines <= (rows * cols) +2)
        {
            values.push_back(currInt);
        }
        else {
            targets.push_back(stoi(curr)); 
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

    // matrix header 
    std::cout << "Matrix\n-------------" << std::endl; 

    // print matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::to_string(list[i][j]) + " ";
        }

        std::cout << "\n" << std::endl;
    }

    // targets header 
    std::cout << "Targets\n-------------" << std::endl; 
    
    int targRow = 0; 
    int targCol = 0; 
    int targPair = 1; 
    int targSize = targets.size(); 

    for (int i = 0; i < targSize ; i++){
        if (i % 2 == 0){
            targRow = targets[i]-1; 
        }
        else if (i % 2 != 0){
            targCol = targets[i]-1; 
            if (targRow >= rows || targCol >= cols){
                std::cout << "Target " + std::to_string(targPair) + ": ERROR - Target out of bounds" << std::endl; 
                targPair++; 
            }
            else {
                std::cout << "Target " + std::to_string(targPair) + ": " + std::to_string(list[targRow][targCol]) << std::endl; 
                targPair++; 
            }
        }
    }

    return 0;
}