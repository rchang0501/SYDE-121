// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
// cd r28chang/SYDE-121/assignment01

#include <iostream>
#include <string>

auto main() -> int
{
    std::string curr;     // current lines identifier
    int lines = 0;        // line counter
    int val = 0;          // this is the initial calculated value
    int instructions = 0; // our instructions counter
    int parameters = 0;   // our parameteres counter

    // this is the operation identifier - we will be assigning values to it later on to distinguish between the instructions
    // LEGEND: 
    // 1 is add 
    // 2 is subtract 
    // 3 is multiply 
    // 4 is divide  
    int operation = 0; 

    std::string valStr = std::to_string(val); // initializer - converts the calculated value to a string

    // loop to read every line in the input file
    while (getline(std::cin, curr))
    {
        lines++; // increment the number of lines to trach which lines we're reading

        // if we find the instruction a 
        if (curr == "a")
        {
            instructions++; // we increase the instruction counter by one 
            operation = 1; // we set the operation identifer to 1 (add) 
        }
        // if we find the instruction b
        else if (curr == "s")
        {
            instructions++; // we increase the instruction counter by one
            operation = 2; // we set the operation identifer to 2 (subtract) 
        }
        // if we find the instruction m
        else if (curr == "m")
        {
            instructions++; // we increase the instruction counter by one
            operation = 3; // we set the operation identifer to 3 (multiply) 
        }
        // if we find the instruction d
        else if (curr == "d")
        {
            instructions++; // we increase the instruction counter by one
            operation = 4; // we set the operation identifer to 4 (divide) 
        }
        // since we can assume that all lines contain either the single character instruction or a correctly formatted integer, 
        // the following will be reading exclusively integers and performing operations as per the instruction 
        else
        {
            parameters++; // we increase the parameter counter by one 

            // if the instruction is add, we will add the values 
            if (operation == 1)
                val += stoi(curr);

            // if the instruction is subtract, we will subtract the values 
            else if (operation == 2)
                val -= stoi(curr);

            // if the instruction is multiply, we will multiply the values 
            else if (operation == 3)
                val *= stoi(curr);

            // if the instruction is divide, we will divide the values 
            else if (operation == 4)
                val /= stoi(curr);
        }

        valStr = std::to_string(val); // converts the current value to a string 

        // we output the read instruction/parameter next to the current value as instructed by the sample output 
        std::cout << "\t" + curr + "\t\t" + valStr << std::endl; 
    }

    std::string instructStr = std::to_string(instructions); // we convert our instruction counter to a string 
    std::string paramStr = std::to_string(parameters); // we convert our parameter counter to a string 

    // Output the Footer as instructed by the sample output
    std::cout << "Instructions: " + instructStr + " Parameters: " + paramStr + " Final Result: " + valStr << std::endl;

    return 0; 
}