// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q2 q2.cpp

#include<string>
#include<iostream>

using namespace std;

auto ReverseString (string word) -> string {
    string reverse = ""; 

    for (int i = word.size()-1 ; i >= 0 ; i--){
        reverse.push_back(word[i]); 
    }

    return reverse; 
}

auto main() -> int
{
    string currentLine;

	while ( getline( cin, currentLine ) )
	{
        cout << currentLine << "\t" << ReverseString( currentLine ) << endl;
    }
}