// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o linelength linelength.cpp

#include <iostream>
#include <string>
#include <vector> 

using namespace std; 

auto main() -> int
{
    std::string curr;
    vector <std::string> arr;

    while (getline(std::cin, curr))
    {
        arr.push_back(curr);
    }

    for (int i = arr.size() -1 ; i >=0 ; i--){
        std::cout << arr[i] << std::endl; 
    }

    return 0;
}