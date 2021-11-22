// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q4 q4.cpp

#include<string>
#include<iostream>

using namespace std;

auto IsCharInString (string str , char c) -> bool{
    int strLength = str.size(); 

    for (int i = 0 ; i < strLength; i++){
        if (c == str[i])
            return true; 
    }

    return false; 
}

auto main() -> int
{
    int linesRead {0};
    string currentLine;
    string sourceString;
    char targetChar;

    cout << boolalpha;

	while ( getline( cin, currentLine ) )
	{
        linesRead += 1;
        if ( ( linesRead % 2 ) == 1 ) { sourceString = currentLine; }
        else
        {
            targetChar = currentLine[0];
            cout << sourceString << "\t" << targetChar << "\t" << IsCharInString( sourceString, targetChar ) << endl;
        }
    }
}