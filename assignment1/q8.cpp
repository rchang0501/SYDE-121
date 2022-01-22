// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp
// cd r28chang/SYDE-121/assignment01

#include <iostream>
#include <string>

auto main() -> int{
    std::string curr; // current lines identifier 
    int lines = 0; // line counter 
    int start = 0; // start index holder 
    int end = 0; // end index holder 
    int stride = 0; // stride holder 

    // loop to iterate through text document 
    while (getline(std::cin, curr)){
        lines++; // increment the number of lines to trach which lines we're reading

        // setting the start, end, and stride numbers 
        if (lines == 1){
            start = stoi(curr) +3; // we add three to adjust for the lines the parameters take up
        }
        else if (lines == 2){
            end = stoi(curr) +3; // we add three to adjust for the lines the parameters take up
        }
        else if (lines == 3){
            stride = stoi(curr); 
        }

        // check if the start and end indexes are formatted correctly 
        if (lines == 3 && start > end){
            std::cout << "ERROR - not sequenced properly" << std::endl; 
            break; // end the loop and program 
        }

        // print lines based on parameters 
        if ((lines >= start) && ((lines-start)%stride ==0) && (lines <= end)){
            std::cout << curr << std::endl; 
        }
    }
    
    return 0; 
}